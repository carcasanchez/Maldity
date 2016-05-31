#include "CreatureChilds.h"
#include <time.h>

void Player::Update()
{
	
	if (world->ghost->position == position && ghost_timer == 0)
	{
		ghost_timer = GetTickCount();
	}

	if (world->ghost->position == position && GetTickCount() - ghost_timer > 1000 && sanity > 1)
	{
		ghost_timer = GetTickCount();
		sanity--;
		gameover_timer = ghost_timer;
	}

	if (state == talking)
	{
		if (creature_timer == 0)
		{
			creature_timer = GetTickCount();
		}

		if (GetTickCount() - creature_timer > 5000 && sanity > 1 && world->knight->state != talking)
		{
			creature_timer = GetTickCount();
			sanity--;
			gameover_timer = creature_timer;
		}

	}	



	switch (sanity)
	{
		case 1:
			printf("~7☻83-todos♣</,1_uswe89hg@#~€¬546#wvr€~ERAgays@#~€€#452");
			if (GetTickCount() - gameover_timer > 2000)
				sanity--;
			break;

		case 75:
			printf("You start to feel a little bit tired.\n");
			sanity--;
			break;

		case 50:
			printf("You feel nervous while the city goes darker around you.\n");
			sanity--;
			break;

		case 30:
			printf("You hear voices and screams. But around you, there's nobody.\n");
			sanity--;
			break;

		case 20:
			printf("You feel exhausted. The city seems to call you.\n");
			sanity--;
			break;

		case 10:
			printf("You collapse at the ground. When you stand up, the whole world seems to \nfall down.\n");
			sanity--;
			break;

	}


	if (contacted_with_army == false && equipped_item == world->transistor)
	{
		
		printf("\n(You turn on the radio machine, and a voice surges from it)\n\nRadio: Hello? Here's the army... Soldier Jasna, it's you? Oh, god, we think...\nOk, what's your position?...Ok. We send a patrol to the place...\nThey will wait for you at the eastern forest of the city.\nBe careful!\n\n");

		world->forest->inside.PushBack(world->patrol);
		
		if (position == world->forest)
			printf("The patrol arrives at the forest.\n");

		contacted_with_army = true;
	}


	
	

}

bool Player::Go(Cardinal dest)
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
			
		printf("%s", world->entity[i]->description.C_str());

		if (((Exit*)(world->entity[i]))->open == false)
			printf("The door is closed.\n");

		return false;
}

