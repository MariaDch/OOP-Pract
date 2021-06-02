#pragma once
#include "Mob.h"

class Enemies : public Mob
{
protected:
	Vector <Mob> mobs;
public:
	Enemies() : Mob()
	{
		type = "Enemies";
	}

	void attack(Mob* other) override
	{
		if (other->getType() != "Enemy" || other->getType() != "Enemies" )
		{
			for (size_t i = 0; i < mobs.getSize(); i++)
			{
				if (mobs[i]->isAlive())
				{
					mobs[i].attack(other);
				}
			}
		}
		else
			throw "Cannot attack other enemies or enemy!!!";
	}

	int getSizeOfEnemies() override
	{
		return mobs.getSize();
	}
};
