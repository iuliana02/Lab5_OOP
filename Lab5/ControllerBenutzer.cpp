#include "ControllerBenutzer.h"
#include <iostream>
#include <vector>
#include <string>
#include "Validation.h"
using namespace std;


ControllerBenutzer::ControllerBenutzer() {
	repo = Repository();
}


void ControllerBenutzer::view_by_genre()
{
	Validation v;

	string gen;
	cout << "Genul filmului:\n";
	cin >> gen;
	while (!v.validate_string(gen))
	{
		cout << "Man soll einen String einfugen!\n";
		cout << "Genul filmului:\n";
		cin >> gen;
	}
	vector<Film> filme = repo.nach_genre_anzeigen(gen);
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
		while (!v.validate_ja_nein(antwort))
		{
			cout << "Sie mussen 'Ja' oder 'Nein' als Antwort geben\n";
			cin >> antwort;
		}
		if (antwort == "Ja")
			repo.watchliste.push_back(filme[i]);

		cout << "Wollen Sie den Trailer des nachsten Films sehen?\n";
		string antwort2;
		cin >> antwort2;
		while (!v.validate_ja_nein(antwort2))
		{
			cout << "Sie mussen 'Ja' oder 'Nein' als Antwort geben\n";
			cin >> antwort2;
		}
		if (antwort2 == "Nein")
			return;

		i++;
	}

}

void ControllerBenutzer::remove_film()
{
	Validation v;
	if (repo.watchliste.size() == 0)
	{
		cout << "Kein Film in der Watchliste. Remove ist nicht moglich!\n";
		return;
	}
	cout << "Welches Film wollen Sie loschen? (Titel)\n";
	string a;
	cin >> a;
	while (!v.validate_string(a))
	{
		cout << "Man soll einen String einfugen!\n";
		cout << "Geben Sie noch einmal den Titel des Films:\n";
		cin >> a;
	}
	Film film = repo.get_film(repo.watchliste, a);

	vector<Film> sters = repo.delete_film_watchliste(repo.watchliste,a);

	cout << "Wollen Sie den geloschten Film bewerten? Like->1\n";
	string b;
	cin >> b;
	if (b == "1")
	{
		repo.update_likes(film,film.get_likes()+1);
		cout << "Danke fur Ihre Bewertung!\n";
	}

	repo.watchliste = sters;
}

void ControllerBenutzer::show_watchliste()
{
	if (repo.watchliste.size() == 0)
		cout << "Kein Film in der Watchliste\n";
	for (int i = 0; i < repo.watchliste.size(); i++)
		cout << repo.watchliste[i].toString() << endl;
}


ControllerBenutzer::~ControllerBenutzer() {}
