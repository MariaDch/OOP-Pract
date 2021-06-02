#pragma once
#include "Vector.h"
#include "String.h"
#include <exception>

class Mob
{
protected:
	String name;
	String type;
	double health;
	double dmg;
	bool isAlive;
public:
	Mob();
	Mob(String _name, double _health, double _dmg, bool _isAlive);
	bool getIsAlive() const;
	double getHealth()const;
	double getDmg() const;
	void setHealth(double _health);
	virtual int getSizeOfEnemies();


	virtual void gettingAttacked(double _dmg);
	virtual void attack(Mob* other) = 0;
	virtual void die();
	virtual String getType() const;
};


