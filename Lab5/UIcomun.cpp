#include "UIcomun.h"
#include "Repository.h"

#include <iostream>
using namespace std;

UIcomun::UIcomun()
{
	repo = Repository();
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
	UIAdministrator uiA;
	UIBenutzer uiB;
	while (true)
	{
		menu_final();
		cout << "Wahlen Sie den Modus\n";
		int optiune;
		cin >> optiune;
		if(optiune!=0)
		{ 
			switch (optiune)
			{
			case 1:
			{
				uiA.optiuni();
				break;
			}
			case 2:
			{
				uiB.optiuni();
				break;
			}
			/*default:
			{
				return;
			}*/
			}
		}
		else if (optiune == 0) { break; }
	}
}