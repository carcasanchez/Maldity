#ifndef __WORLD_H__
#define __WORLD_H__

#define MAX_ITEMS 6

#include <string.h>
#include <iostream>

#include "MyString.h"
#include "Vector.h"
#include "Rooms.h"
#include "Exits.h"
#include "Items.h"

class Player;


class World{
public:
		
	Vector <Room*> room;
	Vector <Exits*> exit;
	Vector <Item*> item;
	Player* player;
	World();
	~World();

	void CreateWorld();
	void Look()const;
	
};

extern World* world;

#endif
	



