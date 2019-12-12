#pragma once
#include "POSInfo.h"
#include <list>

using namespace std;

class POSInfoController
{
private:
	list<POSInfo> m_POSInfoList;

public:
	bool OrderPOSInfo();
	bool FindIDPOSInfo();
	bool FindPWPOSInfo();
	bool ModifyPOSInfo();
	bool DeletePOSInfo();
	bool PrintAllPOSInfo();
	list<POSInfo>* GetPOSList();
};

