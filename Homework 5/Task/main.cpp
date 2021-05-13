#include <iostream>
#include "Coin.h"
#include "AmericanCoin.h"
#include "BulgarianCoin.h"
#include "GermanCoin.h"
#include "Product.h"
#include "Buyer.h"

int main()
{
	Vector<Product> list;
	Product p1("Lqb",2,50);
	Product p2("Mleko", 1, 10);
	Product p3("Sirni", 10, 80);
	Product p4("Tilifon", 60, 50);
	Product p5("Vafle", 0.5, 2);

	list.pushBack(p1);
	list.pushBack(p2);
	list.pushBack(p3);
	list.pushBack(p4);
	list.pushBack(p5);

	AmericanCoin a1;
	a1.setValue(50);
	AmericanCoin a2;
	a2.setValue(10);
	AmericanCoin a3;
	a3.setValue(2.2);
	Vector<AmericanCoin> american;
	american.pushBack(a1);
	american.pushBack(a2);
	american.pushBack(a3);

	BulgarianCoin b1;
	b1.setValue(20);
	BulgarianCoin b2;
	b2.setValue(25.3);
	BulgarianCoin b3;
	b3.setValue(60);
	Vector<BulgarianCoin> bulgarian;
	bulgarian.pushBack(b1);
	bulgarian.pushBack(b2);
	bulgarian.pushBack(b3);

	GermanCoin g1;
	g1.setValue(36);
	GermanCoin g2;
	g2.setValue(50);
	GermanCoin g3;
	g3.setValue(12);
	Vector<GermanCoin> german;
	german.pushBack(g1);
	german.pushBack(g2);
	german.pushBack(g3);

	Buyer buy1(american, bulgarian, german);
	buy1.buy(p4);
	//buy1.printBoughtProducts(list);
}