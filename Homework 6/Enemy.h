#pragma once
#include "Mob.h"

enum typeOfTheEnemy {small = 0, average, big};

class Enemy : public Mob
{
protected:
	typeOfTheEnemy enemyType;
public:

	Enemy() : Mob()
	{
		type = "Enemy";
		enemyType = small;
	}

	typeOfTheEnemy getEnemyType()
	{
		return enemyType;
	}

	void attack(Mob* other) override
	{
		if (other->getType() == "Enemy" || other->getType()=="Enemies" || other->getIsAlive() == false )
		{
			throw "Enemy cannot attack dead hero,another enemy or enemies";
		}
		else
		{
			other->gettingAttacked(dmg);
		}
	}
};