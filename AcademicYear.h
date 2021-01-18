#pragma once
#include <list>
#include "..\Courses\Course.h"
#include "../GUI/Drawable.h"

//Represent one year in the student's study plan
class AcademicYear:public Drawable
{
	int TotalCredits=0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits=0, TotalMajorCredits=0,
		TotalTrackCredits=0, TotalConcentrationCredits=0,
		TotalMinorCredits=0;
	int const MaxCredits = 18;
	int const MinCredits = 12;
	list<Course*> YearCourses[SEM_CNT];
	
public:
	AcademicYear();
	virtual ~AcademicYear();

	bool AddCourse(Course*, SEMESTER );
	//window* A;

	void virtual DrawMe(GUI*) const;
	bool virtual Check_Credits(Course*) 
};

