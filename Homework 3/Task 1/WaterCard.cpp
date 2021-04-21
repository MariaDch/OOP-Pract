#include "WaterCard.h"
#include <iostream>
#include <cstring>

void WaterCard::copy(const WaterCard& other_waterCard)
{
	WaterCardName = new char[strlen(other_waterCard.WaterCardName) + 1];
	strcpy_s(WaterCardName, strlen(other_waterCard.WaterCardName) + 1, other_waterCard.WaterCardName);
	power = other_waterCard.power;
	bonusPower = other_waterCard.bonusPower;
}

void WaterCard::erase()
{
	delete[] WaterCardName;
}

WaterCard::WaterCard()
{
	WaterCardName = new char[6];
	strcpy_s(WaterCardName, 6, "Empty");
	power = 0;
	bonusPower = 0;
}

WaterCard::WaterCard(const WaterCard& other_waterCard)
{
	this->copy(other_waterCard);
}

WaterCard& WaterCard::operator=(const WaterCard& other_waterCard)
{
	if (this != &other_waterCard)
	{
		this->erase();
		this->copy(other_waterCard);
	}
	return *this;
}

bool WaterCard::operator==(const WaterCard& other_earthCard)
{
	for (size_t i = 0; WaterCardName[i] != '\0'; i++)
	{
		if (WaterCardName[i] != other_earthCard.WaterCardName[i])
			return false;
	}
	return true;
}

WaterCard::~WaterCard()
{
	this->erase();
}

void WaterCard::setWaterCardName(const char* _waterCardName)
{
	delete[] WaterCardName;
	WaterCardName = new char[strlen(_waterCardName) + 1];
	strcpy_s(WaterCardName, strlen(_waterCardName) + 1, _waterCardName);
}

void WaterCard::setPower(size_t _power)
{
	power = _power;
}

void WaterCard::setBonusPower(size_t _bonusPower)
{
	bonusPower = _bonusPower;
}

const char* WaterCard::getWaterCardName() const
{
	return WaterCardName;
}

size_t WaterCard::getPower() const
{
	return power;
}

size_t WaterCard::getBonusPowe() const
{
	return bonusPower;
}

void WaterCard::printCard() const
{
	std::cout << WaterCardName;
	std::cout << std::endl;
	std::cout << power;
	std::cout << std::endl;
	std::cout << bonusPower;
	std::cout << std::endl;
	std::cout << type;
	std::cout << std::endl;
}