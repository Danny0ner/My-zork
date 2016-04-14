#ifndef  _ITEMS_
#define  _ITEMS_

#include"world.h"
#include"Entity.h"
#include "Room.h"

class Item : public Entity
{
public:

	Room* pos; 
	void Look() const;
	bool picked = false;
	Item(const char*, const char*, Room*, bool);
	//~Item();

};

#endif