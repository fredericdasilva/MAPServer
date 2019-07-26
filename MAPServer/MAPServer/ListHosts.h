#pragma once

#include <iostream>
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Host.h"

using namespace std;

class ListHosts
{
public:

	template<class Archive>    void serialize(Archive& ar, const unsigned int version);


private:
	string pathTextFileList;
	vector<Host> listeClients;
	vector<Host>::iterator it;

public:
	ListHosts(void);
	//ListHosts(string path);
	virtual ~ListHosts(void);

	//Rechercher un host
	int findHost(string Hostname);

	//Récuperer un host
	//Host * getHost(string Hostname, Host * HostToReturn);

	//Récupèrer un mode depuis un nom d'Host
	int getModeFromHostname(string Hostname);

	//Ajouter un host
	void addHost(Host* HostToAdd);

	//Supprimer un host
	void removeHost(Host* HostToRemove);

	//Supprimer Tous les hosts
	void removeAllHosts(void);

	//Enregistrer la liste dans un fichier
	void SaveList(void);

	//Charger la liste depuis un fichier
	vector<Host> LoadList(void);


};
