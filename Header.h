#pragma once

#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <string>
#include <windows.h>

typedef std::basic_string<TCHAR> tstring;

class Serial
{
protected:
	HANDLE commHandle;

public:
	Serial(tstring& commPortName , int baudrate);

	virtual ~Serial();
	
	
	int read(char* buffer, int buffLen);

	
	void flush();

	void dataParser(char* buffer);
};

#endif
