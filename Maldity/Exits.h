#ifndef __EXITS_H__
#define __EXITS_H__
struct Exits{
	char origin[10];
	char destination[10];
	char description[300];
	bool door, open;
	char orientation[10];
};
#endif