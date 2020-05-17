#pragma once
#include "Film.h"
#include <vector>

class Watchlist
{

protected:
	std::vector<Film> movielist;
	//iterator pentru watchlist
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

