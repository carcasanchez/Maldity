#ifndef __EXITS_H__
#define __EXITS_H__
#include"Entity.h"



class Exit:public Entity{
public:
	String origin;
	String destination;
	String orientation;
	bool door, open;
	
	Exit(const char* name, const char* description, const char* origin, const char* destination, const char* orientation, bool door, bool open) :Entity(name, description, EXIT), origin(origin), destination(destination), orientation(orientation), door(door), open(open){};
	void Look()const;


};
#endif