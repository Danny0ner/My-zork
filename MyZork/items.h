#ifndef  _ITEMS_
#define  _ITEMS_

#include"world.h"
#include"Entity.h"

class Item :public Entity
{
public:

	Room* src; //source room
	void Look() const;
	bool picked = false;
	Item(const char*,const char*,Room*,bool);
	//~Item();

};

#endif