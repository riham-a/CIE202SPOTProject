#include "ActionCalculateGPA.h"
#include "Registrar.h"
#include <iostream>
#include <sstream>
ActionCalculategpa::ActionCalculategpa(Registrar* p) :Action(p)
{

}
bool ActionCalculategpa::Execute() {
	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Enter number of courses you want to calculate in gpa:");
	string getnumber= pGUI->GetSrting();
	int number;
	istringstream(getnumber) >> number;
	for (int i = 0; i < number; i++) 
	{
		ActionData actData = pGUI->GetUserAction("choose a course to calculate it's GPA: ");
		int x, y;
		if (actData.actType == DRAW_AREA) 
		{
			x = actData.x;
			y = actData.y;
			StudyPlan* pS = pReg->getStudyPlay();
			int yearof_course = pS->SETYEAR(x);
			SEMESTER SEM = pS->SETSEM(x);////////////////////////////////////////
			Course* P = pS->Courseposition(x, y, yearof_course, SEM);  //p is pointer on the courses
			if (P != nullptr)          ///user didn't clich somewhere else that has no courses
			{
				int credits =P->getCredits();
				pGUI->PrintMsg("Enter predicted/known Grade of the course: ");
				string grades = pGUI->GetSrting();

				if (lettergrade == "A" || lettergrade == "a") {
					a = 4 * credits;
				}
				else if (lettergrade == "A-" || lettergrade == "a-") {
					a = 3.67 * credits;
				}
				else if (lettergrade == "B+" || lettergrade == "b+") {
					a = 3.33 * credits;
				}
				else if (lettergrade == "B" || lettergrade == "b") {
					a = 3 * credits;
				}
				else if (lettergrade == "B-" || lettergrade == "b-") {
					a = 2.67 * credits;
				}
				else if (lettergrade == "C+" || lettergrade == "c+") {
					a = 2.33 * credits;
				}
				else if (lettergrade == "C" || lettergrade == "c") {
					a = 2 * credits;
				}
				else if (lettergrade == "C-" || lettergrade == "c-") {
					a = 1.67 * credits;
				}
				else if (lettergrade == "D+" || lettergrade == "d+") {
					a = 1.33 * credits;
				}
				else if (lettergrade == "D" || lettergrade == "d") {
					a = 1 * credits;
				}
				else if (lettergrade == "D-" || lettergrade == "d-") {
					a = 0.67 * credits;
				}
				else if (lettergrade == "F" || lettergrade == "f") {
					a = 0 * credits;
				}
				else {
					pGUI->PrintMsg("invalid input..press enter to continue");
					Course_Code invalidMsg = pGUI->GetSrting();
					credits = 0;
					a = 0;
					i=i - 1;
				}
		
				totalcredits += credits;
				totala += a;
			}
			else //clicks in null place or empty area
			{
				pGUI->PrintMsg("invalid");
				Course_Code enter = pGUI->GetSrting();
			}
		}
	}

	double GPA = totala / totalcredits;
	if (GPA >= 0 && GPA <= 4) {
		string StringGPA = to_string(GPA);
		pGUI->PrintMsg("Total GPA is: " + StringGPA + "  press enter to continue");
		Course_Code enter = pGUI->GetSrting();
	}

	return true;
}
ActionCalculategpa::~ActionCalculategpa() {

}



	
