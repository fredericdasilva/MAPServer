#include "StdAfx.h"
#include "Host.h"

Host::Host(void)
{
}

Host::Host(string _hostname, string _address, int _mode)
{
	hostname = _hostname;
	address = _address;
	mode = _mode;
}

Host::~Host(void)
{
}

void Host::setHostname(std::string _hostname)
{
	hostname = _hostname;
}

void Host::setAddress(string _address)
{
	address = _address;
}

void Host::setDataToTreat(string _dataToTreat)
{
	dataToTreat = _dataToTreat;
}

void Host::setMode(int _mode)
{
	mode = _mode;
}

string Host::getHostname(void)
{
	return hostname;
}

string Host::getAddress(void)
{
	return address;
}

string Host::getDataToTreat(void)
{
	return dataToTreat;
}

int Host::getMode(void)
{
	return mode;
}

/*Fonction de sérialisation
*/
template<class Archive> void Host::serialize(Archive& ar, const unsigned int version)
{
	ar & hostname & address & dataToTreat & mode;
}