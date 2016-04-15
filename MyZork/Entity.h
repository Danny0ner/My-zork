#ifndef _ENTITY_ 
#define _ENTITY_

#include"MyString.h"

class Entity
{
public:

	MyString name;
	MyString description;
	Entity(const char*,const char*);
	//~Entity();
	virtual void Look() const{};

};



#endif