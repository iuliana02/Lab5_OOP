#include "ControllerAdministrator.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;

ControllerAdministrator::ControllerAdministrator()

void ControllerAdministrator::add()
{
	cout << "Neues Titel:\n";
	string titel;
	cin >> titel;
	cout << "Genre:\n";
	string genre;
	cin >> genre;
	cout << "Erscheinungsjahr:\n";
	int jahr;
	cin >> jahr;
	cout << "Anzahl Likes\n";
	int likes;
	cin >> likes;
	cout << "URL zum Trailer:\n";
	string trailer;
	cin >> trailer;
	Film neuesFilm = Film(titel, genre, jahr, likes, trailer);
	add_film(neuesFilm);
	cout << "Film eingefugt\n";
}

void ControllerAdministrator::deletee()
{
	Validation v;

	cout << "Titel des Films fur Loschen:\n";
	string titel;
	cin >> titel;
	while (!v.validate_titel(titel))
	{
		cout << "Kein Film mit dieses Titel\n";
		cin >> titel;
	}
	delete_film_repo(titel);
	cout << "Film geloschen\n";
}

void ControllerAdministrator::edit_film_info()
{
	Validation v;
	cout << "Titel des Films zu modifizieren\n";
	string titel;
	cin >> titel;
	while (!v.validate_titel(titel))
	{
		cout << "Kein Film mit dieses Titel\n";
		cin >> titel;
	}

	cout << "Neues Genre:\n";
	string genre;
	cin >> genre;
	cout << "Neues Erscheinungsjahr:\n";
	int jahr;
	cin >> jahr;
	cout << "Neue Anzahl von Likes:\n";
	int likes;
	cin >> likes;
	cout << "Neues URL fur Trailer:\n";
	string trailer;
	cin >> trailer;

	update_film(titel, genre, jahr, likes, trailer);

	cout << "Film modifiziert!\n";
}


void ControllerAdministrator::show_filme()
{
	if (movies.size() == 0)
		cout << "Nu exista filme!\n";
	for (int i = 0; i < movies.size(); i++)
	{
		cout << movies[i].toString() << endl;
	}
}

ControllerAdministrator::~ControllerAdministrator() {}

