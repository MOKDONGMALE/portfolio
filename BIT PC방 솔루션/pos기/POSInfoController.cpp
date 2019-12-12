#include "POSInfoController.h"
#include "POSInfoView.h"
#include "turboc.h"
POSInfoView pi;
bool POSInfoController::OrderPOSInfo()
{
	int seat;
	int select;
	gotoxy(52, 21);
	cout << "좌석번호를 입력해주세요\n";
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
		cout << "일치하는 좌석이 없습니다" << endl;
		getchar();
	}
	else
	{
		pi.ClrScr();
		gotoxy(55, 4); cout << " < M E N U >" << endl;
		gotoxy(19, 14); cout << "1. 라면" << endl;
		gotoxy(20, 17); cout << "1000원" << endl;
		gotoxy(58, 14);	cout << "2. 김밥" << endl;
		gotoxy(59, 17); cout << "3000원" << endl;
		gotoxy(97, 14); cout << "3. 감자튀김" << endl;
		gotoxy(100, 17); cout << "2000원" << endl;
		gotoxy(18, 34); cout << "4. 떡볶이" << endl;
		gotoxy(20, 37); cout << "4000원" << endl;
		gotoxy(57, 34); cout << "5. 스팸덮밥" << endl;
		gotoxy(60, 37); cout << "5000원" << endl;
		gotoxy(97, 34); cout << "6. 제육덮밥" << endl;
		gotoxy(100, 37); cout << "6000원" << endl;
		gotoxy(49, 25); cout << "무엇을 주문하시겠습니까?\n";
	
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
			gotoxy(53, 23); cout << "남은 돈은 " << result << "입니다";
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
			gotoxy(55, 22);	cout << "돈이 부족합니다.";
			gotoxy(56, 24); cout << "충전해주세요.";
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
			cout << "남은 돈은 " << result << "입니다.";
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
			gotoxy(55, 22);	cout << "돈이 부족합니다.";
			gotoxy(56, 24); cout << "충전해주세요.";
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
			cout << "남은 돈은 " << result << "입니다.";
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
			gotoxy(55, 22);	cout << "돈이 부족합니다.";
			gotoxy(56, 24); cout << "충전해주세요.";
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
			cout << "남은 돈은 " << result << "입니다.";
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
			gotoxy(55, 22);	cout << "돈이 부족합니다.";
			gotoxy(56, 24); cout << "충전해주세요.";
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
			cout << "남은 돈은 " << result << "입니다.";
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
			gotoxy(55, 22);	cout << "돈이 부족합니다.";
			gotoxy(56, 24); cout << "충전해주세요.";
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
			cout << "남은 돈은 " << result << "입니다.";
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
			gotoxy(55, 22);	cout << "돈이 부족합니다.";
			gotoxy(56, 24); cout << "충전해주세요.";
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

	gotoxy(36, 20); cout << "이름을 입력해주세요" << endl;
	gotoxy(43, 23); cin >> name;
	gotoxy(70, 20); cout << "생년월일을 입력해주세요" << endl;
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
			gotoxy(57, 20);	cout << "아이디";
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
		gotoxy(50, 22);	cout << "일치하는 ID가 없습니다";
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
	gotoxy(36, 20); cout << "이름을 입력해주세요" << endl;
	gotoxy(43, 23); cin >> name;
	gotoxy(72, 20); cout << "ID를 입력해주세요" << endl;
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
			gotoxy(57, 20);	cout << "비밀번호";
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
		gotoxy(50, 22);	cout << "일치하는 ID가 없습니다";
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
	gotoxy(55, 20);	cout << "아이디 입력";
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
			gotoxy(39, 20); cout << "수정할 ID 입력" << endl;
			gotoxy(44, 23); cin >> ID;
			gotoxy(74, 20); cout << "수정할 PW 입력" << endl;
			gotoxy(78, 23); cin >> PW;
			it->SetID(ID).SetPW(PW);

			pi.ClrScr();
			pi.DrawWidthWall(16, 45, 75);
			pi.DrawWidthWall(28, 45, 75);
			pi.DrawHeightWall(45, 16, 28);
			pi.DrawHeightWall(75, 16, 28);
			gotoxy(54, 22);	cout << "수정되었습니다";
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
		gotoxy(50, 22);	cout << "일치하는 ID가 없습니다";
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
	gotoxy(54, 20);	cout << "삭제할 ID 입력";
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
			gotoxy(52, 22);	cout << "삭제 되었습니다";
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
			gotoxy(50, 22);	cout << "삭제할 ID가 없습니다";
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
		cout << "이름: " << it->GetName() << endl;
		cout << "생년월일: " << it->GetBirth() << endl;
		cout << "ID: " << it->GetID() << endl;
		cout << "비밀번호: " << it->GetPW() << endl;
		cout << "좌석번호: " << it->GetSeat() << endl;
		cout << "남은 돈: " <<  it->GetMoney() << endl;
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