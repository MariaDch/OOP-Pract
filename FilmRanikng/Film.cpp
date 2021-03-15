#include "Film.h"

void Film::copy(const Film& first_film)
{
	nameOfTheFilm = new char[strlen(first_film.nameOfTheFilm) + 1];
	strcpy_s(nameOfTheFilm, strlen(first_film.nameOfTheFilm) + 1, first_film.nameOfTheFilm);
	nameOFTheDirector = new char[strlen(first_film.nameOFTheDirector) + 1];
	strcpy_s(nameOFTheDirector, strlen(first_film.nameOFTheDirector) + 1, first_film.nameOFTheDirector);
	numberOfAwards = first_film.numberOfAwards;
}

void Film::erase()
{
	delete[] this->nameOfTheFilm;
	delete[] this->nameOFTheDirector;
}


Film::Film()
{
	nameOfTheFilm = new char[13];

	nameOFTheDirector = new char[18];
	numberOfAwards = 6;
}


Film& Film::operator=(const Film& first_film)
{
	if (this != &first_film)
	{
		this->erase();
		this->copy(first_film);
	}
	return *this;
}

Film ::~Film()
{
	this->erase();
}  

void Film::setDirectorName(const char* _DirectorName)
{
	delete[] nameOFTheDirector;
	nameOFTheDirector = new char[strlen(_DirectorName) + 1];
	strcpy_s(nameOFTheDirector, strlen(_DirectorName) + 1, _DirectorName);
}

void Film::setFilmName(const char* _FilmName)
{
	delete[] nameOfTheFilm;
	nameOfTheFilm = new char[strlen(_FilmName) + 1];
	strcpy_s(nameOfTheFilm, strlen(_FilmName) + 1, _FilmName);
}

void Film::setNumberOfAwards(int _AwardsNumer)
{
	numberOfAwards = _AwardsNumer;
}

const char* Film::getNameOfTheDirector()const
{
	return nameOFTheDirector;
}

const char* Film::getNameOfTheFilm()const
{
	return nameOfTheFilm;
}

int Film::getNumberOfAwards()const
{
	return numberOfAwards;
}

void Film::print()const
{
	std::cout << nameOfTheFilm << std::endl;
	std::cout << nameOFTheDirector << std::endl;
	std::cout << numberOfAwards << std::endl;
}

Film::Film(const Film& first_film)
{
	this->copy(first_film);
}