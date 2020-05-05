#pragma once
#include "UIAdministrator.h"
#include "UIBenutzer.h"
#include "Repository.h"

class UIcomun
{
	friend class UIAdministrator;
	friend class UIBenutzer;

private:
	Repository repo;

public:

	UIcomun();

	void menu_final();
	void menu();
};

