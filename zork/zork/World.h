#include"Room.h"
#include"Player.h"
#include"Exits.h"

class World
{
public:

	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;

	World();
	~World();
	void CreateWorld() const;
};