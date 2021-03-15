#pragma once
#include <iostream>

class Crypto
{
private:
	char name[30];
	double lastPrice;
	double currentPrice;

public:
	Crypto();
	Crypto(const Crypto& anotherCrypto);

	void setName(const char* _name);
	void setLastPrice(double _lastPrice);
	void setCurrentPrice(double _currentPrice);

	const char* getName() const;
	double getLastPrice() const;
	double getCurrentPrice() const;

	void print() const;
	void priceDifference() const;
};

