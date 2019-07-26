#include "StdAfx.h"

#include "serveur.h"
#include "Frame.h"

#define _MAX_HOST_LENGTH_ 100

using namespace std;



serveur::serveur(int p){
	port	= p;
	running	= false;

	serverHostname = (char *)malloc(15*sizeof(char));
	serverIPAddress = (char *)malloc(15*sizeof(char));
}

serveur::~serveur(void)
{
	//Libération de la mémoire
	free(serverHostname);
	free(serverIPAddress);
}

string serveur::getServerHostname(void)
{
	char FAR bufferServer[64] ;
  
	  // Initialisation du service WSA
	  WORD wVersionRequested;
	  WSADATA wsaData;
	  int err;
	  wVersionRequested = MAKEWORD(1, 1);
	  err = WSAStartup(wVersionRequested, &wsaData);
	  if (err != 0)
	  {
		cerr << "Impossible de trouver winsock.dll";
	  }
	  // Récupération du nom de la machine
	  gethostname(bufferServer, sizeof(bufferServer));

	  return string(bufferServer);
}

string serveur::getServerIPaddress(void)
{
	struct sockaddr_in sin;
	struct hostent * phe;
	
	// Récupération de la liste d'ips associées à la machine
	phe = gethostbyname(getServerHostname().c_str());
	  if(phe==NULL)
	  {
		cerr << "Erreur : pointeur nul";
		WSACleanup();
		system("PAUSE");
		exit(1);
	  }
	  // Enumération des adresses
	  int I = 0 ;
	  while((phe->h_addr_list[I+1])!=NULL)
	  {
		I++;
	  }
	  memcpy(&sin.sin_addr.s_addr, phe->h_addr_list[I], phe->h_length);
	  WSACleanup();
	
		return string(inet_ntoa(sin.sin_addr));	
}

int serveur::init(){
	struct in_addr  MyAddress;
	struct hostent  *host;
	char HostName[_MAX_HOST_LENGTH_];
	WSADATA	      wsaData;

	if(WSAStartup(MAKEWORD(2,2), &wsaData ) != 0 ){
		cerr <<"WSAStartup a échoué "<< endl;
		return 1;
	}

	if( gethostname( HostName, _MAX_HOST_LENGTH_ ) == SOCKET_ERROR ){
		cerr<< "gethostname() a rencontré l'erreur "<< WSAGetLastError()  << endl;
		return 1;
	}

	if( (host = gethostbyname( HostName ) ) == NULL){
		cerr <<"gethostbyname() a rencontré l'erreur "<< WSAGetLastError()<< endl;
		return 1;
	}

	memcpy( &MyAddress.s_addr, host->h_addr_list[0], sizeof( MyAddress.s_addr ) );

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons( port );
	ServerAddr.sin_addr.s_addr = inet_addr( inet_ntoa( MyAddress ) );
	//ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  

	cout <<"server correctement initialise" << endl;
	return 0;
}

int serveur::start (){
	SOCKADDR_IN                 ClientAddr;
	int                         ClientAddrLen;
	HANDLE                      hProcessThread;
	SOCKET                      NewConnection;
	struct thread_param         p;

	if( ( ListeningSocket = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP ) ) == INVALID_SOCKET ){
		cerr << "ne peut créer la socket. Erreur n° " << WSAGetLastError()<< endl;
		WSACleanup();
		return 1;
	}

	if( bind( ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof( ServerAddr ) ) == SOCKET_ERROR ){
		cerr << "bind a échoué avec l'erreur " << WSAGetLastError() << endl;
		cerr << "Le port est peut-être déjà utilisé par un autre processus " << endl;
		closesocket( ListeningSocket );
		WSACleanup();
		return 1;
	}

	if( listen( ListeningSocket, 5 ) == SOCKET_ERROR ){
		cerr << "listen a échoué avec l'erreur " << WSAGetLastError() << endl;
		closesocket( ListeningSocket );
		WSACleanup();
		return 1;
	}

	cout << "serveur demarre : a l'ecoute du port " << port << endl;
	running = true;
	ClientAddrLen = sizeof( ClientAddr );

	while(running){

		if((NewConnection = accept( ListeningSocket, (SOCKADDR *) &ClientAddr, &ClientAddrLen)) == INVALID_SOCKET){
			cerr  << "accept a échoué avec l'erreur " << WSAGetLastError() << endl;;
			closesocket( ListeningSocket );
			WSACleanup();
			return 1;
		}

		p.ser = this;
		p.soc = NewConnection;


		cout << "client connecte ::  IP : " <<inet_ntoa( ClientAddr.sin_addr )<< " ,port = " <<ntohs( ClientAddr.sin_port ) << endl;

		hProcessThread = CreateThread(NULL, 0,&serveur::ThreadLauncher, &p,0,NULL);
		if ( hProcessThread == NULL ){
			cerr << "CreateThread a échoué avec l'erreur " <<GetLastError()<< endl;
		}
	}

	return 0;
}

