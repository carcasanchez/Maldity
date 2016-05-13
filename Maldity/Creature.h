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

	Creature(const char* name, const char* desc, Room* pos, Tipus type, Stats stats) :Entity(name, desc, type), position(pos)
	{
		atk = stats.atk;
		health = stats.hp;
		def = stats.hp;
		sanity = stats.sanity;
	}

	//bool Move(Entity& source, Entity& destination, String name);


	bool Go(Cardinal orientation);
	//void Close(const String& direction)const;
//	void Take(const String& item)const;
	//void Take(const String& what, const String& from)const;
	//void Drop(const String& item)const;
	//void PutIn(const String& what, const String& on)const;
	void ShowStats();
//	bool Unequip();
//	void Equip(const String& item);

};


#endif