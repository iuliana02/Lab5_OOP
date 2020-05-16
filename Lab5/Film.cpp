#include "Film.h"
#include <string>
#include <windows.h>
#include <shellapi.h>
#include<Windows.h>
#include <vector>
#include "Others.h"
#include <sstream>


Film::Film() {}

Film::Film(string titel, string genre, int erscheinungsjahr, int likes, string trailer)
{
	this->titel = titel;
	this->genre = genre;
	this->erscheinungsjahr = erscheinungsjahr;
	this->likes = likes;
	this->trailer = trailer;
}

string Film::toString()
{
	string String;
	String = "Titel: " + this->titel + "  Genre: " + this->genre + "  Erscheinungsjahr: " ;
	string jahr = to_string(this->erscheinungsjahr);
	String += jahr;
	string likes = to_string(this->likes);
	String += "  Anzahl Likes: " + likes;
	String += "\n\tTralier: " + this->trailer + "\n";
	return String;
}

void Film::runURL()
{
	string a = this->trailer;
	wstring b(a.begin(), a.end());
	LPCWSTR c = b.c_str();
	ShellExecute(0, 0, b.c_str(), 0, 0, SW_SHOW);
}

Film::~Film() {}

istream& operator>>(istream& is, Film& m)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5) // make sure all the starship data was valid
		return is;

	m.set_titel(tokens[0]) ;
	m.set_genre(tokens[1]);
	m.set_erscheinungsjahr(stoi(tokens[2]));
	m.set_likes (stoi(tokens[3]));
	m.set_trailer(tokens[4]);

	return is;

}

ostream& operator<<(ostream& os, Film& m)
{
	os << m.get_titel() << ", " << m.get_genre() << ", " << m.get_erscheinungsjahr() << ", " << m.get_likes() << ", " << m.get_trailer() << "\n";
	return os;
}