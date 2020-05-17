#pragma once
#include "Controller.h"

class UI
{
private:
	Controller& ctrl;	// reference to the controller (controller cannot be copied!)

	static void printMenu();
	static void printRepositoryMenu();
	static void printPlayListMenu();

	void addMovieToRepo();
	void removeMovieFromRepo();
	void displayAllMoviesRepo();
	void addMovieToWatchlist();
	void addAllMoviesByGenreToWatchlist();
	void saveWatchlistToFile();


public:
	UI(Controller& c) : ctrl(c) {}

	void run();
};

