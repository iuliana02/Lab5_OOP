#pragma once
#include "Film.h"
#include <vector>

class Watchlist
{
	friend class ControllerBenutzer;

private: 
	vector <Film> watchlist;

public:
	Watchlist();
	~Watchlist();

	vector<Film> get_watchlist() { return watchlist; }

	void add_watchlist(Film f);

	vector<Film> remove_watchlist(Film f);

	void read_wlist();
	void write_wlist();

	void copyToFile(string initial_file, string old_file);
};

