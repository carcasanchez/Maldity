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
					printf("The %s is here.\n", it->data->name.C_str());


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
	entity.PushBack(tavern = new Room("Tavern", "The house seems to be an old tavern, with the door oriented at east.\nThere're a few clients that look at you with hostile eyes.\n"));
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
	entity.PushBack(house_door = new Exit("", "It seems to be a door to a house. The door is firmly closed.\n", center, nullptr, W, false, true));
	

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
entity.PushBack(ghost = new Ghost("Ghost", "A strange ethereal presence. It seems lost.\n", fells, NPC, non_bonus, 0));
entity.PushBack(vendor = new Vendor("Vendor", "Short and wearing a dusty cloak, the vendor looks at you with a smart glance.\n", shop, NPC, non_bonus, 20));
entity.PushBack(knight = new Creature("Knight", "A skeletal knight, wearing a dark armor. He's resting against a pillar.\n", road, NPC, non_bonus, 0));
entity.PushBack(sailor = new Creature("Sailor", "It's a decrepit body with a sailor coat. His empty eyes\nlook at some point in the sea.\n", dock, NPC, non_bonus, 0));
entity.PushBack(collector = new Creature("Collector", "A well dressed and highborn-looking tall man. He wears a strange mask.\n", beach, NPC, non_bonus, 0));
entity.PushBack(patrol = new Creature("Patrol", "The army patrol! They were sent to rescue you from the city.\n", forest, NPC, non_bonus, 0));
entity.PushBack(demented = new Creature("Demented", "Strange, dark, tall figure. You only can see his eyes, under his cloak.\nHe emanes an aura of terror.\n", balcony, NPC, non_bonus, 0));
entity.PushBack(brute = new Creature("Brute", "Incredible robuste, ugly giant. It drinks slowly in the bar.\n", tavern, NPC, non_bonus, 0));
entity.PushBack(seer = new Creature("Seer", "A short figure, resting in a bench, covered in a cloack.", center, NPC, non_bonus, 0));

//Creates items
entity.PushBack(coffer = new Item("Coffer", "An old wooden box. You can put objects into it.\n", NON_EQUIP_ITEM, non_bonus, 3, 0, 0));
entity.PushBack(coin = new Item("Coin", "A very old coin. It seems to be made in gold.\nIt has a strange symbol impressed in it.\n", EQUIP_ITEM, non_bonus, 0, 50, 0));
entity.PushBack(totem = new Item("Totem", "A strange totem, made in wood.\nIt's impossible to determine what it represents...\n", EQUIP_ITEM, non_bonus, 0, 3, 3));
entity.PushBack(sword = new Item("Sword", "It's a short sword, very sharpen.\n", EQUIP_ITEM, sword_bonus, 0, 50, 0));
entity.PushBack(armor = new Item("Armor", "A strange, shiny armor that covers the chest.\n", EQUIP_ITEM, armor_bonus, 0, 60, 0));
entity.PushBack(map = new Item("Map", "The old map of a sailor. It doesn't represent any continent recognizable...\n",  EQUIP_ITEM, non_bonus, 0, 1, 2));
entity.PushBack(fang = new Item("Fang", "It seems to be the fang of a sea creature.\nBut any sea creature known has that fangs...\n", EQUIP_ITEM, fang_bonus, 0, 1, 5));
entity.PushBack(vial = new Item("Vial", "A cristal bottle, with a dark, red sustance in it. Maybe blood?\n", EQUIP_ITEM, non_bonus, 0, 5, 5));
entity.PushBack(transistor = new Item("Transistor", "A very oxidized radio machine. Still working.\nEquip it to use.\n", EQUIP_ITEM, non_bonus, 0, 10, 0));


//Locates creatures and items
forest->inside.PushBack(player);
fells->inside.PushBack(ghost);
shop->inside.PushBack(vendor);
road->inside.PushBack(knight);
dock->inside.PushBack(sailor);
beach->inside.PushBack(collector);
balcony->inside.PushBack(demented);
tavern->inside.PushBack(brute);
center->inside.PushBack(seer);

statue->inside.PushBack(coffer);
vendor->inside.PushBack(coin);
coffer->inside.PushBack(sword);
coffer->inside.PushBack(armor);
coffer->inside.PushBack(vial);
coffer->inside.PushBack(totem);
beach->inside.PushBack(fang);
dock->inside.PushBack(map);
house->inside.PushBack(transistor);



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


