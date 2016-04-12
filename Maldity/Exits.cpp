#include "Exits.h"
#include "Player.h"
#include "World.h"

void Exits::Look()const
{
	printf("%s", description.C_str());
	if (door)
		if (open)
			printf("The door is open.\n");
		else printf("The door is closed.\n");

	
}

void Exits::Open()
{



}

void Exits::Close()
{



}