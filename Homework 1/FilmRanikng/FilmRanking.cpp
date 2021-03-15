#include "FilmRanking.h"
#include "Film.h"
#include <cstring>

void FilmRanking::eraseFilmRanking()
{
	delete[] films;
}

void FilmRanking::copyFilmRanking(const FilmRanking& other_filmRanking)
{
	size = other_filmRanking.size;
	films = new Film[size+1];
}

FilmRanking::FilmRanking()
{
	films = new Film[size+1];
}

FilmRanking::FilmRanking(const FilmRanking& other_filmRanking)
{
	this->copyFilmRanking(other_filmRanking);
}

FilmRanking& FilmRanking::operator=(const FilmRanking& other_filmRanking)

{
	if (this != &other_filmRanking)
	{
		this->copyFilmRanking(other_filmRanking);
		this->eraseFilmRanking();
	}
	return *this;
}

FilmRanking::~FilmRanking()
{
	this->eraseFilmRanking();
}

void FilmRanking::setSize(int _size)
{
	size = _size;
}

void FilmRanking::setFilms(Film* _films)
{
	for (int i = 0; i < size; i++)
	{
		films[i] = _films[i];
	}
}

Film FilmRanking::getFilms()const
{
	return *films;
}

int FilmRanking::getSize()const
{
	return size;
}

void FilmRanking::sortFilms(Film* films, int size)
{
	Film helper;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (films[j].numberOfAwards > films[j + 1].numberOfAwards)
			{
				helper = films[j + 1];
				films[j + 1] = films[j];
				films[j] = helper;
			}
		}
	}
}

void FilmRanking::printTopFilms(int n)
{
	n = 0;
	std::cout << "Input how films do you want to see the top of: " << std::endl;
	std::cin >> n;

	for (int i = 0; i < n; i++)	{
		std::cout << i + 1 << ". ";
		std::cout << films[i].nameOfTheFilm << std::endl;
		std::cout << films[i].nameOFTheDirector << std::endl;
		std::cout << films[i].numberOfAwards << std::endl;
	}
}
