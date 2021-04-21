#include "WindCard.h"
#include <iostream>
#include <cstring>

void WindCard::copy(const WindCard& other_earthCard)
{
	WindCardName = new char[strlen(other_earthCard.WindCardName) + 1];
	strcpy_s(WindCardName, strlen(other_earthCard.WindCardName) + 1, other_earthCard.WindCardName);
	power = other_earthCard.power;
	bonusPower = other_earthCard.bonusPower;
}

void WindCard::erase()
{
	delete[] WindCardName;
}

WindCard::WindCard()
{
	WindCardName = new char[6];
	strcpy_s(WindCardName, 6, "Empty");
	power = 0;
	bonusPower = 0;
}

WindCard::WindCard(const WindCard& other_earthCard)
{
	this->copy(other_earthCard);
}

WindCard& WindCard::operator=(const WindCard& other_earthCard)
{
	if (this != &other_earthCard)
	{
		this->erase();
		this->copy(other_earthCard);
	}
	return *this;
}

bool WindCard::operator==(const WindCard& other_earthCard)
{
	for (size_t i = 0; WindCardName[i] != '\0'; i++)
	{
		if (WindCardName[i] != other_earthCard.WindCardName[i])
			return false;
	}
	return true;
}

WindCard::~WindCard()
{
	this->erase();
}

void WindCard::setWindCardName(const char* _name)
{
	delete[] WindCardName;
	WindCardName = new char[strlen(_name) + 1];
	strcpy_s(WindCardName, strlen(_name) + 1, _name);
}

void WindCard::setPower(size_t _power)
{
	power = _power;
}

void WindCard::setBonusPower(size_t _bonusPower)
{
	bonusPower = _bonusPower;
}

const char* WindCard::getName() const
{
	return WindCardName;
}

size_t WindCard::getPower() const
{
	return power;
}

size_t WindCard::getBonusPower() const
{
	return bonusPower;
}

void WindCard::printCard() const
{
	std::cout << WindCardName;
	std::cout << std::endl;
	std::cout << power;
	std::cout << std::endl;
	std::cout << bonusPower;
	std::cout << std::endl;
	std::cout << type;
	std::cout << std::endl;
}
