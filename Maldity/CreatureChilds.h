#ifndef _CREATURE_CHILD_H_
#define _CREATURE_CHILD_H_

#include "Creature.h"




class Player : public Creature
{
public:
	int sanity;
	int coins;
	int timer;


	Cardinal last_direction;


	Player(const char* name, const char* desc, Room* pos, Tipus type, Stats stats, int limit, int coins) :Creature(name, desc, pos, type, stats, limit), coins(coins)
	{
		sanity = stats.sanity;
	}

	bool Go(Cardinal orientation);
	void Update();
	void Open(Cardinal orientation)const;
	void Close(Cardinal orientation)const;
	bool Take(const String& item);
	bool Take(const String& what, const String& from);
	void Drop(const String& item);
	bool PutIn(const String& what, const String& on);
	void ShowStats();
	bool Unequip();
	bool Equip(const String& item);
	bool Talk_to(const String& interlocutor);
	bool Buy_from(const String& what, const String& from);
	bool Sell_to(const String& what, const String& to);

};


class Ghost : public Creature
{
public:

	unsigned int timer;

	Ghost(const char* name, const char* desc, Room* pos, Tipus type, Stats stats, int limit) :Creature(name, desc, pos, type, stats, limit){ timer = GetTickCount(); }

	void Update();

};


class Vendor : public Creature
{
public:


	Vendor(const char* name, const char* desc, Room* pos, Tipus type, Stats stats, int limit) :Creature(name, desc, pos, type, stats, limit){}


	void Update();



};


#endif