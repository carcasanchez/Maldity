#include "World.h"


World::World()
{

	room = new Room[14];
	player = new Player;
	
}

World::~World()
{
	
	delete[] room;
	delete player;
}

void World::CreateWorld()
{
	
	
	strcpy_s(room[0].name, 10, "Forest");
	strcpy_s(room[0].description, 300, "You are in a forest. \nAt south, you see that the road drives to a city. \nAt west, a high hill. \nAt north, the road vanishes in the distance. \nAt east, only the sea.");
	
	strcpy_s(room[1].name, 10, "Road");
	strcpy_s(room[1].description, 300, "You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest\n");
	
	strcpy_s(room[2].name, 10, "Beach");
	strcpy_s(room[2].description, 300, "The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n");

	strcpy_s(room[3].name, 10, "Dock");
	strcpy_s(room[3].description, 300, "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n");

	strcpy_s(room[4].name, 10, "Center");
	strcpy_s(room[4].description, 300, "Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys that go deeper into the city.\nOnly the alley of the north seems a little bit safer.\n");

	strcpy_s(room[5].name, 10, "Alley");
	strcpy_s(room[5].description, 300, "The narrow alley goes up from the city center.\nThere's a small door that have a 'Tavern' placard.\nThe alley continues ascending to the north.\n");

	strcpy_s(room[6].name, 10, "Tavern");
	strcpy_s(room[6].description, 300, "The house seems to be an old tavern, with the door oriented at east.\n");

	strcpy_s(room[7].name, 10, "Top");
	strcpy_s(room[7].description, 300, "You are in the elevated district of the city.\nYou can see a little alley at south and a enormous statue at east, beyond the\nhill.\n");
	
	strcpy_s(room[8].name, 10, "Fells");
	strcpy_s(room[8].description, 300, "The fells are surrounded by dark trees. The enourmous statue rises over them.");

	strcpy_s(room[9].name, 10, "Statue");
	strcpy_s(room[9].description, 300, "The enormous statue seems to be a Virgin.\nIt looks like she has a balcony on her top.\nThe dark mass of trees looks you from the west.\nThere are stairs that go up inside the statue.\nAt south, a little road goes down the fells.\n");

	strcpy_s(room[10].name, 10, "Balcony");
	strcpy_s(room[10].description, 300, "The head of the virgin is sculpted as a balcony. You can see the whole village from here.\n");

	strcpy_s(room[11].name, 10, "House");
	strcpy_s(room[11].description, 300, "You are in the hall of an old house. The building looks like a gothic palace,\nbut it's dusty and seems abandoned.\n");
	
	strcpy_s(room[12].name, 10, "Shop");
	strcpy_s(room[12].description, 300, "Compared to the rest of the city, the shop looks miserable.\nIt's impossible to determine what is sold here.\n");
	
	strcpy_s(player->position, 10, room[0].name);
	
}

