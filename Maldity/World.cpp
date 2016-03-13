#include "World.h"


World::World()
{

	room = new Room[14];
	exit = new Exits[52];
	player = new Player;

}

World::~World()
{
	
	delete[] room;
	delete[] exit;
	delete player;
}




void World::CreateWorld()
{
	
	//Forest
	strcpy_s(room[0].name, 10, "Forest");
	strcpy_s(room[0].description, 300, "You are in a forest. \nAt south, you see that the road drives to a city. \nAt west, a high hill. \nAt north, the road vanishes in the distance. \nAt east, only the sea.\n");
	
	strcpy_s(exit[0].orientation, 10, "north");
	strcpy_s(exit[1].orientation, 10, "south");
	strcpy_s(exit[2].orientation, 10, "east");
	strcpy_s(exit[3].orientation, 10, "west");
	
	strcpy_s(exit[0].origin, 10, "Forest");
	strcpy_s(exit[1].origin, 10, "Forest");
	strcpy_s(exit[2].origin, 10, "Forest");
	strcpy_s(exit[3].origin, 10, "Forest");

	strcpy_s(exit[0].destination, 10, "empty");
	strcpy_s(exit[1].destination, 10, "Road");
	strcpy_s(exit[2].destination, 10, "empty");
	strcpy_s(exit[3].destination, 10, "empty");

	strcpy_s(exit[0].description, 300, "The road vanishes in the distance.\nBetter no to follow it.\n");
	strcpy_s(exit[1].description, 300, "The road follows the coast and approaches to the village.\n");
	strcpy_s(exit[2].description, 300, "You can't go on that direction.\nThe hill is too high.\n");
	strcpy_s(exit[3].description, 300, "The sea looks grey and unpeaceful.\n");


	//Road
	strcpy_s(room[1].name, 10, "Road");
	strcpy_s(room[1].description, 300, "You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest\n");
	
	strcpy_s(exit[4].orientation, 10, "north");
	strcpy_s(exit[5].orientation, 10, "south");
	strcpy_s(exit[6].orientation, 10, "east");
	strcpy_s(exit[7].orientation, 10, "west");

	strcpy_s(exit[4].origin, 10, "Road");
	strcpy_s(exit[5].origin, 10, "Road");
	strcpy_s(exit[6].origin, 10, "Road");
	strcpy_s(exit[7].origin, 10, "Road");

	strcpy_s(exit[4].destination, 10, "Center");
	strcpy_s(exit[5].destination, 10, "Beach");
	strcpy_s(exit[6].destination, 10, "Forest");
	strcpy_s(exit[7].destination, 10, "Dock");

	strcpy_s(exit[4].description, 300, "The alleys seem to drive to the city center.\n");
	strcpy_s(exit[5].description, 300, "Narrow stairs sculpted in rock descends to the beach.\n");
	strcpy_s(exit[6].description, 300, "The road leaves the city and follows the coast.\n");
	strcpy_s(exit[7].description, 300, "At the distance, you can see numerous boat masts.\n");

	//Beach
	strcpy_s(room[2].name, 10, "Beach");
	strcpy_s(room[2].description, 300, "The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n");

	
	//Dock
	strcpy_s(room[3].name, 10, "Dock");
	strcpy_s(room[3].description, 300, "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n");


	//Center
	strcpy_s(room[4].name, 10, "Center");
	strcpy_s(room[4].description, 300, "Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys that go deeper into the city.\nOnly the alley of the north seems a little bit safer.\n");

	//Alley
	strcpy_s(room[5].name, 10, "Alley");
	strcpy_s(room[5].description, 300, "The narrow alley goes up from the city center.\nThere's a small door that have a 'Tavern' placard.\nThe alley continues ascending to the north.\n");

	//Tavern
	strcpy_s(room[6].name, 10, "Tavern");
	strcpy_s(room[6].description, 300, "The house seems to be an old tavern, with the door oriented at east.\n");

	//Top Disctrict
	strcpy_s(room[7].name, 10, "Top");
	strcpy_s(room[7].description, 300, "You are in the elevated district of the city.\nYou can see a little alley at south and a enormous statue at east, beyond the\nhill.\n");
	
	//Fells
	strcpy_s(room[8].name, 10, "Fells");
	strcpy_s(room[8].description, 300, "The fells are surrounded by dark trees. The enourmous statue rises over them.");

	//Statue
	strcpy_s(room[9].name, 10, "Statue");
	strcpy_s(room[9].description, 300, "The enormous statue seems to be a Virgin.\nIt looks like she has a balcony on her top.\nThe dark mass of trees looks you from the west.\nThere are stairs that go up inside the statue.\nAt south, a little road goes down the fells.\n");

	//Balcony
	strcpy_s(room[10].name, 10, "Balcony");
	strcpy_s(room[10].description, 300, "The head of the virgin is sculpted as a balcony. You can see the whole village \nfrom here.\n");

	//House
	strcpy_s(room[11].name, 10, "House");
	strcpy_s(room[11].description, 300, "You are in the hall of an old house. The building looks like a gothic palace,\nbut it's dusty and seems abandoned.\n");
	
	//Shop
	strcpy_s(room[12].name, 10, "Shop");
	strcpy_s(room[12].description, 300, "Compared to the rest of the city, the shop looks miserable.\nIt's impossible to determine what is sold here.\n");
	
	player->position = 0;
}

