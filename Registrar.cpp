#include "Registrar.h"
#include <fstream>
#include <iostream>
using namespace std;
#include "Actions/ActionAddCourse.h"
#include "Notes.h"
#include "DisplayCourseInfoAction.h"
#include"Actioncalculategpa.h"
#include"Actionaddminor.h"
#include "Actionselectcoursestatus.h"
#include "Actiondisplaystudentlevel.h"

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
}

//returns a pointer to GUI
GUI* Registrar::getGUI() const
{
	return pGUI;
}

//returns the study plan
StudyPlan* Registrar::getStudyPlan() const
{
	return pSPlan;
}

Action* Registrar::CreateRequiredAction() 
{	
	ActionData actData = pGUI->GetUserAction("Pick and action...");
	Action* RequiredAction = nullptr;

	switch (actData.actType)
	{
	case ADD_CRS:	//add_course action
		RequiredAction = new ActionAddCourse(this);
		break;
	case ADD_Notes: 
		RequiredAction = new Notes(this);
		break;
	case View_Report:
		RequiredAction = new ValidityReportAction(this);
	case Double_Major:
		RequiredAction = new DoubleMajorAction(this);
	case Display_CourseInfo :
		RequiredAction = new DisplayCourseInfoAction(this);
		break;
	 case CALC_GPA: //calculate gpa action
		RequiredAction = new ActionCalculategpa(this);
		break;
	case Studentlevel: 
		RequiredAction = new Actiondisplaystudentlevel(this);
		break;
	case Minor: 
		RequiredAction = new Actionaddminor(this);
		break;
	case Disp_course: 
		RequiredAction = new Actionselectcoursestatus(this);
		break;	
			
			
			
			
	/*case EXIT:
		break;
		*/
	}
	return RequiredAction;
}

//Executes the action, Releases its memory, and return true if done, false if cancelled
bool Registrar::ExecuteAction(Action* pAct)
{
	bool done = pAct->Execute();
	delete pAct;	//free memory of that action object (either action is exec or cancelled)
	return done;
}

void Registrar::Run()
{
	while (true)
	{
		//update interface here as CMU Lib doesn't refresh itself
		//when window is minimized then restored
		UpdateInterface();

		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
				UpdateInterface();
		}
	}
}


void Registrar::UpdateInterface()
{
	pGUI->UpdateInterface();	//update interface items
	pSPlan->DrawMe(pGUI);		//make study plan draw itself	
}
CourseInfo* Registrar::getcourseinfo(Course_Code code)
{
	for (int i = 0; i < RegRules.CourseCatalog.size(); i++)
	{
		if (RegRules.CourseCatalog[i].Code == code)
		{
			return &RegRules.CourseCatalog[i];
		}
	}
	for (int z = 0; z < RegRules.CourseCatalog.size(); z++)
	{
		if (RegRules.CourseCatalog[z].Code != code)
		{
			return nullptr;
		}
	}
}












Registrar::~Registrar()
{
	delete pGUI;
};
//StudyPlan* w;
//bool Registrar::check(StudyPlan* w)
//{
//	if (!w->check_credits)
//	{
//		return true;
//	};
//};
