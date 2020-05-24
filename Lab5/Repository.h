#pragma once
#include <vector>
#include "Film.h"
//#include "Validation.h"


class Repository
{
	friend class ControllerAdministrator;
	friend class ControllerBenutzer;

private:
	vector<Film> movies;
	string filename;


public:
	void read_file();
	void writeToFile();

	Repository(const string& filename);

	/*Adds a movie to the repository.
	Input: m - Movie.
	Output: the movie is added to the repository.
	Throws: FileException - if the file cannot be opened.
	DuplicateMovieException - if there is another song with the same artist and title.
	*/
	void addMovie(const Film& m);

	/*
	Updates the movie with the given genre and title.
	Throws: InexistenSongException - if there are no songs with the given artist and title.
	*/
	void updateMovie(const Film& m);

	/*
	Removes the song with the given artist and title.
	Throws: InexistenSongException - if there are no songs with the given artist and title.
	*/
	void removeMovie(const Film& m);

	/*
	Finds a song, by artist and title.
	Input: artist, title - string
	Output: the song that was found, or an "empty" song (all fields empty and duration 0), if nothing was found.
	*/
	Film findByTitleandGenre(const std::string& title, const std::string& genre, const int& year) const;

	std::vector<Film> get_movies() const { return movies; }



};

