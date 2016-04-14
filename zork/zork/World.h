#ifndef _WORLD_
#define _WORLD_
#include"Room.h"
#include"player.h"
#include"Exits.h"

#include"Entity.h"
#include"My string.h"
#include"items.h"
#include"vector.h"

class World
{
public:
	Vector<Room*> rooms;
	Vector<Exit*> exits;
	Vector<Item*> items;

	Player* player = nullptr;
public:
	World();
	~World();
	void CreateWorld();
	void Command();
};
#endif