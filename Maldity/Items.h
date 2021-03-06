#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "Entity.h"
#include "Stats.h"

class Item:public Entity
{

public:

	int bonus_hp = 0;
	int bonus_atk = 0;
	int bonus_def = 0;
	int bonus_sanity = 0;
	int limit;
	int value;




	Item(const char* name, const char* description, Tipus type, Stats bonus, int limit, int value, int madness) : Entity(name, description, type), limit(limit), value(value)
	{
		bonus_atk = bonus.atk;
		bonus_hp = bonus.hp;
		bonus_def = bonus.hp;
		bonus_sanity = bonus.sanity;
		madness_damage = madness;
	}
	
};

#endif