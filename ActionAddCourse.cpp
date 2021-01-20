#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <iostream>
#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include "../GUI/GUI.h"
#include <iostream>
ActionAddCourse::ActionAddCourse(Registrar* p) :Action(p)
{
}

bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();
	CourseInfo* coinfo;   //pointer to title,code,prereq,...
	coinfo = pReg->getcourseinfo(code);   //check if course is found in course catalog
	if (coinfo == NULL)
	{
		pGUI->PrintMsg("course is not found..press enter to contiue");
		Course_Code code = pGUI->GetSrting();
	}
	else {
		ActionData actData = pGUI->GetUserAction("Select a year to add coures to: ");

		int x, y;
		if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
		{
			x = actData.x;
			y = actData.y;
         graphicsInfo gInfo{ x, y };
		 StudyPlan* pS = pReg->getStudyPlay();
		 int yearof_course = pS->SETYEAR(x);
		 SEMESTER SEM = pS->SETSEM(x);

		 string Title = coinfo->Title;
			int crd = coinfo->Credits;
			//int crd = 0;
			Course* pC = new Course(code, Title, crd);
			pC->setGfxInfo(gInfo);
		
			//pS->AddCourse(pC, syearsem.year, syearsem.s);
			pS->AddCourse(pC, yearof_course, SEM);
		}
		//TODO:


		return true;

	}



}


ActionAddCourse::~ActionAddCourse()
{
}
