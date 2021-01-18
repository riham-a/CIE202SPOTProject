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

    Course* StudyPlan::Courseposition(int x, int y, int year, SEMESTER sem) 
	{
	Course* pointPointer = nullptr;
	pointPointer = plan[year - 1]->PositionOfCourse(x, y, sem);
	if (pointPointer != nullptr) {
		return pointPointer;
	}
	else
	{
		return pointPointer;
	}
}
	int StudyPlan::SETYEAR(int y) 
	{
		int year;
		if (y > 80 && y < 192) 
		{ 
			year = 1;
			return year;
		}
		if (y >192 && y < 304)
		{
			year = 2;
			return year;
		}
		if (y> 304 && y< 416) 
		{
			year = 3;
			return year;
		}
		if (y > 416 && y<528)
		{
			year = 4;
			return year;
		}
		if (y > 528 && y <640) 
		{
			year = 5;
			return year;
		}
	}
	SEMESTER StudyPlan::SETSEM(int y) {
		SEMESTER s;
		 if (y> 80 && y < 117.3) { //sem
			s = FALL;
			return s;
		}
		else if (y > 117.3 && y < 154.6) {
			s = SPRING;
			return s;
		}
		else if (y> 154.6 && y < 192) {
			s = SUMMER;
			return s;
		}
		else if (y > 192 && y < 229.3) {
			s = FALL;
			return s;
		}
		else if (y > 229.3 && y < 266.6) {
			s = SPRING;
			return s;
		}
		else	if (y > 266.6 && y < 303.9) {
			s = SUMMER;
			return s;
		}
		else if (y > 303.9 && y < 341.2) {
			s = FALL;
			return s;
		}
		else if (y > 341.2 && y < 378.5)
		{
			s = SPRING;
			return s;
		}
		else if (y > 378.5 && y < 415.8) {
			s = SUMMER;
			return s;
		}
		else	if (y > 415.8 && y < 453.1) {
			s = FALL;
			return s;
		}
		else if (y > 453.1 && y <490.4) {
			s = SPRING;
			return s;
		}
		else if (y > 490.4 && y < 527.7) {
			s = SUMMER;
			return s;
		}
		else if (y > 527.7 && y <565) {
			s = FALL;
			return s;
		}
		else if (y > 565 && y < 602.3) {
			s = SPRING;
			return s;
		}
		else if (y > 602.3 && y < 639.6) {
			s = SUMMER;
			return s;
		}

	}

	bool StudyPlan::donelist(Course_Code CODE)
	{
		donecourses.push_back(CODE);
		return true;
	}
