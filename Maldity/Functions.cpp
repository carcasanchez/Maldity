#include "Functions.h"
#include "World.h"
#define _CRT_SECURE_NO_WARNINGS

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

void AskCommands(char *command1, char *command2){
	

	char player_input[20];
	gets_s(player_input, 20);

	MyStrtok(player_input, command1, command2);

	if (strcmp("empty", command2) == 0){
		
		
		if (strcmp(command1, "look") == 0){
			strcpy_s(command1, 6, "empty");
			}
		else if (strcmp(command1, "go") == 0){
			printf("Where do you want to go?\n");
			gets_s(command2, 10);
		}

		else if (strcmp(command1, "open") == 0){
			printf("What do you want to open?\n");
			gets_s(command2, 10);
		}

		else if (strcmp(command1, "close") == 0){
			printf("What do you want to close?\n");
			gets_s(command2, 10);
		}

		else if (strcmp(command1, "quit") == 0){
			strcpy_s(command1, 5,"quit");
		}

		else if (strcmp(command1, "help") == 0){
			printf("This is a Zork in construction\nValid commands are 'go', 'look', 'open', 'close', 'quit', and 'help'\n");
			strcpy_s(command1, 6, "empty");
		}

		else {
			printf("You have entered and invalid command\n");
			strcpy_s(command1, 6,"empty");
		}


	}


}
