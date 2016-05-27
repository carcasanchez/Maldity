#ifndef __CREATURE_H__
#define __CREATURE_H__
#include "Entity.h"
#include "World.h"

class Dialogue;

enum State{ walking, talking, following, buying, selling };

class Creature:public Entity
{
public:
	Room* position;

	int atk;
	int def;
	int health;
	int limit;

	Dialogue* dialog;
	State state;
	Entity* equipped_item = nullptr;



	Creature(const char* name, const char* desc, Room* pos, Tipus type, Stats stats, int limit) :Entity(name, desc, type), position(pos), limit(limit)
	{
		atk = stats.atk;
		health = stats.hp;
		def = stats.def;

		state = walking;
	}

	virtual ~Creature()
	{
		delete dialog;
	}

	void Update();
	virtual bool Go(Cardinal orientation);

	virtual bool Talking();
	
};


#endif