void Player::Open(Cardinal orient)const
{
	int i;
	for (i = 0; i < world->entity.Size(); i++)

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

void Player::Close(Cardinal orient)const
{
	int i;
	for (i = 0; i < world->entity.Size(); i++)

		if (((Exit*)world->entity[i])->orientation == orient && ((Exit*)world->entity[i])->origin == world->player->position)
		{
			if (((Exit*)world->entity[i])->door == false)
				printf("There's no door on that direction.\n");

			else if (((Exit*)world->entity[i])->open == false)
				printf("The door is already closed.\n");

			else if (((Exit*)world->entity[i])->open)
			{
				printf("You close the door.\n");
				((Exit*)world->entity[i])->open = false;
			}
			break;
		}
}

bool Player::Take(const String& item_name)
{

	List<Entity*>::Node* it = position->inside.first;


	if (inside.Size() == limit)
	{
		printf("Your inventory is full.\n");
		return false;
	}

	while (it != nullptr)
	{
		if (it->data->name.Compare(item_name))
		{
			if (it->data->type == NPC)
			{
				printf("You can't take the %s!.\n", it->data->name.C_str());
				return false;
			}

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

bool Player::Take(const String& what, const String& from)
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

void Player::Drop(const String& item_name)
{
	List<Entity*>::Node* it = inside.first;

	while (it != nullptr)
	{
		if (it->data->name.Compare(item_name))
		{
			Move(this, position, it->data);
			printf("You drop the %s.\n", item_name.C_str());
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

bool Player::PutIn(const String& what, const String& in)
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

void Player::ShowStats()
{
	printf("-----%s's Status        Sanity at %i%\n", name.C_str(), sanity);
	printf("Health: %i \nAtk: %i\nDef: %i\nCoins: %i\n", health, atk, def, coins);

	if (equipped_item != nullptr)
	{
		printf("%s equipped\n", equipped_item->name.C_str());
	}
}

bool Player::Unequip()
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

bool Player::Equip(const String& item)
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

bool Player::Talk_to(const String& interlocutor)
{
	for (List<Entity*>::Node* it = position->inside.first; it != nullptr; it = it->next)
	{
		if (it->data->name.Compare(interlocutor.C_str()))
		{
			if (it->data->type == NPC)
			{
				//For when you have the totem and talk with the collector
				if (it->data == world->collector && world->player->equipped_item == world->totem)
				{

					printf("Collector: Oh! You have the totem! Excellent. I have the transistor in \nmy house, at the centre. I will open the door for you.\n");
					printf("(You give the totem to the collector)\n");

					Move(world->player, world->collector, world->totem);

					world->player->equipped_item = nullptr;

					delete world->collector->dialog;
					world->collector->dialog = new Dialogue("Collector: Excellent, excellent. I hope you find whatever you search for.\nBut, remember, knowledge can be dangerous...\n");

					
					for (int i = 0, j = world->entity.Size(); i < j; i++)
					{
						if (world->entity[i] == world->house_door)
						{
							delete world->entity[i];
							world->entity[i] = new Exit("", "It seems to be a door to a house.\n", world->center, world->house, W, true, false);
							break;
						}
					}

				}

				((Creature*)it->data)->state = talking;
				state = talking;

				printf("%s", ((Creature*)it->data)->dialog->lines[0]->text.C_str());
				((Creature*)it->data)->dialog->current = ((Creature*)it->data)->dialog->lines[0];
			
				if (((Creature*)it->data)->dialog->lines[0]->option.Empty())
				{ 
					state = walking;
					((Creature*)it->data)->state = walking;
				}
					
			    if (it->data == world->patrol)
					world->game_ended = true;
				
				for (int i = 0, size = ((Creature*)it->data)->dialog->lines[0]->option.Size(); i < size; i++)
				{
					printf("%i: %s", i+1, ((Creature*)it->data)->dialog->lines[0]->option[i]->title.C_str());

				}

				return true;

			}

			else if (it->data->type == NON_EQUIP_ITEM || it->data->type == EQUIP_ITEM)
			{
				printf("You can't talk to a %s!\n", interlocutor.C_str());
				return false;
			}
		}
	}


	printf("You can't do that.\n");
	return false;
}

bool Player::Buy_from(const String& what, const String& from)
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


	if (iterator == nullptr)
	{
		printf("There's nothing like a %s here.\n", from.C_str());
		return false;
	}



	while (it != nullptr)
	{
		if ((it->data->type == EQUIP_ITEM || it->data->type == NON_EQUIP_ITEM) && it->data->name.Compare(what))
		{
			if (coins >= ((Item*)it->data)->value)
			{
				coins -= ((Item*)it->data)->value;
				Move(iterator->data, (Entity*)this, it->data);
				printf("You buy the %s to the %s.\n", what.C_str(), from.C_str());
				return true;
			}
			else
			{
				printf("You don't have enough money to buy the %s.\n", what.C_str());
				break;
			}
		}

		it = it->next;
	}

	if (it == nullptr)
	{
		printf("The %s doesn`t have a %s.\n", from.C_str(), what.C_str());
		return false;
	}
}

bool Player::Buy_from(const String& from)const
{
	List<Entity*>::Node* it = position->inside.first;

	while (it != nullptr)
	{
		if (it->data->type == NPC && it->data->name.Compare(from.C_str()))
		{
			if (it->data->inside.Empty())
			{
				printf("The %s has nothing to sell to you.\n", it->data->name.C_str());
				return false;
			}
			printf("The %s has to sell:\n", it->data->name.C_str());
			for (List<Entity*>::Node* j = it->data->inside.first; j != nullptr; j = j->next)
			{
				printf("%s for %i coins\n", j->data->name.C_str(), ((Item*)j->data)->value);
			}
			return true;
		}
		it = it->next;
	}

	printf("You can't do that.\n");
	return false;
}

bool Player::Sell_to(const String& what, const String& to)
{
	List<Entity*>::Node* iterator = position->inside.first;
	List<Entity*>::Node* it = inside.first;



	//Check in the room
	while (iterator != nullptr)
	{
		if (iterator->data->name.Compare(to))
		{
			break;
		}
		iterator = iterator->next;
	}



	if (iterator == nullptr)
	{
		printf("There's nothing like a %s here.\n", to.C_str());
		return false;
	}

	if (iterator->data->inside.Size() == ((Item*)iterator->data)->limit)
	{
		if (((Item*)iterator->data)->limit == 0)
			printf("You can't sell nothing to the %s.\n", to.C_str());
		return false;
	}




	while (it != nullptr)
	{
		if (it->data->name.Compare(what))
		{
			coins += ((Item*)it->data)->value / 2;
			printf("You sell the %s to the %s for %i coins.\n", what.C_str(), to.C_str(), ((Item*)it->data)->value / 2);
			Move(this, iterator->data, it->data);
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

bool Player::Sell_to(const String& to)const
{
	List<Entity*>::Node* it = position->inside.first;
	

	while (it != nullptr)
	{
		if (it->data->type == NPC && it->data->name.Compare(to.C_str()))
		{
			if (it->data != world->vendor)
			{
				printf("The %s is not interested in buy nothing from you.\n", it->data->name.C_str());
				return false;
			}

			else if (inside.Empty())
			{
				printf("You have nothing to sell.\n");
				return false;
			}

			else
			{
				printf("The %s offers you:\n", it->data->name.C_str());

				for (List<Entity*>::Node* j = inside.first; j != nullptr; j = j->next)
				{
					printf("%i coins for the %s\n", ((Item*)j->data)->value/2, j->data->name.C_str());
				}
				return true;
			}
		}
		it = it->next;
	}

	printf("You can't do that.\n");
	return false;

}



void Ghost::Update()
{
	srand(time(NULL));

	if (state == walking)
	{
		if (GetTickCount() - timer > 10000)
		{
			Cardinal orient = Cardinal(rand() % 4);

			if (Go(Cardinal(orient)) && position == world->player->position)
			{
				printf("The ghost enters the %s.\n", world->ghost->position->name.C_str());
			}

			timer=GetTickCount();
		}


		if (position == world->player->position)
		{
			state = following;
			timer = 0;
		}
	}

	else if (state == following)
	{

		if (position != world->player->position && timer == 0)
		{
			timer = GetTickCount();
		}
		

		if (position != world->player->position && GetTickCount() - timer > 2000)
		{
			Go(world->player->last_direction);

			if (position == world->player->position)
			{
				printf("The ghost enters the %s.\n", world->ghost->position->name.C_str());
				timer = 0;
			}
			else 
			{
				state = walking;
				timer = 0;
			}
		}
	}

}



void Vendor::Update()
{
		if (state == talking)
		{	

			if (*world->last_key == '\r')
			{
				Talking();
			}

		}
	
}

