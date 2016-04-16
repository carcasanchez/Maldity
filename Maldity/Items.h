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

	Item(const char* str1, const char* str2, const char* str3, int cap, int num)
	{

		name = str1;
		description = str2;
		location = str3;
		capacity = cap;
		num_items = num;

	}// :Entity(name, description){}

	void Look();
	
};

#endif