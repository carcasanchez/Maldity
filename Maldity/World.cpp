#include "World.h"
#include "CreatureChilds.h"



World::World()
{}

World::~World()
{
	int size = entity.Size();
	for (int i = 0; i < size; i++)
	{
		delete entity[i];
	}


}

void World::Look()const{

	printf("%s", player->position->description.C_str());
	List<Entity*>::Node* it;


	for (int i = 0; i < entity.Size(); i++)
	{
		if (entity[i] == player->position)
		{
			it = entity[i]->inside.first;
			
			while (it != nullptr)
			{
				if (it->data->type == NON_EQUIP_ITEM || it->data->type == EQUIP_ITEM)
					printf("There's a %s in the floor.\n", it->data->name.C_str());

				else if (it->data->type == NPC)
					printf("%s is here.\n", it->data->name.C_str());


				it = it->next;
			}
			break;
		}	
	}
}



void World::CreateWorld()
{
	

	
	//Rooms

	entity.PushBack(forest = new Room("Forest","You are in a forest. \nAt south, you see that the road drives to a city. \nAt west, a high hill. \nAt north, the road vanishes in the distance. \nAt east, only the sea.\n"));
	entity.PushBack(road = new Room("Road", "You are in a high road. \nAt north, there's a mass of gothic buildings. \nAt south, the sea, and a small beach. \nAt west, a way to a big dock. \nAt east, the road that drives to the forest.\n"));
	entity.PushBack(beach = new Room("Beach", "The beach is small and it's full of rocks\nYou can only see the main road, at north, and the wide open sea, at south.\n"));
	entity.PushBack(dock = new Room("Dock", "The dock is really impressive.\nThere are enourmous woody ships in all directions except for the east.\n"));
	entity.PushBack(center = new Room("Center", "Gothic buildings are all around of a narrow square.\nYou can see the main road at south, and a couple of sinister alleys that go \ndeeper into the city.\nOnly the alley of the north seems a little bit safer.\nYou can see two doors, at west and at east.\n"));
	entity.PushBack(alley = new Room("Alley", "The narrow alley goes up from the city center.\nThere's a small door that have a 'Tavern' placard at your left.\nThe alley continues ascending to the north.\n"));
	entity.PushBack(tavern = new Room("Tavern", "The house seems to be an old tavern, with the door oriented at east.\n"));
	entity.PushBack(top = new Room("Top", "You are in the elevated district of the city.\nYou can see a little alley at south and a enormous statue at east, beyond the\nfells.\n"));
	entity.PushBack(fells = new Room("Fells", "The fells are surrounded by dark trees. The enourmous statue rises over them.\n"));
	entity.PushBack(statue = new Room("Statue", "The enormous statue seems to be a Virgin.\nIt looks like she has a balcony on her top.\nThe dark mass of trees looks you from the west.\nThere are stairs that go up inside the statue.\nAt south, a little road goes down the fells.\n"));
	entity.PushBack(house = new Room("House", "You are in the hall of an old house. The building looks like a gothic palace,\nbut it's dusty and seems abandoned.\n"));
	entity.PushBack(balcony = new Room("Balcony", "The head of the virgin is sculpted as a balcony. You can see the whole village \nfrom here.\n"));
	entity.PushBack(shop = new Room("Shop", "Compared to the rest of the city, the shop looks miserable.\nIt's impossible to determine what is sold here.\n"));


	//Forest exits
	entity.PushBack(new Exit("", "The road vanishes in the distance.\nBetter no to follow it.\n", forest, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The road follows the coast and approaches to the village.\n", forest, road, S, false, true));
	entity.PushBack(new Exit("", "The sea looks grey and unpeaceful.\n", forest, nullptr, E, false, true));
	entity.PushBack(new Exit("", "You can't go on that direction.\nThe hill is too high.\n", forest, nullptr, W, false, true));
	

	//Road exits
	entity.PushBack(new Exit("", "The alleys seem to drive to the city center.\n", road, center, N, false, true));
	entity.PushBack(new Exit("", "Narrow stairs sculpted in rock descends to the beach.\n", road, beach, S, false, true));
	entity.PushBack(new Exit("", "The road leaves the city and follows the coast.\n", road, forest, E, false, true));
	entity.PushBack(new Exit("", "At the distance, you can see numerous boat masts.\n", road , dock, W, false, true));

	
	//Beach exits
	entity.PushBack(new Exit("", "The stairs go back to the road\n", beach, road, N, false, true));
	entity.PushBack(new Exit("", "You look at the sea. The horizon is cloudy, and the water, grey.\nYou feel a little relief for stay in land,\nbut the cold and ferocious wind spreads it.\n", beach, nullptr, S, false, true));
	entity.PushBack(new Exit("", "The rocks are too abrupt to walk over them.\n", beach, nullptr, E, false, true));
	entity.PushBack(new Exit("", "The rocks are too abrupt to walk over them.\n", beach, nullptr, W, false, true));

	
	//Dock exits

	entity.PushBack(new Exit("", "The big boats seems old and abandoned. Better not try to go into.\n", dock, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The big boats seems old and abandoned. Better not try to go into.\n", dock, nullptr, S, false, true));
	entity.PushBack(new Exit("", "Between the gigant boats, you can see the road.\n", dock, road, E, false, true));
	entity.PushBack(new Exit("", "The big boats seems old and abandoned. Better not try to go into.\n", dock, nullptr, W, false, true));




	//Center exits

	entity.PushBack(new Exit("", "The northern alley leaves the square between buildings. It seems to ascend.\n", center, alley, N, false, true));
	entity.PushBack(new Exit("", "You can see the main road, near the sea.\n", center, road, S, false, true));
	entity.PushBack(new Exit("", "It seems to be the entrance a shop.\n", center, shop, E, true, false));
	entity.PushBack(new Exit("", "It seems to be a door to a house.\n", center, house, W, true, false));
	

	//Alley exits

	entity.PushBack(new Exit("", "The alley continues ascending.\n", alley, top, N, false, true));
	entity.PushBack(new Exit("", "The alley descends to the city center.\n", alley, center, S, false, true));
	entity.PushBack(new Exit("", "The gothic buildings looks impressive, and the rest of the alleys,\ntoo dark to go into.\n", alley, nullptr, E, false, true));
	entity.PushBack(new Exit("", "It seems to be the door of a tavern.\n", alley, tavern, W, true, false));


	//Tavern exits

	entity.PushBack(new Exit("", "The tavern has no more exits than the east one.\n", tavern, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The tavern has no more exits than the east one.\n", tavern, nullptr, S, false, true));
	entity.PushBack(new Exit("", "This is the only door of the tavern.\n", tavern, alley, E, true, true));
	entity.PushBack(new Exit("", "The tavern has no more exits than the east one.\n", tavern, nullptr, W, false, true));



	

	//Top Disctrict exits
	entity.PushBack(new Exit("", "The city is surrounded by a chain of old fells.\nThe woody mountain looks dark and threatening.\n", top, nullptr, N, false, true));
	entity.PushBack(new Exit("", "You can see the alley descending to the city.\n", top, alley, S, false, true));
	entity.PushBack(new Exit("", "Between dark and high trees, you can see a enormous statue.\n", top, fells, E, false, true));
	entity.PushBack(new Exit("", "The city is surrounded by a chain of old fells.\nThe woody mountains looks dark and threatening.\n", top, nullptr, W, false, true));



	//Fells exits

	entity.PushBack(new Exit("", "The forest is too dense to go into it.\n", fells, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The forest is too dense to go into it.\n", fells, nullptr, S, false, true));
	entity.PushBack(new Exit("", "Between dark and high trees, you can see a enormous statue.\n", fells, statue, E, false, true));
	entity.PushBack(new Exit("", "You can see some buildings between the trees.\n", fells, top, W, false, true));





	//Statue exits

	entity.PushBack(new Exit("", "The mountains look so terrifying\n", statue, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The hill descends abruptly to a forest.\nIt's possible that you can't climb back.\n", statue, forest, S, false, true));
	entity.PushBack(new Exit("", "The statue has a little opened door.\nYou can see stairs behind it.\n", statue, balcony, E, false, true));
	entity.PushBack(new Exit("", "The fells look tenebrous, but it's the only way to go to the village.\n", statue, fells, W, false, true));


	
	//Balcony exits

	entity.PushBack(new Exit("", "The mountains look so terrifying\n", balcony, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The gothic city is placed between the feets of the mountains and the grey sea.\nIt looks like a phantom village.\n", balcony, nullptr, S, false, true));
	entity.PushBack(new Exit("", "You can see a little road at the bottom of the fells.\nOne of its sides goes to the city.\nThe other, vanishes in the distance.\n", balcony, nullptr, E, false, true));
	entity.PushBack(new Exit("", "That stairs are the only way to go down the balcony.\n", balcony, statue, W, false, true));


	//House

	entity.PushBack(new Exit("", "The only exit is the door at the east.\n", house, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The only exit is the door at the east.\n", house, nullptr, S, false, true));
	entity.PushBack(new Exit("", "This is the only exit of the old house.\n", house, center, E, true, true));
	entity.PushBack(new Exit("", "The only exit is the door at the east.\n", house, nullptr, W, false, true));

	//Shop

	entity.PushBack(new Exit("", "The only exit is the door at the west.\n", shop, nullptr, N, false, true));
	entity.PushBack(new Exit("", "The only exit is the door at the west.\n", shop, nullptr, S, false, true));
	entity.PushBack(new Exit("", "The only exit is the door at the west.\n", shop, nullptr, E, false, true));
	entity.PushBack(new Exit("", "You can see the city center from the interior of the shop.\n", shop, center, W, true, true));


	

//Create stats struct
Stats Jasna_stats(20, 2, 5, 100);

Stats non_bonus(0, 0, 0, 0);
Stats sword_bonus(0, 5, 0, 0);
Stats armor_bonus(0, 0, 3, 0);
Stats fang_bonus(0, 2, 0, 0);


//Create creatures
entity.PushBack(player = new Player("Jasna", "", forest, PLAYER, Jasna_stats, 5, 100));
entity.PushBack(ghost = new Ghost("Ghost", "A strange ethereal presence. It seems lost.\n", center, NPC, non_bonus, 0));
entity.PushBack(vendor = new Vendor("Vendor", "", forest, NPC, non_bonus, 20));


//Creates items
entity.PushBack(key = new Item("Key", "It's an old, little, rusty key.\n", EQUIP_ITEM, non_bonus, 0, 5));
entity.PushBack(coffer = new Item("Coffer", "An old wooden box. You can put objects into it.\n", NON_EQUIP_ITEM, non_bonus, 3, 0));
entity.PushBack(coin = new Item("Coin", "A very old coin. It seems to be made in gold.\nIt has a strange symbol impressed in it.\n", EQUIP_ITEM, non_bonus, 0, 200));
entity.PushBack(totem = new Item("Totem", "A strange totem, made in wood.\nIt's impossible to determine what it represents...\n", EQUIP_ITEM, non_bonus, 0, 3));
entity.PushBack(sword = new Item("Sword", "It's a short sword, very sharpen.\n", EQUIP_ITEM, sword_bonus, 0, 50));
entity.PushBack(armor = new Item("Armor", "A strange, shiny armor that covers the chest.\n", EQUIP_ITEM, armor_bonus, 0, 60));
entity.PushBack(map = new Item("Map", "The old map of a sailor. It doesn't represent any continent recognizable...\n",  EQUIP_ITEM, non_bonus, 0, 1));
entity.PushBack(fang = new Item("Fang", "It seems to be the fang of a sea creature.\nBut any sea creature known has that fangs...\n", EQUIP_ITEM, fang_bonus, 0, 1));
entity.PushBack(rope = new Item("Rope", "A simple piece of rope. Nothing strange.\n", EQUIP_ITEM, non_bonus, 0, 2));
entity.PushBack(swordcase = new Item("Swordcase", "Very useful case, perfect for keep a sword inside.\n", EQUIP_ITEM, non_bonus, 1, 20));
entity.PushBack(vial = new Item("Vial", "A cristal bottle, with a dark, red sustance in it. Maybe blood?\n", EQUIP_ITEM, non_bonus, 0, 5));


//Locates creatures and items
forest->inside.PushBack(player);
center->inside.PushBack(ghost);
forest->inside.PushBack(vendor);

house->inside.PushBack(coffer);
vendor->inside.PushBack(coin);
coffer->inside.PushBack(sword);
vendor->inside.PushBack(rope);
forest->inside.PushBack(key);
beach->inside.PushBack(fang);
dock->inside.PushBack(map);


//Add dialogues

ghost->dialog = new Dialogue("The ghost doesn't seem able to talk.\n");

vendor->dialog = new Dialogue("Vendor: Welcome, dear, to my shop! I have a lot of interesting items for you.\nSome information, maybe.\n");
vendor->dialog->AddLine("What is this city?\n", "Vendor: My dear, this is our home, Baiona. The weather here is so pleasant,\nisn't it?. We have not much work, but... the life here is still interesting.\n", 0, -1);
vendor->dialog->AddLine("What interesting objects do you have?\n", "Vendor: Oh, glad you ask. I have anything you want, from utility objects to \nsome old relics!\n", 0, 0);
vendor->dialog->AddLine("Interesting? What do you mean?\n", "Vendor: Oh, dear. We receive visits from once to once. Visits from very \nimportant... person.\n", 1, -1);
vendor->dialog->AddLine("(Ok, I think I have better things to do)\n", "Vendor: See you later\n", 1, -1);
vendor->dialog->AddLine("Person? What person?\n", "Vendor: Oh, maybe you will know him, soon or later. Don't be impatient.\n", 3, 0);
vendor->dialog->AddLine("Mhf. Ok, see you later.\n", "Vendor: Don't you want to buy something?\n", 3, -1);
vendor->dialog->AddLine("I'm not interested, thanks.\n", "Vendor: What a pity\n", 0, -1);

}

