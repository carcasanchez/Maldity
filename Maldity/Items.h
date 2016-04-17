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
	bool equippable = true;

	Item(const char* n, const char* d, const char* l, int cap, int num)
	{

		name = n;
		description = d;
		location = l;
		capacity = cap;
		num_items = num;

	}// :Entity(name, description){}  TODO 2: inherit entity constructor

	void Look();
	
};

#endif