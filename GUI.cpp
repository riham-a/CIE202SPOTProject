#include "GUI.h"
#include "../Courses/Course.h"
#include "../StudyPlan/AcademicYear.h"
#include "../StudyPlan/StudyPlan.h"
#include <sstream>

GUI::GUI()
{ 
	pWind = new window(WindWidth, WindHeight,wx,wy);
	pWind->ChangeTitle(WindTitle);
	pWind->SetPen(RED, 5);
	//pWind->DrawRectangle(20,20,1320,1320,FILLED,0,0);
	ClearDrawingArea();
	ClearStatusBar();
	CreateMenu();
}


//Clears the status bar
void GUI::ClearDrawingArea() const
{
	pWind->SetBrush(BkGrndColor);
	pWind->SetPen(BkGrndColor);
	pWind->DrawRectangle(0, MenuBarHeight, WindWidth, WindHeight -StatusBarHeight);

}

void GUI::ClearStatusBar() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, WindHeight - StatusBarHeight, WindWidth, WindHeight);
}

void GUI::CreateMenu() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, 0, WindWidth, MenuBarHeight);

	//You can draw the menu icons any way you want.

	//First prepare List of images paths for menu item
	string MenuItemImages[ITM_CNT];
	MenuItemImages[ITM_ADD] = "GUI\\Images\\Menu\\Menu_add_course.jpg";
	MenuItemImages[ITM_EXIT] = "GUI\\Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_Notes] = "GUI\\Images\\Menu\\Notes.jpg";
	MenuItemImages[ITM_Report] = "GUI\\Images\\Menu\\ValidityReport.jpg";
	MenuItemImages[ITM_DoubleMajor] = "GUI\\Images\\Menu\\DoubleMajor.jpg";
	MenuItemImages[ITM_calculategpa] = "GUI\\Images\\Menu\\Mnue_calculategpa.jpg";
	MenuItemImages[ITM_SU] = "GUI\\Images\\Menu\\Menu_Studentlevel.jpg";
	MenuItemImages[ITM_Minor] = "GUI\\Images\\Menu\\Menu_Minor.jpg";
	MenuItemImages[ITM_CS] = "GUI\\Images\\Menu\\Menu_Coursestatus.jpg";
		

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu items one image at a time
	for (int i = 0; i<ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*MenuItemWidth, 0, MenuItemWidth, MenuBarHeight);
}

////////////////////////    Output functions    ///////////////////

//Prints a message on the status bar
void GUI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX, WindHeight - MsgY, msg);
}

//////////////////////////////////////////////////////////////////////////
void GUI::UpdateInterface() const
{
	
	pWind->SetBuffering(true);
	//Redraw everything
	CreateMenu();
	ClearStatusBar();
	ClearDrawingArea();
	pWind->UpdateBuffer();
	pWind->SetBuffering(false);
}

