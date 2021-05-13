#include "Buyer.h"

Buyer::Buyer(Vector<AmericanCoin> _americanCoinsBag, Vector<BulgarianCoin> _bulgarianCoinsBag, Vector<GermanCoin> _germanCoinsBag)
{
	americanCoinsBag = _americanCoinsBag;
	bulgarianCoinsBag = _bulgarianCoinsBag;
	germanCoinsBag = _germanCoinsBag;
}

Buyer::Buyer(const Buyer& other_buyer)
{
	americanCoinsBag = other_buyer.americanCoinsBag;
	bulgarianCoinsBag = other_buyer.bulgarianCoinsBag;
	germanCoinsBag = other_buyer.germanCoinsBag;
}

void Buyer::addCoinsAmerican(AmericanCoin coin)
{
	americanCoinsBag.pushBack(coin);
}

void Buyer::addCoinsBulgarian(BulgarianCoin coin)
{
	bulgarianCoinsBag.pushBack(coin);
}

void Buyer::addCoinsGerman(GermanCoin coin)
{
	germanCoinsBag.pushBack(coin);
}

void Buyer::removeCoinsAmerican(size_t index)
{
	americanCoinsBag.removeElement(index);
}

void Buyer::removeCoinsBulgarian(size_t index)
{
	bulgarianCoinsBag.removeElement(index);
}

void Buyer::removeCoinsGerman(size_t index)
{
	germanCoinsBag.removeElement(index);
}

