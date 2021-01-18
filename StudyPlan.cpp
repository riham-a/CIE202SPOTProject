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
	int StudyPlan::SETYEAR(int x) {
		int year;
		if (x > 0 && x < 264) { //year
			year = 1;
			return year;
		}
		if (x>264 && x < 528) {
			year = 2;
			return year;
		}
		if (x > 528 && x < 792) {
			year = 3;
			return year;
		}
		if (x > 792 && x <1056) {
			year = 4;
			return year;
		}
		if (x > 1056 && x <1320) {
			year = 5;
			return year;
		}
	}
	SEMESTER StudyPlan::SETSEM(int x) {
		SEMESTER s;
		 if (x > 0 && x < 88) { //sem
			s = FALL;
			return s;
		}
		else if (x > 88 && x < 176) {
			s = SPRING;
			return s;
		}
		else if (x > 176 && x < 264) {
			s = SUMMER;
			return s;
		}
		else if (x > 264 && x < 352) {
			s = FALL;
			return s;
		}
		else if (x > 352 && x < 440) {
			s = SPRING;
			return s;
		}
		else	if (x > 440 && x < 528) {
			s = SUMMER;
			return s;
		}
		else if (x > 528 && x < 616) {
			s = FALL;
			return s;
		}
		else if (x > 616 && x < 704) {
			s = SPRING;
			return s;
		}
		else if (x > 704 && x < 792) {
			s = SUMMER;
			return s;
		}
		else	if (x > 792 && x < 880) {
			s = FALL;
			return s;
		}
		else if (x > 880 && x < 968) {
			s = SPRING;
			return s;
		}
		else if (x > 968 && x < 1056) {
			s = SUMMER;
			return s;
		}
		else if (x > 1056 && x <1144) {
			s = FALL;
			return s;
		}
		else if (x > 1144 && x < 1232) {
			s = SPRING;
			return s;
		}
		else if (x > 1232 && x < 1320) {
			s = SUMMER;
			return s;
		}

	}

	bool StudyPlan::donelist(Course_Code CODE)
	{
		donecourses.push_back(CODE);
		return true;
	}
