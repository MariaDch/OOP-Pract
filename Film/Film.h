#pragma once
#include <iostream>

class Film
{
private:

	void copy(const Film& first_film);
	void erase();

public:
	char* nameOfTheFilm;
	char* nameOFTheDirector;
	int numberOfAwards;

	Film();
	Film(const Film& first_film);
	Film& operator=(const Film& first_film);
	~Film();

	void setDirectorName(const char* _DirectorName);
	void setFilmName(const char* _filmNname);
	void setNumberOfAwards(int _awardsNumber);

	const char* getNameOfTheFilm()const;
	const char* getNameOfTheDirector()const;
	int getNumberOfAwards()const;

	void print()const;
};