int serveur::pause (){
	running = false;
	cout << "Serveur en pause" << endl;
	closesocket( ListeningSocket );
	return 0;
}

/* ======================================================================== */
/* ========================== thread proc ================================= */
/* ======================================================================== */


DWORD serveur::ClientThread(SOCKET socket)
{
	Host hostConnect;
	
	
	//Reception des données
	cout << "Reception des donnees" << endl;
	while (receptClientRequest(socket, &hostConnect) == 0)
	{

		//Recherche de mode pour le poste
		//if(hostConnect != NULL)
			cout << "Recherche de mode" << endl;
			findClientTreatement(&hostConnect);

		//Renvoie des données
		cout << "Renvoie des donnees" << endl;
		sendClientRequest(socket, &hostConnect);
	}
	
	
	return 0;
}

/*--------------------------------------------------
Cette fonction recoit la requete d'un client, vérifie le CS et constitue un host
	renvoit 0: si Checksum OK
	renvoit -1: si Checksum KO
----------------------------------------------------*/
int serveur::receptClientRequest(SOCKET soc, Host * newHost)
{
	int returnValue;
	int datalen;
	char buffer[1024];

	Frame * frame = new Frame;
	
	datalen = recv((int)soc,buffer,1024,0);

	if (datalen == SOCKET_ERROR)
		 cerr << "Echec dans le reception des donnees " <<GetLastError()<< endl;
	else
		{
			cout << "	Reconstituttion de la trame" << endl;
		  //buffer[datalen]=0; 
		  // Permet de fermer le tableau après le contenu des data, car la fonction recv ne le fait pas		

			/*printf("Contenu de la trame recue :\n");
			for (int i=0; i<=1023;i++)
				printf("%i",buffer[i]);

			printf("\n");*/
		
			frame->setNumCommand(buffer[0]);

			char * IP;	
			char * name;
			char * datas;
			
			IP =(char *)malloc(16*sizeof(char));
			name =(char *)malloc(16*sizeof(char));
			datas =(char *)malloc(1000*sizeof(char));

			for(int i=0; i <= 15; i++)
			{
				IP[i]=buffer[i+1];
				name[i]=buffer[i+17];
			}

		frame->setHostIP(IP);
		frame->setHostname(name);
	
			for(int i=0; i <= 990; i++)
				datas[i]=buffer[i+32];		

		 frame->setData(datas);
		 frame->setChecksum(buffer[1023]);

			if ((char)frame->computeChecksum() == frame->getChecksum())
			{
				cout << "	Validation CheckSum : OK" << endl;
				returnValue = 0;
				newHost->setAddress(string(frame->getHostIP()));
				newHost->setHostname(string(frame->getHostname()));
				newHost->setMode(frame->getNumCommand());
			}
			else
			{
				cout << "	CheckSum invalide" << endl;
				returnValue = -1;
			}

			//On libère la mémoire aprés avoir completer notre objet Host
			//frame.~Frame();
			//delete[] frame;
			/*free(IP);
			free(name);
			free(datas);*/
		}
 
	return returnValue;
}

