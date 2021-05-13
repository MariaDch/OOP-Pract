#include "Coin.h"

Coin::Coin()
{
	nationality = new char[6];
	strcpy_s(nationality, 6, "Empty");
	sideOfTheCoin = HEADS;
	value = 0;
}

Coin::~Coin()
{
	delete[] nationality;
}

void Coin::setNationality(const char* other_nationality)
{
	delete[] nationality;
	nationality = new char[strlen(other_nationality) + 1];
	strcpy_s(nationality, strlen(other_nationality) + 1, other_nationality);
}

void Coin::setValue(double other_value)
{
	value = other_value;
}

void Coin::setFace(face other_sideOfTheCoin)
{
	sideOfTheCoin = other_sideOfTheCoin;
}

const char* Coin::getNAtionality()
{
	return nationality;
}

double Coin::getValue()
{
	return value;
}

face Coin::getFace()
{
	return sideOfTheCoin;
}

Coin& Coin::operator=(const Coin& other_Coin)
{
	if (this != &other_Coin)
	{
		delete[] nationality;
		nationality = new char[strlen(other_Coin.nationality) + 1];
		strcpy_s(nationality, strlen(other_Coin.nationality) + 1, other_Coin.nationality);
		value = other_Coin.value;
		sideOfTheCoin = other_Coin.sideOfTheCoin;

	}
	return *this;
}

void Coin::flip()                 
{
	if (rand() % 100 < 50)
	{
		std::cout << (rand() % 100);
		std::cout << std::endl;
		sideOfTheCoin = HEADS;
	}
	else
	{
		sideOfTheCoin = TAILS;
	}
}

void Coin::print() const
{
	for (int i = 0; i < strlen(nationality); i++)
	{
		std::cout << nationality[i];
	}

	std::cout<<std::endl;
	if (sideOfTheCoin == 0)
		std::cout << "Head";
	else std::cout << "Tail";

	std::cout << std::endl;
	std::cout << value;
}


