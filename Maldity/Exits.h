#ifndef __EXITS_H__
#define __EXITS_H__
#include"Entity.h"

class Exits:public Entity{
public:
	String origin;
	String description;
	String destination;
	String orientation;
	bool door, open;
	
	//Exits() :Entity(){} TODO 2: inherit entity constructor
	void Look()const;


};
#endif