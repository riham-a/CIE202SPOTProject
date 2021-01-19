#include "ValidityReportAction.h"
#include "Registrar.h"
using namespace std;
#include <string>
#include <iostream>
ValidityReportAction::ValidityReportAction(Registrar* VR) :Action(VR)
{
}
bool ValidityReportAction::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Choose your Second Major");
	string Second_Major = pGUI->GetSrting();
	StudyPlan* S = pReg->getStudyPlay();
	S->setDoubleMajor(true);
	return true;
}
