#include "DoubleMajorAction.h"
#include "Registrar.h"
using namespace std;
#include <string>
#include <iostream>
DoubleMajorAction::DoubleMajorAction(Registrar* DM) :Action(DM)
{
}
bool DoubleMajorAction::Execute()
{
	GUI* pGUI = pReg->getGUI();
	StudyPlan* S = pReg->getStudyPlay();
	S->setDoubleMajor(true);
	pGUI->PrintMsg("Choose your Second Major");
	string Second_Major = pGUI->GetSrting();
	string DoubleMajorAction::getSecond_Major()
	{
		return Second_Major;
	};
	return true;
}
