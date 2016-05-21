#include "MemLeaks.h"
#include "World.h"
#include "Creature.h"
#include "conio.h"

World* world = nullptr;

int main(){
	ReportMemoryLeaks();

	world = new World;
	world->CreateWorld();


	Room* player_pos = nullptr;

	char key[2];

	String player_input("");
	String command1;
	String command2;  
	String command3;
	String command4;

	Cardinal orient = NONE;
	
	
	printf("\n				MALDITY\n\n");

	while (player_input.Compare("quit")==false)
	{
		key[0] = 0;
		player_input.Clean();

		player_pos = world->player->position;
		world->Look();
		printf("\n");

		while (1)
		{	
			orient = NONE;
			
				
			if (_kbhit() != 0)
			{
				key[0] = _getch();
				key[1] = 0;

				if (key[0] == '\b' && player_input.Empty()==false)
				{
					player_input.BackSpace();
					printf("\b");
					printf(" ");
					printf("\b");
				}

				else if (key[0] != '\r')
				{
					printf("%c", key[0]);
					player_input += key;
				}
			}
			

			//UPDATE
			for (int i = 1; i < world->entity.Size(); i++)
				world->entity[i]->Update();

			
			
			if (key[0] != '\r')
				continue;

			
			printf("\n");
			
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


			//TRANSLATE THE ORIENTATION COMMAND INTO CARDINAL
			if (command2.Compare("north"))
				orient = N;
			else if (command2.Compare("south"))
				orient = S;
			else if (command2.Compare("east"))
				orient = E;
			else if (command2.Compare("west"))
				orient = W;
			


			if (world->player->state == walking)
			{
				if (player_input.Empty()){}

				//QUIT
				else if (player_input.Compare("quit"))
					break;


				//LOOK
				else if (command1.Compare("look"))
				{
					//Look the room
					if (command2.Empty())
						world->Look();


					else if (command3.Empty())
					{



						//Look the exits
						if (orient != NONE) for (int i = 0; i < world->entity.Size(); i++)
						{
							if (world->entity[i]->type == EXIT)
								if (((Exit*)world->entity[i])->orientation == orient && ((Exit*)world->entity[i])->origin == player_pos)
								{
									((Exit*)world->entity[i])->Look();
									break;
								}
						}

						//Else, look entities
						else
						{
							//In the room
							List<Entity*>::Node* it = player_pos->inside.first;
							while (it != nullptr)
							{
								if (it->data->name.Compare(command2) &&
									(it->data->type == NON_EQUIP_ITEM ||
									it->data->type == EQUIP_ITEM ||
									it->data->type == NPC))
								{
									it->data->Look();
									break;
								}

								it = it->next;
							}

							//In the inventory
							if (it == nullptr){
								it = world->player->inside.first;
								while (it != nullptr)
								{
									if (it->data->name.Compare(command2) &&
										(it->data->type == NON_EQUIP_ITEM ||
										it->data->type == EQUIP_ITEM))
									{
										it->data->Look();
										break;
									}

									it = it->next;
								}
							}

							if (it == nullptr)
								printf("There's nothing like a %s here.\n", command2.C_str());
						}
					}
				}



				//GO
				else if (command1.Compare("go") && command2.Empty() == false && command3.Empty())
				{

					if (orient == NONE)
						printf("That's not a direction you could go.\n");

					else if (world->player->Go(orient))
						break;

				}

				//OPEN
				else if (command1.Compare("open") && command3.Empty() == false && command4.Empty())
				{

					if (command3.Compare("door"))
						world->player->Open(orient);

					else printf("You can't do that.\n");
				}

				//CLOSE
				else if (command1.Compare("close") && command3.Empty() == false && command4.Empty())
				{

					if (command3.Compare("door"))
						world->player->Close(orient);


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

				else if (command1.Compare("drop") && command2.Empty() == false && command3.Empty())
				{

					world->player->Drop(command2);
				}


				//PUT IN

				else if (command1.Compare("put") && command3.Compare("in") && command4.Empty() == false)
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
					world->player->Unequip();
				}

				//TALK TO
				else if (command1.Compare("talk") && command2.Compare("to") && command3.Empty() == false)
				{
					world->player->Talk_to(command3);
				}

				//BUY FROM
				else if (command1.Compare("buy") && command3.Compare("from") && command4.Empty() == false)
				{
					world->player->Buy_from(command2, command4);
				}

				//SELL TO
				else if (command1.Compare("sell") && command3.Compare("to") && command4.Empty() == false)
				{
					world->player->Sell_to(command2, command4);
				}

				//INVENTORY
				else if ((command1.Compare("inventory") || command1.Compare("i")) && command2.Empty())
				{
					List <Entity*> ::Node *it = world->player->inside.first;
					printf("\n-----Jasna's inventory:\n");

					if (it == nullptr)
						printf("Your inventory is empty.\n");

					while (it != nullptr)
					{
						printf("%s\n", it->data->name.C_str());
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



				//	fflush(stdin);
				key[0] = 0;
				player_input.Clean();
			}
			printf("\n");
		}

		system("cls");
		
	
	}

	printf("Thanks for playing!");
	return 0;
}