#pragma once
#include "Util.h"
#include "PCInfo.h"

class PCcontroller
{
private:
	PCinfo* g_pPCInfo;		// ����ü�� ����� ȸ�� ���� �ּ�
	int g_nPCCount;			// ȸ�� ��
	int g_nSeatCount;		// �̿� �¼� ��
	PCinfo* m_pCurrPCinfo;	// �α��� ���� ����
public:
	PCcontroller();
	~PCcontroller();

	bool loginPCInfo();
	bool joinPCInfo();
	bool seatPCInfo();
	bool loadPCInfo();
	bool savePCInfo();
	bool printAllPCInfo();
	PCinfo* GetCurrPCinfo();
};