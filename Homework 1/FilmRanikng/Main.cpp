#include <iostream>
#include "Film.h"
#include "FilmRanking.h"

int main()
{
	int n = 3;
	int size = 200;

	Film firstfilm;
	firstfilm.setFilmName("Intersteller");
	firstfilm.setDirectorName("George Freeman");
	firstfilm.setNumberOfAwards(7);

	Film secondfilm;
	secondfilm.setFilmName("After");
	secondfilm.setDirectorName("Ann Todd");
	secondfilm.setNumberOfAwards(5);

	Film thirdfilm;
	thirdfilm.setFilmName("Fast & furious 10000");
	thirdfilm.setDirectorName("Harry Potter");
	thirdfilm.setNumberOfAwards(9);

	FilmRanking ttreefilms;
	Film* films = new Film[3];
	films[0] = firstfilm;
	films[1] = secondfilm;
	films[2] = thirdfilm;

	ttreefilms.setSize(size);
	ttreefilms.setFilms(films);
	n = ttreefilms.getSize();
	ttreefilms.printTopFilms(n);
}