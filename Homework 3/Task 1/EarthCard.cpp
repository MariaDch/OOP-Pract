#include "EarthCard.h"
#include <iostream>
#include <cstring>

void EarthCard::copy(const EarthCard& other_earthCard)
{
	EarthCardName = new char[strlen(other_earthCard.EarthCardName) + 1];
	strcpy_s(EarthCardName, strlen(other_earthCard.EarthCardName) + 1, other_earthCard.EarthCardName);
	power = other_earthCard.power;
	bonusPower = other_earthCard.bonusPower;
}

void EarthCard::erase()
{
	delete[] EarthCardName;
}

EarthCard::EarthCard()
{
	EarthCardName = new char[6];
	strcpy_s(EarthCardName, 6, "Empty");
	power = 0;
	bonusPower = 0;
}

EarthCard::EarthCard(const EarthCard& other_earthCard)
{
	this->copy(other_earthCard);
}

EarthCard& EarthCard::operator=(const EarthCard& other_earthCard)
{
	if (this != &other_earthCard)
	{
		this->erase();
		this->copy(other_earthCard);
	}
	return *this;
}

bool EarthCard::operator==(const EarthCard& other_earthCard)
{
	for (size_t i = 0; EarthCardName[i] != '\0'; i++)
	{
		if (EarthCardName[i] != other_earthCard.EarthCardName[i])
			return false;
	}
	return true;
}

EarthCard::~EarthCard()
{
	this->erase();
}

void EarthCard::setEarthCardName(const char* _name)
{
	delete[] EarthCardName;
	EarthCardName = new char[strlen(_name) + 1];
	strcpy_s(EarthCardName, strlen(_name) + 1, _name);
}

void EarthCard::setPower(size_t _power)
{
	power = _power;
}

void EarthCard::setBonusPower(size_t _bonusPower)
{
	bonusPower = _bonusPower;
}

const char* EarthCard::getName() const
{
	return EarthCardName;
}

size_t EarthCard::getPower() const
{
	return power;
}

size_t EarthCard::getBonusPower() const
{
	return bonusPower;
}

void EarthCard::printCard() const
{
	std::cout << EarthCardName;
	std::cout << std::endl;
	std::cout << power;
	std::cout << std::endl;
	std::cout << bonusPower;
	std::cout << std::endl;
	std::cout << type;
	std::cout << std::endl;
}