knight->dialog = new Dialogue("Knight: Hello. You seem a little bit lost. Be careful here. Don't forget \nwho you are. I will help you if madness stalks you.\n");
knight->dialog->AddLine("What do you mean?\n", "Knight: Don't be afraid. Everybody here is lost.\nBut only a few realizes it.\n", 0, -1);
knight->dialog->AddLine("What is happening in this village?\n", "Knight: ...\n", 0, -1);
knight->dialog->AddLine("I need help. I want to leave this city, but...\n", "Knight: I see. If you leave the city by yourself...\nProbably you won't last so much.\nBut I think i could help you.\nThere's an old transistor somewhere... you can use it.\n", 0, -1);
knight->dialog->AddLine("Ah... But, why they are lost?\n", "Knight: They not only lost their lives. They lost themselves.\n", 1, 0);
knight->dialog->AddLine("I didn't mean... bah, forget it.\n", "Knight: ...\n", 1, -1);
knight->dialog->AddLine("Please, tell me!\n", "Knight: Something big... so big, that we can't understand it...\nAt north...\n", 2, 0);
knight->dialog->AddLine("(He doesn't seem so much talkative. I am losing my time)\n", "Knight: ...\n", 2, -1);
knight->dialog->AddLine("A transistor? Where?\n", "Knight: ...I don't know. Ask to the rest of inhabitants. But don't get lost.\n", 3, 3);
knight->dialog->AddLine("Why do you help me?\n", "Knight: ...Knowledge is dangerous. Be afraid of the truth.\nIf you start to forget who you are... Talk to me.\n", 3, 3);
knight->dialog->AddLine("Ok... thanks for the help.\n", "Knight: ...\n", 3, -1);
knight->dialog->AddLine("Ok...Bye...\n", "Knight: Bye. Be careful.\n", 0, -1);


sailor->dialog = new Dialogue("Sailor: ...\n");
sailor->dialog->AddLine("Hello. Maybe you could help me...\n", "Sailor: Why I would want to help you?\n", 0, -1);
sailor->dialog->AddLine("(Ok, better I leave him)\n", "Sailor: ...\n", 0, -1);
sailor->dialog->AddLine("I'm only searching for a transistor.\n", "Sailor: What? What the hell is a transistor?\nThis city is cursed enough. We don't need people like you here.\n", 1, -1);
sailor->dialog->AddLine("(Mmf, what a rude man. I don't want to speak to him more)\n", "Sailor: ...Leave me alone.\n", 1, -1);
sailor->dialog->AddLine("Cursed?\n", "Sailor: ...Yes, cursed. Look at me. Look at the rest of inhabitants.\nDon't you think so?\n", 3, -1);
sailor->dialog->AddLine("Don't you know what a transistor is?\n", "Sailor: Would you kindly stop bothering me? I have been here for years.\nI only mind my boats and my work.\n", 3, 3);
sailor->dialog->AddLine("Tell me more about that curse.\n", "(The sailor looks at the sea, between the giant boats, and keeps silent)\n", 5, 5);
sailor->dialog->AddLine("That boats... Why are them so big?\n", "Sailor: ...It's for him... at north...\n", 5, 5);
sailor->dialog->AddLine("...farewell...\n", "(The sailor still looks at the sea)\n", 5, -1);



collector->dialog = new Dialogue("Collector: Oh. Hello, My Lady. Looking for a good sight of the sea?\n");
collector->dialog->AddLine("Maybe. But this sea is a bit ferocious for me.\n", "Collector: Oh, true. The sea here is not peaceful.\nBut, our souls are not peaceful too...\n", 0, -1);
collector->dialog->AddLine("Actually not. I'm searching for help.\n", "Collector: Oh, how I could help such a beautiful lady?\n", 0, -1);
collector->dialog->AddLine("Yes. And you, what are you sarching for?\n", "Collector: I search for the strange.\n", 0, -1);
collector->dialog->AddLine("Souls? What do you mean?\n", "Collector: Our souls, MyLady, our souls. The souls trapped in this city.\n", 1, -1);
collector->dialog->AddLine("Trapped?\n", "Collector: Yes... I have been trapped here for a few years.\nThe Knight is the oldest soul here. But is the most lucid.\nWould you become the youngest soul here?\	n", 4, 4);
collector->dialog->AddLine("(Probably is crazy. I will leave)\n", "Collector: Farewell, MyLady\n", 4, -1);
collector->dialog->AddLine("Did you know where I can found something like a transistor?\n","Collector: A radio machine? I have one in my house, I think.\nI can let you using it if you... make something for me.\n", 2, -1);
collector->dialog->AddLine("Probably you can't. See you later.\n", "Collector: Oh, how dissapointing...\n", 2, -1);
collector->dialog->AddLine("What do you want?\n", "Collector: I am a collector. I search for strange things.\nI know a strange thing is in the giant statue, at north.\nA strange totem... Talk to me when you got it.\n", 7, -1);
collector->dialog->AddLine("I have not time. I will continue without help\n", "Collector: ...Ok...\n", 7, -1);
collector->dialog->AddLine("The strange?\n", "Collector: Yes! I am a collector. I love strange things.\nAnd in this beach, there are those strange rests...\n", 3, 3);
collector->dialog->AddLine("Those fangs, do you mean?\n", "Collector: Yes... they are interesting, aren't it? I don't know \nwhat creature could have those fangs, but... Sure, it was weird.\nBut, you know? It's better not know it. The truth can be dangerous, sometimes.\n", 3, 3);
collector->dialog->AddLine("OK... I think I have something to do...\n", "Collector: Bye, MyLady. Be careful with the truth...\n", 3, -1);

