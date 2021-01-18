#pragma once
#include <string>
#include <list>
using namespace std;
#include "..\DEFs.h"
#include <fstream>
#include <iostream>
#include "../GUI/Drawable.h"

//Base class for all types of courses
class Course : public Drawable
{
	const Course_Code code;	//course code: e.g. "CIE202". This is the course ID
	const string Title;		//course title: e.g. "Fundamentals of Computer Programming"
	int credits;	//no. of course credits
	string type;	//Univ, track, or major.....etc.
	bool Done;		//Done or not yet?
	list<Course_Code> PreReq;	//list of prerequisites
	list<Course_Code> CoReq;	//list of prerequisites
	bool show;
public:
	Course(Course_Code r_code,string r_title, int crd);
	string getTitle() const;
	string getCode() const;
	int getCredits() const;
	Course_Code getPreReq() const;
	Course_Code getcoReq() const;
	void DrawMe(GUI*) const;
	char* pch;
	char* context = nullptr;
	char line[300]; 
	char* point = line;
	void importCourseCatalog() const;
	virtual ~Course();
	string GetType() const ;

};
