#include "Repository.h"
#include "Validation.h"
#include <vector>
#include <iostream>
using namespace std;

Repository::Repository() {
	zehn_eintrage();
}

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

vector <Film> Repository::delete_film_repo(string titel)
{
	vector<Film> sters;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() != titel)
		{
			sters.push_back(movies[i]);
		}
	}
	movies = sters;
	return sters;
}

vector<Film> Repository::delete_film_watchliste(vector<Film> aux,string titel)
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

bool Repository::update_film(string titel, string genre, int jahr, int likes, string trailer)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == titel)
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

	Film f3;
	f3.set_titel("Focus");
	f3.set_genre("Comedie");
	f3.set_erscheinungsjahr(2015);
	f3.set_likes(1277);
	f3.set_trailer("https://www.youtube.com/watch?v=MxCRgtdAuBo");
	add_film(f3);

	Film f4;
	f4.set_titel("The longest ride");
	f4.set_genre("Romance");
	f4.set_erscheinungsjahr(2015);
	f4.set_likes(1600);
	f4.set_trailer("https://www.youtube.com/watch?v=FUS_Q7FsfqU");
	add_film(f4);

	Film f5;
	f5.set_titel("Bird Box");
	f5.set_genre("Horror");
	f5.set_erscheinungsjahr(2018);
	f5.set_likes(2055);
	f5.set_trailer("https://www.youtube.com/watch?v=o2AsIXSh2xo");
	add_film(f5);
}

void Repository::update_likes(Film f, int likes)
{
	for (int i = 0; i < movies.size(); i++)
		if (movies[i].get_titel() == f.get_titel())
			movies[i].set_likes(likes);
}