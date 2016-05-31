#include "World.h"
#include "Creature.h"
#include "Double-Linked List.h"



void Creature::Update(){

	if (state == talking)
	{

		if (*world->last_key == '\r')
		{
			Talking();
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

bool Creature::Talking()
{
	
		int i = world->player_input.FirstAscii() - 1;

		printf("\n");


		if (i < 0 || i >= dialog->current->option.Size())
		{
			printf("You have chose an invalid option.");
			return false;
		}

		printf("%s", dialog->current->option[i]->text);

		


		if (dialog->current->option[i]->next == nullptr)
		{
			dialog->current = dialog->current->option[i];

			if (dialog->current->option.Empty())
			{
				state = walking;
				world->player->state = walking;
				world->player_input.Clean();
				if (this == world->demented)
				{
					for (List<Entity*>::Node* it = world->balcony->inside.first; it != nullptr; it = it->next)
					{
						if (it->data == world->demented)
						{
							world->balcony->inside.Erase(it);
							break;
						}
					}
				}


				return false;
			}			
		}

		else
		{
			dialog->current = dialog->current->option[i]->next;
		}


		printf("\n");

		int size = dialog->current->option.Size();

		for (int i = 0; i < size; i++)
			{
				printf("%i: %s", i + 1, dialog->current->option[i]->title.C_str());
			}
			return true;
		
	
}



