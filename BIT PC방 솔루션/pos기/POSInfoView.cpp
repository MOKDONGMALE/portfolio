#include "POSInfoView.h"
#include "POSInfoModel.h"
#include "turboc.h"
POSInfoController* POSInfoView::GetPOSInfoController()
{
	return &m_POSInfoController;
}

void POSInfoView::ClrScr()
{
	system("cls");
}

void POSInfoView::consoleSize()
{
	system("mode con cols=125 lines=46");
}

void POSInfoView::DrawWidthWall(int y, int from, int to)
{
	int i = 0;
	for (i = from; i <= to; i++)
	{
		gotoxy(i, y);
		if (i == from)		printf("*");
		else			printf("*");
	}
}

void POSInfoView::DrawHeightWall(int x, int from, int to)
{
	int i = 0;
	for (i = from; i <= to; i++)
	{
		gotoxy(x, i);
		if (i == from)		printf("*");
		else			printf("*");
	}
}

void POSInfoView::ShowMenu()
{
	consoleSize();
	gotoxy(53, 4); cout << "B  I  T  P  C  방" << endl;
	gotoxy(54, 6); cout << "    Pos.Ver    " << endl;
	gotoxy(16, 15); cout << "1. 주문하기" << endl;
	gotoxy(51, 15);	cout << "2. 아이디/비밀번호 찾기" << endl;
	gotoxy(95, 15); cout << "3. 회원정보 수정" << endl;
	gotoxy(14, 35); cout << "4. 회원정보 삭제" << endl;
	gotoxy(54, 35); cout << "5. 회원정보 출력" << endl;
	gotoxy(94, 35); cout << "6. 프로그램 종료" << endl;

	DrawWidthWall(0, 0, 124);
	DrawWidthWall(45, 0, 124);
	DrawHeightWall(0, 0, 45);
	DrawHeightWall(124, 0, 45);

	DrawWidthWall(8, 6, 38);
	DrawWidthWall(23, 6, 38);
	DrawHeightWall(6, 8, 23);
	DrawHeightWall(38, 8, 23);

	DrawWidthWall(8, 46, 78);
	DrawWidthWall(23, 46, 78);
	DrawHeightWall(46, 8, 23);
	DrawHeightWall(78, 8, 23);

	DrawWidthWall(8, 86, 118);
	DrawWidthWall(23, 86, 118);
	DrawHeightWall(86, 8, 23);
	DrawHeightWall(118, 8, 23);

	DrawWidthWall(28, 6, 38);
	DrawWidthWall(43, 6, 38);
	DrawHeightWall(6, 28, 43);
	DrawHeightWall(38, 28, 43);

	DrawWidthWall(28, 46, 78);
	DrawWidthWall(43, 46, 78);
	DrawHeightWall(46, 28, 43);
	DrawHeightWall(78, 28, 43);

	DrawWidthWall(28, 86, 118);
	DrawWidthWall(43, 86, 118);
	DrawHeightWall(86, 28, 43);
	DrawHeightWall(118, 28, 43);
}

int POSInfoView::GetSelMenu()
{
	int num = 0;
	gotoxy(55, 25); cout << "입력: ";
	cin >> num;
	return num;
}

bool POSInfoView::CommandMenu(int sel)
{
	bool bRet = true;
	int num = 0;
	switch (sel)
	{
	case ORDER:
		ClrScr();
		DrawWidthWall(18, 50, 75);
		DrawWidthWall(28, 50, 75);
		DrawHeightWall(50, 18, 28);
		DrawHeightWall(75, 18, 28);
		m_POSInfoController.OrderPOSInfo();
		break;
	case FIND:
		ClrScr();
		gotoxy(42, 22); cout << "1. ID 찾기" << endl;
		gotoxy(76, 22); cout << "2. PW 찾기" << endl;
		DrawWidthWall(16, 30, 61);
		DrawWidthWall(28, 30, 61);
		DrawHeightWall(30, 16, 27);
		DrawHeightWall(61, 16, 27);

		DrawWidthWall(16, 65, 96);
		DrawWidthWall(28, 65, 96);
		DrawHeightWall(65, 16, 27);
		DrawHeightWall(96, 16, 27);

		gotoxy(63, 30);
		cin >> num;
		if (num == 1)
		{
			m_POSInfoController.FindIDPOSInfo();
			break;
		}
		else if (num == 2)
		{
			m_POSInfoController.FindPWPOSInfo();
			break;
		}
		break;
	case MODIFY:
		m_POSInfoController.ModifyPOSInfo();
		break;
	case DEL:
		m_POSInfoController.DeletePOSInfo();
		break;
	case PRINTALL:
		m_POSInfoController.PrintAllPOSInfo();
		break;
	case EXIT:
		ClrScr();
		DrawWidthWall(16, 45, 75);
		DrawWidthWall(28, 45, 75);
		DrawHeightWall(45, 16, 28);
		DrawHeightWall(75, 16, 28);
		gotoxy(53, 22);	cout << "종료 되었습니다";
		cout << "\n\n\n\n\n\n\n\n\n";
		POSInfoModel pim;
		//pim.SavePOSInfoFile(m_POSInfoController.GetPOSList());
		pim.SaveTransPOSInfoFile(m_POSInfoController.GetPOSList());
		bRet = false;
		break;
	default:
		ClrScr();
		DrawWidthWall(16, 45, 75);
		DrawWidthWall(28, 45, 75);
		DrawHeightWall(45, 16, 28);
		DrawHeightWall(75, 16, 28);
		gotoxy(51, 22);	cout << "잘못 입력하셨습니다";
		getchar();
		break;
	}
	getchar();
	return bRet;
}

