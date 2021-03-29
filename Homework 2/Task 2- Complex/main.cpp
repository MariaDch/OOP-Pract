#include <iostream>
#include "Complex.h"

int main()
{
	Complex complex1;
	complex1.setRealPart(2);
	complex1.setImaginaryPart(-6);
	Complex complex2;
	complex2.setRealPart(-2);
	complex2.setImaginaryPart(6);                 
	
	complex1.operator*=(complex2);               //(2-6i)*(-2+6i)=-4+36 + 12i + 12i = 32+24i
	complex1.print();			                //(2-6i)/(-2+6i)= (-4 -36)/(4+36) + (12 - 12)/(4+36)= -1+0i
	std::cout << std::endl;
}