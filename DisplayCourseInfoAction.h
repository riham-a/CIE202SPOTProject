#pragma once
#include "Actions//Action.h"
//Class responsible for displaying course information
class DisplayCourseInfoAction :public Action
{
public:
	DisplayCourseInfoAction(Registrar*);
	bool virtual Execute();
	virtual ~DisplayCourseInfoAction();
};


