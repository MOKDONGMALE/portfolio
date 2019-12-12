#include "Util.h"
#include "PCview.h"
#include "PCInfo.h"
#include "PCcontroller.h"

int pcSeat[100];
void init(PCcontroller* pm);
void loop(PCcontroller* pm);
void end(PCcontroller* pm);


void init(PCcontroller* pm)
{
	pm->loadPCInfo();
}

void end(PCcontroller* pm)
{
	pm->savePCInfo();
}

void loop(PCcontroller* pm)
{
	consoleSize();
	int sel = 0;
	bool bRun = true;

	while (bRun)
	{
		clearScreen();
		showMenu();
		sel = getSelectMenu();
		bRun = commandPCinfo(sel, pm);

	}
}

void main()
{
	PCcontroller pm;
	init(&pm);
	loop(&pm);
	end(&pm);
}