#include <vector>
#include "../GUI/Drawable.h"
#include "StudyPlan.h"
#include "Action.h"
#include "ImportSP.h"
#include <ifstream> 
#include "Registrar.h"
using namespace std;

StudyPlan*  ImportSP::savedPlan() const 
{
	pReg-> getStudyPlan()->pSPlan;
	return pSPlan;

	GUI* pGUI = pReg->getGUI();

}
bool ImportSP::Execute() {
	GUI* pGUI = pReg->getGUI();

	ifstream studyPlan;
	studyPlan.open("D:\\UNI\\CIE \\ C++ \\ project\\DeafultSP");
	vector <Course_Code> TheStudyPlan;
	double size = 250;
	char line[size];
	char* pch;
	char* Context;
	StudyPlan* pCourses;

	
	while (!StudyPlan.getline(line, size) {
		pch = strtok_s(line, ",", &Context);
		while (pch != NULL)
		{

			pch = strtok_s(NULL, ",", &context);
			TheStudyPlan.push_back(Context);
        }
		
	}
	for (int i; i < TheStudyPlan.size(); i++) {
		pCourses->pReg;
	}
	GUI* pGUI = pReg->getGUI();

	return true;
}
