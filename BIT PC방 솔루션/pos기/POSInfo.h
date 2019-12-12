#pragma once
#include <iostream>
using namespace std;

enum
{
	ORDER = 1, FIND, MODIFY, DEL, PRINTALL, EXIT
};

class POSInfo
{
private:
	string m_strID;
	string m_strPW;
	string m_strName;
	int m_nSeat;
	int cycle;
	int m_nMoney;
	int time1;
	int time2;
	int m_nBirth;

public:
	string GetID();
	POSInfo& SetID(string ID);
	string GetName();
	POSInfo& SetName(string Name);
	string GetPW();
	POSInfo& SetPW(string Pw);
	int GetBirth();
	POSInfo& SetBirth(int Birth);
	int GetSeat();
	POSInfo& SetSeat(int Birth);
	int GetMoney();
	POSInfo& SetMoney(int Money);
};

