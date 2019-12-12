#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "turboc.h"
#include <Windows.h>

#define FILE_NAME "../pcinfo.bin"
#define MAX_NUM	200
#define MAX_PC	100



enum
{
	LOGIN=1, JOIN, SEAT, EXIT
};