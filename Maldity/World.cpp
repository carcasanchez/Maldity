#include "Maldity.h"
#include <stdio.h>

World::World(){

	printf("Constructor\n");

}

World::~World(){

	printf("Destructor");
}

void World::CreateWorld(int * &room)const{
	
	printf("World created\n");

	room = new int[13];

	Room Forest;
	Room Main_Road;
	Room Beach;
	Room Dock;
	Room City_Center;
	Room House_A;
	Room Shop;
	Room Alley;
	Room Tavern;
	Room Top_District;
	Room Fells;
}

void World::DestroyWorld(int * &room){
	printf("World destroyed\n");
	delete[]room;
}