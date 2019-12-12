#pragma once
#include "Util.h"
#include "PCInfo.h"

class PCcontroller
{
private:
	PCinfo* g_pPCInfo;		// 구조체에 저장된 회원 정보 주소
	int g_nPCCount;			// 회원 수
	int g_nSeatCount;		// 이용 좌석 수
	PCinfo* m_pCurrPCinfo;	// 로그인 상태 유지
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