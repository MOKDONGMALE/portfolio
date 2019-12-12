#include "POSInfoController.h"
#include "POSInfoView.h"
#include "turboc.h"
POSInfoView pi;
bool POSInfoController::OrderPOSInfo()
{
	int seat;
	int select;
	gotoxy(52, 21);
	cout << "�¼���ȣ�� �Է����ּ���\n";
	gotoxy(62, 24);
	cin >> seat;
	int result;

	list<POSInfo>::iterator it = m_POSInfoList.begin();
	while (it != m_POSInfoList.end())
	{
		if (seat == it->GetSeat())
			break;
		it++;
	}
	if (it == m_POSInfoList.end())
	{
		pi.ClrScr();
		pi.DrawWidthWall(18, 50, 75);
		pi.DrawWidthWall(28, 50, 75);
		pi.DrawHeightWall(50, 18, 28);
		pi.DrawHeightWall(75, 18, 28);
		gotoxy(51, 23);
		cout << "��ġ�ϴ� �¼��� �����ϴ�" << endl;
		getchar();
	}
	else
	{
		pi.ClrScr();
		gotoxy(55, 4); cout << " < M E N U >" << endl;
		gotoxy(19, 14); cout << "1. ���" << endl;
		gotoxy(20, 17); cout << "1000��" << endl;
		gotoxy(58, 14);	cout << "2. ���" << endl;
		gotoxy(59, 17); cout << "3000��" << endl;
		gotoxy(97, 14); cout << "3. ����Ƣ��" << endl;
		gotoxy(100, 17); cout << "2000��" << endl;
		gotoxy(18, 34); cout << "4. ������" << endl;
		gotoxy(20, 37); cout << "4000��" << endl;
		gotoxy(57, 34); cout << "5. ���Ե���" << endl;
		gotoxy(60, 37); cout << "5000��" << endl;
		gotoxy(97, 34); cout << "6. ��������" << endl;
		gotoxy(100, 37); cout << "6000��" << endl;
		gotoxy(49, 25); cout << "������ �ֹ��Ͻðڽ��ϱ�?\n";
	
		pi.DrawWidthWall(0, 0, 124);
		pi.DrawWidthWall(45, 0, 124);
		pi.DrawHeightWall(0, 0, 45);
		pi.DrawHeightWall(124, 0, 45);

		pi.DrawWidthWall(8, 6, 38);
		pi.DrawWidthWall(23, 6, 38);
		pi.DrawHeightWall(6, 8, 23);
		pi.DrawHeightWall(38, 8, 23);

		pi.DrawWidthWall(8, 46, 78);
		pi.DrawWidthWall(23, 46, 78);
		pi.DrawHeightWall(46, 8, 23);
		pi.DrawHeightWall(78, 8, 23);

		pi.DrawWidthWall(8, 86, 118);
		pi.DrawWidthWall(23, 86, 118);
		pi.DrawHeightWall(86, 8, 23);
		pi.DrawHeightWall(118, 8, 23);

		pi.DrawWidthWall(28, 6, 38);
		pi.DrawWidthWall(43, 6, 38);
		pi.DrawHeightWall(6, 28, 43);
		pi.DrawHeightWall(38, 28, 43);

		pi.DrawWidthWall(28, 46, 78);
		pi.DrawWidthWall(43, 46, 78);
		pi.DrawHeightWall(46, 28, 43);
		pi.DrawHeightWall(78, 28, 43);

		pi.DrawWidthWall(28, 86, 118);
		pi.DrawWidthWall(43, 86, 118);
		pi.DrawHeightWall(86, 28, 43);
		pi.DrawHeightWall(118, 28, 43);

		gotoxy(74, 25);
		cin >> select;


		if (select == 1 && it->GetMoney() - 2000 >= 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			result = it->GetMoney() - 2000;
			gotoxy(53, 23); cout << "���� ���� " << result << "�Դϴ�";
			it->SetMoney(result);
			getchar();
		}
		else if (select == 1 && it->GetMoney() - 2000 < 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(55, 22);	cout << "���� �����մϴ�.";
			gotoxy(56, 24); cout << "�������ּ���.";
			getchar();
		}
		if (select == 2 && it->GetMoney() - 3000 >= 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(53, 23);
			result = it->GetMoney() - 3000;
			cout << "���� ���� " << result << "�Դϴ�.";
			it->SetMoney(result);
			getchar();
		}
		else if (select == 2 && it->GetMoney() - 3000 < 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(55, 22);	cout << "���� �����մϴ�.";
			gotoxy(56, 24); cout << "�������ּ���.";
			result = it->GetMoney();
			getchar();
		}
		if (select == 3 && it->GetMoney() - 1000 >= 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);	
			gotoxy(53, 23);
			result = it->GetMoney() - 1000;
			cout << "���� ���� " << result << "�Դϴ�.";
			it->SetMoney(result);
			getchar();
		}
		else if (select == 3 && it->GetMoney() - 1000 < 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(55, 22);	cout << "���� �����մϴ�.";
			gotoxy(56, 24); cout << "�������ּ���.";
			result = it->GetMoney();
			getchar();
		}
		if (select == 4 && it->GetMoney() - 4000 >= 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);				
			gotoxy(53, 23);
			result = it->GetMoney() - 4000;
			cout << "���� ���� " << result << "�Դϴ�.";
			it->SetMoney(result);
			getchar();
		}
		else if (select == 4 && it->GetMoney() - 4000 < 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(55, 22);	cout << "���� �����մϴ�.";
			gotoxy(56, 24); cout << "�������ּ���.";
			result = it->GetMoney();
			getchar();
		}
		if (select == 5 && it->GetMoney() - 5000 >= 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(53, 23);
			result = it->GetMoney() - 5000;
			cout << "���� ���� " << result << "�Դϴ�.";
			it->SetMoney(result);
			getchar();
		}
		else if (select == 5 && it->GetMoney() - 5000 < 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(55, 22);	cout << "���� �����մϴ�.";
			gotoxy(56, 24); cout << "�������ּ���.";
			result = it->GetMoney();
			getchar();
		}
		if (select == 6 && it->GetMoney() - 6000 >= 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(53, 23);
			result = it->GetMoney() - 6000;
			cout << "���� ���� " << result << "�Դϴ�.";
			it->SetMoney(result);
			getchar();
		}
		else if (select == 6 && it->GetMoney() - 6000 < 0)
		{
			pi.ClrScr();
			pi.DrawWidthWall(18, 50, 75);
			pi.DrawWidthWall(28, 50, 75);
			pi.DrawHeightWall(50, 18, 28);
			pi.DrawHeightWall(75, 18, 28);
			gotoxy(55, 22);	cout << "���� �����մϴ�.";
			gotoxy(56, 24); cout << "�������ּ���.";
			result = it->GetMoney();
			getchar();
		}
	}
	return true;
}

