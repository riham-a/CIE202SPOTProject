#include "StudyPlan.h"
#include "DEf.h"
#include <ifstream>
#include <vector>
#include "GUI.h"
#include "Course.h"


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


// feature 4 implementation:
bool StudyPlan::ChangeCourse(Course_Code* code) {
	pGUI->PrintMsg("Please enter the code you want to change");
	Course_Code code = pGUI->GetSrting();

	ifstream Course_Catalog;
	Course_Catalog.open("D:\\UNI\\CIE \\ C++ \\ project\\Course_Catalog");
	vector <Course_Code> Course_Catalog;
	double size = 250;
	char line[size];
	while (!Course_Catalog.getline(line,size) {
		pch = strtok_s(line, ",", &context);
		while (pch != NULL)
		{

			pch = strtok_s(NULL, ",", &context);
		}
		Course_Catalog >> Course_Code CoursesData;
		Course_Code.push_back(CoursesData);
	}
	for (int i = 0; i < Course_Catalog.size(); i++) {
		if (code == Course_Catalog[i])
			plan.push_back(code);
		//plan = pGUI->UpdateInterface();
	}
	return true;
}


void StudyPlan::DrawMe(GUI* pGUI) const
{
	//Plan draws all year inside it.
	for (int i = 0; i < plan.size(); i++)
		plan[i]->DrawMe(pGUI);
}
void StudyPlan::setNotes(string sss)
{
	notes = sss;
	 /// feature 15 & 18
	vector <vector<Course*>> StudyPlan::CollectCoursesSP() {
		vector <Course*> SPCourses;
		int j;
		  for (j = 0; j < plan.size(); j++)
		  {
			  vector <Course*> collector;
			  collector = (*plan[j]).CollectCourses ();
			  SPCourses.puch_back (collector);
		  }
		return SPCourses;
	}

	bool  StudyPlan::checkUnivCompul() {
		for (int i= 0; i > CollectCoursesSP.size(); i++) {
			for (int j = 0; j > Rules.UnivCompulsory.size(); j++) {
			  bool* f = std :: find (CollectCoursesSP.begin (), CollectCoursesSP.end(), Rules.UnivCompulsory [i])
				  if (f == false)
				   pGUI->PrintMsg("crtitical issue: missed compulsory course");
			}
		}
		return true;
	}


	bool StudyPlan :: UnivElective() {
	
		for (int i = 0; i > CollectCoursesSP.size(); i++) {
			for (int j = 0; j > Rules.UnivElective.size(); j++) {
				bool* f = std::find(CollectCoursesSP.begin(), CollectCoursesSP.end(), Rules.UnivElective[i])
					if (f == false)
						pGUI->PrintMsg("crtitical issue: missed elective course");
			}
		}
		return true;
	}

	bool StudyPlan :: TrackCompulsory() {

		for (int i = 0; i > CollectCoursesSP.size(); i++) {
			for (int j = 0; j > Rules.TrackCompulsory.size(); j++) {
				bool* f = std::find(CollectCoursesSP.begin(), CollectCoursesSP.end(), Rules.TrackCompulsory[i])
					if (f == false)
						pGUI->PrintMsg("crtitical issue: missed Track Compulsory course");
			}
		}
		return true;

	}
	bool StudyPlan :: MajorCompulsory() {
	
		for (int i = 0; i > CollectCoursesSP.size(); i++) {
			for (int j = 0; j > Rules.MajorCompulsory.size(); j++) {
				bool* f = std::find(CollectCoursesSP.begin(), CollectCoursesSP.end(), Rules.MajorCompulsory[i])
					if (f == false)
						pGUI->PrintMsg("crtitical issue: missed Major Compulsory course");
			}
		}
		return true;
	
	
	}

	bool StudyPlan :: MajorElective() {
		for (int i = 0; i > CollectCoursesSP.size(); i++) {
			for (int j = 0; j > Rules.MajorElective.size(); j++) {
				bool* f = std::find(CollectCoursesSP.begin(), CollectCoursesSP.end(), Rules.MajorElective[i])
					if (f == false)
						pGUI->PrintMsg("crtitical issue: missed Major Elective course");
			}
		}
		return true;
	}

	bool StudyPlan :: checkUniCre() {
		for (int i; i > CollectCoursesSP.size(); i++) {
			CollectCoursesSP[i].getCredits = credits;

		}
			if (credits != Rules.ReqUnivCredits)
				pGUI->PrintMsg("crtitical issue: number of total credits is not correct");
		
		return true;
	}
	//DoubleMajor
			if (StudyPlan::DoubleMajor)
			{
				vector <vector<Course*>> StudyPlan::CollectCoursesSPDoubleMajor() {
					vector <Course*> SPCoursesDoubleMajor;
					int j;
					for (j = 0; j < plan.size(); j++)
					{
						vector <Course*> collectorDoubleMajor;
						collectorDoubleMajor = (*plan[j]).CollectCourses();  //////
						SPCoursesDoubleMajor.push_back(collectorDoubleMajor);
					}
					return SPCoursesDoubleMajor;
				};
				bool  StudyPlan::checkUnivCompul() {
					for (int i = 0; i > CollectCoursesSPDoubleMajor.size(); i++) {
						for (int j = 0; j > Rules.UnivCompulsory.size(); j++) {
							bool* f = std::find(CollectCoursesSPDoubleMajor.begin(), CollectCoursesSPDoubleMajor.end(), Rules.UnivCompulsory[i])
								if (f == false)
									pGUI->PrintMsg("crtitical issue: missed compulsory course");
						}
					}
					return true;
				}


				bool StudyPlan::UnivElective() {

					for (int i = 0; i > CollectCoursesSPDoubleMajor.size(); i++) {
						for (int j = 0; j > Rules.UnivElective.size(); j++) {
							bool* f = std::find(CollectCoursesSPDoubleMajor.begin(), CollectCoursesSPDoubleMajor.end(), Rules.UnivElective[i])
								if (f == false)
									pGUI->PrintMsg("crtitical issue: missed elective course");
						}
					}
					return true;
				}

				bool StudyPlan::TrackCompulsory() {

					for (int i = 0; i > CollectCoursesSPDoubleMajor.size(); i++) {
						for (int j = 0; j > Rules.TrackCompulsory.size(); j++) {
							bool* f = std::find(CollectCoursesSPDoubleMajor.begin(), CollectCoursesSPDoubleMajor.end(), Rules.TrackCompulsory[i])
								if (f == false)
									pGUI->PrintMsg("crtitical issue: missed Track Compulsory course");
						}
					}
					return true;

				}
				bool StudyPlan::MajorCompulsory() {

					for (int i = 0; i > CollectCoursesSPDoubleMajor.size(); i++) {
						for (int j = 0; j > Rules.MajorCompulsory.size(); j++) {
							bool* f = std::find(CollectCoursesSPDoubleMajor.begin(), CollectCoursesSPDoubleMajor.end(), Rules.MajorCompulsory[i])
								if (f == false)
									pGUI->PrintMsg("crtitical issue: missed Major Compulsory course");
						}
					}
					return true;


				}

				bool StudyPlan::MajorElective() {
					for (int i = 0; i > CollectCoursesSPDoubleMajor.size(); i++) {
						for (int j = 0; j > Rules.MajorElective.size(); j++) {
							bool* f = std::find(CollectCoursesSPDoubleMajor.begin(), CollectCoursesSPDoubleMajor.end(), Rules.MajorElective[i])
								if (f == false)
									pGUI->PrintMsg("crtitical issue: missed Major Elective course");
						}
					}
					return true;
				}

				bool StudyPlan::checkUniCre() {
					for (int i; i > CollectCoursesSPDoubleMajor.size(); i++) {
						CollectCoursesSPDoubleMajor[i].getCredits = credits;

					}
					if (credits != Rules.ReqUnivCredits)
						pGUI->PrintMsg("crtitical issue: number of total credits is not correct");

					return true;
				}
			}
	bool  StudyPlan::check_preco(Course* C, AcademicYear* A)
	{
		for (int i = 0; i < plan.size(); i++)
		{
			for (int sem = FALL; sem < SEM_CNT; sem++)
				for (auto it = A.YearCourses[sem].begin(); it != A.YearCourses[sem].end(); ++it)
				{
					char* context;
					char line[200];
					char* pch = strtok_s(line, ",", &context);
					string CoReq;
					pch = strtok_s(line, ",", &context);
					CoReq = pch;
					pch = strtok_s(NULL, ",", &context);

					stringstream StudyPlan::sss(CoReq);
					string tmp;
					sss >> tmp;
					if (tmp == "")
						return;
					if (tmp == "CoReq:")
					{
						sss >> tmp;

					};

					string PreReq;
					pch = strtok_s(line, ",", &context);
					PreReq = pch;
					pch = strtok_s(NULL, ",", &context);
					stringstream StudyPlan::sss(PreReq);
					string tmp1;
					sss >> tmp;
					if (tmp == "")
						return;
					if (tmp1 == "PreReq:")
					{
						sss >> tmp1;
						
					}
					if (!(tmp = C->getPreReq() || tmp = C->getcoReq()))
						return true;
				};
		}
		
		C->getPreReq();
	};
			window* pwindow = new window(600, 400, 0, 0);
	
        window StudyPlan::getReport()
		{
			for (int i = 0; i < plan.size(); i++)
			{
				for (int sem = FALL; sem < SEM_CNT; sem++)
				{
					for (auto it = A.YearCourses[sem].begin(); it != A.YearCourses[sem].end(); ++it)
					{

						if (check_preco(A.YearCourses[sem], A))
						{
							window* pwindow = new window(600, 400, 0, 0);
							pwindow->DrawString(100, 100 + 35, "Moderete Issue");
							ofstream Repotr1;
							Repotr1.open("Moderete_Issue");
							Repotr1 << "Moderete Issue" << A.YearCourses[sem];
							Repotr1.close();
						}
					};
				}
			};
			Course* C;
			bool crd = A->Check_Credits(C);
			for (int i = 0; i < plan.size(); i++)
			{
				for (int sem = FALL; sem < SEM_CNT; sem++)
				{
					for (auto it = A.YearCourses[sem].begin(); it != A.YearCourses[sem].end(); ++it)
					{

						if (crd)
						{
							window* pwindow = new window(600, 400, 0, 0);
							pwindow->DrawString(100, 100 + 35, "Critical Issue");
							ofstream Repotr2;
							Repotr2.open("Moderete_Issue");
							Repotr2 << "Moderete Issue" << A.YearCourses[sem];
							Repotr2.close();
						}
					};
				}
			}}
