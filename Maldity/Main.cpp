#include "MemLeaks.h"
#include "World.h"
#include "Player.h"

World* world = nullptr;

int main(){
	ReportMemoryLeaks();

	world = new World;
	world->CreateWorld();


	Room* player_pos = world->player->position;
	

	char temp[40];

	String player_input;
	String command1;
	String command2;  
	String command3;
	String command4;

	
	
	
	printf("\n				MALDITY\n\n");

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
					List <Exit*> ::Node *it = nullptr;
					it = world->exit.first;

					while (it != nullptr)
					{
						if (command2.Compare(it->data->orientation.C_str()) && player_pos->data->name.Compare(it->data->origin.C_str()))
						{
							it->data->Look();
							break;
						}

						it = it->next;
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
			else if (command1.Compare("go") && command2.Empty() == false && command3.Empty())
			{
				if (world->player->Go(command2))
					break;
			}

			//OPEN
			else if (command1.Compare("open") && command3.Empty() == false && command4.Empty())
			{
				

				if (command3.Compare("door"))
					world->player->Open(command2);

				else printf("You can't do that.\n");
			}


			//CLOSE
			else if (command1.Compare("close") && command3.Empty() == false && command4.Empty())
			{

				if (command3.Compare("door"))
					world->player->Close(command2);


				else printf("You can't do that.\n");
			}

			//TAKE
			else if ((command1.Compare("take") || command1.Compare("pick")) && (command2.Empty() == false) && (command3.Empty()))
			{
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
			else if (command1.Compare("equip") && command3.Empty() && command2.Empty() == false)
			{
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
				List <Item*> ::Node *it = world->player->inside.first;
				printf("\n-----Jasna's inventory:\n");

				if (it == nullptr)
					printf("The inventory is empty.\n");
				
				while (it != nullptr)
				{
					printf("%s", it->data->description.C_str());
					it = it->next;
				}
				
			}
			
			//STATS

			else if (command1.Compare("stats") && command2.Empty())
				{
					world->player->ShowStats();
				}

			//HELP
			else if (player_input.Compare("help"))
				printf("Welcome to Maldity!\nUse the command 'look' for receive a description of the current room.\nCombine it with 'north', 'south', 'east' and 'west' to receive descriptions \nof the exits.	\nUse 'go' and 'north', 'south', 'east' and 'west' to move between rooms. \nUse 'open <orientation> door' if you find a closed door, or \n'close <orientation> door' if you want to close it.\nSee your inventory whit 'inventory' or 'i'.\nCheck your status with 'Stats'.\nUse 'take' or 'pick' to take objects.\nUse 'take <item> from <item>' and 'put <item> in <item>' to take and put in \nother items.\nAlso, you can look at items.\nYou can equip objects to increase your stats. Use 'unequip' to unequip them.\nUse 'help' to see the controls and 'quit' if you want to finish the game.\n");

			//INVALID COMMAND
			else printf("You have entered an invalid command.\n");

			
			fflush(stdin);

		}

		system("cls");
	
	}

	
	return 0;
}