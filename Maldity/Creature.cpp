#include "World.h"
#include "Creature.h"
#include "Double-Linked List.h"

//This move enttities from one list to another
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

					if (((Exit*)world->entity[i])->open == false)
					{
						break;
					}

					Move(position, ((Exit*)(world->entity[i]))->destination, this);
					position = ((Exit*)(world->entity[i]))->destination;										
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


bool Creature::Take(const String& item_name)const
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

		it = it->next;
	}
	
	if (it == nullptr)
	{
		printf("There's nothing like a %s here.\n", item_name.C_str());
		return false;
	}

}

bool Creature::Take(const String& what, const String& from)const
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

/*void Player::Drop(const String& item_name)const
{
	int i;
	for (i = 0; i < MAX_ITEMS; i++)
	{
		if ((world->item[i]->location.Compare("inventory") || world->item[i]->location.Compare("equipped")) && world->item[i]->name.Compare(item_name.C_str()))
		{ 
			world->item[i]->location = world->room[position]->name.C_str();
			printf("You dropped the %s.\n", world->item[i]->name.C_str());
			world->player->num_items--;
			break;
		}	
	}

	if (i == MAX_ITEMS) printf("You have no %s in your inventory.\n", item_name.C_str());
}

void Player::PutIn(const String& what, const String& in)const
{
	int i=0, j=0;
	
	if (what.Compare(in))
		printf("You can't put an object into itself!\n");

	else for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->name.Compare(what.C_str()) && world->item[i]->location.Compare("inventory"))
		{
			for (j = 0; j < MAX_ITEMS; j++)
			{

				if (world->item[j]->name.Compare(in.C_str()) && (world->item[j]->location.Compare(world->room[position]->name.C_str()) || world->item[j]->location.Compare("inventory")))
				{
					if (world->item[j]->capacity == 0)
						printf("You can't put nothing in the %s!\n", world->item[j]->name.C_str());

					else if (world->item[j]->capacity == world->item[j]->num_items)
						printf("The %s its full. You can't put more items in it.\n", in.C_str());

					else
					{
					printf("You put the %s in the %s.\n", what.C_str(), in.C_str());
					world->item[i]->location = world->item[j]->name.C_str();
					world->item[j]->num_items++;
					world->player->num_items--;
					}

					break;
				}

				
			}

			if (j == MAX_ITEMS)
				printf("There's nothing like a %s here.\n", in.C_str());
			break;
		}

	}

	if (i == MAX_ITEMS) printf("You have no %s in your inventory.\n", what.C_str());


}
*/
void Creature::ShowStats()
{
	printf("-----%s's Status        Sanity at %i%\n", name.C_str(), sanity);
	printf("Health: %i \nAtk: %i\nDef: %i\n", health, atk, def);	
}

/*bool Player::Unequip()
{
	
	for ( int i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->location.Compare("equipped"))
		{
			world->item[i]->location = "inventory";
			health -= world->item[i]->bonus_hp;
			def -= world->item[i]->bonus_def;
			atk -= world->item[i]->bonus_atk;

			printf("You unequip the %s.\n", world->item[i]->name.C_str());
			world->player->num_items++;
			return true;
			
		}
	}

	return false;
}

void Player::Equip(const String& item)
{
	int i = 0;
	
	for (i = 0; i < MAX_ITEMS; i++)
	{

		if (world->item[i]->name.Compare(item.C_str()) && world->item[i]->location.Compare("inventory"))
		{

			if (world->item[i]->equippable)
			{ 

			Unequip();

			printf("You equip the %s.\n", world->item[i]->name.C_str());
			world->item[i]->location = "equipped";
			world->player->num_items--;

			health += world->item[i]->bonus_hp;
			atk += world->item[i]->bonus_atk;
			def += world->item[i]->bonus_def;

			}
			else printf("You can't equip that!\n");

			break;
		}

		
	}

	if (i == MAX_ITEMS)
		printf("You have nothing like that in your inventory.\n");

}

*/