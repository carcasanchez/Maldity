#ifndef __CREATURE_H__
#define __CREATURE_H__
#include "Entity.h"
#include "World.h"

enum State{ walking, talking, following, buying, selling };

class Creature:public Entity
{
public:
	Room* position;
	int sanity;
	int atk;
	int def;
	int health;
	int limit;
	State state;
	Entity* equipped_item = nullptr;

	Cardinal last_direction;

	Creature(const char* name, const char* desc, Room* pos, Tipus type, Stats stats, int limit) :Entity(name, desc, type), position(pos), limit(limit)
	{
		atk = stats.atk;
		health = stats.hp;
		def = stats.def;
		sanity = stats.sanity;

		state = walking;
	}

	


	bool Go(Cardinal orientation);
	void Open(Cardinal orientation)const;
	void Close(Cardinal orientation)const;
	bool Take(const String& item);
	bool Take(const String& what, const String& from);
	void Drop(const String& item);
	bool PutIn(const String& what, const String& on);
	void ShowStats();
	bool Unequip();
	bool Equip(const String& item);
	void Update();

};


#endif