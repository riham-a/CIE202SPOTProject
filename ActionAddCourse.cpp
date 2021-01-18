#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <iostream>
ActionAddCourse::ActionAddCourse(Registrar* p) :Action(p)
{
}

bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();

	CourseInfo* cinfo;
	cinfo = pReg->getcourseinfo(code);   //check if course is found in course catalog
	if (cinfo == NULL)
	{
		pGUI->PrintMsg("course is not found..press enter to contiue");
		Course_Code code = pGUI->GetSrting();
	}
	else {
		ActionData actData = pGUI->GetUserAction("Select a year to add coures to: ");
		int x, y;
		if (actData.actType == DRAW_AREA)
		{
			x = actData.x;
			y = actData.y;
			graphicsInfo gInfo{ x, y };
			string Title = "Test101";
			int crd = cinfo->Credits;
			Course* pC = new Course(code, Title, crd);
			pC->setGfxInfo(gInfo);
			StudyPlan* pS = pReg->getStudyPlay();
			int yearof_course = pS->SETYEAR(x);
			SEMESTER SEM = pS->SETSEM(x);
			pS->AddCourse(pC, yearof_course, SEM);
		}
		return true;

	}
}

ActionAddCourse::~ActionAddCourse()
{
}
