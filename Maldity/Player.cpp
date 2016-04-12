#include "World.h"
#include "Player.h"


bool Player::Go(const String& dest)
{

		for (int i = 0; i < 52; i++)
		{
			
			if (world->exit[i].orientation.Compare(dest.C_str()) && world->exit[i].origin.Compare(world->room[position].name.C_str()))
			{
				if ((world->exit[i].door) && (world->exit[i].open == false))
					{ 
					printf("You can't go on that direction. The door is closed.\n");
					return false;
					}

				if (world->exit[i].destination.Empty())
					{
						printf("%s", world->exit[i].description.C_str());
						return false;
					}


				for (int j = 0; j < 13; j++)
					if (world->room[j].name.Compare(world->exit[i].destination.C_str()))
					{

						position = j;
						return true;
					}					
			}
		}
		printf("You can't do that.\n");
		return false;
}