#ifndef _EXITS_
#define _EXITS_
#include "room.h"

enum directions { north, south, west, east, up, down };
enum locked {open, close};
class Exit : public Entity
{
public:
	Room* src; //source room
	Room* dst; //destination room
	bool door = false; //indicates if an exits has a door to open/close
	bool open = true; //indicates if an exit is opened or closed
	directions direction;

	Exit(const char* name, const char* descrip, Room* source, Room* dest, directions direct, bool d, bool o) : Entity(name, descrip),
		src(source), dst(dest), direction(direct), door(d), open(o){}

};
#endif