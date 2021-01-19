#pragma once
#include "Actions//Action.h"
class Registrar;

class ValidityReportAction : public Action
{
public:
	ValidityReportAction(Registrar*);
	bool virtual Execute();
};
