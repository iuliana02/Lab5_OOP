#include "Watchlist.h"
#include <fstream>

Watchlist::Watchlist() {
	this->current = 0;
}

//void Watchlist::add_watchlist(Film f)
//{
//	//for (int i = 0; i < watchlist.size(); i++)
//	//{
//	//	if (watchlist[i].get_titel() == f.get_titel())
//	//	{
//	//		return false;
//	//	}
//	//}
//	watchlist.push_back(f);
//	//return true;
//}
//
//vector<Film> Watchlist::remove_watchlist(Film f)
//{
//	vector<Film> sters;
//	for (int i = 0; i < watchlist.size(); i++)
//	{
//		if (watchlist[i].get_titel() != f.get_titel())
//		{
//			sters.push_back(watchlist[i]);
//		}
//	}
//	return sters;;
//}
//
//void Watchlist::read_wlist()
//{
//	ifstream readFile;
//	readFile.open("watchlist.txt");
//
//	string titlu;
//	string gen;
//	int an;
//	int likes;
//	string link;
//
//	if (readFile.is_open())
//		while (!readFile.eof())
//		{
//			while (readFile >> titlu >> gen >> an >> likes >> link)
//			{
//				Film f = Film(titlu, gen, an, likes, link);
//				watchlist.push_back(f);
//			}
//		}
//}
//
//void Watchlist::write_wlist()
//{
//	ofstream writeFile;
//	writeFile.open("watchlist.txt", ofstream::app);
//
//	for (int i = 0; i < watchlist.size(); i++)
//	{
//		writeFile << i << ". " << watchlist[i].get_titel() << " " << watchlist[i].get_genre() << " " << watchlist[i].get_erscheinungsjahr() << " " << watchlist[i].get_likes() << " " << watchlist[i].get_trailer() << endl;
//	}
//
//	writeFile.close();
//}
//
//void Watchlist::copyToFile(string initialFile, string newFile)
//{
//	ifstream file1;
//	file1.open(initialFile);
//
//	ofstream file2;
//	file2.open(newFile, ios::app);
//
//	string line;
//	while (!file1.eof())
//		while (getline(file1, line))
//			file2 << line << '\n';
//	
//}
//
//Watchlist::~Watchlist() {}

void Watchlist::add(Film& movie)
{
	this->movielist.push_back(movie);
}

Film Watchlist::getCurrentMovie()
{
	if (this->current == this->movielist.size())
		this->current = 0;
	return this->movielist[this->current];
	return Film{};
}

void Watchlist::play()
{
	if (this->movielist.size() == 0)
		return;
	this->current = 0;
	Film currentMovie = this->getCurrentMovie();
	currentMovie.runURL();
}

void Watchlist::next()
{
	if (this->movielist.size() == 0)
		return;
	this->current++;
	Film currentMovie = this->getCurrentMovie();
	currentMovie.runURL();
}

bool Watchlist::isEmpty()
{
	return this->movielist.size() == 0;
}