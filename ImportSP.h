#pragma once
#include <vector>
#include "StudyPlan/AcademicYear.h"
#include "GUI/Drawable.h"
#include "Courses/Course.h"
#include "StudyPlan/StudyPlan.h"
#include "Actions/Action.h"

class ImportSP :public Action
{

public:
	StudyPlan* pSPlan;
	Course_Code default;
	bool Execute();
	StudyPlan* getStudyPlay() const;


};
