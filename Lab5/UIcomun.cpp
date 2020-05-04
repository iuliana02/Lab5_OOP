#include "UIcomun.h"
#include "Repository.h"
#include <iostream>
using namespace std;

UIcomun::UIcomun()
{
//	repo.zehn_eintrage();
}

void UIcomun::menu_final()
{
	cout << "\tMoviesApp app\n\n";
	cout << "1.Administratormodus\n";
	cout << "2.Benutzermodus\n";
	cout << "0.Exit\n\n";
}

void UIcomun::menu()
{
	//repo.zehn_eintrage();
	
	menu_final();
	cout << "Wahlen Sie den Modus\n";
	int optiune;
	cin >> optiune;
	while (true)
	{
		switch (optiune)
		{
		case 1:
		{
			UIAdministrator uiA;
			uiA.optiuni();
			break;
		}
		case 2:
		{
			UIBenutzer uiB;
			uiB.optiuni();
			break;
		}
		default:
			return;
		}
	}
}