////////////////////////    Drawing functions    ///////////////////
void GUI::DrawCourse(const Course* pCrs)
{
	if (pCrs->isSelected())
		pWind->SetPen(HiColor, 2);
	else
	pWind->SetPen(DrawColor, 2);
	pWind->SetBrush(FillColor);
	graphicsInfo gInfo = pCrs->getGfxInfo();
	// to draw course properly
	if (gInfo.y > 80 && gInfo.y < 192) //user clicked on first year
	{
		if (gInfo.y > 80 && gInfo.y < 117.3)
		{
			gInfo.y = 81;
		}
		else if (gInfo.x > 117.3 && gInfo.x < 154.66)
		{
			gInfo.y = 118.3;
		}
		else if (gInfo.y > 154.66 && gInfo.y < 192) 
		{
			gInfo.y = 155.66;
		}
	}
	else if (gInfo.y > 192 && gInfo.y < 304) 
	{
		if (gInfo.y > 192 && gInfo.y < 229.3)
		{
			gInfo.y = 193;
		}
		else if (gInfo.y > 229.3 && gInfo.y < 266.6) 
		{
			gInfo.y =230.3;
		}
		else if (gInfo.y > 266.6 && gInfo.y <304) 
		{
			gInfo.y = 267.6;
		}
	}
	else if (gInfo.y > 304 && gInfo.y < 416)
	{
		if (gInfo.y >304 && gInfo.y < 341.3) {
			gInfo.y = 305;
		}
		else if (gInfo.y > 341.3 && gInfo.y < 378.6) {
			gInfo.y = 342.3;
		}
		else if (gInfo.y > 378.6 && gInfo.y < 416) {
			gInfo.y = 379.6;
		}
	}
	else if (gInfo.y > 416 && gInfo.y < 526) {
		if (gInfo.y >416 && gInfo.y < 453.3) {
			gInfo.y = 417;
		}
		else if (gInfo.y >453.3&& gInfo.y < 490.6) {
			gInfo.y = 454.3;
		}
		else	if (gInfo.y > 490.6 && gInfo.y < 528) {
			gInfo.y = 491.6;
		}
	}
	else if (gInfo.y > 528 && gInfo.y < 640) {
		if (gInfo.y > 528 && gInfo.y < 565.3) {
			gInfo.y = 529;
		}
		else	if (gInfo.y >565.3 && gInfo.y < 602.6) {
			gInfo.y = 566.3;
		}
		else if (gInfo.y > 602.6 && gInfo.y < 640) {
			gInfo.y = 603.6;
		}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	pWind->DrawRectangle(gInfo.x, gInfo.y, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT);
	pWind->DrawLine(gInfo.x, gInfo.y + CRS_HEIGHT / 2, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT / 2);
	
	//Write the course code and credit hours.
	int Code_x = gInfo.x + CRS_WIDTH * 0.15;
	int Code_y = gInfo.y + CRS_HEIGHT * 0.05;
	pWind->SetFont(CRS_HEIGHT * 0.4, BOLD , BY_NAME, "Gramound");
	pWind->SetPen(MsgColor);
	if ( pCourse->GetType() == "UniversityCoumpulsory" || pCourse->GetType() == "UniversityElective") {
		pWind->SetPen(GREEN, 2);
	}
	else if (pCourse->GetType() == "MajorCompulsory" || pCourse->GetType() == "MajorElective") {
		pWind->SetPen(RED, 2);
	}
	else if (pCourse->GetType() == "TrackCoumpulsory" || pCourse->GetType() == "TrackCoumpulsoryElective") {
		pWind->SetPen(YELLOW, 2);
	}
	else if (pCourse->GetType() == "MajorCoumpulsory" || pCourse->GetType() == "MajorElective") {
		pWind->SetPen(BLACK, 2);


	ostringstream crd;
	crd<< "crd:" << pCrs->getCredits();
	pWind->DrawString(Code_x, Code_y, pCrs->getCode());
	pWind->DrawString(Code_x, Code_y + CRS_HEIGHT/2, crd.str());
}

void GUI::DrawAcademicYear(const AcademicYear* pY)
{
	//graphicsInfo gInfo = pY->getGfxInfo();
	//gInfo.x = 10;
	//gInfo.y = 10;
	//pWind->SetPen(BLACK, 5);
	//pWind->DrawRectangle(WindWidth - 100, MenuBarHeight, WindWidth - 20, WindHeight - StatusBarHeight, FRAME, 0, 0);
	//pWind->SetFont(16, BOLD | ITALICIZED, BY_NAME, "Arial");
	//pWind->DrawString(WindWidth - 90, MenuBarHeight + 20, "YOUR");
	////pWind->DrawString(WindWidth - 90, MenuBarHeight + 35, "NOTES");
	//string s = "Notes";
	//pWind->DrawString(WindWidth - 90, MenuBarHeight + 35, s);
	//pWind->SetFont(25, BOLD | ITALICIZED, BY_NAME, "Arial");
	////numbers of years
	//pWind->DrawString(Colum / 3, MenuBarHeight + YearHeight / 3, "1");
	//pWind->DrawString(Colum / 3, MenuBarHeight +4* YearHeight / 3, "2");
	//pWind->DrawString(Colum / 3, MenuBarHeight + 7 * YearHeight / 3, "3");
	//pWind->DrawString(Colum / 3, MenuBarHeight + 10 * YearHeight / 3, "4");
	//pWind->DrawString(Colum / 3, MenuBarHeight + 13 * YearHeight / 3, "5");
	//// rectangle for semesters name
	//pWind->DrawRectangle(Colum, MenuBarHeight,3* Colum, WindHeight - StatusBarHeight, FRAME, 0, 0);
	//// rectangle for years name
	//pWind->DrawRectangle(0, MenuBarHeight, Colum, WindHeight - StatusBarHeight, FRAME, 0, 0);
	//for (int i = 1; i < 6; i++) {
	//	pWind->SetPen(BLACK, 5);
	//	pWind->DrawRectangle(0,MenuBarHeight, WindWidth - 100, MenuBarHeight+i* YearHeight, FRAME, 3, 3);
	//}
	//pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	//for (int i = 1; i < 16; i++) {
	//	pWind->SetPen(BLACK, 2);
	//	pWind->DrawRectangle(Colum, MenuBarHeight, WindWidth - 100, MenuBarHeight + i * SemHeight, FRAME, 0, 0);
	//	pWind->DrawString(4*Colum / 3, MenuBarHeight+ (i-1)* YearHeight+5, "FALL");
	//	pWind->DrawRectangle(Colum, MenuBarHeight, WindWidth - 100, MenuBarHeight + i * SemHeight, FRAME, 0, 0);
	//	pWind->DrawString(4 * Colum / 3, MenuBarHeight + (i - 1) * YearHeight + 5+ SemHeight, "Spring");
	//	pWind->DrawString(4 * Colum / 3, MenuBarHeight + (i - 1) * YearHeight + 5 + 2*SemHeight, "Summer");
	//}
}
void GUI::DrawANotes(const string* N)
{
	pWind->SetPen(BLACK, 5);
	pWind->DrawRectangle(WindWidth - 100, MenuBarHeight, WindWidth - 20, WindHeight - StatusBarHeight, FRAME, 0, 0);
	pWind->SetFont(16, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawString(WindWidth - 90, MenuBarHeight + 20, "YOUR");
	string s = "Notes";
	pWind->DrawString(WindWidth - 90, MenuBarHeight + 35, s);
	//pWind->DrawString(WindWidth - 90, MenuBarHeight + 35, Registrar::* notes); //qqqq

}

////////////////////////    Input functions    ///////////////////
//This function reads the position where the user clicks to determine the desired action
//If action is done by mouse, actData will be the filled by mouse position
ActionData GUI::GetUserAction(string msg) const
{
	keytype ktInput;
	clicktype ctInput;
	char cKeyData;

	
	// Flush out the input queues before beginning
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();
	
	PrintMsg(msg);

	while (true)
	{
		int x, y;
		ctInput = pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		ktInput = pWind->GetKeyPress(cKeyData);

		if (ktInput == ESCAPE)	//if ESC is pressed,return CANCEL action
		{
			return ActionData{ CANCEL };
		}

		
		if (ctInput == LEFT_CLICK)	//mouse left click
		{
			//[1] If user clicks on the Menu bar
			if (y >= 0 && y < MenuBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_ADD: return ActionData{ ADD_CRS };	//Add course
				case ITM_Notes: return ActionData{ ADD_Notes };
				case ITM_Report: return ActionData{ View_Report };
				case ITM_DoubleMajor: return ActionData{ Double_Major };
				case ITM_EXIT: return ActionData{ EXIT };		//Exit
				case ITM_calculategpa :return ActionData{ CALC_GPA }; //calculate gpa
				case ITM_CS:return ActionData{ Disp_course }; //select course status
				case ITM_Minor:return ActionData{ Minor }; //addminorcourses
				case ITM_SU:return ActionData{ Studentlevel }; //display the student level

				default: return ActionData{ MENU_BAR };	//A click on empty place in menu bar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= MenuBarHeight && y < WindHeight - StatusBarHeight)
			{
				return ActionData{ DRAW_AREA,x,y };	//user want clicks inside drawing area
			}

			//[3] User clicks on the status bar
			return ActionData{ STATUS_BAR };
		}
	}//end while

}

string GUI::GetSrting() const
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar

	

	string userInput;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);

		switch (Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input

		case 13:		//ENTER key is pressed
			return userInput;

		case 8:		//BackSpace is pressed
			if (userInput.size() > 0)
				userInput.resize(userInput.size() - 1);
			break;

		default:
			userInput += Key;
		};

		PrintMsg(userInput);
	}

}








GUI::~GUI()
{
	delete pWind;
}


void GUI::DrawStudyPlan(const StudyPlan* p)
{
	graphicsInfo gInfo;// = pY->getGfxInfo();
	gInfo.x = 10;
	gInfo.y = 10;
	pWind->SetPen(BLACK, 5);
	pWind->DrawRectangle(WindWidth - 100, MenuBarHeight, WindWidth - 20, WindHeight - StatusBarHeight, FRAME, 0, 0);
	pWind->SetFont(16, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->DrawString(WindWidth - 90, MenuBarHeight + 20, "YOUR");
	//pWind->DrawString(WindWidth - 90, MenuBarHeight + 35, "NOTES");
	string s = p->notes;
	pWind->DrawString(WindWidth - 90, MenuBarHeight + 35, "Notes");
	pWind->DrawString(WindWidth - 90, MenuBarHeight + 50, s);
	pWind->SetFont(25, BOLD | ITALICIZED, BY_NAME, "Arial");
	//numbers of years
	pWind->DrawString(Colum / 3, MenuBarHeight + YearHeight / 3, "1");
	pWind->DrawString(Colum / 3, MenuBarHeight + 4 * YearHeight / 3, "2");
	pWind->DrawString(Colum / 3, MenuBarHeight + 7 * YearHeight / 3, "3");
	pWind->DrawString(Colum / 3, MenuBarHeight + 10 * YearHeight / 3, "4");
	pWind->DrawString(Colum / 3, MenuBarHeight + 13 * YearHeight / 3, "5");
	// rectangle for semesters name
	pWind->DrawRectangle(Colum, MenuBarHeight, 3 * Colum, WindHeight - StatusBarHeight, FRAME, 0, 0);
	// rectangle for years name
	pWind->DrawRectangle(0, MenuBarHeight, Colum, WindHeight - StatusBarHeight, FRAME, 0, 0);
	for (int i = 1; i < 6; i++) {
		pWind->SetPen(BLACK, 5);
		pWind->DrawRectangle(0, MenuBarHeight, WindWidth - 100, MenuBarHeight + i * YearHeight, FRAME, 3, 3);
	}
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	for (int i = 1; i < 16; i++) {
		pWind->SetPen(BLACK, 2);
		pWind->DrawRectangle(Colum, MenuBarHeight, WindWidth - 100, MenuBarHeight + i * SemHeight, FRAME, 0, 0);
		pWind->DrawString(4 * Colum / 3, MenuBarHeight + (i - 1) * YearHeight + 5, "FALL");
		pWind->DrawRectangle(Colum, MenuBarHeight, WindWidth - 100, MenuBarHeight + i * SemHeight, FRAME, 0, 0);
		pWind->DrawString(4 * Colum / 3, MenuBarHeight + (i - 1) * YearHeight + 5 + SemHeight, "Spring");
		pWind->DrawString(4 * Colum / 3, MenuBarHeight + (i - 1) * YearHeight + 5 + 2 * SemHeight, "Summer");
	}

}
