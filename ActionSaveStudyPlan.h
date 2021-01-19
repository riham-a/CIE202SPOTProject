#pragma once
#include "Actions/Action.h"
class ActionSaveStudyPlan :
	public Action
{
public:
	ActionSaveStudyPlan(Registrar*);
	bool virtual Execute();
	virtual ~ActionSaveStudyPlan();
};