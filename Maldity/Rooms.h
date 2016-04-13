#ifndef __ROOMS_H__
#define __ROOMS_H__
#include"Entity.h"

class Room:public Entity{
public:
	String name;
	String description;

	
	Room(const char* str1, const char* str2)
	{
		name = str1;
		description = str2;
	}
};

#endif