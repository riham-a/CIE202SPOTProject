/*#include "Actionaddminor.h"
#include "Registrar.h"
#include <iostream>
#include <sstream>
Actionaddminor::Actionaddminor(Registrar* p) : Action(p)
{

}
bool  Actionaddminor::Execute()
{
	GUI* pGUI = pReg->getGUI();
	for (int i = 0; i <= 5; i++) //only five courses
	{
		pGUI->PrintMsg("Add Course to your minor:");
		Course_Code code = pGUI->GetSrting();
		CourseInfo* cinfo;   //pointer to title,code,prereq,...
		cinfo = pReg->getcourseinfo(code);   //check if course is found in course catalog
		if (cinfo == NULL)
		{
			pGUI->PrintMsg("course is not found..press enter to contiue");
			Course_Code code = pGUI->GetSrting();
		}
		else
		{
		
		}
	}
}
Actionaddminor::~Actionaddminor()
{

}
*/