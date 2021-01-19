#include "ActionSaveStudyPlan.h"
#include "Registrar.h"
#include<fstream>


ActionSaveStudyPlan::ActionSaveStudyPlan(Registrar* p) :Action(p)
{}

bool ActionSaveStudyPlan::Execute() {
	ofstream datafile;
	datafile.open("textfiles\\savedstudyplan.txt", ios::trunc);
	pReg->getStudyPlay()->saveMe(datafile);
	datafile.close();
	return true;
}

ActionSaveStudyPlan::~ActionSaveStudyPlan() {}