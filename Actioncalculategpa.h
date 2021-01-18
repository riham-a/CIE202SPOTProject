

#include "Actions\Action.h"
#include<fstream>
#include <iostream>
#include<string>
using namespace std;
class ActionCalculategpa : public Action
{
private:
	int c;
	string lettergrade;
	double credit;
	double a = 0;
	double totala = 0;
	double totalcredits = 0;
	double gpa = 0;

public:
	ActionCalculategpa(Registrar*);
	bool virtual Execute();
	virtual ~ActionCalculategpa();

};






