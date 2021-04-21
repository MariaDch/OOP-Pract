#include "FireCard.h"
#include <iostream>
#include <cstring>

void FireCard::copy(const FireCard& other_fireCard)
{
	FireCardName = new char[strlen(other_fireCard.FireCardName) + 1];
	strcpy_s(FireCardName, strlen(other_fireCard.FireCardName) + 1, other_fireCard.FireCardName);
	power = other_fireCard.power;
	bonusPower = other_fireCard.bonusPower;
}

void FireCard::erase()
{
	delete[] FireCardName;
}

FireCard::FireCard()
{
	FireCardName = new char[6];
	strcpy_s(FireCardName, 6, "Empty");
	power = 0;
	bonusPower = 0;
}

FireCard::FireCard(const FireCard& other_fireCard)
{
	this->copy(other_fireCard);
}

FireCard& FireCard::operator=(const FireCard& other_fireCard)
{
	if (this != &other_fireCard)
	{
		this->erase();
		this->copy(other_fireCard);
	}
	return *this;
}

bool FireCard::operator==(const FireCard& other_earthCard)
{
	for (size_t i = 0; FireCardName[i] != '\0'; i++)
	{
		if (FireCardName[i] != other_earthCard.FireCardName[i])
			return false;
	}
	return true;
}

FireCard::~FireCard()
{
	this->erase();
}

void FireCard::setFireCardName(const char* _fireCardName)
{
	delete[] FireCardName;
	FireCardName = new char[strlen(_fireCardName) + 1];
	strcpy_s(FireCardName, strlen(_fireCardName) + 1, _fireCardName);
}

void FireCard::setpower(size_t _power)
{
	power = _power;
}

void FireCard::setBonusPower(size_t _bonusPower)
{
	bonusPower = _bonusPower;
}

const char* FireCard::getFireCardName() const
{
	return FireCardName;
}

size_t FireCard::getPower() const
{
	return power;
}

size_t FireCard::getBonusPower() const
{
	return bonusPower;
}

void FireCard::printCard()const
{
	std::cout << FireCardName;
	std::cout << std::endl;
	std::cout << power;
	std::cout << std::endl;
	std::cout << bonusPower;
	std::cout << std::endl;
	std::cout << type;
	std::cout << std::endl;
}