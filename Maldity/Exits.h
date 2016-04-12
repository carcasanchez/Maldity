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
	
	void Look()const;
    void Open();
	void Close();

};
#endif