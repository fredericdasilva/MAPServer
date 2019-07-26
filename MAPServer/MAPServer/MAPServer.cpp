// MAPServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

#include "Frame.h"
#include "serveur.h"


	
int _tmain(int argc, _TCHAR* argv[])
{
	int numPort = 8080;

	cout << "----SERVEUR----"<<endl;
	cout << "Ecoute du port "<< numPort <<" ..."<<endl;

	serveur *MyServer = new serveur(numPort);
	if(MyServer->init()!=0)
	{
		cerr << "ne peut initialiser le serveur"<< endl;
		return 1;
	}
  
	if(MyServer->start()!=0){
		cerr << "ne peut démarrer le serveur"<< endl;
		return 1;
	}


	system("PAUSE");

	return 0;
}

