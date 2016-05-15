#ifndef __CREATURE_H__
#define __CREATURE_H__
#include "Entity.h"
#include "World.h"


class Creature:public Entity
{
public:
	Room* position;
	int sanity;
	int atk;
	int def;
	int health;
	int limit;

	Creature(const char* name, const char* desc, Room* pos, Tipus type, Stats stats, int limit) :Entity(name, desc, type), position(pos), limit(limit)
	{
		atk = stats.atk;
		health = stats.hp;
		def = stats.hp;
		sanity = stats.sanity;
	}

	


	bool Go(Cardinal orientation);
	void Open(Cardinal orientation)const;
	void Close(Cardinal orientation)const;
	bool Take(const String& item);
	bool Take(const String& what, const String& from);
	void Drop(const String& item);
	bool PutIn(const String& what, const String& on);
	void ShowStats();
//	bool Unequip();
//	void Equip(const String& item);

};


#endif