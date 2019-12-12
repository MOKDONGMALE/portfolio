#include "PCcontroller.h"
#include "PCInfo.h"
#include "PCview.h"
#include <Windows.h>
#include <string>
using namespace std;
extern int pcSeat[100];
PCcontroller::PCcontroller()
{
	g_pPCInfo = new PCinfo[1000];
	g_nPCCount = 0;
}
PCcontroller::~PCcontroller()
{
	delete[] g_pPCInfo;
}

bool PCcontroller::loginPCInfo()
{
	SYSTEMTIME lst;
	GetLocalTime(&lst);
	PCinfo pi;

	if (g_nPCCount == 0)
	{
		cout << "회원이 없습니다" << endl;
		getchar();
		return true;
	}
	gotoxy(59, 21);
	cin >> pi.id;
	gotoxy(59, 25);
	cin >> pi.pw;
	int select = 0;

	for (int i = 0; i < g_nPCCount; i++)
	{
		if (pi.id.compare( g_pPCInfo[i].id)==0 && pi.pw.compare(g_pPCInfo[i].pw)==0)
		{
			m_pCurrPCinfo = &g_pPCInfo[i];
			int a = i;
			if (g_pPCInfo[i].cycle == 1)
			{
				clearScreen();
				cout << "퇴장하시겠습니까?" << endl;
				cin >> select;
				cout << "예";
				cout << "아니오";
				switch (select)
				{
				case 1:
					clearScreen();
					pcSeat[(m_pCurrPCinfo->seat) - 1] = 0;
					g_pPCInfo[i].cycle = 0;
					m_pCurrPCinfo->seat = 0;
					m_pCurrPCinfo->time2 = (lst.wHour * 100) + lst.wMinute;
					m_pCurrPCinfo->money = (m_pCurrPCinfo->money) - (m_pCurrPCinfo->time2 - m_pCurrPCinfo->time1) * 1000;
					
					getchar();
					cout << "안녕히가세요~";
					return true;
				case 2:
					clearScreen();
					return true;
				}
			}
			clearScreen();
			gotoxy(53, 18); 
			getchar();
			cout << m_pCurrPCinfo->name << "님 환영합니다" << endl;
			getchar();
			clearScreen();
			g_pPCInfo[i].cycle = 1;
			gotoxy(0, 5);
			showSeat();

			return false;
		}
	}

	getchar();
	gotoxy(55, 30);
	cout << "회원이 아닙니다" << endl;
	
	return true;
}

bool PCcontroller::joinPCInfo()
{
	PCinfo pi;
	char pass[16] = { 0 };
	int i = 0;
	if (g_nPCCount == 200)
	{
		cout << "더 이상 회원 가입 할 수 없습니다" << endl;
		return false;
	}
	gotoxy(59, 21);
	cin >> pi.id;
	gotoxy(59, 23);
	cin >> pi.pw;
	gotoxy(61, 25);
	cin >> pi.name;
	pi.cycle = 0;
	gotoxy(65, 27);
	cin >> pi.birth;
	

	
	g_pPCInfo[g_nPCCount] = pi;
	g_nPCCount++;

	return true;
}
bool PCcontroller::seatPCInfo()
{
	SYSTEMTIME lst;
	GetLocalTime(&lst);
	
	int myseat = 0;
	
	if (g_nSeatCount > MAX_PC)
	{
		cout << "만석" << endl;
		return false;
	}
	
	gotoxy(53, 2);
	cout << "좌석을 선택하세요";
	cin >> myseat; 
	
	pcSeat[myseat-1] = 1;
	m_pCurrPCinfo->seat = myseat;
	m_pCurrPCinfo->time1 = (lst.wHour * 100) + lst.wMinute;
	g_nSeatCount++;

	clearScreen();
	return true;
}

bool PCcontroller::printAllPCInfo()
{
	int i = 0;

	if (g_nPCCount == 0)
	{	 
		printf("출력할 정보가 없습니다!!\n");
		getchar();
		return false;
	}

	for (i = 0; i < g_nPCCount; i++)
	{
		cout << "************" << i+1 << "번째" << "************" << endl;
		cout << g_pPCInfo[i].id << endl;
		cout << g_pPCInfo[i].pw << endl;
		cout << g_pPCInfo[i].name << endl;
		cout << g_pPCInfo[i].seat << endl;
		cout << g_pPCInfo[i].time1 << endl;
		cout << g_pPCInfo[i].time2 << endl;
		cout << g_pPCInfo[i].money << endl;
		cout << g_pPCInfo[i].birth << endl;
		cout << "*******************************" << endl;
	}
	getchar();
	return true;
}
bool PCcontroller::loadPCInfo()
{
	FILE* fp = NULL;
	errno_t err = 0;
	err = fopen_s(&fp, FILE_NAME, "rb");
	if (fp == NULL)
	{
		cout << "파일 OPEN 실패, 에러:" << err << endl;
		return false;
	}

	fread(&g_nPCCount, sizeof(int), 1, fp);
	fread(g_pPCInfo, sizeof(PCinfo), g_nPCCount, fp);

	fclose(fp);

	return true;
}
bool PCcontroller::savePCInfo()
{
	FILE* fp = NULL;
	errno_t err = 0;
	err = fopen_s(&fp, FILE_NAME, "wb");
	if (fp == NULL)
	{
		cout << "파일 OPEN 실패, 에러:" << err << endl;
		return false;
	}

	fwrite(&g_nPCCount, sizeof(int), 1, fp);
	fwrite(g_pPCInfo, sizeof(PCinfo), g_nPCCount, fp);

	fclose(fp);
	return true;
}

PCinfo* PCcontroller::GetCurrPCinfo()
{
	return m_pCurrPCinfo;
}