#include "BulgarianCoin.h"

BulgarianCoin::BulgarianCoin() : Coin()
{
	strcpy_s(nationality, 3, "BG");
}

void BulgarianCoin::valueating(Coin& other_coin)
{
	if (other_coin.getNAtionality()[0] == 'U' && other_coin.getNAtionality()[1] == 'S')
	{
		std::cout << value << " Bulgarian coins = " << value * 3 << "American coins.";
		std::cout << std::endl;
		return;
	}
	if (other_coin.getNAtionality()[0] == 'D' && other_coin.getNAtionality()[1] == 'E')
	{
		std::cout << value << " Bulgarian coins = " << value * 6 << "German coins.";
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << value << "Bulgarian coins = " << value << "Bulgarian coins.";
		std::cout << std::endl;
	}
}

void BulgarianCoin::flip()
{
	if (rand() % 100 < 30)
	{
		sideOfTheCoin = HEADS;
	}
	else
	{
		sideOfTheCoin = TAILS;
	}
}