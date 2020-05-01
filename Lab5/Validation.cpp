#include "Validation.h"
#include "Repository.h"
#include <string>
using namespace std;

Validation::Validation() {}

bool Validation::validate_string(string s)
{
	for (int i=0;i<s.length();i++)
		if (isdigit(s[i]))
			return false;
	return true;
}

bool Validation::validate_int(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isalpha(s[i]))
			return false;
	return true;
}

bool Validation::validate_exist(vector<Film> v, Film f)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i].get_titel() == f.get_titel() && v[i].get_genre()==f.get_genre() && v[i].get_erscheinungsjahr()==f.get_erscheinungsjahr() && v[i].get_likes()==f.get_likes() && v[i].get_trailer()==f.get_trailer())
			return true;
	return false;
}

bool Validation::validate_ja_nein(string frage)
{
	if (frage == "Ja" || frage == "Nein")
		return true;
	return false;
}

bool Validation::validate_titel(string titel)
{
	Repository repo;
	for (int i = 0; i < repo.movies.size(); i++)
		if (repo.movies[i].get_titel() == titel)
			return true;
	return false;
}