#include "ControllerAdministrator.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

ControllerAdministrator::ControllerAdministrator(){
	rep = Repository();
}

ControllerAdministrator::~ControllerAdministrator() {}

bool ControllerAdministrator::search(Film f)
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i].get_titel() == f.get_titel())
		{
			return true;
		}
	}
	return false;
}

void ControllerAdministrator::add_film(Film f)
{
	if (!search(f))
	{
		movies.push_back(f);
	}
	else
	{
		cout << "Filmul exista deja!\n";
	}
}

void ControllerAdministrator::delete_film(Film f)
{
	if (search(f))
	{
		for (int i = 0; i < movies.size(); i++)
		{
			if (movies[i].get_titel() == f.get_titel())
			{
				movies.erase(movies.begin() + i);
				return;
			}
		}
	}
	else
	{
		cout << "Filmul nu exista!\n";
	}
}

void ControllerAdministrator::edit_film_info(Film& f)
{

	if (search(f))
	{
		for (int i = 0; i < movies.size(); i++)
		{
			if (movies.at(i).get_titel() == f.get_titel() && movies.at(i).get_genre()==f.get_genre() && movies.at(i).get_erscheinungsjahr()==f.get_erscheinungsjahr() && movies.at(i).get_likes()==f.get_likes() && movies.at(i).get_trailer()==f.get_trailer())
			{
				update_film(movies.at(i));
				return;
			}
		}
	}
	else
	{
		cout << "Filmul nu exista!\n";
	}
}

void ControllerAdministrator::show_film()
{
	if (movies.size() == 0)
		cout << "Nu exista filme!\n";
	for (int i = 0; i < movies.size(); i++)
		cout << movies[i].toString() << endl;
}