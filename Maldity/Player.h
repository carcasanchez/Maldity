#ifndef __PLAYER_H__
#define __PLAYER_H_

#include "Entity.h"


class Player: public Entity{	
public:
	int position;
	
	//Player() :Entity(){}

	bool Go(const String& dest);
	void Open(const String& direction)const;
	void Close(const String& direction)const;
	void Take(const String& item)const;
	void Drop(const String& item)const;

};

#endif 