bool POSInfoController::FindIDPOSInfo()
{
	
	string name;		
	int birth;
	pi.ClrScr();
	pi.DrawWidthWall(16, 30, 61);
	pi.DrawWidthWall(28, 30, 61);
	pi.DrawHeightWall(30, 16, 27);
	pi.DrawHeightWall(61, 16, 27);

	pi.DrawWidthWall(16, 65, 96);
	pi.DrawWidthWall(28, 65, 96);
	pi.DrawHeightWall(65, 16, 27);
	pi.DrawHeightWall(96, 16, 27);

	gotoxy(36, 20); cout << "�̸��� �Է����ּ���" << endl;
	gotoxy(43, 23); cin >> name;
	gotoxy(70, 20); cout << "��������� �Է����ּ���" << endl;
	gotoxy(78, 23); cin >> birth;


	list<POSInfo>::iterator it = m_POSInfoList.begin();
	while (it != m_POSInfoList.end())
	{
		if (name == it->GetName() && birth == it->GetBirth())
		{
			pi.ClrScr();

			pi.DrawWidthWall(16, 45, 75);
			pi.DrawWidthWall(28, 45, 75);
			pi.DrawHeightWall(45, 16, 28);
			pi.DrawHeightWall(75, 16, 28);
			gotoxy(57, 20);	cout << "���̵�";
			gotoxy(57, 23); cout << it->GetID();
			break;
		}	
		it++;
	}
	if (it == m_POSInfoList.end())
	{
		pi.ClrScr();
		pi.DrawWidthWall(16, 45, 75);
		pi.DrawWidthWall(28, 45, 75);
		pi.DrawHeightWall(45, 16, 28);
		pi.DrawHeightWall(75, 16, 28);
		gotoxy(50, 22);	cout << "��ġ�ϴ� ID�� �����ϴ�";
	}
	getchar();
	return true;
}

bool POSInfoController::FindPWPOSInfo()
{
	pi.ClrScr();
	pi.DrawWidthWall(16, 30, 61);
	pi.DrawWidthWall(28, 30, 61);
	pi.DrawHeightWall(30, 16, 27);
	pi.DrawHeightWall(61, 16, 27);

	pi.DrawWidthWall(16, 65, 96);
	pi.DrawWidthWall(28, 65, 96);
	pi.DrawHeightWall(65, 16, 27);
	pi.DrawHeightWall(96, 16, 27);
	
	string name;
	string ID;
	gotoxy(36, 20); cout << "�̸��� �Է����ּ���" << endl;
	gotoxy(43, 23); cin >> name;
	gotoxy(72, 20); cout << "ID�� �Է����ּ���" << endl;
	gotoxy(77, 23); cin >> ID;
	list<POSInfo>::iterator it = m_POSInfoList.begin();
	while (it != m_POSInfoList.end())
	{
		if (name == it->GetName() && ID == it->GetID())
		{
			pi.ClrScr();
			pi.DrawWidthWall(16, 45, 75);
			pi.DrawWidthWall(28, 45, 75);
			pi.DrawHeightWall(45, 16, 28);
			pi.DrawHeightWall(75, 16, 28);
			gotoxy(57, 20);	cout << "��й�ȣ";
			gotoxy(5, 23); cout << it->GetPW();
			break;
		}
		it++;
	}
	if (it == m_POSInfoList.end())
	{
		pi.ClrScr();
		pi.DrawWidthWall(16, 45, 75);
		pi.DrawWidthWall(28, 45, 75);
		pi.DrawHeightWall(45, 16, 28);
		pi.DrawHeightWall(75, 16, 28);
		gotoxy(50, 22);	cout << "��ġ�ϴ� ID�� �����ϴ�";
	}
	getchar();
	return true;
}

