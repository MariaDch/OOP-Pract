#include <iostream>
#include "Crypto.h"

int main()
{
	Crypto crypt;
	crypt.setName("Bitcoin");
	crypt.setLastPrice(5123.2);
	crypt.setCurrentPrice(388887.25);

	crypt.print();
	crypt.priceDifference();
}