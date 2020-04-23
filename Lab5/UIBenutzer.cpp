#include "UIBenutzer.h"
#include <iostream>

UIBenutzer::UIBenutzer() {}

void UIBenutzer::meniu()
{
	cout << "\t Benutzermodus \n";
	cout << "0.Exit\n";
	cout << "1.Ansehen der Filme nach Genre + Trailer\n";
	cout << "2.Loschen eines Films aus der Watchliste\n";
	cout << "3.Anzeigen der Watchliste\n";
}

void UIBenutzer::optiuni()
{
	ControllerBenutzer ctrl;
	meniu();
	int optiune;
	cout << "Wahlen sie eine Option\n";
	cin >> optiune;
	switch (optiune)
	{
	case 0:
		break;

	case 1:
		ctrl.view_by_genre();

	case 2:
		ctrl.remove_film();

	case 3:
		ctrl.show_watchliste();

	}
}