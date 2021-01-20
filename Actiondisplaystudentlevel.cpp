#include "ActionDisplayStudentLevel.h"
#include "ActionSelectCourseStatus.h"
#include "Registrar.h"
#include <iostream>
Actiondisplaystudentlevel::Actiondisplaystudentlevel(Registrar* p) : Action(p)
{

}
bool Actiondisplaystudentlevel::Execute()
{
	GUI* pGUI = pReg->getGUI();

	int credits = pReg-> Coursestatus(0);
//////////////////*credits = pCOURSE->getdone();
	
	if (credits  > 0 && credits <= 30) 
	{
		ActionData actData = pGUI->GetUserAction("Foundation Student");
	}
	if (credits  > 30 && credits <= 59) {
		ActionData actData = pGUI->GetUserAction("Sophomore Student");
	}
	if (credits  > 59 && credits <= 89) {
		ActionData actData = pGUI->GetUserAction("Junior Student");
	}
	if (credits  > 89 && credits <= 90) {
		ActionData actData = pGUI->GetUserAction("Pre_Senior Student ");
	}
	if (credits  > 90 && credits <= 162) {
		ActionData actData = pGUI->GetUserAction("Senior Student  ");
	}
	return true;
}
Actiondisplaystudentlevel::~Actiondisplaystudentlevel() {

}

