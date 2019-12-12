#include "PCview.h"
extern int pcSeat[100];
using namespace std;

PCcontroller* g_pController;

void consoleSize()
{
	system("mode con cols=125 lines=46");
}

void clearScreen()
{
	system("cls");
}
void DrawWidthWall(int y, int from, int to)
{
	int i = 0;
	for (i = from; i <= to; i++)
	{
		gotoxy(i, y);
		if (i == from)		printf("*");
		else			printf("*");
	}
}

void DrawHeightWall(int x, int from, int to)
{
	int i = 0;
	for (i = from; i <= to; i++)
	{
		gotoxy(x, i);
		if (i == from)		printf("*");
		else			printf("*");
	}
}
void showMenu()
{
	gotoxy(53, 4); cout << "B  I  T  P  C  ��" << endl;
	gotoxy(30, 15); cout << "1. �α���" << endl;
	gotoxy(80, 15);	cout << "2. ȸ�� ����" << endl;
	gotoxy(30, 35); cout << "3. �¼� Ȯ��" << endl;
	gotoxy(78, 35); cout << "4. ���α׷� ����" << endl;

	DrawWidthWall(0, 0, 124);
	DrawWidthWall(8, 15, 55);
	DrawWidthWall(23, 15, 55);
	DrawWidthWall(8, 65, 105);
	DrawWidthWall(23, 65, 105);

	DrawWidthWall(45, 0, 124);
	DrawWidthWall(28, 15, 55);
	DrawWidthWall(43, 15, 55);
	DrawWidthWall(28, 65, 105);
	DrawWidthWall(43, 65, 105);

	DrawHeightWall(0, 0, 45);
	DrawHeightWall(15, 8, 23);
	DrawHeightWall(55, 8, 23);
	DrawHeightWall(65, 8, 23);
	DrawHeightWall(105, 8, 23);

	DrawHeightWall(124, 0, 45);
	DrawHeightWall(15, 28, 43);
	DrawHeightWall(55, 28, 43);
	DrawHeightWall(65, 28, 43);
	DrawHeightWall(105, 28, 43);
}
int getSelectMenu()
{
	int sel = 0;
	gotoxy(55, 25); cout << "�Է�: ";
	cin >> sel;
	return sel;
}
void printResult(bool bResult)
{
	if (bResult == true)
	{
		cout << "ó�� �����Ͽ����ϴ�" << endl;
		getchar();
	}
	else if (bResult == false)
	{
		cout << "ó�� �����Ͽ����ϴ�" << endl;
		getchar();
	}
}
bool commandPCinfo(int sel, PCcontroller* pm)
{
	g_pController = pm;
	bool bRet = true;
	bool bResult = true;

	switch (sel)
	{
	case LOGIN:
		clearScreen();
		DrawWidthWall(18, 50, 75);
		DrawWidthWall(28, 50, 75);
		DrawHeightWall(50, 18, 28);
		DrawHeightWall(75, 18, 28);
		gotoxy(55, 21); cout << "ID: " << endl;
		gotoxy(55, 25); cout << "PW: " << endl;
		bResult = pm->loginPCInfo();
		
		if (bResult == true)
			break;
		bResult = pm->seatPCInfo();
		showCharge();
		break;
	case JOIN:
		showJoin();
		bResult = pm->joinPCInfo();
		printResult(bResult);
		break;
	case SEAT:
		clearScreen();
		gotoxy(44, 3);
		cout << " �ְ��� �ü��� �ڶ��ϴ� BIT PC��\n\n" << endl;

		showSeat();
		getchar();
		break;
	case EXIT:
		gotoxy(55, 27);
		cout << "���α׷� ����" << endl;
		bRet = false;
		break;
	case 5:
		pm->printAllPCInfo();
		break;
	default:
		cout << "�� �� �Է��ϼ̽��ϴ�..." << endl;
		break;
	}
	getchar();



	return bRet;

}

void showJoin()
{
	clearScreen();
	DrawWidthWall(18, 50, 75);
	DrawWidthWall(28, 50, 75);
	DrawHeightWall(50, 18, 28);
	DrawHeightWall(75, 18, 28);

	gotoxy(55, 21); cout << "ID: " << endl;
	gotoxy(55, 23); cout << "PW: " << endl;
	gotoxy(55, 25); cout << "�̸�: " << endl;
	gotoxy(55, 27); cout << "�������: " << endl;
}

