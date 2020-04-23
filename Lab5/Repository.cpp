#include "Repository.h"
#include <vector>
using namespace std;

bool Repository::add_film(Film film)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == film.get_titel())
		{
			return false;
		}
		movies.push_back(film);
	}
	return true;
}

bool Repository::delete_film(vector<Film> aux,string titel)
{
	for (int i = 0; i < aux.size(); i++)
	{
		if (aux[i].get_titel() == titel)
		{
			aux.erase(aux.begin() + i);
			return true;
		}
	}
	return false;
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
	if (genre == " ")
		return movies;
	vector<Film> aux;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_genre() == genre)
			aux.push_back(movies[i]);
	}
	return aux;
}

