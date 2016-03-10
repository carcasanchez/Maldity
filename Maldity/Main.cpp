#include <stdio.h>
#include "Maldity.h"

World world;

int main(){
	int* room;

	world.CreateWorld(room);

	for (int i = 0; i < 13;i++)
	room[i] = i;

	for (int i = 0; i < 13; i++)
	printf("%i\n", room[i]);

	world.DestroyWorld(room);
	
	getchar();
	return 0;

}