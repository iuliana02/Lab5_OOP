#include "Film.h"
#include <string>
#include <windows.h>
#include <shellapi.h>
#include<Windows.h>


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
	String += "  Tralier: " + this->trailer;
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