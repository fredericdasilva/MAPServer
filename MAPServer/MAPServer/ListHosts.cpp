#include "StdAfx.h"
#include "ListHosts.h"

#include <fstream>
#include <string>

ListHosts::ListHosts(void)
{
	pathTextFileList = "ListsHosts.txt";
}


/*ListHosts::ListHosts(string path)
{
	pathTextFileList = path;
}*/

ListHosts::~ListHosts(void)
{
}

/*Fonction de recherche d'un host.
Valeur de retour:	0 si OK
					-1 si KO
*/
int ListHosts::findHost(string Hostname)
{
	int ReturnValue = -1;

	for(it=listeClients.begin(); it!=listeClients.end(); it++)
	{
		if(it->getHostname().compare(Hostname.c_str()) == 0)
			ReturnValue = 0;
	}

	return ReturnValue;
}


/*Fonction de récupération d'un Host
*//*
void ListHosts::getHost(string Hostname, Host * HostToReturn)
{
	for(it=listeClients.begin(); it!=listeClients.end(); it++)
	{
		if(it->getHostname().compare(Hostname.c_str()) == 0)
			HostToReturn = *it;
	}
}*/

/*Fonction de récupération d'un mode depuis un nom de machine
*/
int ListHosts::getModeFromHostname(string Hostname)
{
	int modeToReturn;

	for(it=listeClients.begin(); it!=listeClients.end(); it++)
	{
		if(it->getHostname().compare(Hostname.c_str()) == 0)
			modeToReturn = it->getMode();
	}

	return modeToReturn;
}

/*Fonction d'ajout d'un Host
*/
void ListHosts::addHost(Host * HostToAdd)
{
	listeClients.push_back(*HostToAdd);
}

/*Fonction de suppression d'un Host
*/
void ListHosts::removeHost(Host* HostToRemove)
{
	for(it=listeClients.begin(); it!=listeClients.end(); it++)
	{
		if(it->getHostname().compare(HostToRemove->getHostname().c_str()) == 0)
			listeClients.erase(it);
	}
}

/*Fonction de suppression de tous les Hosts
*/
void ListHosts::removeAllHosts(void)
{
	listeClients.clear();
}

/*
Fonction d'enregistrement de la liste dans un fichier texte
*/
void ListHosts::SaveList(void)
{

}

/*
Fonction d'enregistrement de la liste dans un fichier texte
*/
vector<Host> ListHosts::LoadList(void)
{
	vector<Host> LoadedList;

	return LoadedList;
}

/*Fonction de sérialisation
*/
template<class Archive> void ListHosts::serialize(Archive& ar, const unsigned int version)
{
	ar & boost::serialization::base_object<ListHosts>(*this); 
	ar & pathTextFileList & listeClients & it;
}