#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#ifndef HELPER_H
#define HELPER_H

class Helper {
public:
	Helper();
	~Helper();

	char* GetAbsolutePath();
};

#endif