#include "StudyPlan.h"
#include "..\GUI\GUI.h"


StudyPlan::StudyPlan()
{
	//By default, the study plan starts with 5 years
	//More year can be added
	for (int i = 0; i < 5; i++)
		plan.push_back(new AcademicYear);
}

//adds a course to the study plan in certain year, semester
//year idetifies year number to add course to 1=first, 2 = 2nd,....
bool StudyPlan::AddCourse(Course* pC, int year, SEMESTER sem)
{
	//TODO: add all requried checks to add the course 

	plan[year - 1]->AddCourse(pC, sem);
	
	return true;
}

void StudyPlan::DrawMe(GUI* pGUI) const
{
	//Plan draws all year inside it.
	pGUI->DrawStudyPlan(this);
	for (int i = 0; i < plan.size(); i++)
		plan[i]->DrawMe(pGUI);
}
void StudyPlan::setNotes(string sss)
{
	notes =sss;

}
StudyPlan::~StudyPlan()
{
};
void StudyPlan::importCourseCatalog() const
{
	CourseInfo rr;
	ifstream Course_Catalog("D:\\ZC\\C++\\Project\\Catalog.txt");
	char* context;
	char line[200];
	string code, Title, credits;
	while (Course_Catalog.getline(line, size))
	{
		char* pch = strtok_s(line, ",", &context);
		code = pch;
		pch = strtok_s(NULL, ",", &context);

		pch = strtok_s(line, ",", &context);
		rr.Title = pch;
		pch = strtok_s(NULL, ",", &context);

		pch = strtok_s(line, ",", &context);
		credits = pch;
		pch = strtok_s(NULL, ",", &context);

		string CoReq;
		pch = strtok_s(line, ",", &context);
		CoReq = pch;
		pch = strtok_s(NULL, ",", &context);
		
		//stringstream sss(CoReq);
		//string tmp;
		//sss >> tmp;
		//if (tmp == "")
		//	return;
		//if (tmp == "CoReq:")
		//{
		//	sss >> tmp;
		//	//insert tmp in coreq
		//	sss >> tmp;
		//}

		string PreReq;
		pch = strtok_s(line, ",", &context);
		PreReq = pch;
		pch = strtok_s(NULL, ",", &context);

	};
	
}
	/*bool check_credits()
	{
		int TotalCredits;
		if ( TotalCredits <= 21 && TotalCredits > 12)
			return true;
		else
			return false;
	};*/
	/*bool check_preco()
	{
		if()
			return true;
		else
			return false;
	};*/

