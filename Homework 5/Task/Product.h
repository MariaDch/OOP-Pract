#pragma once
#include <cstring>


class Product
{
	enum side { HEADS, TAILS };
public:
	Product();
	Product(Product& other);
	Product(const char* name, double _price, double _percent);
	~Product();

	void setChance(int _chance);
	void setNameOfProduct(const char* name);
	void setPrice(double _price);
	void setPercentSale(double _percent);
	void setBought(bool haveBeenBought);

	double getPrice();
	double getPercentSale();
	int getChance();
	char* getNAmeOfPRoduct();
	bool getBought();

private:
	side chance;
	char* nameOfProduct;
	double price;
	double percentSale;
	bool bought;
};

