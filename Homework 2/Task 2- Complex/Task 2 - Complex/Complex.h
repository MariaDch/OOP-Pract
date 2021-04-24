#pragma once
#include <iostream>

class Complex
{
private: 
	double realPart;
	double imaginaryPart;

public:
	Complex ();
	Complex(double other_realPart, double other_imaginaryPart);
	
	void setRealPart(double _realPart);
	void setImaginaryPart(double _imaginaryPart);

	double getRealPart() const;
	double getImaginaryPart() const;

	Complex& operator+(const Complex& other_complex);
	Complex& operator-(const Complex& other_complex);
	Complex& operator*(const Complex& other_complex);
	Complex& operator/(const Complex& other_complex);

	//bool operator>=(const Complex& other_complex);
	//bool operator<=(const Complex& other_complex);
	bool operator==(const Complex& other_complex);
	bool operator!=(const Complex& other_complex);

	Complex operator=(const Complex& other_complex);

	Complex& operator+=(const Complex& other_complex);
	Complex& operator-=(const Complex& other_complex);
	Complex& operator*=(const Complex& other_complex);
	Complex& operator/=(const Complex& other_complex);

	void print() const;
};