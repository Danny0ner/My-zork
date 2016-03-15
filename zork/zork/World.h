#include"Room.h"
#include"Player.h"
#include"Exits.h"

class World
{
public:

	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;
public:

	World();
	~World();
public:
	void CreateWorld() const;
	void Command();
	void CreateExits() const;
	void MoveNorth();
	void MoveSouth();
	void MoveWest();
	void MoveEast();
};