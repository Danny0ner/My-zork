#ifndef _EXITS_
#define _EXITS_
#include "room.h"

enum directions { north, south, west, east, up, down };
enum locked {open, close};
class Exit : public Entity
{
public:
	char name[20];
	char description[200];
	Room* origin;
	Room* destination;
	directions direction;
	int door = 1;
	locked lock;

};
#endif