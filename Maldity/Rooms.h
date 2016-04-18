#ifndef __ROOMS_H__
#define __ROOMS_H__
#include"Entity.h"

class Room:public Entity{
public:
	

	Room(const char* str1, const char* str2) :Entity(str1, str2) {}
	~Room(){};
};

#endif