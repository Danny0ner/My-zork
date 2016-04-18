#ifndef _ENTITY_ 
#define _ENTITY_

#include"MyString.h"

class Entity
{
public:

	String name;
	String description;
	Entity(const char*,const char*);
	virtual ~Entity(){}
	virtual void Look() const{};

};



#endif