#include "World.h"

#define _CRT_SECURE_NO_WARNINGS

World world;

int main(){
	
	char command1[10] = "empty";
	char command2[10] = "empty";
	int position=0;

	world.CreateWorld();
	position = world.player->position;


	while (1){
	


		while (strcmp(command1, "empty") == 0){
			AskCommands(command1, command2);
		}

		if (strcmp(command1, "quit") == 0){
			return 0;
		}


		//look
		else if (strcmp(command1, "look") == 0){
			if (strcmp(command2, "empty") == 0)
				printf("%s", world.room[position].description);

			for (int i = 0; i < 52; i++){


				if ((strcmp(command2, world.exit[i].orientation) != 0) || (strcmp(world.room[position].name, world.exit[i].origin) != 0)){
					continue;

				}
				printf("%s", world.exit[i].description);
				break;
			}
		}

		//go


	
	strcpy_s(command1, 6, "empty");
	strcpy_s(command2, 6, "empty");
	}


}