#include "Notes.h"
#include "Registrar.h"
using namespace std;
#include <string>
#include <iostream>
Notes::Notes(Registrar* nnn) :Action(nnn)
{
}
bool Notes::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Enter your Notes");
	//ActionData actData = pGUI->GetUserAction("Enter your Notes");
	string U_notes = pGUI->GetSrting();
	StudyPlan* S = pReg->getStudyPlay();
	S->setNotes(U_notes);
	return true;
}