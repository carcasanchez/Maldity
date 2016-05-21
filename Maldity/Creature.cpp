#include "World.h"
#include "Creature.h"
#include "Double-Linked List.h"
#include <time.h>


void Creature::Update()
{
	srand(time(NULL));

	if (this == world->ghost)
	{
		if (state == walking)
		{
			if (GetTickCount() - world->time > 5000)
			{
				Cardinal orient = Cardinal(rand() % 4);

				if (Go(Cardinal(orient)) && position == world->player->position)
				{
					printf("The ghost enters the %s.\n", world->ghost->position->name.C_str());
				}
				world->ResetTime();
			}


			if (position == world->player->position)
			{
				state = following;
			}
		}

		else if (state == following)
		{
			if (position != world->player->position && GetTickCount() - world->time > 5000)
			{
				Go(world->player->last_direction);



				if (position == world->player->position)
				{
					printf("The ghost enters the %s.\n", world->ghost->position->name.C_str());
				}
				else state = walking;

				world->ResetTime();
			}
		}

		else if (state == talking)
		{
			printf("Ghost: Hello!\n\n");
			state = following;
			world->player->state = walking;
		}
	}

	else if (this == world->vendor)
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




//This move entities from one list to another
void Move(Entity* source, Entity* destination, const Entity* entity)
{
	List <Entity*> ::Node* n = source->inside.first;


	while (n != nullptr)
	{
		List <Entity*> ::Node* tmp = n->next;

		if (n->data == entity)
		{
			destination->inside.PushBack(n->data);
			source->inside.Erase(n);
		}

		n = tmp;
	}


}

bool Creature::Go(Cardinal dest)
{
	int i;

		for ( i = 0; i < world->entity.Size(); i++)
		{
			if (world->entity[i]->type == EXIT)
			{

				if (((Exit*)world->entity[i])->orientation == dest && ((Exit*)world->entity[i])->origin == position)
				{
					if (((Exit*)world->entity[i])->destination == nullptr)
						break;

					if (((Exit*)world->entity[i])->open == false && this != world->ghost)
					{
						break;
					}

					Move(position, ((Exit*)(world->entity[i]))->destination, this);
					position = ((Exit*)(world->entity[i]))->destination;			
					last_direction = dest;
					return true;
				}
			}
				
		}
		
		
		if (type == PLAYER)
		{
			printf("%s", world->entity[i]->description.C_str());
			
			if (((Exit*)(world->entity[i]))->open==false)
				printf("The door is closed.\n");

		}
			

		return false;
}

void Creature::Open(Cardinal orient)const
{
	int i;
	for (i = 0; i < world->entity.Size();i++)

		if (((Exit*)world->entity[i])->orientation == orient && ((Exit*)world->entity[i])->origin == world->player->position)
		{	
			if (((Exit*)world->entity[i])->door == false)
				printf("There's no door on that direction.\n");

			else if (((Exit*)world->entity[i])->open)
				printf("The door is already open.\n");

			else if (((Exit*)world->entity[i])->open == false)
			{ 
				printf("You open the door.\n");
				((Exit*)world->entity[i])->open = true;
			}	
			break;
		}
}

void Creature::Close(Cardinal orient)const
{
	int i;
	for (i = 0; i < world->entity.Size(); i++)

		if (((Exit*)world->entity[i])->orientation == orient && ((Exit*)world->entity[i])->origin == world->player->position)
		{
			if (((Exit*)world->entity[i])->door == false)
				printf("There's no door on that direction.\n");

			else if (((Exit*)world->entity[i])->open==false)
				printf("The door is already closed.\n");

			else if (((Exit*)world->entity[i])->open)
			{
				printf("You close the door.\n");
				((Exit*)world->entity[i])->open = false;
			}
			break;
		}
}

bool Creature::Take(const String& item_name)
{

	List<Entity*>::Node* it = position->inside.first;


	if (inside.Size() == limit)
	{
		printf("Your inventory is full.\n");
		return false;
	}

	while (it != nullptr)
	{
		if ((it->data->type == EQUIP_ITEM || it->data->type == NON_EQUIP_ITEM) && it->data->name.Compare(item_name))
		{
			
			Move(position, (Entity*)this, it->data);
			printf("You pick the %s.\n", item_name.C_str());
			return true;
		}

		else if (it->data->type == NPC)
		{
			printf("You can't take the %s!.\n", it->data->name.C_str());
			return false;
		}

		it = it->next;
	}
	
	if (it == nullptr)
	{
		printf("There's nothing like a %s here.\n", item_name.C_str());
		return false;
	}

}

bool Creature::Take(const String& what, const String& from)
{	
	List<Entity*>::Node* iterator = position->inside.first;
	List<Entity*>::Node* it = nullptr;


	if (inside.Size() == limit)
	{
		printf("Your inventory is full.\n");
		return false;
	}

	//Check in the room
	while (iterator != nullptr)
	{
		if (iterator->data->name.Compare(from))
		{
			it = iterator->data->inside.first;
			break;
		}
		iterator = iterator->next;
	}

	

	//Else, check in the inventory
	if (iterator == nullptr)
	{
		iterator = inside.first;

		while (iterator != nullptr)
		{
			if (iterator->data->name.Compare(from))
			{
				it = iterator->data->inside.first;
				break;
			}
			iterator = iterator->next;
		}

	}
	
	if (iterator == nullptr)
	{
		printf("There's nothing like a %s here.\n", from.C_str());
		return false;
	}

	else if (iterator->data->type == NPC)
	{
		printf("Better not to try to steal things in this place...\n");
		return false;
	}

			
	while (it != nullptr)
	{
		if ((it->data->type == EQUIP_ITEM || it->data->type == NON_EQUIP_ITEM) && it->data->name.Compare(what))
		{
			Move(iterator->data, (Entity*)this, it->data);
			printf("You pick the %s.\n", what.C_str());
			return true;
		}

		it = it->next;
	}

	if (it == nullptr)
	{
		printf("There's nothing like a %s inside the %s.\n", what.C_str(), from.C_str());
		return false;
	}

}

void Creature::Drop(const String& item_name)
{
	List<Entity*>::Node* it = inside.first;

	while (it != nullptr)
	{
		if (it->data->name.Compare(item_name))
		{
			Move(this, position, it->data);
			printf("You drop the %s.\n", item_name.C_str());
			if (it->data == equipped_item)
				equipped_item = nullptr;
			break;
		}

		it = it->next;
	}

	if (it == nullptr)
	{
		printf("There's nothing like a %s in your inventory.\n", item_name.C_str());
	}
}

bool Creature::PutIn(const String& what, const String& in)
{	

	List<Entity*>::Node* iterator = position->inside.first;
	List<Entity*>::Node* it = inside.first;


	if (what.Compare(in))
	{ 
		printf("You can't put an object into itself!\n");
		return false;
	}

	//Check in the room
	while (iterator != nullptr)
	{
		if (iterator->data->name.Compare(in))
		{
			break;
		}
		iterator = iterator->next;
	}

	//Check the inventory
	if (iterator == nullptr)
	{
		iterator = inside.first;
		while (iterator != nullptr)
		{
			if (iterator->data->name.Compare(in))
			{
				break;
			}
			iterator = iterator->next;
		}
	}

	if (iterator == nullptr)
	{
		printf("There's nothing like a %s here.\n", in.C_str());
		return false;
	}

	if (iterator->data->inside.Size() == ((Item*)iterator->data)->limit)
	{
		if (((Item*)iterator->data)->limit == 0)
			printf("You can't put objects inside the %s!\n", in.C_str());
		else
				printf("The %s is full.\n", in.C_str());

		return false;
	}




	while (it != nullptr)
	{
		if (it->data->name.Compare(what))
		{			
			Move(this, iterator->data, it->data);
			printf("You put the %s in the %s.\n", what.C_str(), in.C_str());
			return true;
		}

		it = it->next;
	}

	if (it == nullptr)
	{
		printf("There's nothing like a %s in your inventory.\n", what.C_str());
		return false;
	}

}

void Creature::ShowStats()
{
	printf("-----%s's Status        Sanity at %i%\n", name.C_str(), sanity);
	printf("Health: %i \nAtk: %i\nDef: %i\n", health, atk, def);	

	if (equipped_item != nullptr)
	{
		printf("%s equipped\n", equipped_item->name.C_str());
	}
}

bool Creature::Unequip()
{
	if (equipped_item == nullptr)
	{
		printf("You have nothing equipped.\n");
		return false;

	}

	printf("You unequip the %s.\n", equipped_item->name.C_str());
	
	health -= ((Item*)equipped_item)->bonus_hp;
	atk -= ((Item*)equipped_item)->bonus_atk;
	def -= ((Item*)equipped_item)->bonus_def;
	sanity -= ((Item*)equipped_item)->bonus_sanity;

	equipped_item = nullptr;
	return true;
}

bool Creature::Equip(const String& item)
{
	
	for (List<Entity*>::Node* it = inside.first; it != nullptr; it = it->next)
	{
		if (it->data->name.Compare(item.C_str()))
		{
			if (it->data->type == NON_EQUIP_ITEM)
			{
				printf("You can't equip the %s.\n", item.C_str());
				return false;
			}

			if (it->data->type == EQUIP_ITEM)
			{

				if (equipped_item != nullptr)
				{
					Unequip();						
				}
				printf("You equip the %s.\n", item.C_str());

				health += ((Item*)it->data)->bonus_hp;
				atk += ((Item*)it->data)->bonus_atk;
				def += ((Item*)it->data)->bonus_def;
				sanity += ((Item*)it->data)->bonus_sanity;


				equipped_item = it->data;
				return true;
			}

		}
	}

	printf("You have no %s in your inventory.\n", item.C_str());
	return false;

}

bool Creature::Talk_to(const String& interlocutor)
{
	for (List<Entity*>::Node* it = position->inside.first; it != nullptr; it = it->next)
	{
		if (it->data->name.Compare(interlocutor.C_str()))
		{
			if (it->data->type == NPC)
			{
				((Creature*)it->data)->state = talking;
				state = talking;
				return true;
			}

			else if (it->data->type == NON_EQUIP_ITEM || it->data->type == EQUIP_ITEM)
			{
				printf("You can't talk to a %s.!\n", interlocutor.C_str());
				return false;
			}
		}
	}


	printf("You can't do that.\n");
	return false;
}

bool Creature::Talking()
{
	return true;


}


