#include "RulesAction.h"
#include "Rules.h"
#include <fstream>
#include <iostream>
#include <ifstream>
#include <sstream>
#include "ifstream"
#include <vector>
using namespace std;




bool RulesAction::RulesRequirements() {
	
	ifstream file ("Rules.txt");
	 int line;
	 int count = 1;
	 int const size = 300;
	 char* pch;
	 char *context = nullptr;
	 char LINE[size];
	int count2 =7 ;

	 vector <string> lines;
	 while (file.getline (line) && count != 5)
	 {
		 lines.push_back(line);
		 count++
	 }
	 Rules.totalcredit = lines.begin();
	 Rules.ReqUnivCredits = lines.at(1);
	 Rules.ReqTrackCredits = lines.at(2);
	 Rules.ReqMajorCredits = lines.at(3);
	///////////////
	 vector <vector<string>> LINES;
	while (file.getline(LINE, size) && count2  != 12)
	{
		pch = strtok_s(LINE, ",", &context);
		while (pch != NULL)
		{

			pch = strtok_s(NULL, ",", &context);
			LINES.push_back(pch);
		}
		
		count2++;
	}
	Rules.UnivCompulsory = LINES.at(0);
	Rules.UnivElective = LINES.at(1);
	Rules.TrackCompulsory = LINES.at(2);
	Rules.MajorCompulsory = LINES.at(3);
	Rules.MajorElective = LINES.at(4);

	return true;
}
