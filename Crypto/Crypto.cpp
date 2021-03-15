#include "Crypto.h"
#include <cstring>
#include <iostream>

Crypto::Crypto()
{
	strcpy_s(name, 8, "Bitcoin");
	lastPrice = 5678.63;
	currentPrice = 5789.12;
}

Crypto::Crypto(const Crypto& anotherCrypto)
{
	strcpy_s(name, strlen(anotherCrypto.name) + 1, anotherCrypto.name);
	lastPrice = anotherCrypto.lastPrice;
	currentPrice = anotherCrypto.currentPrice;
}

void Crypto::setName(const char* _name)
{
	strcpy_s(name, strlen(_name) + 1, _name);
}

void Crypto::setCurrentPrice(double _currentPrice)
{
	currentPrice = _currentPrice;
}

void Crypto::setLastPrice(double _lastPrice)
{
	lastPrice = _lastPrice;
}

const char* Crypto::getName() const
{
	return name;
}

double Crypto::getCurrentPrice() const
{
	return currentPrice;
}

double Crypto::getLastPrice() const
{
	return lastPrice;
}

void Crypto::print() const
{
	std::cout << name << std::endl;
	std::cout << lastPrice << std::endl;
	std::cout << currentPrice << std::endl;
}

void Crypto::priceDifference() const
{
	if (lastPrice<currentPrice)
	{
		double difference = (currentPrice - lastPrice) * 100 / lastPrice;
		std::cout << difference << "% higher" << std::endl;
	}
	else
	{
		double difference = (lastPrice - currentPrice) * 100 / lastPrice;
		std::cout <<difference <<"% lower" <<std::endl;
	}
}

