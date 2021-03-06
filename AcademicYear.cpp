#include "AcademicYear.h"
#include "../GUI/GUI.h"
#include "vector"

AcademicYear::AcademicYear()
{
	//TODO: make all necessary initializations
	graphicsInfo A_Year;
	A_Year.x = 80;
		A_Year.y = 80;


}


AcademicYear::~AcademicYear()
{
}

//Adds a course to this year in the spesified semester
bool AcademicYear::AddCourse(Course* pC, SEMESTER sem)
{
	//TODO:
	//This function still needs many checks to be compelete
	YearCourses[sem].push_back(pC);
	TotalCredits += pC->getCredits();
	return true;
}



void AcademicYear::DrawMe(GUI* pGUI) const
{
	pGUI->DrawAcademicYear(this);
	//Draw all semesters inside this year by iterating on each semester list
	//to get courses and draw each course

	for (int sem = FALL; sem < SEM_CNT; sem++)
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{

		}
};

bool AcademicYear::Check_Credits(Course* crd) 
{

	for (int sem = FALL; sem < SEM_CNT; sem++)
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			TotalCredits = TotalCredits + crd->getCredits();
		}
	if (!(TotalCredits <= MaxCredits && TotalCredits >= MinCredits))
		
		return false;
}
//feature 15 and 16 to colllect the courses of the year in one vector

 vector <Course*> AcademicYear ::  CollectCourses()
{
////////////////////////////////////////////
//int i=0, k=0;
	for (int sem = FALL; sem < SEM_CNT; sem++)
	{
		for (int i = (YearCourses[sem].begin()); i != (YearCourses[sem].end()); i++)
		{
			vector <Course*> CoursesOfYear;
			list <Course*> ::iterator courses = YearCourses.begin();
			advance(courses, 1)
				CoursesOfYear.Push_back(courses);
			return CoursesOfYear;

		}
		
	}
}



Course* AcademicYear::PositionOfCourse(int x, int y, SEMESTER sem) //to know the course place in which semester
{

	for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it) 
	{
		Course* coursepointer = *it;
		graphicsInfo pos = coursepointer->getGfxInfo();   
		if (x > pos.x && x<pos.x + 80 && y > pos.y && y < pos.y + 40) //width and heght of course
		{
			return coursepointer;
	}

	}
	return nullptr;
}
