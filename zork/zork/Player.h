#ifndef _PLAYER_
#define _PLAYER_
#include "Room.h"
#include "Entity.h"
class Player : public Entity, Room
{
public:
	Room * position;
	char description[200];


};
#endif