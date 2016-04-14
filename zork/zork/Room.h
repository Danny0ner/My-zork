#ifndef _ROOMS_
#define  _ROOMS_

#include"Entity.h"

class Room :public Entity
{
public:
	Room(const char* name, const char* descrip) :Entity(name, descrip){}
	//~Room();

	void Look()const;

};

#endif