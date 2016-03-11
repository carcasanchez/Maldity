#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#ifndef __MALDITY_H__
#define __MALDITY_H__


class World{
	public:
		/*
	Room* room = nullptr;
	Exits* exit = nullptr;
	World();
	~World();
*/

	void CreateWorld();
	
};
		
struct Room{
	
	char name[15];
	char description[250];

};

struct Player{

	char position[10];

};

struct Exits{
	char origin[10];
	char destination[10];
	char description[];
	bool door();

};


void MyStrtok(char *player_input, char *command1, char *command2);

#endif