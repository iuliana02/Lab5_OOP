#pragma once
#include "Film.h"
#include <vector>

class Watchlist
{
	/*friend class ControllerBenutzer;

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

	void copyToFile(string initial_file, string old_file);*/
protected:
	std::vector<Film> movielist;
	int current;

public:
	Watchlist();

	// Adds a movie to the Watchlist.
	void add(Film& movie);

	// Returns the movie trailer that is currently being watched.
	Film getCurrentMovie();

	// Starts the watchlist - plays the first movie trailer.
	void play();

	// Plays the next movie trailer in the watchlist.
	void next();

	// Checks if the Watchlist is empty.
	bool isEmpty();

	virtual ~Watchlist() {}
};

