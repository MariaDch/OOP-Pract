#include "AmericanCoin.h"

AmericanCoin::AmericanCoin() : Coin()
{
	strcpy_s(nationality, 3, "US");
}

void AmericanCoin::valueating(Coin& other_coin)
{
	if (other_coin.getNAtionality()[0]=='B' && other_coin.getNAtionality()[1] == 'G')
	{
		std::cout << value << " American coins = " << value / 3 << "Bulgarian coins.";
		std::cout << std::endl;
		return;
	}
	if (other_coin.getNAtionality()[0] == 'D' && other_coin.getNAtionality()[1] == 'E')
	{
		std::cout << value << " American coins = " << value * 2.5 << "German coins.";
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << value << "American coins = " << value << "American coins.";
		std::cout << std::endl;
	}
}

void AmericanCoin::flip()
{
	if (rand() % 100 < 90)
	{
		sideOfTheCoin = HEADS;
	}
	else
	{
		sideOfTheCoin = TAILS;
	}
}

