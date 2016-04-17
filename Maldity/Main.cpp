#include "World.h"
#include "Player.h"

World* world = nullptr;

int main(){
	
	world = new World;

	int *player_pos = &world->player->position;
	char temp[40];
	String player_input;
	String command1;
	String command2;  //TODO 1: make the commands a vector
	String command3;
	String command4;


	world->CreateWorld();
	
	
	while (player_input.Compare("quit")==false)
	{
		world->Look();
	
		while (1)
		{	
			printf("\n");
			gets_s(temp, 40);  
		
			player_input = temp;

			command1 = player_input.Strtok(' ', 1);
			command2 = player_input.Strtok(' ', 2);
			command3 = player_input.Strtok(' ', 3);
			command4 = player_input.Strtok(' ', 4);

			//MOVE USING n/s/e/w
			if (player_input.Compare("n"))
			{
				command1 = "go"; command2 = "north"; command3.Clean();
			}
			else if (player_input.Compare("s"))
			{
				command1 = "go"; command2 = "south"; command3.Clean();
			}
			else if (player_input.Compare("e"))
			{
				command1 = "go"; command2 = "east"; command3.Clean();
			}
			else if (player_input.Compare("w"))
			{
				command1 = "go"; command2 = "west"; command3.Clean();
			}
			




			if (player_input.Empty()){}

			//QUIT
			else if (player_input.Compare("quit"))
				break;
			
			
			//LOOK
			else if (command1.Compare("look"))
			{ 
				//Look the room
				if(command2.Empty())
					world->Look();

				//Look the exits
				else if (command3.Empty())
				{
					int i, j;
					for (i = 0; i < 52;i++)
						if (world->exit[i]->orientation.Compare(command2)
							&& world->exit[i]->origin.Compare(world->room[*player_pos]->name.C_str()))
						{
							world->exit[i]->Look();
							break;
						}
					//Look the items
					if (i == 52)
						for (j = 0; j < MAX_ITEMS; j++)
						{
							if (world->item[j]->name.Compare(command2))
							{ 
								world->item[j]->Look();
								break;
							}

						}
					if (j == MAX_ITEMS)
						printf("There's nothing like a %s here.\n", command2.C_str());
				}
			}



			//GO
			else if (command1.Compare("go") && command3.Empty())
			{
				if (command2.Empty())
				{
					printf("Where do you want to go?\n");
					scanf_s("%s", command2); //TODO 4: revise the scanf's to Strings 
				}
					
				if (world->player->Go(command2))
					break;
				
			}
			//OPEN
			else if (command1.Compare("open") && command4.Empty())
			{
				if (command2.Empty())
				{ 
					printf("What do you want to open?\n");
					scanf_s("%s", command2);
					
				}	

				if (command2.Compare("door"))
				{
					printf("Where is the door do you want to open?\n");

					scanf_s("%s", command3);
					

					world->player->Open(command3);
				}
				else if (command3.Compare("door"))
					world->player->Open(command2);



				else printf("You can't do that.\n");
			}


			//CLOSE
			else if (command1.Compare("close") && command4.Empty())
			{
				if (command2.Empty())
				{
					printf("What do you want to close?\n");
					scanf_s("%s", command2);

				}

				if (command2.Compare("door"))
				{
					printf("Where is the door do you want to close?\n");

					scanf_s("%s", command3);


					world->player->Close(command3);
				}
				else if (command3.Compare("door"))
					world->player->Close(command2);



				else printf("You can't do that.\n");
			}

			//TAKE
			else if ((command1.Compare("take") || command1.Compare("pick"))&&(command3.Empty()))
			{
				if (command2.Empty())
				{
					printf("What do you want to %s?\n", command1);
					scanf_s("%s", command2);
				}
					
				world->player->Take(command2);

			}

			//TAKE FROM
			else if ((command1.Compare("take") || command1.Compare("pick")) && (command3.Compare("from")) && (command4.Empty() == false))
			{
				
				world->player->Take(command2, command4);

			}



			//DROP

			else if (command1.Compare("drop") && command3.Empty())
			{
				if (command2.Empty())
				{
					printf("What do you want to %s?\n", command1);
					scanf_s("%s", command2);
				}

				world->player->Drop(command2);
			}

			//PUT IN

			else if ( command1.Compare("put") && command3.Compare("in") && command4.Empty()==false )
			{
				world->player->PutIn(command2, command4);


			}

			//EQUIP
			else if (command1.Compare("equip") && command3.Empty())
			{
				if (command2.Empty())
				{
					printf("What do you want to equip?\n");
					scanf_s("%s", command2);
				}

				world->player->Equip(command2);


			}

			//UNEQUIP
			else if (command1.Compare("unequip") && command2.Empty())
			{ 
				if (world->player->Unequip() == false)
					printf("You have nothing equipped.\n");
					
				
			}
			//INVENTORY
			else if ((command1.Compare("inventory") || command1.Compare("i")) && command2.Empty())
			{
				int i;
				printf("\n-----Jasna's inventory:\n");
				for (i = 0; i < MAX_ITEMS; i++)
					if (world->item[i]->location.Compare("inventory"))
						printf("%s\n", world->item[i]->name.C_str());

				
			}
			
			//STATS

			else if (command1.Compare("stats") && command2.Empty())
				{
					world->player->ShowStats();
				}

			//HELP
			else if (player_input.Compare("help"))
				printf("Welcome to Maldity!\nUse the command 'look' for receive a description of the current room.\nCombine it with 'north', 'south', 'east' and 'west' to receive descriptions \nof the exits.	\nUse 'go' and 'north', 'south', 'east' and 'west' to move between rooms. \nUse 'open door' if you find a closed door, or 'close door' if you want to close it.\nUse 'help' to see the controls and 'quit' if you want to finish the game.\n");

			//INVALID COMMAND
			else printf("You have entered an invalid command.\n");

			
			fflush(stdin);

		}

		system("cls");
	
	}

	
	return 0;
}