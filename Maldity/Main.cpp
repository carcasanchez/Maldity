#include "World.h"

#define _CRT_SECURE_NO_WARNINGS

World world;

int main(){
	
	char command1[10] = "empty";
	char command2[10] = "empty";
	world.CreateWorld();
	

	while (1){

		printf("%s\n", world.player->position);

		while (strcmp(command1, "empty")==0){
			AskCommands(command1, command2);
		}

		if (strcmp(command1, "quit") == 0){
			return 0;
		}

	
	strcpy_s(command1, 6, "empty");
	strcpy_s(command2, 6, "empty");
	}


}