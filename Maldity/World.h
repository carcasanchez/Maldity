#ifndef __WORLD_H__
#define __WORLD_H__

#define MAX_ITEMS 11

#include <Windows.h>
#include <string.h>
#include <iostream>


#include "MyString.h"
#include "Double-Linked List.h"
#include "Vector.h"
#include "Rooms.h"
#include "Exits.h"
#include "Items.h"
#include "Creature.h"




class World{
public:
	
	unsigned int time = GetTickCount();

	Vector <Entity*> entity;
	
	Creature* player;
	Creature* ghost;
	Creature* vendor;


	Room* forest = nullptr;
	Room* road = nullptr;
	Room* beach = nullptr;
	Room* dock = nullptr;
	Room* center = nullptr;
	Room* shop = nullptr;
	Room* house = nullptr;
	Room* alley = nullptr;
	Room* tavern = nullptr;
	Room* top = nullptr;
	Room* fells = nullptr;
	Room* statue = nullptr;
	Room* balcony = nullptr;


	Item* key = nullptr;
	Item* coffer = nullptr;
	Item* coin = nullptr;
	Item* totem = nullptr;
	Item* sword = nullptr;
	Item* armor = nullptr;
	Item* map = nullptr;
	Item* fang = nullptr;
	Item* rope = nullptr;
	Item* swordcase = nullptr;
	Item* vial = nullptr;


	World();
	~World();

	void CreateWorld();
	void Look()const;

	void ResetTime(){ time = GetTickCount(); };
	
};

extern World* world;

#endif
	



