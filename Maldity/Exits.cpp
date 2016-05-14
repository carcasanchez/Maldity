#include "Exits.h"
#include "World.h"

void Exit::Look()const
{

	printf("%s", description.C_str());
	if (door)
		if (open)
			printf("The door is open.\n");
		else printf("The door is closed.\n");
		

}

