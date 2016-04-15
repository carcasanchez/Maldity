#include "World.h"
#include "Player.h"


bool Player::Go(const String& dest)
{

		for (int i = 0; i < 52; i++)
		{
			
			if (world->exit[i]->orientation.Compare(dest.C_str()) && world->exit[i]->origin.Compare(world->room[position]->name.C_str()))
			{
				if ((world->exit[i]->door) && (world->exit[i]->open == false))
					{ 
					printf("You can't go on that direction. The door is closed.\n");
					return false;
					}

				if (world->exit[i]->destination.Empty())
					{
					printf("%s", world->exit[i]->description.C_str());
						return false;
					}


				for (int j = 0; j < 13; j++)
				if (world->room[j]->name.Compare(world->exit[i]->destination.C_str()))
					{

						position = j;
						return true;
					}					
			}
		}
		printf("You can't do that.\n");
		return false;
}

void Player::Open(const String& direction)const
{
	int i;
	for (i = 0; i < 52;i++)
		if (world->exit[i]->origin.Compare(world->room[position]->name.C_str())
			&& world->exit[i]->orientation.Compare(direction))
		{	
			if (world->exit[i]->door == false)
				printf("There's no door on that direction.\n");

			else if (world->exit[i]->open)
				printf("The door is already open.\n");

			else if (world->exit[i]->open == false)
			{ 
				printf("You open the door at %s.\n", direction.C_str());
				world->exit[i]->open = true;
			}	
			break;
		}

	if (i==52) printf("That's not a direction.\n");

}

void Player::Close(const String& direction)const
{
	int i;
	for (i = 0; i < 52; i++)
		if (world->exit[i]->origin.Compare(world->room[position]->name.C_str())
			&& world->exit[i]->orientation.Compare(direction))
		{
			if (world->exit[i]->door == false)
				printf("There's no door on that direction.\n");

			else if (world->exit[i]->open==false)
				printf("The door is already closed.\n");

			else if (world->exit[i]->open)
			{
				printf("You close the door at %s.\n", direction.C_str());
				world->exit[i]->open = false;
			}
			break;
		}

	if (i == 52) printf("That's not a direction.\n");



}

void Player::Take(const String& item_name)const
{
	int i;

	for ( i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->name.Compare(item_name.C_str())&&
			world->item[i]->location.Compare(world->room[position]->name.C_str()))
		{
			
			printf("You picked the %s.\n", world->item[i]->name.C_str());
			world->item[i]->location = "Inventory";
			break;
		}

	}

	if (i == 3) printf("There's nothing like that here.\n");
}

void Player::Take(const String& what, const String& from)const
{
	int i, j;

	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->name.Compare(from) && (world->item[i]->location.Compare(world->room[position]->name.C_str()) || world->item[i]->location.Compare("inventory")))
		{
			if (world->item[i]->capacity == 0)
				printf("You can't do that!");

			else if (world->item[i]->num_items == 0)
				printf("The %s is empty.\n", world->item[i]->name.C_str());

			else for (j = 0; j < MAX_ITEMS;j++)
			{ 
			
				if (world->item[j]->name.Compare(what) && world->item[j]->location.Compare(from))
				{
					printf("You picked the %s.\n", world->item[j]->name.C_str());
					world->item[j]->location = "Inventory";
					world->item[i]->num_items--;
					break;
				}
			
			}
			
			break;
		}

	}

	if (i == MAX_ITEMS) printf("There's nothing like that here.\n");
}

void Player::Drop(const String& item_name)const
{
	int i;
	for (i = 0; i < MAX_ITEMS; i++)
	{
		if (world->item[i]->location.Compare("inventory") && world->item[i]->name.Compare(item_name.C_str()))
		{ 
			world->item[i]->location = world->room[position]->name.C_str();
			printf("You dropped the %s.\n", world->item[i]->name.C_str());
			break;
		}	
	}

	if (i == 3) printf("You have no %s in your inventory.\n", item_name.C_str());
}

void Player::ShowStats()
{
	printf("-----Jasna's Status        Sanity at %i%\n", sanity);
	printf("Atk: %i\nDef:%i\n", atk, def);
}