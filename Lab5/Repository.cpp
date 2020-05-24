#include "Repository.h"
#include "Validation.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Exceptions.h"
using namespace std;


Repository::Repository( const string &filename) {
	this->filename = filename;
	this->read_file();
}

//adaug un film daca nu exista deja; daca exista -> arunc exceptie
void Repository::addMovie(const Film& m)
{
	Film m1{};
	try
	{
		m1 = this->findByTitleandGenre(m.get_titel(), m.get_genre(), m.get_erscheinungsjahr());
		throw DuplicateMovieException();
	}
	catch (InexistentMovieException& e) {}
	this->movies.push_back(m);
	this->writeToFile();
}

//parcurg cu un iterator vectorul de filme, iar daca ajung la final inseamna ca nu exista filmul si arunc exceptie
//altfel il sterg din movies si actualizez fisierul txt de filme
void Repository::removeMovie(const Film& m)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == m.get_titel())
			movies.erase(movies.begin() + i);
	this->writeToFile();

	/*
	auto it = find(this->movies.begin(), this->movies.end(), m);
	if (it == this->movies.end())
		throw InexistentMovieException{};
	this->movies.erase(it);
	this->writeToFile();
	*/
}

//citirea din fiser; daca nu se poate deschide, arunc exceptie
//altfel citesc si salvez in vector
void Repository::read_file()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Film m;
	while (file >> m)
		this->movies.push_back(m);

	file.close();
}

//scrierea in fisier; din nou, daca nu se poate deschide arunc exceptie, altfel scriu din vector in fisier
void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");

	for (auto m : this->movies)
	{
		file << m;
	}

	file.close();
}

void Repository::updateMovie(const Film& m)
{
	removeMovie(m);
	cout << "Current number of likes is: " << m.get_likes();
	cout << "Do you want to change it?(y/n)";
	std::string w;
	Film m1 = m;
	cin >> w;
	//throw ConsoleerrorChar("Your answer must be or the letter y or n");
	if (w == "y")
	{
		int likes;
		cout << "The new amount of likes is: ";
		cin >> likes;
		m1.set_likes(likes);
	}

	cout << "The current source is: " << m.get_trailer();
	cout << "Do you want to change it?(y/n)";
	cin >> w;
	if (w == "y")
	{
		std::string link;
		cout << "The new link is: ";
		cin >> link;
		m1.set_trailer(link);
	}
	addMovie(m1);
}

//returnez filmul cu titlul si genul date ca parametru
//daca nu exista -> arunc exceptie
Film Repository::findByTitleandGenre(const std::string& title, const std::string& genre, const int &year) const
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == title && movies[i].get_genre() == genre)
			return movies[i];
	throw InexistentMovieException{};
	/*
	for (auto m : this->movies)
	{
		if (m.get_titel() == title && m.get_genre() == genre)
			return m;
	}

	throw InexistentMovieException{};
	*/
}
