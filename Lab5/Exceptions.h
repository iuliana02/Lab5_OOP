#pragma once
#include <exception>
#include <string>

//Exceptii pentru fisier
class FileException : public std::exception
{
protected:
	std::string message;

public:
	//constructor
	//are ca si parametru un string pentru un mesaj in cazul unei exceptii
	FileException(const std::string& msg);

	//functie virtuala
	//returneaza mesajul dat ca si parametru la apelul functiei
	virtual const char* what();
};

//exceptii repo
class RepositoryException : public std::exception
{
protected:
	std::string message;

public:
	RepositoryException();

	//ca si parametru am un string (mesaj)
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {}

	//retuneaza string-ul cu mesajul exceptiei
	virtual const char* what();
};

//clasa pentru exceptiile in cazurile cand un film exista deja
class DuplicateMovieException : public RepositoryException
{
public:
	//returneaza un mesaj care sa anunte utilizatorul ca exista deja un film cu titlul si genul respectiv
	const char* what();
};

//clasa pt cazurile cand un film cautat nu exista
class InexistentMovieException : public RepositoryException
{
public:
	//returneaza un string cu mesajul ca nu exista filmul cautat
	const char* what();
};

