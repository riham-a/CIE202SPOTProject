#include "DisplayCourseInfoAction.h"
#include "Registrar.h"
#include "Courses/UnivCourse.h"
#include "Courses/TrackCourse.h"
#include "Courses/MajorCourse.h"
#include <iostream>
#include <fstream>
DisplayCourseInfoAction::DisplayCourseInfoAction(Registrar* DCIA) :Action(DCIA)
{
}

bool DisplayCourseInfoAction::Execute()
{
	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("Choose Course to display its Info");
	ActionData actData = pGUI->GetUserAction();
	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		x = actData.x;
		y = actData.y;
		graphicsInfo gInfo{ x, y };
		ofstream Course_Catalog;
		/*Course* pC = new Course();
		pC->importCourseCatalog();
		pC->getTitle();
	    pC->getPreReq();
	    pC->getcoReq();
		pC->getCredits();
		pC->setGfxInfo(gInfo);*/
		StudyPlan* pS = pReg->getStudyPlay();
	}
	return true;
}


DisplayCourseInfoAction::~DisplayCourseInfoAction()
{
}

