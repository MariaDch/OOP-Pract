#include "Complex.h"

Complex::Complex()
{
	realPart = 0;
	imaginaryPart = 0;
}

Complex::Complex(double other_realPart, double other_imaginaryPart)
{
	realPart = other_realPart;
	imaginaryPart = other_imaginaryPart;
}

void Complex::setRealPart(double _realPart)
{
	realPart = _realPart;
}

void Complex::setImaginaryPart(double _imaginaryPart)
{
	imaginaryPart = _imaginaryPart;
}

double Complex::getRealPart() const
{
	return realPart;
}

double Complex::getImaginaryPart() const
{
	return imaginaryPart;
}

Complex& Complex:: operator+(const Complex& other_complex)
{
	Complex complex3;
	complex3 = *this;
	//std::cout << realPart + other_complex.realPart << " + " << imaginaryPart + other_complex.imaginaryPart << " i";
	complex3.setRealPart(realPart + other_complex.realPart);
	complex3.setImaginaryPart(imaginaryPart + other_complex.imaginaryPart);
	return complex3;
}

Complex& Complex:: operator-(const Complex& other_complex)
{
	Complex complex3;
	complex3 = *this;
	complex3.setRealPart(realPart - other_complex.realPart);
	complex3.setImaginaryPart(imaginaryPart - other_complex.imaginaryPart);
	return complex3;
}

Complex& Complex:: operator*(const Complex& other_complex)
{
	Complex complex3;
	complex3 = *this;
	complex3.setRealPart((realPart * other_complex.realPart) - (imaginaryPart * other_complex.imaginaryPart));
	complex3.setImaginaryPart((imaginaryPart * other_complex.realPart) + (realPart * other_complex.imaginaryPart));
	return complex3;
}

Complex& Complex::operator/(const Complex& other_complex)
{
	Complex complex3;
	complex3 = *this;
	complex3.setRealPart(((realPart * other_complex.realPart) + (imaginaryPart * other_complex.imaginaryPart))
		/ ((other_complex.realPart * other_complex.realPart) + (other_complex.imaginaryPart * other_complex.imaginaryPart)));
	complex3.setImaginaryPart (((imaginaryPart * other_complex.realPart) - (realPart * other_complex.imaginaryPart))
		/ ((other_complex.realPart * other_complex.realPart) + (other_complex.imaginaryPart * other_complex.imaginaryPart)));
	return complex3;
}

//complexnite chisla ne mogat da se sravnqvt s >= ili <=

bool Complex::operator==(const Complex& other_complex)
{
	if (realPart == other_complex.realPart && imaginaryPart == other_complex.imaginaryPart)
		return true;
	else
		return false;
}

bool Complex::operator!=(const Complex& other_complex)
{
	if (realPart != other_complex.realPart  || imaginaryPart == other_complex.imaginaryPart)
		return true;
	else
		return false;
}

Complex Complex::operator=(const Complex& other_complex)
{
	realPart = other_complex.realPart;
	imaginaryPart = other_complex.imaginaryPart;
	return *this;
}

Complex& Complex::operator+=(const Complex& other_complex)
{
	*this = *this + other_complex;
	return *this;
}

Complex& Complex::operator-=(const Complex& other_complex)
{
	*this = *this - other_complex;
	return *this;
}

Complex& Complex::operator*=(const Complex& other_complex)
{	
	*this = *this * other_complex;
	return *this;
}

Complex& Complex::operator/=(const Complex& other_complex)
{
	*this = *this / other_complex;
	return *this;
}

void Complex::print() const
{
	if (imaginaryPart < 0)
	{
		std::cout << realPart << imaginaryPart << "i";
	}
	else
	{
		std::cout << realPart << "+" << imaginaryPart << "i";
	}
}