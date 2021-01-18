#include "CourseCatalogAction.h"
//#include <fstream>
//
//CourseCatalogAction::CourseCatalogAction()
//{
//	ofstream Course_Catalog;
//
//	Course_Catalog.open("D:\\ZC\\C++\\Project\\Course_Catalog");
//};
//
///*ofstream Course_Catalog;
//
//	Course_Catalog.open("D:\\ZC\\C++\\Project\\Course_Catalog");*/



/*
fstream file;
	//assume that course catalog file is CourseCatalog.txt
	ifstream finput("CourseCatalog.txt");
	CourseInfo coinfo;
	string corequesit;
	string prerequesit;
	string data;
	string co;
	string core;
	while (getline(file, data))
	{
		stringstream  s(data);
		getline(s, coinfo.Code, ',');
		getline(s, coinfo.Title, ',');
		getline(s, co, ',');
		coinfo.Credits = stoi(co);
		getline(s, core, ',');
		while (coinfo.CoReqList.empty() != NULL)
		{
			coinfo.CoReqList.push_back(corequesit);
		}
		getline(s, prerequesit, ',');
		while (coinfo.PreReqList.empty() != NULL)
		{
			coinfo.PreReqList.push_back(corequesit);
		}
		RegRules.CourseCatalog.push_back(coinfo);
	}*/
