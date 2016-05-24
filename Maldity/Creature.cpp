#include "World.h"
#include "Creature.h"
#include "Double-Linked List.h"



void Creature::Update()
{


	if (this == world->vendor)
	{
		if (state == talking)
		{
			printf("Vendor: Hello, dear, to my shop! I have a lot of thing to trade with you.\n");
			for (List<Entity*>::Node* it = inside.first; it != nullptr; it = it->next)
			{
				printf("%s for %i coins.\n", it->data->name.C_str(), ((Item*)it->data)->value);
			}
			printf("\n");
			state = walking;
			world->player->state = walking;
		}
	}
	
}


bool Creature::Go(Cardinal dest)
{
	int i;

	for (i = 0; i < world->entity.Size(); i++)
	{
		if (world->entity[i]->type == EXIT)
		{

			if (((Exit*)world->entity[i])->orientation == dest && ((Exit*)world->entity[i])->origin == position)
			{
				if (((Exit*)world->entity[i])->destination == nullptr)
					break;

				if (((Exit*)world->entity[i])->open == false)
				{
					break;
				}

				Move(position, ((Exit*)(world->entity[i]))->destination, this);
				position = ((Exit*)(world->entity[i]))->destination;
				world->player->last_direction = dest;
				return true;
			}
		}

	}

	return false;
}





