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
	strcpy_s(exit[2].description, 300, "The sea looks grey and unpeaceful.\n");
	strcpy_s(exit[3].description, 300, "You can't go on that direction.\nThe hill is too high.\n");


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
	
	strcpy_s(exit[8].orientation, 10, "north");
	strcpy_s(exit[9].orientation, 10, "south");
	strcpy_s(exit[10].orientation, 10, "east");
	strcpy_s(exit[11].orientation, 10, "west");

	strcpy_s(exit[8].origin, 10, "Beach");
	strcpy_s(exit[9].origin, 10, "Beach");
	strcpy_s(exit[10].origin, 10, "Beach");
	strcpy_s(exit[11].origin, 10, "Beach");

	strcpy_s(exit[8].destination, 10, "Road");
	strcpy_s(exit[9].destination, 10, "empty");
	strcpy_s(exit[10].destination, 10, "empty");
	strcpy_s(exit[11].destination, 10, "empty");

	strcpy_s(exit[8].description, 300, "The stairs go back to the road\n");
	strcpy_s(exit[9].description, 300, "You look at the sea. The horizon is cloudy, and the water, grey.\nYou feel a little relief for stay in land,\nbut the cold and ferocious wind spreads it.\n");
	strcpy_s(exit[10].description, 300, "The rocks are too abrupt to walk over them.\n");
	strcpy_s(exit[11].description, 300, "The rocks are too abrupt to walk over them.\n");
	

	//Dock
	strcpy_s(room[3].name, 10, "Dock");
	strcpy_s(room[3].description, 300, "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n");

	strcpy_s(exit[12].orientation, 10, "north");
	strcpy_s(exit[13].orientation, 10, "south");
	strcpy_s(exit[14].orientation, 10, "east");
	strcpy_s(exit[15].orientation, 10, "west");

	strcpy_s(exit[12].origin, 10, "Dock");
	strcpy_s(exit[13].origin, 10, "Dock");
	strcpy_s(exit[14].origin, 10, "Dock");
	strcpy_s(exit[15].origin, 10, "Dock");

	strcpy_s(exit[12].destination, 10, "empty");
	strcpy_s(exit[13].destination, 10, "empty");
	strcpy_s(exit[14].destination, 10, "Road");
	strcpy_s(exit[15].destination, 10, "empty");

	strcpy_s(exit[12].description, 300, "The big boats seems old and abandoned. Better not try to go into.\n");
	strcpy_s(exit[13].description, 300, "The big boats seems old and abandoned. Better not try to go into.\n");
	strcpy_s(exit[14].description, 300, "Between the gigant boats, you can see the road.\n");
	strcpy_s(exit[15].description, 300, "The big boats seems old and abandoned. Better not try to go into.\n");


	//Center
	strcpy_s(room[4].name, 10, "Center");
	strcpy_s(room[4].description, 300, "Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys that go \ndeeper into the city.\nOnly the alley of the north seems a little bit safer.\nThe door of the east is widely open, but the west one needs a little push.\n");

	strcpy_s(exit[16].orientation, 10, "north");
	strcpy_s(exit[17].orientation, 10, "south");
	strcpy_s(exit[18].orientation, 10, "east");
	strcpy_s(exit[19].orientation, 10, "west");

	strcpy_s(exit[16].origin, 10, "Center");
	strcpy_s(exit[17].origin, 10, "Center");
	strcpy_s(exit[18].origin, 10, "Center");
	strcpy_s(exit[19].origin, 10, "Center");

	strcpy_s(exit[16].destination, 10, "Alley");
	strcpy_s(exit[17].destination, 10, "Road");
	strcpy_s(exit[18].destination, 10, "Shop");
	strcpy_s(exit[19].destination, 10, "House");

	strcpy_s(exit[16].description, 300, "The northern alley leaves the square between buildings. It seems to ascend.\n");
	strcpy_s(exit[17].description, 300, "You can see the main road, near the sea.\n");
	strcpy_s(exit[18].description, 300, "A little door is widely open. It seems to be a shop.\n");
	strcpy_s(exit[19].description, 300, "The door is closed, but it looks like you can open it easily.\n");


	//Alley
	strcpy_s(room[5].name, 10, "Alley");
	strcpy_s(room[5].description, 300, "The narrow alley goes up from the city center.\nThere's a small door that have a 'Tavern' placard at your left.\nThe alley continues ascending to the north.\n");
	
	strcpy_s(exit[20].orientation, 10, "north");
	strcpy_s(exit[21].orientation, 10, "south");
	strcpy_s(exit[22].orientation, 10, "east");
	strcpy_s(exit[23].orientation, 10, "west");

	strcpy_s(exit[20].origin, 10, "Alley");
	strcpy_s(exit[21].origin, 10, "Alley");
	strcpy_s(exit[22].origin, 10, "Alley");
	strcpy_s(exit[23].origin, 10, "Alley");

	strcpy_s(exit[20].destination, 10, "Top");
	strcpy_s(exit[21].destination, 10, "Center");
	strcpy_s(exit[22].destination, 10, "empty");
	strcpy_s(exit[23].destination, 10, "Tavern");

	strcpy_s(exit[20].description, 300, "The alley continues ascending.\n");
	strcpy_s(exit[21].description, 300, "The alley descends to the city center.\n");
	strcpy_s(exit[22].description, 300, "The gothic buildings looks impressive, and the rest of the alleys,\ntoo dark to go into.\n");
	strcpy_s(exit[23].description, 300, "The door is closed, but it looks like you can open it easily.\n");

	//Tavern
	strcpy_s(room[6].name, 10, "Tavern");
	strcpy_s(room[6].description, 300, "The house seems to be an old tavern, with the door oriented at east.\n");

	strcpy_s(exit[24].orientation, 10, "north");
	strcpy_s(exit[25].orientation, 10, "south");
	strcpy_s(exit[26].orientation, 10, "east");
	strcpy_s(exit[27].orientation, 10, "west");

	strcpy_s(exit[24].origin, 10, "Tavern");
	strcpy_s(exit[25].origin, 10, "Tavern");
	strcpy_s(exit[26].origin, 10, "Tavern");
	strcpy_s(exit[27].origin, 10, "Tavern");

	strcpy_s(exit[24].destination, 10, "empty");
	strcpy_s(exit[25].destination, 10, "empty");
	strcpy_s(exit[26].destination, 10, "Alley");
	strcpy_s(exit[27].destination, 10, "empty");

	strcpy_s(exit[24].description, 300, "The tavern has no more exits than the east one.\n");
	strcpy_s(exit[25].description, 300, "The tavern has no more exits than the east one.\n");
	strcpy_s(exit[26].description, 300, "The door is open.\n");
	strcpy_s(exit[27].description, 300, "The tavern has no more exits than the east one.\n");


	//Top Disctrict
	strcpy_s(room[7].name, 10, "Top");
	strcpy_s(room[7].description, 300, "You are in the elevated district of the city.\nYou can see a little alley at south and a enormous statue at east, beyond the\nhill.\n");

	strcpy_s(exit[28].orientation, 10, "north");
	strcpy_s(exit[29].orientation, 10, "south");
	strcpy_s(exit[30].orientation, 10, "east");
	strcpy_s(exit[31].orientation, 10, "west");

	strcpy_s(exit[28].origin, 10, "Top");
	strcpy_s(exit[29].origin, 10, "Top");
	strcpy_s(exit[30].origin, 10, "Top");
	strcpy_s(exit[31].origin, 10, "Top");

	strcpy_s(exit[28].destination, 10, "empty");
	strcpy_s(exit[29].destination, 10, "Alley");
	strcpy_s(exit[30].destination, 10, "Fells");
	strcpy_s(exit[31].destination, 10, "empty");

	strcpy_s(exit[28].description, 300, "The city is surrounded by a chain of old fells.\nThe woody mountains looks dark and threatening.\n");
	strcpy_s(exit[29].description, 300, "You can see the alley descending to the city.\n");
	strcpy_s(exit[30].description, 300, "Between dark and high trees, you can see a enormous statue.\n");
	strcpy_s(exit[31].description, 300, "The city is surrounded by a chain of old fells.\nThe woody mountains looks dark and threatening.\n");


	//Fells
	strcpy_s(room[8].name, 10, "Fells");
	strcpy_s(room[8].description, 300, "The fells are surrounded by dark trees. The enourmous statue rises over them.");

	strcpy_s(exit[32].orientation, 10, "north");
	strcpy_s(exit[33].orientation, 10, "south");
	strcpy_s(exit[34].orientation, 10, "east");
	strcpy_s(exit[35].orientation, 10, "west");

	strcpy_s(exit[32].origin, 10, "Fells");
	strcpy_s(exit[33].origin, 10, "Fells");
	strcpy_s(exit[34].origin, 10, "Fells");
	strcpy_s(exit[35].origin, 10, "Fells");

	strcpy_s(exit[32].destination, 10, "empty");
	strcpy_s(exit[33].destination, 10, "empty");
	strcpy_s(exit[34].destination, 10, "Statue");
	strcpy_s(exit[35].destination, 10, "Top");

	strcpy_s(exit[32].description, 300, "The forest is too dense to go into it.\n");
	strcpy_s(exit[33].description, 300, "The forest is too dense to go into it.\n");
	strcpy_s(exit[34].description, 300, "Between dark and high trees, you can see a enormous statue.\n");
	strcpy_s(exit[35].description, 300, "You can see some buildings between the trees.\n");



	//Statue
	strcpy_s(room[9].name, 10, "Statue");
	strcpy_s(room[9].description, 300, "The enormous statue seems to be a Virgin.\nIt looks like she has a balcony on her top.\nThe dark mass of trees looks you from the west.\nThere are stairs that go up inside the statue.\nAt south, a little road goes down the fells.\n");

	strcpy_s(exit[36].orientation, 10, "north");
	strcpy_s(exit[37].orientation, 10, "south");
	strcpy_s(exit[38].orientation, 10, "east");
	strcpy_s(exit[39].orientation, 10, "west");

	strcpy_s(exit[36].origin, 10, "Statue");
	strcpy_s(exit[37].origin, 10, "Statue");
	strcpy_s(exit[38].origin, 10, "Statue");
	strcpy_s(exit[39].origin, 10, "Statue");

	strcpy_s(exit[36].destination, 10, "empty");
	strcpy_s(exit[37].destination, 10, "Forest");
	strcpy_s(exit[38].destination, 10, "Balcony");
	strcpy_s(exit[39].destination, 10, "Fells");

	strcpy_s(exit[36].description, 300, "The mountains look so terrifying\n");
	strcpy_s(exit[37].description, 300, "The hill descends abruptly to a forest.\nIt's possible that you can't climb back.\n");
	strcpy_s(exit[38].description, 300, "The statue has a little opened door.\nYou can see stairs behind it.\n");
	strcpy_s(exit[39].description, 300, "The fells look tenebrous, but it's the only way to go to the village.\n");


	//Balcony
	strcpy_s(room[10].name, 10, "Balcony");
	strcpy_s(room[10].description, 300, "The head of the virgin is sculpted as a balcony. You can see the whole village \nfrom here.\n");

	strcpy_s(exit[40].orientation, 10, "north");
	strcpy_s(exit[41].orientation, 10, "south");
	strcpy_s(exit[42].orientation, 10, "east");
	strcpy_s(exit[43].orientation, 10, "west");

	strcpy_s(exit[40].origin, 10, "Balcony");
	strcpy_s(exit[41].origin, 10, "Balcony");
	strcpy_s(exit[42].origin, 10, "Balcony");
	strcpy_s(exit[43].origin, 10, "Balcony");

	strcpy_s(exit[40].destination, 10, "empty");
	strcpy_s(exit[41].destination, 10, "empty");
	strcpy_s(exit[42].destination, 10, "empty");
	strcpy_s(exit[43].destination, 10, "Statue");

	strcpy_s(exit[40].description, 300, "The mountains look so terrfying");
	strcpy_s(exit[41].description, 300, "The gothic city is placed between the feets of the mountains and the grey sea.\nIt looks like a phantom village\n.");
	strcpy_s(exit[42].description, 300, "You can see a little road at the bottom of the fells.\nOne of its sides goes to the city.\nThe other, vanishes in the distance.\n");
	strcpy_s(exit[43].description, 300, "That stairs are the only way to go down the balcony.\n");


	//House
	strcpy_s(room[11].name, 10, "House");
	strcpy_s(room[11].description, 300, "You are in the hall of an old house. The building looks like a gothic palace,\nbut it's dusty and seems abandoned.\n");

	strcpy_s(exit[44].orientation, 10, "north");
	strcpy_s(exit[45].orientation, 10, "south");
	strcpy_s(exit[46].orientation, 10, "east");
	strcpy_s(exit[47].orientation, 10, "west");

	strcpy_s(exit[44].origin, 10, "House");
	strcpy_s(exit[45].origin, 10, "House");
	strcpy_s(exit[46].origin, 10, "House");
	strcpy_s(exit[47].origin, 10, "House");

	strcpy_s(exit[44].destination, 10, "empty");
	strcpy_s(exit[45].destination, 10, "empty");
	strcpy_s(exit[46].destination, 10, "Center");
	strcpy_s(exit[47].destination, 10, "empty");

	strcpy_s(exit[44].description, 300, "The only exit is the door at the east.\n");
	strcpy_s(exit[45].description, 300, "The only exit is the door at the east.\n");
	strcpy_s(exit[46].description, 300, "The door is open.\n");
	strcpy_s(exit[47].description, 300, "The only exit is the door at the east.\n");


	//Shop
	strcpy_s(room[12].name, 10, "Shop");
	strcpy_s(room[12].description, 300, "Compared to the rest of the city, the shop looks miserable.\nIt's impossible to determine what is sold here.\n");
	
	strcpy_s(exit[48].orientation, 10, "north");
	strcpy_s(exit[49].orientation, 10, "south");
	strcpy_s(exit[50].orientation, 10, "east");
	strcpy_s(exit[51].orientation, 10, "west");

	strcpy_s(exit[48].origin, 10, "Shop");
	strcpy_s(exit[49].origin, 10, "Shop");
	strcpy_s(exit[50].origin, 10, "Shop");
	strcpy_s(exit[51].origin, 10, "Shop");

	strcpy_s(exit[48].destination, 10, "empty");
	strcpy_s(exit[49].destination, 10, "empty");
	strcpy_s(exit[50].destination, 10, "empty");
	strcpy_s(exit[51].destination, 10, "Center");

	strcpy_s(exit[48].description, 300, "The only exit is the door at the west.\n");
	strcpy_s(exit[48].description, 300, "The only exit is the door at the west.\n");
	strcpy_s(exit[50].description, 300, "The only exit is the door at the west.\n");
	strcpy_s(exit[51].description, 300, "You can see the city center from the interior of the shop.\n");

	player->position = 0;
}

