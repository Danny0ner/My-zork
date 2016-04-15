#ifndef _EXITS_
#define  _EXITS_

#include"world.h"
#include"Entity.h"

enum dir{ north, south, east, west, up, down };

class Exit :public Entity
{
public:

	Room* src; //source room
	Room* dst; //destination room
	bool door = false; //indicates if an exits has a door to open/close
	bool open = true; //indicates if an exit is opened or closed
	dir direction;
	void Look()const;

	Exit(const char*, const char*,Room*,Room*,dir,bool,bool);
	//~Exit();

};

#endif