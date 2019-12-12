#pragma once
#include <list>
#include "POSInfo.h"
#define FILE_NAME "../pcinfo.bin" 
using namespace std;

class POSInfoModel
{
public:
	//bool LoadPOSInfoFile(list<POSInfo>* POSList);
	//bool SavePOSInfoFile(list<POSInfo>* POSList);

	bool LoadTransPOSInfoFile(list<POSInfo>* POSList);
	bool SaveTransPOSInfoFile(list<POSInfo>* POSList);
};