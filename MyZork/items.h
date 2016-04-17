#ifndef  _ITEMS_
#define  _ITEMS_

#include"world.h"
#include"Entity.h"

class Item :public Entity
{
public:

	Room* src; 
	void Look() const;
	bool picked = false;
	bool shrink = false;
	bool equiped;
	Item(const char*,const char*,Room*,bool, bool, bool);
	

};

#endif