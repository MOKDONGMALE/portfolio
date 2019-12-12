#include "POSInfoLoop.h"
#include "POSInfoModel.h"
#include <list>
using namespace std;

POSInfoLoop::POSInfoLoop()
{
	list<POSInfo>*POSList = m_POSInfoView.GetPOSInfoController()->GetPOSList();
	POSInfoModel pim;
	//pim.LoadPOSInfoFile(POSList);
	pim.LoadTransPOSInfoFile(POSList);
}

void POSInfoLoop::RunLoop()
{
	bool bRun = true;
	while (bRun)
	{
		POSInfoView::ClrScr();
		m_POSInfoView.ShowMenu();
		int sel = m_POSInfoView.GetSelMenu();
		bRun = m_POSInfoView.CommandMenu(sel);
	}
}
