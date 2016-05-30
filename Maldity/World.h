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
#include "CreatureChilds.h"
#include "Dialogue.h"

class Creature;
class Vendor;
class Player;
class Ghost;


class World{
public:
	
	String player_input;
	char* last_key = nullptr;
	bool game_ended = false;

	Vector <Entity*> entity;
	

	Ghost* ghost = nullptr;
	Vendor* vendor = nullptr;
	Player* player = nullptr;
	Creature* knight = nullptr;
	Creature* sailor = nullptr;
	Creature* collector = nullptr;
	Creature* patrol = nullptr;
	Creature* demented = nullptr;

	Creature* brute = nullptr;
	
	/*
	Inkeeper* inkeeper=nullptr;
	Seer* seer=nullptr;
	*/

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


	Item* coffer = nullptr;
	Item* coin = nullptr;
	Item* totem = nullptr;
	Item* sword = nullptr;
	Item* armor = nullptr;
	Item* map = nullptr;
	Item* fang = nullptr;
	Item* vial = nullptr;
	Item* transistor = nullptr;

	Exit* house_door = nullptr;


	World();
	~World();

	void CreateWorld();
	void Look()const;

	
};

extern World* world;

#endif
	



