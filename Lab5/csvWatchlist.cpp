#include "csvWatchlist.h"
#include <fstream>
#include <Windows.h>
#include "Exceptions.h"
#include <iostream>
using namespace std;

void csvWatchlist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException(" The file could not be opened!");

	for (auto m : this->movielist)
		f << m;

	f.close();
}

void csvWatchlist::displayWatchlist() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "c:\\Program Files\\Microsoft Office\\Office15\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
