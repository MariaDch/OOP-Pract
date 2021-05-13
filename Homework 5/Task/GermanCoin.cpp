#include "GermanCoin.h"
GermanCoin::GermanCoin() : Coin()
{
	strcpy_s(nationality, 3, "DE");
}

void GermanCoin::valueating(Coin& other_coin)
{
	if (other_coin.getNAtionality()[0] == 'B' && other_coin.getNAtionality()[1] == 'G')
	{
		std::cout << value << " German coins = " << value / 6 << "Bulgarian coins.";
		std::cout << std::endl;
		return;
	}
	if (other_coin.getNAtionality()[0] == 'U' && other_coin.getNAtionality()[1] == 'S')
	{
		std::cout << value << " German coins = " << value * (2/5) << "American coins.";
		std::cout << std::endl;
		return;
	}
	else
	{
		std::cout << value << "German coins = " << value << "German coins.";
		std::cout << std::endl;
	}
}

void GermanCoin::flip()
{
	if (rand() % 100 < 50)
	{
		sideOfTheCoin = HEADS;
	}
	else
	{
		sideOfTheCoin = TAILS;
	}
}