bool POSInfoController::ModifyPOSInfo()
{
	string ID;

	pi.ClrScr();
	pi.DrawWidthWall(16, 45, 75);
	pi.DrawWidthWall(28, 45, 75);
	pi.DrawHeightWall(45, 16, 28);
	pi.DrawHeightWall(75, 16, 28);
	gotoxy(55, 20);	cout << "���̵� �Է�";
	gotoxy(58, 23); cin >> ID;

	list<POSInfo>::iterator it = m_POSInfoList.begin();
	while (it != m_POSInfoList.end())
	{
		if (ID == it->GetID())
		{
			pi.ClrScr();
			pi.DrawWidthWall(16, 30, 61);
			pi.DrawWidthWall(28, 30, 61);
			pi.DrawHeightWall(30, 16, 27);
			pi.DrawHeightWall(61, 16, 27);

			pi.DrawWidthWall(16, 65, 96);
			pi.DrawWidthWall(28, 65, 96);
			pi.DrawHeightWall(65, 16, 27);
			pi.DrawHeightWall(96, 16, 27);

			string ID;
			string PW;
			gotoxy(39, 20); cout << "������ ID �Է�" << endl;
			gotoxy(44, 23); cin >> ID;
			gotoxy(74, 20); cout << "������ PW �Է�" << endl;
			gotoxy(78, 23); cin >> PW;
			it->SetID(ID).SetPW(PW);

			pi.ClrScr();
			pi.DrawWidthWall(16, 45, 75);
			pi.DrawWidthWall(28, 45, 75);
			pi.DrawHeightWall(45, 16, 28);
			pi.DrawHeightWall(75, 16, 28);
			gotoxy(54, 22);	cout << "�����Ǿ����ϴ�";
			getchar();
			break;
		}
		it++;
	}
	if(it == m_POSInfoList.end())
	{
		pi.ClrScr();
		pi.DrawWidthWall(16, 45, 75);
		pi.DrawWidthWall(28, 45, 75);
		pi.DrawHeightWall(45, 16, 28);
		pi.DrawHeightWall(75, 16, 28);
		gotoxy(50, 22);	cout << "��ġ�ϴ� ID�� �����ϴ�";
		getchar();
	}
	return true;
}

bool POSInfoController::DeletePOSInfo()
{
	string ID;
	pi.ClrScr();
	pi.DrawWidthWall(16, 45, 75);
	pi.DrawWidthWall(28, 45, 75);
	pi.DrawHeightWall(45, 16, 28);
	pi.DrawHeightWall(75, 16, 28);
	gotoxy(54, 20);	cout << "������ ID �Է�";
	gotoxy(58, 23); cin >> ID;

	list<POSInfo>::iterator it = m_POSInfoList.begin();
	while (it != m_POSInfoList.end())
	{
		if (ID == it->GetID())
		{
			m_POSInfoList.erase(it);
			pi.ClrScr();
			pi.DrawWidthWall(16, 45, 75);
			pi.DrawWidthWall(28, 45, 75);
			pi.DrawHeightWall(45, 16, 28);
			pi.DrawHeightWall(75, 16, 28);
			gotoxy(52, 22);	cout << "���� �Ǿ����ϴ�";
			break;
		}
		it++;
		if (it == m_POSInfoList.end())
		{
			pi.ClrScr();
			pi.DrawWidthWall(16, 45, 75);
			pi.DrawWidthWall(28, 45, 75);
			pi.DrawHeightWall(45, 16, 28);
			pi.DrawHeightWall(75, 16, 28);
			gotoxy(50, 22);	cout << "������ ID�� �����ϴ�";
		}
	}
	getchar();
	return true;
}

bool POSInfoController::PrintAllPOSInfo()
{
	list<POSInfo>::iterator it = m_POSInfoList.begin();
	while (it != m_POSInfoList.end())
	{
		pi.ClrScr();
		cout << "�̸�: " << it->GetName() << endl;
		cout << "�������: " << it->GetBirth() << endl;
		cout << "ID: " << it->GetID() << endl;
		cout << "��й�ȣ: " << it->GetPW() << endl;
		cout << "�¼���ȣ: " << it->GetSeat() << endl;
		cout << "���� ��: " <<  it->GetMoney() << endl;
		cout << "***************" << endl;
		cout << "***************";
		it++;
	}
	getchar();
	return true;
}

list<POSInfo>* POSInfoController::GetPOSList()
{
	return &m_POSInfoList;
}