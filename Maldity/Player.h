#ifndef __PLAYER_H__
#define __PLAYER_H_

#include "Entity.h"


class Player: public Entity{	
public:
	int position;
	int sanity;
	int atk;
	int def;

	Player(){
		position = 0;
		name = "Jasna";
		sanity = 100;
		atk = 2;
		def = 5;
	}
	//Player() :Entity(){}

	bool Go(const String& dest);
	void Open(const String& direction)const;
	void Close(const String& direction)const;
	void Take(const String& item)const;
	void Take(const String& what, const String& from)const;
	void Drop(const String& item)const;
	void ShowStats();

};

#endif 