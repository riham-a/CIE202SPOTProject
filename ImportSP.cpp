#include <vector>
#include "ImportSP.h"
#include <fstream> 
#include "StudyPlan/StudyPlan.h"
StudyPlan* ImportSP::getStudyPlay() const
{
	return pSPlan;
}
bool ImportSP::Execute() {
	GUI* pGUI = pReg->getGUI();

	ifstream StudyPlan;
	StudyPlan.open("D:\\UNI\\CIE \\ C++ \\ project\\DeafultSP");
	vector <Course_Code> StudyPlan;
	 double size = 250;
	char line[250];
	while (!StudyPlan.getline(line, size) 
	{
		pch = strtok_s(line, ",", &context);
		while (pch != NULL)
		{

			pch = strtok_s(NULL, ",", &context);
		}
		StudyPlan >> Course_Code theplan;
		Course_Code.push_back(theplan);
	}
	for (int i; i < StudyPlan.size(); i++) {
		if (default == StudyPlan[i])
			plan.push_back(default);
	}
	return true;
}
