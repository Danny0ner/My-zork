#ifndef _EXITS_
#define  _EXITS_

#include"world.h"
#include"Entity.h"

enum dir{ north, south, east, west, up, down };

class Exit :public Entity
{
public:

	Room* src; 
	Room* dst; 
	bool door = false; 
	bool open = true; 
	dir direction;
	void Look()const;

	Exit(const char*, const char*,Room*,Room*,dir,bool,bool);


};

#endif