#pragma once
#include "fileWatchlist.h"
#include <string>

class csvWatchlist : public FileWatchlist
{
public:
	/*
	Writes the Watchlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the Watchlist using Microsoft Excel.
	*/
	void displayWatchlist() const override;
};



