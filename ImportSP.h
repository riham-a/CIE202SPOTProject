#include <vector>
#include "AcademicYear.h"
#include "../GUI/Drawable.h"
#include "course.h"
#include "StudyPlan.h"
#include "Action.h"
#include "Registrar.h"


class ImportSP:public Action
{

public:
	Course_Code default;
	bool Execute();
	StudyPlan* savedPlan() const;
	StudyPlan* pSPlan;

	
};
