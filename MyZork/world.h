#ifndef _WORLD_
#define  _WORLD_

#include"rooms.h"
#include"player.h"
#include"exits.h"
#include"Actions.h"
#include"Entity.h"
#include"MyString.h"
#include"items.h"
#include"vector.h"

#define EXIT 200
#define NUM_ROOMS 11
#define NUM_EXITS 18
#define NUM_ITEMS 9
#define TOKENIZE 100

// Now, if you include "world.h" in other files,
// you are including these other headers and MACROS too.

class World
{
public:

	Vector<Room*> rooms;
	Vector<Exit*> exits;
	Vector<Item*> items;


	Player* player = nullptr;


	World();

	void CreateWorld();
	void Movement(int&, Vector<String>&);
	void Look(int, Vector<String>&) const;
	void Help() const;
	void Open(int, Vector<String>&) const;
	void Close(int, Vector<String>&) const;
	void Pick(Vector<String>&);
	void Drop(Vector<String>&);
	void Inventory() const;
	void Shrink();
	void Equip(Vector<String>&);
	void Grow();
	void Unequip(Vector<String> &commands);
	void Die() const;
	~World();
};

#endif