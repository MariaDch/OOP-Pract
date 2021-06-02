#include "Mob.h"

Mob::Mob()
{
	name = "Mobche";
	health = 0.0;
	dmg = 1.0;
	isAlive = true;
}

Mob::Mob(String _name, double _health, double _dmg, bool _isAlive)
{
	name = _name;
	health = _health;
	dmg = _dmg;
	isAlive = _isAlive;
}

void Mob::gettingAttacked(double _dmg)
{
	health -= _dmg;
	if (health <= 0)
	{
		die();
	}
}

void Mob::die()
{
	isAlive = false;
}

String Mob::getType() const
{
	return type;
}

bool Mob::getIsAlive() const
{
	return isAlive;
}

double Mob::getHealth() const
{
	return health;
}

double Mob::getDmg() const
{
	return dmg;
}

void Mob::setHealth(double _health)
{
	health = _health;
}

int Mob::getSizeOfEnemies()
{
	return 0;
}
