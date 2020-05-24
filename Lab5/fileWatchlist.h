#pragma once
#include "Watchlist.h"

//clasa pt crearea watchlist-ului in fisier
class FileWatchlist : public Watchlist
{
protected:
	std::string filename;

public:
	//constructor
	FileWatchlist();
	//destructor
	virtual ~FileWatchlist() {}

	//seteaza numele fisierului in care se va salva lista de filme a utilizatorului
	void setFilename(const std::string& filename);

	//functie virtuala, suprascrisa in clasele pentru convertirea in csv si html
	virtual void writeToFile() = 0;
	//functie virtuala pt afisarea watchlist-ului, folosite tot in clasele pt csv si html
	virtual void displayWatchlist() const = 0;
};
