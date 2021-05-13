#pragma once
#include <cstring>
#include <cstdlib>
#include <iostream>

enum face { HEADS, TAILS };
class Coin
{
protected:
	char* nationality;
	double value;
	face sideOfTheCoin;

public:
	Coin();
	~Coin();

	void setNationality(const char* other_nationality);
	void setValue(double other_value);
	void setFace(face other_sideOfTheCoin);

	const char* getNAtionality();
	double getValue();
	face getFace();
	Coin& operator=(const Coin& other_Coin);

	virtual void flip();
	void print()const;
};