void Buyer::buy(Product product)
{
	int randNum2 = rand() % 2;

	if (randNum2 == 0)
	{
		product.setChance(0);
	}
	else
		product.setChance(1);

	int randomNum = rand() % 3;
	if (randomNum == 0)
	{

		americanCoinsBag[0].flip();
		if (americanCoinsBag[0].getFace() == product.getChance())
		{
			if (americanCoinsBag[0].getValue() > product.getPrice() * (product.getPercentSale() / 100))
			{
				std::cout << "You will buy the product cheaper!";
				americanCoinsBag[0].setValue(americanCoinsBag[0].getValue() - product.getPrice() * (product.getPercentSale() / 100));
				product.setBought(true);
				return;
			}
			if (americanCoinsBag[0].getValue() == product.getPrice() * (product.getPercentSale() / 100))
			{
				std::cout << "You will buy the product cheaper!";
				removeCoinsAmerican(americanCoinsBag.getSize());
				product.setBought(true);
				return;
			}
			if (americanCoinsBag[0].getValue() < product.getPrice() * (product.getPercentSale() / 100))
			{
				double leftPrice = 0;
				std::cout << "You will buy the product cheaper!";
				leftPrice = product.getPrice() * (product.getPercentSale() / 100) - americanCoinsBag[0].getValue();
				removeCoinsAmerican(0);
				americanCoinsBag[0].setValue(americanCoinsBag[0].getValue() - leftPrice);
				product.setBought(true);
				return;
			}
		}
		else
		{
			if (americanCoinsBag[0].getValue() > product.getPrice())
			{
				std::cout << "You will buy the product without the sale!";
				americanCoinsBag[0].setValue(americanCoinsBag[0].getValue() - product.getPrice() * (product.getPercentSale() / 100));
				product.setBought(true);
				return;
			}
			if (americanCoinsBag[0].getValue() == product.getPrice())
			{
				std::cout << "You will buy the product without the sale!";
				removeCoinsAmerican(0);
				product.setBought(true);
				return;
			}
			if (americanCoinsBag[0].getValue() < product.getPrice())
			{
				double leftPrice = 0;
				std::cout << "You will buy the product without the sale!";
				leftPrice = product.getPrice() * (product.getPercentSale() / 100) - americanCoinsBag[0].getValue();
				removeCoinsAmerican(0);
				americanCoinsBag[0].setValue(americanCoinsBag[0].getValue() - leftPrice);
				product.setBought(true);
				return;
			}
		}

	}

	if (randomNum == 1)
	{
		bulgarianCoinsBag[0].flip();
		if (bulgarianCoinsBag[0].getFace() == product.getChance())
		{
			if (bulgarianCoinsBag[0].getValue() > product.getPrice() * (product.getPercentSale() / 100))
			{
				std::cout << "You will buy the product cheaper!";
				bulgarianCoinsBag[0].setValue(bulgarianCoinsBag[0].getValue() - product.getPrice() * (product.getPercentSale() / 100));
				product.setBought(true);
			}
			else if (bulgarianCoinsBag[0].getValue() == product.getPrice() * (product.getPercentSale() / 100))
			{
				std::cout << "You will buy the product cheaper!";
				removeCoinsBulgarian(bulgarianCoinsBag.getSize());
				product.setBought(true);
			}
			else if (bulgarianCoinsBag[0].getValue() < product.getPrice() * (product.getPercentSale() / 100))
			{
				double leftPrice = 0;
				std::cout << "You will buy the product cheaper!";
				leftPrice = product.getPrice() * (product.getPercentSale() / 100) - bulgarianCoinsBag[0].getValue();
				removeCoinsBulgarian(0);
				bulgarianCoinsBag[0].setValue(bulgarianCoinsBag[0].getValue() - leftPrice);
				product.setBought(true);
			}
		}
		else
		{
			if (bulgarianCoinsBag[0].getValue() > product.getPrice())
			{
				std::cout << "You will buy the product without the sale!";
				bulgarianCoinsBag[0].setValue(bulgarianCoinsBag[0].getValue() - product.getPrice() * (product.getPercentSale() / 100));
				product.setBought(true);
				return;
			}
			if (bulgarianCoinsBag[0].getValue() == product.getPrice())
			{
				std::cout << "You will buy the product without the sale!";
				removeCoinsBulgarian(0);
				product.setBought(true);
				return;
			}
			if (bulgarianCoinsBag[0].getValue() < product.getPrice())
			{
				double leftPrice = 0;
				std::cout << "You will buy the product without the sale!";
				leftPrice = product.getPrice() * (product.getPercentSale() / 100) - bulgarianCoinsBag[0].getValue();
				removeCoinsBulgarian(0);
				bulgarianCoinsBag[0].setValue(bulgarianCoinsBag[0].getValue() - leftPrice);
				product.setBought(true);
				return;
			}
		}
	}

	if (randomNum == 2)
	{
		germanCoinsBag[germanCoinsBag.getSize()].flip();
		if (germanCoinsBag[0].getFace() == product.getChance())
		{
			if (germanCoinsBag[0].getValue() > product.getPrice() * (product.getPercentSale() / 100))
			{
				std::cout << "You will buy the product cheaper!";
				germanCoinsBag[0].setValue(germanCoinsBag[0].getValue() - product.getPrice() * (product.getPercentSale() / 100));
				product.setBought(true);
			}
			else if (germanCoinsBag[0].getValue() == product.getPrice() * (product.getPercentSale() / 100))
			{
				std::cout << "You will buy the product cheaper!";
				removeCoinsGerman(0);
				product.setBought(true);
			}
			else if (germanCoinsBag[0].getValue() < product.getPrice() * (product.getPercentSale() / 100))
			{
				double leftPrice = 0;
				std::cout << "You will buy the product cheaper!";
				leftPrice = product.getPrice() * (product.getPercentSale() / 100) - germanCoinsBag[0].getValue();
				removeCoinsGerman(0);
				germanCoinsBag[0].setValue(germanCoinsBag[0].getValue() - leftPrice);
				product.setBought(true);
			}
		}
		else
		{
			if (germanCoinsBag[0].getValue() > product.getPrice())
			{
				std::cout << "You will buy the product without the sale!";
				germanCoinsBag[0].setValue(germanCoinsBag[0].getValue() - product.getPrice());
				product.setBought(true);
				return;
			}
			if (germanCoinsBag[0].getValue() == product.getPrice())
			{
				std::cout << "You will buy the product without the sale!";
				removeCoinsGerman(0);
				product.setBought(true);
				return;
			}
			if (germanCoinsBag[0].getValue() < product.getPrice() )
			{
				double leftPrice = 0;
				std::cout << "You will buy the product without the sale!";
				leftPrice = product.getPrice()- germanCoinsBag[0].getValue();
				removeCoinsGerman(0);
				germanCoinsBag[0].setValue(germanCoinsBag[0].getValue() - leftPrice);
				product.setBought(true);
				return;
			}
		}
	}
}

void Buyer::printBoughtProducts(Vector<Product> products) const
{
	for (int i = 0; i < products.getSize(); i++)
	{
		if (products[i].getBought() == true)
		{
			std::cout << products[i].getNAmeOfPRoduct() << " " << products[i].getPrice() << " " << products[i].getPercentSale() << std::endl;
		}
	}
}