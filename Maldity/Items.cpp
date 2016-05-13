#include "Items.h"
#include "World.h"
#include "Creature.h"
#include <iostream>

void Item::Look()const
{
	printf("%s", description.C_str());

	for (List<Entity*>::Node *it = inside.first; it != nullptr; it = it->next)
	{
		printf("It has a %s inside.\n", it->data->name.C_str());
	}
}