/*--------------------------------------------------
Cette fonction renvoit une requete à un client
----------------------------------------------------*/
void serveur::sendClientRequest(SOCKET soc, Host *hostConnected)
{
	int result;
	char * donnees;
	Frame * frame = new Frame;

	donnees =(char *)malloc(1025*sizeof(char));

	//Efface la trame
	for(int i= 0; i<= 1024; i++)
		donnees[i] = 0;

	for(int i= 0; i<= hostConnected->getDataToTreat().length(); i++)
		donnees[i] = hostConnected->getDataToTreat().c_str()[i];

	//Envoie des données à traiter
	fillServerFrame(hostConnected->getMode(), donnees, frame, hostConnected);
	
	
	//Envoie de la trame
	//donnees = frame->buildFinalFrame();

	result = send(soc, frame->buildFinalFrame(), 1024, 0);
	if(result < 0)
	{
		perror("Erreur dans l'envoie de donnees\n");
		//exit(errno);
	}

	//Une fois les données envoyés on peut liberer la mémoire
	//delete[] frame;
	//free(donnees);
	
}


/*--------------------------------------------------
Cette fonction renvoit une requete à un client
----------------------------------------------------*/
void serveur::findClientTreatement(Host *hostConnected)
{

	int mode;
	
	//Recherche du poste dans une liste par son hostname,
	//s'il est trouvé, Apllication de son mode
	if (listeClients.findHost(hostConnected->getHostname()) == 0)
	{
		//L'objet courant prend les attributs définis dans la liste
		//hostConnected->setMode(listeClients.getModeFromHostname(hostConnected->getHostname()));

		//Test d'entrée des commande au clavier
		cout << "Host : " << hostConnected->getHostname().c_str()<<endl;
		cout << "Which mode ?" ;

		cin >> mode;
		hostConnected->setMode(mode);

	}
	else	//Il n'existe pas on l'ajoute
	{
		listeClients.addHost(hostConnected);
	}
	
	//hostConnected->setMode(Mode::LaunchWaitApps);	//Test pour relance appli
	//hostConnected->setDataToTreat("calc.exe");
}

/*
	Cette fonction remplit les parties (numMode et Données) de la trames selon le mode du client
	La partie hostname est automatiquement renseignée peut importe le mode
	Implémentation à modifier selon le mode
*/
void serveur::fillServerFrame(int numMode, char* dataArgs, Frame * frameToSend, Host *hostConnected )
{	
	cout << "	Constitution de la trame a renvoyer" << endl;
	//Num commande
	frameToSend->setNumCommand(numMode);

	//Initialisation des tableaux de caractères
	for (int i=0;i<=15;i++)
	{
		serverHostname[i] = 0;
		serverIPAddress[i] = 0;
	}

	//HostIP
	for(int i=0; i<=getServerIPaddress().length();i++)
		serverIPAddress[i] = getServerIPaddress().c_str()[i];

	frameToSend->setHostIP(serverIPAddress);

	//Hostname
		//Affectation du nom de la machine
	for(int i=0; i<=getServerHostname().length();i++)
		serverHostname[i] = getServerHostname().c_str()[i];

	frameToSend->setHostname(serverHostname);

	//Données variable selon mode
	//for (int i=0;i<=992;i++)
	//	dataToSend[i] = 0;
	
	FillDataSwitchMode(hostConnected->getMode(), dataArgs);

	/*//TEST
	cout << "Contenu de la trame avec les données :" << endl;
	for (int i=0; i<=1023;i++)
			printf("%c",donnees[i]);

	cout <<endl;*/

	frameToSend->setData(dataArgs);
	
	//Le checksum, lui, est calculé automatiquement lors de la construction de la trame
}

/*
Cette fonction remplie la partie des données selon le mode
*/
void serveur::FillDataSwitchMode(int numMode, char * dataToFill)
{
	
	switch (numMode)
	{
	case Mode::LaunchApps:		cout << "Enter the path of the application to launch :" <<endl;
										cin.get();
										cin.get(dataToFill,990);
											break;
	
	case Mode::LaunchWaitApps:		cout << "Enter the path of the application to launch (wait) :" <<endl;
										cin.get();
										cin.get(dataToFill,990);
											break;

	case Mode::DisplayInfoMessage:		cout << "Enter the info to display :" <<endl;
										cin.get();
										cin.get(dataToFill,990);
											break;

	case Mode::DisplayWarningMessage:	cout << "Enter the warning to display :" <<endl;
										cin.get();
										cin.get(dataToFill,990);
											break;

	case Mode::DisplayErrorMessage:		cout << "Enter the error to display :" <<endl;
										cin.get();
										cin.get(dataToFill,990);
											break;
	
	}
	

}
