#include "POSInfo.h"
string POSInfo::GetName()
{
	return m_strName;
}

POSInfo& POSInfo::SetName(string Name)
{
	m_strName = Name;
	return *this;
}

string POSInfo::GetID()
{
	return m_strID;
}

POSInfo& POSInfo::SetID(string ID)
{
	m_strID = ID;
	return *this;
}

string POSInfo::GetPW()
{
	return m_strPW;
}

POSInfo& POSInfo::SetPW(string Pw)
{
	m_strPW = Pw;
	return *this;
}

int POSInfo::GetBirth()
{
	return m_nBirth;
}

POSInfo& POSInfo::SetBirth(int Birth)
{
	m_nBirth = Birth;
	return *this;
}

int POSInfo::GetSeat()
{
	return m_nSeat;
}

POSInfo& POSInfo::SetSeat(int seat)
{
	m_nSeat = seat;
	return *this;
}

int POSInfo::GetMoney()
{
	return m_nMoney;
}

POSInfo& POSInfo::SetMoney(int Money)
{
	m_nMoney = Money;
	return *this;
}