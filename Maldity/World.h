#ifndef __WORLD_H__
#define __WORLD_H__

#define MAX_ITEMS 11

#include <string.h>
#include <iostream>

#include "MyString.h"
#include "Double-Linked List.h"
#include "Vector.h"
#include "Rooms.h"
#include "Exits.h"
#include "Items.h"
#include "Creature.h"

class Player;


class World{
public:
		

	Vector <Entity*> entity;
	
	Creature* player;

	World();
	~World();

	void CreateWorld();
	void Look()const;
	
};

extern World* world;

#endif
	



