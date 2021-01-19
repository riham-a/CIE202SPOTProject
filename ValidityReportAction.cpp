#include "ValidityReportAction.h"
#include "Registrar.h"
using namespace std;
#include <string>
#include <iostream>
ValidityReportAction::ValidityReportAction(Registrar* VR) :Action(VR)
{
}
bool ValidityReportAction::Execute()
{
	StudyPlan* SP;
	SP->getReport();
	return true;
}
