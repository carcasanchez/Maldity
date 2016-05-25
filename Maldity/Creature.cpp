#include "World.h"
#include "Creature.h"
#include "Double-Linked List.h"



void Creature::Update(){}


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





