#include "Actionselectcoursestatus.h"
#include "Registrar.h"
#include <list>
#include"Actions\Action.h"
#include "Registrar.h"
#include <iostream>
#include <sstream>
using namespace std;
Actionselectcoursestatus::Actionselectcoursestatus(Registrar*p) :Action(p)
{
}

bool Actionselectcoursestatus::Execute(){
	GUI* pGUI = pReg->getGUI();
	int static wholedonecred = 0;  //to be used in 25
	ActionData actData = pGUI->GetUserAction("choose course to add it's status");
		int x, y;
	if (actData.actType == DRAW_AREA)	
	{
		
		x = actData.x;
		y = actData.y;
		StudyPlan* pS = pReg->getStudyPlay();
		int yearof_course = pS->SETYEAR(x);
		SEMESTER SEM = pS->SETSEM(x);
		Course* P = pS->Courseposition(x, y, yearof_course, SEM); 
		ActionData actData = pGUI->GetUserAction("select course status: Done(defualt), in progress ,pending: ");
		if (P != nullptr)          ///user didn't clich somewhere else that has no courses
		{
			string status = pGUI->GetSrting();

			if (status == "Done" || status == "done")
			{
				int credt= P->getCredits();
				wholedonecred += credt;
				Course_Code CODE = P->getCode();
				pS->donelist(CODE);
			}
			else {
				wholedonecred = wholedonecred;
			}
		}
		else //clicks in null place or empty area
		{
			pGUI->PrintMsg("invalid");
			Course_Code enter = pGUI->GetSrting();
		}
	}
	return true;
}
Actionselectcoursestatus::~Actionselectcoursestatus()
{
}





