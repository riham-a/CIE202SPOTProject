#include "Course.h"
#include "../GUI/GUI.h"
#include <fstream>
#include <sstream>
using namespace std;
Course::Course(){
	show=true;
}
Course::Course(Course_Code r_code, string r_title, int crd):code(r_code),Title(r_title)
{
	credits = crd;
	show=true;
}

Course::~Course()
{
}

Course_Code Course::getCode() const
{
	return code;
}

string Course::getTitle() const
{
	return Title;
}

//return course credits
int Course::getCredits() const
{
	return credits;
}

void Course::DrawMe(GUI* pG) const
{
	pG->DrawCourse(this);
	
}
