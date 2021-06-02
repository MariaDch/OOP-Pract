#pragma once
#include "Mob.h"

enum typeAttack {normalAttack, splashAttack };

class Hero : public Mob
{
protected:
	int armor;
	typeAttack attackType;
public:

	Hero() : Mob()
	{
		type = "Hero";
		armor = 0;
		attackType = normalAttack;
	}

	void gettingAttacked(double _dmg) override
	{
		if (armor == 0)
		{
			health -= _dmg;
		}
		else if (armor < _dmg)
		{
			double temp = armor - _dmg;
			health += temp;
			armor = 0;
		}
		else if (armor > _dmg)
		{
			armor -= _dmg;
		}

		if (health <= 0)
		{
			die();
		}
	}

	void attack(Mob* other) override
	{
		if (other->getType() != "Hero")
		{
			if (other->getType() == "Enemy")
			{
				other->gettingAttacked(dmg);
			}
			else
			{
				if (attackType == splashAttack)
				{
					for (size_t i = 0; i < other->getSizeOfEnemies(); i++)
					{
						other[i].gettingAttacked(dmg);
					}
				}
				else
				{
					for (size_t i = 0; i < other->getSizeOfEnemies(); i++)
					{
						if (other[i]->isAlive())
						{
							other[i].gettingAttacked(dmg);
							break;
						}
					}
				}
			}
		}
		else
			throw "Cannot attack another Hero!!!";
	}
};