void showSeat()
{
	
	for (int i = 0; i < 10; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 10; i < 20; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	for (int i = 20; i < 30; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 30; i < 40; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 40; i < 50; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 50; i < 60; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 60; i < 70; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 70; i < 80; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 80; i < 90; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 90; i < 100; i++)
	{
		if (pcSeat[i] != 0)
		{
			printf("   %3d  ��  ", i + 1);
		}
		else if (pcSeat[i] == 0)
		{
			printf("   %3d  ��  ", i + 1);
		}

	}



}
void showCharge()
{

	int choice = 0;
	gotoxy(53, 4); cout << "�󸶸� �����Ͻðڽ��ϱ�?" << endl;

	gotoxy(30, 15); cout << "1. 1000��" << endl;
	gotoxy(80, 15);	cout << "2. 3000��" << endl;
	gotoxy(30, 35); cout << "3. 5000��" << endl;
	gotoxy(78, 35); cout << "4. 10000��" << endl;

	DrawWidthWall(0, 0, 124);
	DrawWidthWall(8, 15, 55);
	DrawWidthWall(23, 15, 55);
	DrawWidthWall(8, 65, 105);
	DrawWidthWall(23, 65, 105);

	DrawWidthWall(45, 0, 124);
	DrawWidthWall(28, 15, 55);
	DrawWidthWall(43, 15, 55);
	DrawWidthWall(28, 65, 105);
	DrawWidthWall(43, 65, 105);

	DrawHeightWall(0, 0, 45);
	DrawHeightWall(15, 8, 23);
	DrawHeightWall(55, 8, 23);
	DrawHeightWall(65, 8, 23);
	DrawHeightWall(105, 8, 23);

	DrawHeightWall(124, 0, 45);
	DrawHeightWall(15, 28, 43);
	DrawHeightWall(55, 28, 43);
	DrawHeightWall(65, 28, 43);
	DrawHeightWall(105, 28, 43);
	gotoxy(55, 25); cout << "�Է�: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		clearScreen();
		DrawWidthWall(18, 50, 75);
		DrawWidthWall(28, 50, 75);
		DrawHeightWall(50, 18, 28);
		DrawHeightWall(75, 18, 28);
		gotoxy(51, 18); cout << "1000���� �Է��ϼ̽��ϴ�." << endl;
		getchar();
		showHowMuch(1000);
		showExchange(1000);
		g_pController->GetCurrPCinfo()->money += 1000;

		getchar();
		break;

	case 2:
		clearScreen();
		DrawWidthWall(18, 50, 75);
		DrawWidthWall(28, 50, 75);
		DrawHeightWall(50, 18, 28);
		DrawHeightWall(75, 18, 28);
		gotoxy(51, 18); cout << "3000���� �Է��ϼ̽��ϴ�." << endl;
		getchar();
		showHowMuch(3000);
		showExchange(3000);
		g_pController->GetCurrPCinfo()->money += 3000;
		getchar();
		break;

	case 3:
		clearScreen();
		DrawWidthWall(18, 50, 75);
		DrawWidthWall(28, 50, 75);
		DrawHeightWall(50, 18, 28);
		DrawHeightWall(75, 18, 28);
		gotoxy(51, 18); cout << "5000���� �Է��ϼ̽��ϴ�." << endl;
		getchar();
		showHowMuch(5000);
		showExchange(5000);
		g_pController->GetCurrPCinfo()->money += 5000;
		getchar();
		break;

	case 4:
		clearScreen();
		DrawWidthWall(18, 50, 75);
		DrawWidthWall(28, 50, 75);
		DrawHeightWall(50, 18, 28);
		DrawHeightWall(75, 18, 28);
		gotoxy(51, 18); cout << "10000���� �Է��ϼ̽��ϴ�" << endl;
		getchar();
		showHowMuch(10000);
		showExchange(10000);
		g_pController->GetCurrPCinfo()->money += 10000;
		getchar();
		break;

	default:
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
}
void showHowMuch(int money)
{
	gotoxy(53, 21);	cout << money << "���� �־��ּ���." << endl;
}
void showExchange(int change)
{
	int money = 0;
	while (true)
	{
		gotoxy(61, 24);
		cin >> money;
		if (money < change)
		{
			clearScreen();
			gotoxy(53, 21);
			cout << "���� �����մϴ�. �ٽ� �־��ּ���." << endl;
			getchar();
		}
		else if (money >= change)
		{
			clearScreen();
			DrawWidthWall(18, 50, 75);
			DrawWidthWall(28, 50, 75);
			DrawHeightWall(50, 18, 28);
			DrawHeightWall(75, 18, 28);
			gotoxy(52, 21);
			cout << "�Ž������� " << money - change << "�Դϴ�." << endl;
			gotoxy(53, 25);
			cout << "��ſ� Game �Ǽ���~";


			break;
		}
	}
}



