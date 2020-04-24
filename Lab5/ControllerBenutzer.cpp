#include "ControllerBenutzer.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


ControllerBenutzer::ControllerBenutzer() : Repository() {}


void ControllerBenutzer::view_by_genre()
{
	string gen;
	cout << "Genul filmului:\n";
	cin >> gen;

	vector<Film> filme = nach_genre_anzeigen(gen);
	for (int i = 0; i < filme.size(); i++)
		cout << filme[i].get_titel() << endl;

	int i = 0;
	while (i < filme.size())
	{
		cout << "\nTrailer des Films " << filme[i].get_titel() << "\n";
		cout << filme[i].toString() << endl;
		filme[i].runURL();

		cout << "Fugen Sie diesen Film zu der Watchliste ein? \n";
		string antwort;
		cin >> antwort;
		if (antwort == "Ja")
			watchliste.push_back(filme[i]);

		cout << "Wollen Sie den Trailer des nachsten Films sehen?\n";
		string antwort2;
		cin >> antwort2;
		if (antwort2 != "Ja")
			return;

		i++;
	}

}

void ControllerBenutzer::remove_film()
{
	cout << "Welches Film wollen Sie loschen? (Titel)\n";
	string a;
	cin >> a;
	Film film = get_film(watchliste, a);

	vector<Film> sters = delete_film(watchliste,a);

	cout << "Wollen Sie den geloschten Film bewerten? Like->1\n";
	string b;
	cin >> b;
	if (b == "1")
	{
		update_likes(film,film.get_likes()+1);
		cout << "Danke fur Ihre Bewertung!\n";
	}

	watchliste = sters;
}

void ControllerBenutzer::show_watchliste()
{
	if (watchliste.size() == 0)
		cout << "Kein Film in der Watchliste\n";
	for (int i = 0; i < watchliste.size(); i++)
		cout << watchliste[i].toString() << endl;
}


ControllerBenutzer::~ControllerBenutzer() {}
