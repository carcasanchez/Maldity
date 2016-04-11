#include "World.h"


int main(){
	World* world = nullptr;
	world = new World;

	int *player_pos = &world->player->position;
	String player_input;
	String command1;
	String command2;
	String command3;
	String command4;


	world->CreateWorld();

	
	while (player_input.Compare("quit")==false)
	{
		printf("%s", world->room[*player_pos].description.C_str());
	
		while (1)
		{	
			printf("\n");
			scanf_s("%s", player_input);  ///NEEDS REVISION
			
			command1 = player_input.Strtok(' ', 1);
			command2 = player_input.Strtok(' ', 2);
			command3 = player_input.Strtok(' ', 3);
			command4 = player_input.Strtok(' ', 4);

			if (player_input.Compare("quit") && command2.Empty())
				break;

			else if (command1.Compare("look"))
			{ 
				if(command2.Empty());
				world->Look();
			}

			else if (command1.Compare("go"))
			{

			}
			
			else printf("%s", "You have entered an invalid command.\n");

			fflush(stdin);

		}

		
	/*

	char command1[10] = "empty";
	char command2[10] = "empty";
	int *position=nullptr;

	world->CreateWorld();
	position = &world->player->position;

	printf("%s", world->room[*position].description);

	while (1){
		
		printf("\n");
		while (strcmp(command1, "empty") == 0)
		{
			AskCommands(command1, command2);
		}
			

		//quit

		if (strcmp(command1, "quit") == 0)
		{
			return 0;
		}
			

		//look
		else if (strcmp(command1, "look") == 0)
		{
			world.Look(command1, command2);
		}


		//go
		else if (strcmp(command1, "go") == 0)
		{
			for (int i = 0; i <= 52; i++)
			{

				if (i == 52)
				{
					printf("You can't do that\n");
					break;
				}

				if ((strcmp(command2, world.exit[i].orientation) != 0) || (strcmp(world.room[*position].name, world.exit[i].origin) != 0))
				{
					continue;
				}


				if (strcmp(world.exit[i].destination, "empty") == 0)
					printf("%s", world.exit[i].description);
				else if (world.exit[i].door == true && world.exit[i].open == false)
				{
					printf("The door is closed. You can't go on that direction.\n");
					break;
				}
				else
				{
					int j = 0;
					for (j = 0; j < 52; j++)
					{
						if (strcmp(world.room[j].name, world.exit[i].destination) != 0)
						{
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


		//open
		else if (strcmp(command1, "open") == 0)
		{
			if (strcmp(command2, "door") != 0)
				printf("You can't do that.\n");

			else for (int i = 0; i < 52; i++)
			{
				if ((strcmp(world.exit[i].origin, world.room[*position].name) == 0) && world.exit[i].door)
				{
					if (world.exit[i].open==true)
						printf("The door is already open.\n");
				
					else
					{ 
						printf("Door opened.\n"); 
						world.exit[i].open = true;
					}
					break;
				}

				if (i == 51) printf("There's no door here.\n");
			}
		}


		//close
		else if (strcmp(command1, "close") == 0)
		{
			if (strcmp(command2, "door") != 0)
				printf("You can't do that.\n");

			else for (int i = 0; i < 52; i++)
			{
				if ((strcmp(world.exit[i].origin, world.room[*position].name) == 0) && world.exit[i].door)
				{
					if (world.exit[i].open==true){
						printf("Door closed.\n");
						world.exit[i].open = false;
					}
					
					else 
					{
						printf("The door is already closed\n");
						
					}
					break;
				}
				if (i == 51) printf("There's no door here.\n");
			}
			
		}

		else printf("You have entered an invalid command.\n");




	strcpy_s(command1, 6, "empty");
	strcpy_s(command2, 6, "empty");
	}

	*/
	}

	return 0;
}