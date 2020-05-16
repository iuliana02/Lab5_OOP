#include "Controller.h"
#include <algorithm>
#include "FileWatchlist.h"
#include "Exceptions.h"

using namespace std;

void Controller::addMovieToRepository(const std::string& title, const std::string& genre, const int& year, const int& like, const std::string& trailer)
{
	Film m{ title, genre, year, like, trailer };
	this->validator.validate(m);
	this->repo.add_film(m);
}

void Controller::removeMovieFromRepository(const std::string& title, const std::string& genre)
{
	Film m = this->repo.findByTitleandGenre(title, genre);
	this->repo.delete_film_repo(m.get_titel());

}

void Controller::addMovieToWatchlist( Film& movie)
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->add(movie);
}

void Controller::addAllMoviesByGenreToWatchlist(const std::string& genre)
{
	vector<Film> movielist = this->repo.get_movies();
	int nMovies = count_if(movielist.begin(), movielist.end(),
		[genre]( Film& m)
		{
			return m.get_genre() == genre;
		});

	vector<Film> moviesbyGenre(nMovies);
	copy_if(movielist.begin(), movielist.end(), moviesbyGenre.begin(),
		[genre]( Film& m)
		{
			return m.get_genre() == genre;
		});

	for (auto m : moviesbyGenre)
		this->watchlist->add(m);
}

void Controller::startWatchlist()
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->play();
}

void Controller::nextMovieWatchlist()
{
	if (this->watchlist == nullptr)
		return;
	this->watchlist->next();
}

void Controller::saveWatchlist(const std::string& filename)
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->setFilename(filename);
	this->watchlist->writeToFile();
}

void Controller::openWatchlist() const
{
	if (this->watchlist == nullptr)
		return;

	this->watchlist->displayWatchlist();
}
