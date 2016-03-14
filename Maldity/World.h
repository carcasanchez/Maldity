#ifndef __WORLD_H__
#define __WORLD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Rooms.h"
#include "Player.h"
#include "Exits.h"
#include "Functions.h"

class World{
public:
		
	Room* room = nullptr;
	Exits* exit = nullptr;
	Player* player = nullptr;
	World();
	~World();


	void CreateWorld()const;
	
};

#endif
	



