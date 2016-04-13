#include"Room.h"
#include"Player.h"
#include"Exits.h"

class World : public Entity
{
public:

	vector<Room>* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;
public:

	World();
	~World();
public:
	void CreateWorld() const;
	void Command() const;
	void CreateExits() const;
};