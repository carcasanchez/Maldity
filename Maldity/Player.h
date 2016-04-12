#ifndef __PLAYER_H__
#define __PLAYER_H_

#include "Entity.h"


class Player: public Entity{	
public:
	int position;
	
	
	bool Go(const String& dest);


};

#endif 