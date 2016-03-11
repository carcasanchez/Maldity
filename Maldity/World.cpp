#include "Maldity.h"

/*
World::World()
{

	room = new Room[13];
	exit = new Exits[4];
}

World::~World()
{
	
	delete[] room;
	delete[] exit;
}

void World::CreateWorld()
{

	strcpy(room[0].name, "Forest");
	strcpy(room[0].description, "You are in a forest. \nAt south, you see that the road drives to a city. \nAt west, a high hill. \nAt north, the road vanishes in the distance. \nAt east, only the sea.");
	
	strcpy(room[1].name, "Road");
	strcpy(room[1].description, "You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest\n");
	
	strcpy(room[2].name, "Beach");
	strcpy(room[2].description, "The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n");

	strcpy(room[3].name, "Dock");
	strcpy(room[3].description, "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n");

	strcpy(room[3].name, "Center");
	strcpy(room[3].description, "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n");

}
*/
void MyStrtok(char *player_input, char *command1, char *command2){
	int i, j;

	for (i = 0; player_input[i] != ' ' && player_input[i] != '\0'; i++){

		command1[i] = player_input[i];
	}
	command1[i] = '\0';

	if (player_input[i] == ' '){
		i++;
		for (j = 0; player_input[i] != NULL; j++, i++){

			command2[j] = player_input[i];
		}
		command2[j] = '\0';
	}

}