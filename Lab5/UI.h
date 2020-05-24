#pragma once
#include "Controller.h"

class UI
{
private:
	Controller& ctrl;	// reference to the controller (controller cannot be copied!)

	//afisarea meniului mare
	static void printMenu();

	//afisarea meniului pentru utilizator
	static void printUserMenu();
	
	//afisarea meniului pentru administrator
	static void printAdminMenu();

	//functiile pentru interfata de administrator
	void addMovieToRepo();
	void removeMovieFromRepo();
	void updateMovieFromRepo();
	void displayAllMoviesRepo();

	//functiile pentru interfata de utilizator
	
	//adauga un film la watchlist
	void addMovieToWatchlist();
	//salveaza lista cu numele si extensia date de utilizator
	void saveWatchlistToFile();
	//sterge un film din watchlist
	void removeMovieFromWatchlist();
	//afiseaza filmele disponibile, ofera optiunile de a vedea trailerul filmului, a-l adauga in watchlist si a vedea la fel si urmatoarele filme
	void view();

public:
	//constructor
	UI(Controller& c) : ctrl(c) {}

	//meniul cu case-uri
	void run();
};