patrol->dialog = new Dialogue("Jasna! You are alive! C'mon, we must leave this city.\n\n(You get on the car and leaves the cursed city)\n					 END\n\n\n(press any key to end the game)");

demented->dialog = new Dialogue("Strange figure: Ah. Hello. I have waiting for you.\n");
demented->dialog->AddLine("What did you mean?\n","Strange figure: Waiting, dear, waiting. For you. I saw you from here, walking through \nthe forest, coming to this cursed village...\n", 0, 0);
demented->dialog->AddLine("Are you the important person everybody is talking about here?\n", "Strange figure: Person? Did you call me a 'person'? How disappointing.\nI am the harbinger. I'm not a person. I am more.\n", 0, -1);
demented->dialog->AddLine("Who are you? What's happening in this city?\n", "Strange figure: Oh, are you searching for the truth? It could be dangerous.", 0 , 0);
demented->dialog->AddLine("What? Harbinger of what?\n","Strange figure: Of those who came from the sea.\nOf those who converted you in what you are now.\n", 2, -1);
demented->dialog->AddLine("More? What do you mean? Are you not human?\n", "(The strange figure inclines to you. You can slightly see a mass of darkness, a horrible non-human face)\nStrange figure: Do you want to know more? Knowledge could be your ruin.\n", 2, 2);
demented->dialog->AddLine("Who came from the sea?\n", "Strange figure: The Great. So Great, you can't understand.\nA superior existence. This city tried to reach their glory.\nThey reach their lore.\nAnd with the glory and the lore, they reach de Madness.\n", 4, 4);
demented->dialog->AddLine("Shut up! You are crazy.\n", "Strange figure: Crazy? Oh, no. I'm not crazy. You, humans, regret all you can't understand.\nAnd, when you finally understand... you mind shatters in pieces.\n(The dark figure points to the south, to the grey sea. At the cloudy horizon,\nyou can barely distinguish three enormous silhouettes. They are slowly moving, \nlike they were alive)\nHarbinger of the Great: You see, little human? The greatness, \nthe terrible greatness. Now, you know the truth. What will you do with it?\n(The dark figure vanishes silently)\n", 4, -1);

brute->dialog = new Dialogue("Brute: What do you want? Didn't you see that I'm busy?\n");
brute->dialog->AddLine("Sorry, I must ask you some questions.\n", "Brute: What? Mf. Ok. Be quick.\n", 0, -1);
brute->dialog->AddLine("(It seems aggressive. Better I leave)\n", "(The brute continues drinking)\n", 0, -1);
brute->dialog->AddLine("Why are all afraid of the north part of the city?\n", "Brute: Probably is the ghost. There's a strange entity around the Virgin\nstatue. From once to once, it comes to the city. It's really disturbing.\nIf I were you, I won't approach to it...\n", 1, 1);
brute->dialog->AddLine("Those giant boats of the dock...\n", "Brute: They aren't for us. Don't ask.\n", 1, 1);
brute->dialog->AddLine("Who is that knight?\n", "Brute: It's the oldest here. He doesn't talk very much.\n", 1, 1);
brute->dialog->AddLine("What is the giant statue at the top of the village?\n", "Brute: The Virgin of the Stone... is very ancient. You can go\ninto it, but it's no a good idea.\n", 1, 1);
brute->dialog->AddLine("The fells of the north...\n", "Brute: They are as cursed as this village. Even more. Don't walk through \nthem if you can.\n", 1, 1);
brute->dialog->AddLine("Ok. Thanks for the answers.\n", "Brute:...farewell...\n", 1, -1);

}

