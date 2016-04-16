#ifndef _ROOMS_
#define  _ROOMS_

#include"Entity.h"

class Room:public Entity
{
public:
	MyString ShrinkDesc;
	Room(const char*,const char*, const char*);
	
	void Look()const;
	
};

#endif