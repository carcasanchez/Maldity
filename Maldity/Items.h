#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "Entity.h"


class Item:public Entity
{
public:

	String location;
	

	Item(const char* str1, const char* str2, const char* str3)
	{

		name = str1;
		description = str2;
		location = str3;

	}// :Entity(name, description){}


};

#endif