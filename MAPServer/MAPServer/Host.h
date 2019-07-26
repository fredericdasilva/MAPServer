#pragma once

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <winsock.h>
#include "Mode.h"

using namespace std;

#pragma comment( lib, "wsock32.lib" )


class Host
{
private:
	string hostname;
	string address;
	string dataToTreat;
	int mode;
	
public:
	Host(void);
	Host(string _hostname, string _address, int _mode);
	virtual ~Host(void);

	void setHostname(string _hostname);
	void setAddress(string _address);
	void setDataToTreat(string _dataToTreat);
	void setMode(int _mode);
	
	string getHostname(void);
	string getAddress(void);
	string getDataToTreat(void);
	int getMode(void);

	template<class Archive> void serialize(Archive& ar, const unsigned int version);

};
