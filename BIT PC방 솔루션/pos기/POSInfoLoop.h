#pragma once
#include "POSInfoView.h"
class POSInfoLoop
{
private:
	POSInfoView m_POSInfoView;

public:
	POSInfoLoop();
	void RunLoop();
};

