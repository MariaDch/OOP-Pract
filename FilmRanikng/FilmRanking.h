#pragma once
#include <iostream>
#include "Film.h"
#include <cstring>

class FilmRanking
{
private:
	int size = 200;
	Film* films=new Film [size+1]; 

	void eraseFilmRanking();
	void copyFilmRanking(const FilmRanking& other_filmRanking);

public:
	FilmRanking();
	FilmRanking(const FilmRanking& other_filmRanking);
	FilmRanking& operator=(const FilmRanking& other_FilmRanking);
	~FilmRanking();

	void setSize(int _size); 
	void setFilms(Film* films);

	Film getFilms() const;
	int getSize() const;

	void sortFilms(Film* films, int size);
	void printTopFilms(int m);
};

