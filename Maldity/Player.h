#ifndef __PLAYER_H__
#define __PLAYER_H_

#include "Entity.h"


class Player: public Entity{	
public:

	List <Room*> ::Node* position;
	int sanity;
	int atk;    //TODO: Constructor of player: stats
	int def;
	int health;

	Player(const char* name, const char* desc, int pos) :Entity(name, desc, PLAYER){
		position = world->room.first;
	}

	bool Move(Entity& source, Entity& destination, String name);

	bool Go(const String& dest);
	void Open(const String& direction)const;
	void Close(const String& direction)const;
	void Take(const String& item)const;
	void Take(const String& what, const String& from)const;
	void Drop(const String& item)const;
	void PutIn(const String& what, const String& on)const;
	void ShowStats();
	bool Unequip();
	void Equip(const String& item);

	

};

#endif 