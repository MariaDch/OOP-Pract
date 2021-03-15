#include <iostream>
#include "Film.h"

int main()
{
	Film f1;
	f1.setFilmName("Intersteller");
	f1.setDirectorName("Maria Chervenkova");
	f1.setNumberOfAwards(10);

	f1.print();
}