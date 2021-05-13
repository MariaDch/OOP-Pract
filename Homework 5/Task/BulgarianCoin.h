#pragma once
#include "Coin.h"

class BulgarianCoin : public Coin
{
public:
	BulgarianCoin();
	void valueating(Coin& other_coin);
	void flip();
};

