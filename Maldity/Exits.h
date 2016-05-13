#ifndef __EXITS_H__
#define __EXITS_H__
#include"Entity.h"
#include "Rooms.h"




class Exit:public Entity
{
public:
	Room* origin;
	Room* destination;
	Cardinal orientation;
	bool door, open;
	
	Exit(const char* name, const char* description, Room* origin, Room* destination, Cardinal orientation, bool door, bool open) :Entity(name, description, EXIT), origin(origin), destination(destination), orientation(orientation), door(door), open(open){};
	void Look()const;


};
#endif