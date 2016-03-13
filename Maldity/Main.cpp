#include "World.h"

#define _CRT_SECURE_NO_WARNINGS

World world;

int main(){
	
	char command1[10] = "empty";
	char command2[10] = "empty";
	int *position=nullptr;

	world.CreateWorld();
	position = &world.player->position;

	printf("%s", world.room[*position].description);

	while (1){
		
		printf("\n");
		while (strcmp(command1, "empty") == 0){
			AskCommands(command1, command2);
		}
			

		//quit
		if (strcmp(command1, "quit") == 0){
			return 0;
		}
			

		//look
		else if (strcmp(command1, "look") == 0){
			if (strcmp(command2, "empty") == 0)
				printf("%s", world.room[*position].description);

			else for (int i = 0; i <= 52; i++){

				if (i == 52){
					printf("You can't do that\n");
					break;
				}

				if ((strcmp(command2, world.exit[i].orientation) != 0) || (strcmp(world.room[*position].name, world.exit[i].origin) != 0)){
					continue;

				}
				printf("%s", world.exit[i].description);
				break;
			}
		}


		//go
		else if (strcmp(command1, "go") == 0){
			for (int i = 0; i <= 52; i++){

				if (i == 52){
					printf("You can't do that\n");
					break;
				}

				if ((strcmp(command2, world.exit[i].orientation) != 0) || (strcmp(world.room[*position].name, world.exit[i].origin) != 0)){
					continue;
					}
	
				if (strcmp(world.exit[i].destination, "empty") == 0)
					printf("%s", world.exit[i].description);	
				
				else{
					int j = 0;
					for (j = 0; j < 52; j++){
						if (strcmp(world.room[j].name, world.exit[i].destination)!=0){
							continue;
						}
						break;
					}
					*position = j;
					system("cls");
					printf("%s", world.room[*position].description);
				}
				break;
			}
		}
	



	strcpy_s(command1, 6, "empty");
	strcpy_s(command2, 6, "empty");
	}


}