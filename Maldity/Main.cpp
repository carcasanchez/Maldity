#include "Maldity.h"

World world;

int main(){

	char player_input[20];
	char command1[10] = "empty";
	char command2[10] = "empty";
	
	//world.CreateWorld();
		
	gets_s(player_input, 20);

	MyStrtok(player_input, command1, command2);
	
	
	if (strcmp("empty", command2)==0){
		printf("Insert second command\n");
		gets_s(command2, 10);
	}

	printf("%s\n", command1);
	printf("%s\n", command2);
	getchar();
	return 0;

}