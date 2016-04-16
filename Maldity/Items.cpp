#include "Items.h"
#include "World.h"
#include "Player.h"
#include <iostream>

void Item::Look()
{

	if (location.Compare(world->room[world->player->position]->name.C_str()) || location.Compare("inventory")|| location.Compare("equipped"))
	{ 
	printf("%s", description);

	if (num_items > 0)
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			if (world->item[i]->location.Compare(name))
				printf("There's a %s inside.\n", world->item[i]->name.C_str());
		}
	}
	else printf("There's nothing like that here.\n");
}