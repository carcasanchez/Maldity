#ifndef __STATS_H__
#define __STATS_H__

struct Stats
{
	int hp = 0;
	int atk = 0;
	int def = 0;
	int sanity = 0;

	
	Stats(int hp, int atk, int def, int sanity): hp(hp), atk(atk), def(def), sanity (sanity){};

};

#endif