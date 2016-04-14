#ifndef _ENTITY_
#define _ENTITY_
#include "My string.h"
#include "Vector.h"

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity {
public:
	Entity(const char* name, const char *desc) : name(name), description(desc)
	{}

	virtual ~Entity(){};
	string Get_Name() const
	{
		return name;
	}

	string Get_Description()const
	{
		return description;
	}

public:
	EntityType type;
	string name;
	string description;

	Entity* parent;
	Vector<Entity*> container;
};
#endif