#pragma once
#include "Coin.h"

class GermanCoin:public Coin
{
public:
	GermanCoin();
	void valueating(Coin& other_coin);
	void flip();
};

