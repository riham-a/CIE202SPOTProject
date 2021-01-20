#pragma once
#include "GUI\GUI.h"
#include "Actions\Action.h"
#include "Rules.h"
#include "StudyPlan/StudyPlan.h"


//The maestro class for the application
class Registrar
{
	GUI *pGUI;	//pointer to GUI 
	Rules RegRules;	//Registration rules
	StudyPlan *pSPlan;
		Rules* IsReq; // pointer to all rules requirements to check them


public:
	Registrar();
	GUI* getGUI() const;
	Action* CreateRequiredAction();
	bool ExecuteAction(Action*);
	void UpdateInterface();
	StudyPlan* getStudyPlan() const;
	void Run();
	string* notes = nullptr;
	StudyPlan* w = nullptr;
	bool check(StudyPlan * w);
	CourseInfo* getcourseinfo(Course_Code code);
	bool importcoursecatalog();
	~Registrar();
};

