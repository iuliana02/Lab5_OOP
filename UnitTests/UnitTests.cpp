#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5/Film.h"
#include "../Lab5/Repository.h"
#include "../Lab5/Validation.h"
#include <string>
#include <vector>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
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

		TEST_METHOD(TestRepo)
		{
			auto repo = new Repository();
			size_t i = 5;
			size_t j = 0;
			Assert::AreEqual(repo->movies.size(), i);
			Assert::AreEqual(repo->watchliste.size(), j);

			Film film = Film("a", "b", 2000, 150, "www");
			repo->add_film(film);
			size_t k = 6;
			Assert::AreEqual(repo->movies.size(), k);

			repo->delete_film_repo("a");
			repo->delete_film_repo("Titanic");
			size_t l = 4;
			Assert::AreEqual(repo->movies.size(), l);
		}

		TEST_METHOD(TestModify)
		{
			auto repo = new Repository();
			Assert::AreEqual(repo->movies[0].get_titel(), string("Titanic"));
			Assert::AreEqual(repo->movies[0].get_genre(), string("Drama"));
			Assert::AreEqual(repo->movies[0].get_erscheinungsjahr(), 1997);

			repo->update_film("Titanic", "nou", 2005, 1234, "https.www.trailer_titanic");

			Assert::AreEqual(repo->movies[0].get_genre(), string("nou"));
			Assert::AreEqual(repo->movies[0].get_erscheinungsjahr(), 2005);

			Film f1 = Film("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			Assert::AreEqual(repo->movies[0].get_likes(), 1234);
			repo->update_likes(f1, 2050);
			Assert::AreEqual(repo->movies[0].get_likes(), 2050);

			vector<Film> aux = repo->nach_genre_anzeigen("Horror");
			Assert::AreEqual(aux.size(), size_t (1));
		}

		TEST_METHOD(TestValidation)
		{
			Validation v;
			Repository repo;
			bool actual = v.validate_string("string");
			bool expected = true;
			Assert::AreEqual(actual, expected);

			bool actual2 = v.validate_string("abc12");
			bool expected2 = false;
			Assert::AreEqual(actual, expected);

			bool actual3 = v.validate_int("1234");
			bool expected3 = true;
			Assert::AreEqual(actual3, expected3);

			Film f1 = Film("Titanic", "Drama", 1997, 1000, "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
			bool actual4 = v.validate_exist(repo.movies, f1);
			bool expected4 = true;
			Assert::AreEqual(actual4, expected4);

			Film f2 = Film("q", "w", 1111, 5555, "https://www.youtube.VrqfYjkTdQ");
			bool actual5 = v.validate_exist(repo.movies, f2);
			bool expected5 = false;
			Assert::AreEqual(actual5, expected5);

			bool actual6 = v.validate_titel("Focus");
			bool expected6 = true;
			Assert::AreEqual(actual6, expected6);

			bool actual7 = v.validate_titel("xyz");
			bool expected7 = false;
			Assert::AreEqual(actual7, expected7);
		}
	};
}
