#pragma once
#include "Actions//Action.h"

class Registrar;
		//Class responsible for adding Notes
class Notes : public Action
		{
		public:
			Notes(Registrar*);
			bool virtual Execute();
		};

