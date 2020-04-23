#pragma once
#include <string>
using namespace std;

class Film
{
private:
	string titel;
	string genre;
	int erscheinungsjahr;
	int likes;
	string trailer;

public:
	Film();
	Film(string, string, int, int, string);

	string get_titel() { return this->titel; }
	string get_genre() { return this->genre; }
	int get_erscheinungsjahr() { return this->erscheinungsjahr; }
	int get_likes() { return this->likes; }
	string get_trailer() { return this->trailer; }

	void set_titel(string titel) { this->titel = titel; }
	void set_genre(string genre) { this->genre = genre; }
	void set_erscheinungsjahr(int erscheinungsjahr) { this->erscheinungsjahr = erscheinungsjahr; }
	void set_likes(int likes) { this->likes = likes; }
	void set_trailer(string trailer) { this->trailer = trailer; }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Convert this  into a string representation. </summary>
	///
	/// <remarks>	Popai, 23/04/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	string toString();

	void runURL();

	~Film();
};

