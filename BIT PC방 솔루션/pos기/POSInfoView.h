#pragma once
#include "POSInfoController.h"
class POSInfoView
{
private:
	POSInfoController m_POSInfoController;

public:
	POSInfoController* GetPOSInfoController();
	void ShowMenu();
	int GetSelMenu();
	bool CommandMenu(int sel);
	void consoleSize();
	void DrawWidthWall(int y, int from, int to);
	void DrawHeightWall(int y, int from, int to);
	static void ClrScr();
};
