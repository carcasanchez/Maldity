#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "MyString.h"
#include "Vector.h"


class Entity{

public:

	String name;
	String description;
	//TODO 3: create a vector for cointain other entities


	int capacity;
	int num_items;

	//Entity(){};
	//TODO 2: create entity constructor
	/*Entity(const char* str1, char* str2)
	{
		name = str1;
		description = str2;

	}*/


	
	virtual void Look(){};
	

};


#endif