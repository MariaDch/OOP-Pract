#include "Product.h"

Product::Product()
{
	bought = false;
	chance = HEADS;
	nameOfProduct = new char[6];
	strcpy_s(nameOfProduct, 6, "Empty");
	price = 0;
	percentSale = 0;
}

Product::Product(const char* name, double _price, double _percent)
{
	bought = false;
	chance = HEADS;
	nameOfProduct = new char[strlen(name)+1];
	strcpy_s(nameOfProduct, strlen(name) + 1, name);
	price = _price;
	percentSale = _percent;
}

Product::Product(Product& other)
{
	bought = false;
	chance = other.chance;
	nameOfProduct = new char[strlen(other.nameOfProduct) + 1];
	strcpy_s(nameOfProduct, strlen(other.nameOfProduct) + 1, other.nameOfProduct);
	price = other.price;
	percentSale = other.percentSale;
}

Product::~Product()
{
	delete[] nameOfProduct;
}

void Product::setChance(int _chance)
{
	if (_chance == 0)
	{
		chance = HEADS;
	}
	else
		chance = TAILS;
}

void Product::setNameOfProduct(const char* name)
{
	delete[] nameOfProduct;
	nameOfProduct = new char[strlen(name) + 1];
	strcpy_s(nameOfProduct, strlen(name) + 1, name);
}

void Product::setPrice(double _price)
{
	price = _price;
}

void Product::setPercentSale(double percent)
{
	percentSale = percent;
}

void Product::setBought(bool haveBeenBought)
{
	bought = haveBeenBought;
}

double Product::getPrice()
{
	return price;
}

double Product::getPercentSale()
{
	return percentSale;
}

int Product::getChance()
{
	return chance;
}

char* Product::getNAmeOfPRoduct()
{
	return nameOfProduct;
}

bool Product::getBought()
{
	return bought;
}
