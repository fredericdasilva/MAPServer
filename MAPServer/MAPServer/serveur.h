#pragma once
#ifndef __serveur_h__ 
#define __serveur_h__ 

#include <winsock2.h>

#include <iostream>
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <winsock.h>

#include "Host.h"
#include "Frame.h"
#include "ListHosts.h"

//#include "boost/archive/text_iarchive.hpp"
//#include "boost/archive/text_oarchive.hpp"


using namespace std;

#pragma comment( lib, "wsock32.lib" )

class serveur;

struct thread_param{
       serveur* ser;
       SOCKET soc;
};


class serveur{
	private: 
		int           port;
		SOCKET	      ListeningSocket;
		bool          running;  
		SOCKADDR_IN   ServerAddr;   
		DWORD         ClientThread(SOCKET);

		char *		serverHostname;
		char *		serverIPAddress;
		ListHosts listeClients;
	
public:                                        
		serveur(int);
		virtual ~serveur(void);
		int                 init();
		int                 start ();  
		int                 pause ();
		static DWORD WINAPI ThreadLauncher(void *p){
			struct thread_param *Obj = reinterpret_cast<struct thread_param*>(p);               
			serveur *s = Obj->ser;                          
			return s->ClientThread(Obj->soc);       
		}

		string getServerHostname(void);
		string getServerIPaddress(void);

	private:
		int receptClientRequest(SOCKET soc, Host * newHost);
		void sendClientRequest(SOCKET soc, Host * hostConnected);
		void findClientTreatement(Host * hostConnected);
		void fillServerFrame(int numMode, char * dataArgs, Frame * frameToSend, Host *hostConnected);
		void FillDataSwitchMode(int numMode, char * dataToFill);

}; 



#endif
