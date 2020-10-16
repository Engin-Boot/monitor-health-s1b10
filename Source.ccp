
#include <iostream>
using namespace std;

#include "Header.h"
int main()
{
	string commPortName = "COM2";
	int baudrate = 57600;

	Serial Obj(commPortName, baudrate);
	
	int buffLen = 108;
	char buffer[108];
	
	Obj.read(buffer, buffLen);
	Obj.dataParser(buffer);
	Obj.flush();
}
Serial::Serial(string& commPortName, int baudrate)
{

	commHandle = CreateFile(commPortName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING,
		0, NULL);

	if (commHandle == INVALID_HANDLE_VALUE)
	{
		throw("ERROR: Could not open com port");
	}
	else
	{
		
		DCB dcb;
		
		memset(&dcb, 0, sizeof(dcb));
		dcb.DCBlength = sizeof(dcb);
		dcb.BaudRate = baudrate;
		dcb.fBinary = 1;

		dcb.Parity = NOPARITY;
		dcb.StopBits = ONESTOPBIT;
		dcb.ByteSize = 8;

	}
}

Serial::~Serial()
{
	CloseHandle(commHandle);
}

int Serial::read(char* buffer, int buffLen)
{
	bool nullTerminate = TRUE;
	DWORD numRead;
	
	BOOL ret = ReadFile(commHandle, buffer, buffLen, &numRead, NULL);
	
	if (!ret)
	{
		return 0;
	}

	if (nullTerminate)
	{
		buffer[numRead] = '\0';
	}
	cout << buffer << endl;
	
	return numRead;
}

#define FLUSH_BUFFSIZE 108

void Serial::flush()
{
	char buffer[FLUSH_BUFFSIZE];
	int numBytes = read(buffer, FLUSH_BUFFSIZE);
	while (numBytes != 0)
	{
		numBytes = read(buffer, FLUSH_BUFFSIZE);
	}
}
