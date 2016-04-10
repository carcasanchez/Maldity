/*#include "World.h"
#include "String.h"
#define _CRT_SECURE_NO_WARNINGS





void AskCommands(char *command1, char *command2)
{
	

	char player_input[20];
	gets_s(player_input, 20);
	

	MyStrtok(player_input, command1, command2);

	if (Compare("empty", command2)){
		
		
		if (Compare(command1, "look")){
			Copy(command2, 6, "empty");
			}
		else if (Compare(command1, "go"))
		{
			printf("Where do you want to go?\n");
			gets_s(command2, 10);
		}

		else if (Compare(command1, "open"))
		{
			printf("What do you want to open?\n");
			gets_s(command2, 10);
		}

		else if (Compare(command1, "close"))
		{
			printf("What do you want to close?\n");
			gets_s(command2, 10);
		}

		else if (Compare(command1, "quit"))
		{
			Copy(command1, 5, "quit");
		}

		else if (Compare(command1, "help"))
		{
			printf("Welcome to Maldity!\nUse the commands 'go' and 'look', and the cardinal directions \nto explore the map.\nIf you use only 'look', you will receive a description of your current room.\nIf you encounter a closed door, use the 'open door' command.\nUse 'close door' for close it.\nUse 'quit' if you want to exit the game.\n\n");
			Copy(command1, 6, "empty");
		}

		else {
			printf("You have entered and invalid command\n\n");
			Copy(command1, 6, "empty");
		}


	}


}
*/
