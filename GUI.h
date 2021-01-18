#pragma once
#include <string>
using namespace std;

#include "..\DEFs.h"
#include "CMUgraphicsLib\CMUgraphics.h"
class Registrar;

class Course;
class AcademicYear;
class StudyPlan;
class Notes;
//user interface class
class GUI
{

	enum MENU_ITEM //The items of the menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_ADD,		//Add a new course

						//TODO: Add more items names here


		ITM_EXIT,		//Exit item
		ITM_Notes,
		ITM_CNT			//no. of menu items ==> This should be the last line in this enum

	};

	//Some constants for GUI
	static const int	WindWidth = 1300, WindHeight = 700,	//Window width and height
		wx = 15, wy = 15,		//Window starting coordinates
		StatusBarHeight = 60,	//Status Bar Height
		MenuBarHeight = 80,		//Menu Bar Height (distance from top of window to bottom line of menu bar)
		MenuItemWidth = 70;		//Width of each item in the menu



	color DrawColor = BLACK;		//Drawing color
	color FillColor = YELLOW;		//Filling color (for courses)
	color HiColor = RED;			//Highlighting color
	color ConnColor = GREEN;		//Connector color
	color MsgColor = BLUE;			//Messages color
	color BkGrndColor = LIGHTGRAY;	//Background color
	color StatusBarColor = DARKGRAY;//statusbar color
	string WindTitle = "Study-Plan Organizational Tool (SPOT)";

	window* pWind;
public:
	GUI();
	void CreateMenu() const;
	void ClearDrawingArea() const;
	void ClearStatusBar() const;	//Clears the status bar

	//output functions
	void PrintMsg(string msg) const;		//prints a message on status bar

	//Drawing functions
	void DrawCourse(const Course* );
	void DrawAcademicYear(const AcademicYear*);
	void DrawStudyPlan(const StudyPlan* pS);
	void UpdateInterface() const;
	void GUI::DrawANotes(const string* N);
	
	//input functions
	ActionData GUI::GetUserAction(string msg = "") const;
	string GetSrting() const;
	string user_Notes;
	const double YearHeight=(WindHeight - StatusBarHeight - MenuBarHeight) / 5;
	const double SemHeight = YearHeight / 3;
	const double Colum=50;

	~GUI();
};

