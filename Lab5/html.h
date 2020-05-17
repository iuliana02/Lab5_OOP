#pragma once
#ifndef html_h
#define html_h

#include "Watchlist.h"
#include "Repository.h"
#include <stdio.h>
#include <fstream>

class HTMLBuilder : public Watchlist {
public:
    void build_watchlist(vector <int> watchlist, Repository& repo);
};

#endif 