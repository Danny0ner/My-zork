#ifndef _ENTITY_
#define _ENTITY_
#include "My string.h"
#include "Vector.h"

enum EntityType{
	ENtity,
	ROOM,
	EXIT,
	ITEM,
	PLAYER,
};

class Entity {
public:
	Entity* Type;
	EntityType EnType;
	string name;
	string description;
	vector<Entity*> buffer;
public:
	Entity(const char* name, const char* description, Entity* Type) : name(name), description(description), Type(Type){
		EnType = ENtity;
		if (Type != NULL) Type->buffer.pushback(this);
	};
	virtual ~Entity(){};
};
#endif