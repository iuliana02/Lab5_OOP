#include "Validation.h"
#include "Repository.h"
#include <string>
using namespace std;

Validation::Validation() 
{
}

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

bool Validation::validate_ja_nein(string frage)
{
	if (frage == "Ja" || frage == "Nein")
		return true;
	return false;
}

bool Validation::invalid_year(int year)
{
	if (year < 1900 || year>2020)
		return true;
	return false;

}