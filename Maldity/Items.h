#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "Entity.h"


class Item:public Entity
{

public:
	
	String location;
	int bonus_atk = 0;
	int bonus_def = 0;
	int bonus_hp = 0;
	int limit;

	//TODO: item location and stats
	Item(const char* name, const char* description, const char* l, Tipus type, int limit) : Entity(name, description, type), limit(limit)
	{
		location = l;

	}

	void Look() const;
	
};

#endif