#pragma once
#include "Util.h"
#include "PCcontroller.h"

void consoleSize();		// 콘솔창 크기 고정
void showMenu();
int getSelectMenu();
bool commandPCinfo(int sel, PCcontroller* pcc);
void clearScreen();

void showSeat();
void showCharge();
void showHowMuch(int money);
void showExchange(int change);
void showJoin();
void printResult(bool bResult);
void DrawWidthWall(int y, int from, int to);
void DrawHeightWall(int x, int from, int to);