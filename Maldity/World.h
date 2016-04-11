#ifndef __WORLD_H__
#define __WORLD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Rooms.h"
#include "Exits.h"
#include "MyString.h"


class Player;

class World{
public:
		
	Room* room = nullptr;
	Exits* exit = nullptr;
	Player* player = nullptr;
	World();
	~World();

	void CreateWorld()const;
	void Look()const;
	
};

extern World* world;

#endif
	



