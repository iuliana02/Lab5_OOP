#include "html.h"
#include<iostream>

void HTMLBuilder::build_watchlist(vector <int> watchlist, Repository& repo) {
    ofstream fin;
    fin.open("watchlist.html", std::fstream::in | std::fstream::out | std::fstream::app);

    fin << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchliste</title>\n</head>\n<body>\n<table border =";
    fin << "'1'";
    fin << "> \n<tr>\n<td>Titel</td>\n<td>Genre</td>\n<td>Jahr</td>\n<td>Likes</td>\n<td>Trailer link </td>\n";

    for (int i = 0; i < watchlist.size(); i++) {
        Film m = repo.get_movie_by_id(watchlist[i]);
        fin << "</tr>\n<tr>\n<td>" << m.get_titel() << "</td>\n<td>" << m.get_genre() << "</td>\n<td>" << m.get_erscheinungsjahr() << "</td>\n<td>" << m.get_number_of_likes() << "</td>\n<td><a href = '" << m.get_trailer() << "'>Link</a></td>\n";
    }
    fin << "</tr>\n</table>\n</body>\n</html>";
    //fin.close();
}