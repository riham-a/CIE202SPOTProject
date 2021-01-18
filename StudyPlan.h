#pragma once
#include <vector>
#include "AcademicYear.h"
#include "../GUI/Drawable.h"
#include <fstream>
using namespace std;
#include "D:\ZC\C++\Project\SPOT\Rules.h"


//A full study plan for as student
class StudyPlan:public Drawable
{
	int TotalCredits=0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits=0, TotalMajorCredits=0,
		TotalTrackCredits=0, TotalConcentrationCredits=0,
		TotalMinorCredits=0;
        vector<Course_Code> donecourses;
	vector<AcademicYear*> plan;	//plan is a list of academic years

	string PlanNotes;
public:
	StudyPlan();
	bool AddCourse(Course*, int year, SEMESTER);
	//bool AddNotes(Notes*, string notes);
	void virtual DrawMe(GUI*) const;
	virtual ~StudyPlan();
	string notes;
	void setNotes(string ss);
	void importCourseCatalog() const;
	const int size = 300;
	bool check_credits();
	bool check_preco();
	stringstream sss();
	//int TotalCredits;
	bool donelist(Course_Code CODE);
	Course* Courseposition(int x, int y, int year, SEMESTER sem);
	int SETYEAR(int x);
	SEMESTER SETSEM(int x);

};

