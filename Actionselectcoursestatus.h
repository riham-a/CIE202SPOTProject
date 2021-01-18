#pragma once
#include "Registrar.h"
class Actionselectcoursestatus : public Action
{

public:
	Actionselectcoursestatus(Registrar*);
	bool Execute();
	virtual ~Actionselectcoursestatus();
};