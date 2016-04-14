#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "MyString.h"

class Entity{
public:
	String name;
	String description;

	//Entity(){};

	/*Entity(const char* str1, char* str2)
	{
		name = str1;
		description = str2;

	}*/
	
	virtual void Look(){};
	

};


#endif