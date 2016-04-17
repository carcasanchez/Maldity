#ifndef __PLAYER_H__
#define __PLAYER_H_

#include "Entity.h"


class Player: public Entity{	
public:
	int position;
	int sanity;
	int atk;
	int def;
	int health;

	Player(int pos, char* n){
		position = pos;
		name = n;
	}

	//Player() :Entity(){} TODO 2: inherit entity constructor

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