
#include <string.h>
#include <iostream>
#include "Header.h"

using namespace std;

extern char buffer[108];

struct params
{
	char date[13];
	char sypr[8];
	char dipr[8];
	char augpr[4];
	char meanpr[8];
	char hrate[4];
	char alarm[5];
	char asratio[2];
	char bvol[5];
	char infm[5];
	char defm[5];
	char opmod[5];
	char tgmod[5];
	char checksum[3];

};

void Serial::dataParser(char* buffer)
{
	unsigned int index = 0;
	unsigned int i;
	params obj;
	
	for (i = 0; i < sizeof(obj.date) - 1; i++)
	{
		obj.date[i] = buffer[i+2];
		
	}
	obj.date[sizeof(obj.date)-1] = '\0';

	for (i = 0; i < sizeof(obj.sypr) - 1; i++)
	{
		obj.sypr[i] = buffer[i+17];
	}
	obj.sypr[sizeof(obj.sypr)-1] = '\0';

	for (i = 0; i < sizeof(obj.augpr) - 1; i++)
	{
		obj.augpr[i] = buffer[i+28];
	}
	obj.augpr[sizeof(obj.augpr)-1] = '\0';

	for (i = 0; i < sizeof(obj.dipr) - 1; i++)
	{
		obj.dipr[i] = buffer[i+34];
	}
	obj.dipr[sizeof(obj.dipr)-1] = '\0';
	

	for (i = 0; i < sizeof(obj.meanpr) - 1; i++)
	{
		obj.meanpr[i] = buffer[i+44];
	}
	obj.meanpr[sizeof(obj.meanpr)-1] = '\0';
	

	for (i = 0; i < sizeof(obj.hrate) - 1; i++)
	{
		obj.hrate[i] = buffer[i+53];
	}
	obj.hrate[sizeof(obj.hrate) - 1] = '\0';

	for (i = 0; i < sizeof(obj.alarm) - 1; i++)
	{
		obj.alarm[i] = buffer[i+60];
	}
	obj.alarm[sizeof(obj.alarm) - 1] = '\0';

	for (i = 0; i < sizeof(obj.asratio) - 1; i++)
	{
		obj.asratio[i] = buffer[i+67];
	}
	obj.asratio[sizeof(obj.asratio) - 1] = '\0';
	
	for (i = 0; i < sizeof(obj.bvol) - 1; i++)
	{
		obj.bvol[i] = buffer[i+71];
	}
	obj.bvol[sizeof(obj.bvol) - 1] = '\0';
	
	for (i = 0; i < sizeof(obj.infm) - 1; i++)
	{
		obj.infm[i] = buffer[i+78];
	}
	obj.infm[sizeof(obj.infm) - 1] = '\0';

	for (i = 0; i < sizeof(obj.defm) - 1; i++)
	{
		obj.defm[i] = buffer[i+85];
	}
	obj.defm[sizeof(obj.defm) - 1] = '\0';
	
	for (i = 0; i < sizeof(obj.opmod) - 1; i++)
	{
		obj.opmod[i] = buffer[i+92];
	}
	obj.opmod[sizeof(obj.opmod) - 1] = '\0';
	
	for (i = 0; i < sizeof(obj.tgmod) - 1; i++)
	{
		obj.tgmod[i] = buffer[i+99];
	}
	obj.tgmod[sizeof(obj.tgmod) - 1] = '\0';
	
	for (i = 0; i < sizeof(obj.checksum) - 1; i++)
	{
		obj.checksum[i] = buffer[i+104];
	}
	obj.checksum[sizeof(obj.checksum) - 1] = '\0';
	
}

