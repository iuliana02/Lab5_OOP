#include "Repository.h"
#include <vector>
#include <iostream>
using namespace std;

Repository::Repository() {}

void Repository::add_film(Film film)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == film.get_titel())
		{
			return;
		}
	}
	movies.push_back(film);
}

vector<Film> Repository::delete_film(vector<Film> aux,string titel)
{
	vector<Film> sters;
	for (int i = 0; i < aux.size(); i++)
	{
		if (aux[i].get_titel() != titel)
		{
			sters.push_back(aux[i]);
		}
	}
	return sters;
}

Film Repository::get_film(vector<Film> aux, string titel)
{
	for (int i = 0; i < aux.size(); i++)
		if (aux[i].get_titel() == titel)
			return aux[i];
}

bool Repository::update_film(Film film, string genre, int jahr, int likes, string trailer)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == film.get_titel())
		{
			movies[i].set_genre(genre);
			movies[i].set_erscheinungsjahr(jahr);
			movies[i].set_likes(likes);
			movies[i].set_trailer(trailer);
			return true;
		}
	}
	return false;
}

vector<Film> Repository::nach_genre_anzeigen(string genre)
{
	zehn_eintrage();
	if (genre == "")
		return movies;
	vector<Film> aux;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_genre() == genre)
			aux.push_back(movies[i]);
	}
	return aux;
}

void Repository::zehn_eintrage()
{
	Film f1 = Film("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	add_film(f1);

	Film f2 = Film("The Pianist", "Drama", 2002, 890, "https://www.youtube.com/watch?v=BFwGqLa_oAo");
	add_film(f2);

	Film f3 = Film("Focus", "Comedie", 2015, 1277, "https://www.youtube.com/watch?v=MxCRgtdAuBo");
	add_film(f3);

	Film f4 = Film("The longest ride", "Romance", 2015, 1600, "https://www.youtube.com/watch?v=FUS_Q7FsfqU");
	add_film(f4);

}

void Repository::afisare_filme()
{
	for (int i = 0; i < movies.size(); i++)
		cout << movies[i].toString() << endl;
}

void Repository::update_likes(Film f, int likes)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == f.get_titel())
			movies[i].set_likes(likes);
}