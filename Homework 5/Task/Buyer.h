#pragma once
#include "AmericanCoin.h"
#include "BulgarianCoin.h"
#include "GermanCoin.h"
#include "Vector.h"
#include "Product.h"

class Buyer
{
	enum face { HEADS, TAILS };
private:
	Vector<AmericanCoin> americanCoinsBag;
	Vector<BulgarianCoin> bulgarianCoinsBag;
	Vector<GermanCoin> germanCoinsBag;
public:
	//Buyer();
	Buyer(Vector<AmericanCoin> _americanCoinsBag, Vector<BulgarianCoin> _bulgarianCoinsBag, Vector<GermanCoin> _germanCoinsBag);
	Buyer(const Buyer& other_buyer);

	void addCoinsAmerican(AmericanCoin coin);
	void addCoinsBulgarian(BulgarianCoin coin);
	void addCoinsGerman(GermanCoin coin);

	void removeCoinsAmerican(size_t index);
	void removeCoinsBulgarian(size_t index);
	void removeCoinsGerman(size_t index);

	void buy(Product product);
	void printBoughtProducts(Vector<Product> products)const;
};
