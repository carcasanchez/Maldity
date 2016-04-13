#ifndef __WORLD_H__
#define __WORLD_H__


#include <string.h>
#include <iostream>

#include "MyString.h"
#include "Vector.h"
#include "Rooms.h"
#include "Exits.h"

class Player;

class World{
public:
		
	Vector <Room*> room;
	Vector <Exits*> exit;
	Player* player;
	World();
	~World();

	void CreateWorld();
	void Look()const;
	
};

extern World* world;

#endif
	



