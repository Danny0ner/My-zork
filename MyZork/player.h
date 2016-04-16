#ifndef _PLAYER_
#define _PLAYER_

#include"world.h"
#include"Entity.h"
#include"items.h"

class Player
{
public:

	Room* player_pos;
	bool shrink = false;
	unsigned int num_items = 0;


};


#endif