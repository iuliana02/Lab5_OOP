#include "UIBenutzer.h"
#include <iostream>

UIBenutzer::UIBenutzer() {
	//repo.zehn_eintrage();
}

void UIBenutzer::meniu()
{
	cout << "\t Benutzermodus \n\n";
	cout << "1.Ansehen der Filme nach Genre + Trailer\n";
	cout << "2.Loschen eines Films aus der Watchliste\n";
	cout << "3.Anzeigen der Watchliste\n";
	cout << "0.Exit\n\n";
}

void UIBenutzer::optiuni()
{
	UIcomun ui;
	ControllerBenutzer ctrl;
	while (true)
	{
		meniu();

		int optiune;
		cout << "Wahlen sie eine Option\n";
		cin >> optiune;
		switch (optiune)
		{
		default:
			return;

		case 1:
		{
			ctrl.view_by_genre();
			break;
		}
		case 2:
		{
			ctrl.remove_film();
			break;
		}
		case 3:
		{
			ctrl.show_watchliste();
			break;
		}
		}
	}
}