#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5/Film.h"
#include "../Lab5/Repository.h"
#include "../Lab5/Validation.h"
#include "../Lab5/Watchlist.h"
#include "../Lab5/Controller.h"
#include "../Lab5/UI.h"
#include "../Lab5/Watchlist.h"
#include "../Lab5/Exceptions.h"
#include "../Lab5/Others.h"
#include "../Lab5/csvWatchlist.h"



#include <string>
#include <vector>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestss
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestConstructorFilm)
		{
			auto film = new Film("a", "b", 2000, 150, "www");
			Assert::AreEqual(string("a"), film->get_titel());
			Assert::AreEqual(string("b"), film->get_genre());
			Assert::AreEqual(2000, film->get_erscheinungsjahr());
			Assert::AreEqual(150, film->get_likes());
			Assert::AreEqual(string("www"), film->get_trailer());
		}

		TEST_METHOD(TestRepository)
		{
			const string& filename = "file.txt";
			auto repo = new Repository(filename);
			vector <Film> films = repo->get_movies();
			Assert::AreEqual(films[0].get_titel(), string ("Titanic"));
			Assert::AreEqual(films[0].get_genre(), string("Drama"));
			Assert::AreEqual(films[0].get_erscheinungsjahr(), 1997);
			Assert::AreEqual(films[0].get_likes(), 1000);
			Assert::AreEqual(films[0].get_trailer(), string("https://www.youtube.com/watch?v=kVrqfYjkTdQ"));
		}


		TEST_METHOD(TestController)
		{

		}

		TEST_METHOD(TestUI)
		{

		}

		TEST_METHOD(TestWatchlist)
		{
			auto wlist = new Watchlist();
			Assert::AreEqual(wlist->current, 0);
			Assert::AreEqual(wlist->isEmpty(), true);

			Film f = Film("a", "b", 1, 2, "https.m");
			wlist->add(f);
			Assert::AreEqual(wlist->size(), 1);

			Film f2 = wlist->getCurrentMovie();
			Assert::AreEqual(f2.get_titel(), string("a"));
			Assert::AreEqual(f2.get_genre(), string("b"));
			Assert::AreEqual(f2.get_erscheinungsjahr(), 1);
			Assert::AreEqual(f2.get_likes(), 2);
			Assert::AreEqual(f2.get_trailer(), string("https.m"));

			Assert::AreEqual(wlist->isEmpty(),false);

			Film f3= Film("aa", "bb", 11, 22, "https.mm");
			wlist->add(f3);
			Assert::AreEqual(wlist->size(), 2);

		}

		TEST_METHOD(TestOthers)
		{
			const string& s = "  unu doi ";
			const string& r = "unu doi";
			Assert::AreEqual(trim(s), r);
		}

		TEST_METHOD(TestCsvWatchlist)
		{
			auto csv = new csvWatchlist();
		}

		TEST_METHOD(TestExceptions)
		{
			const string& msg = "mesaj";
			auto fileEx = FileException(msg);
			const char* ms = "mesaj";
			Assert::AreEqual(fileEx.what(), ms);
		}
			

	};
}
