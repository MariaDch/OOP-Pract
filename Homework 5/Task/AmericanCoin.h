#pragma once
#include "Coin.h"
#include <cstring>

class AmericanCoin :public Coin
{
public:
	AmericanCoin();
	void valueating(Coin &other_coin);
	void flip();
};

