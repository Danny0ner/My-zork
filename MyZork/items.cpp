#include"world.h"
#include<stdio.h>

void Item::Look()const
{
	printf("%s\n%s\n",name.c_str(),description.c_str());
}

Item::Item(const char*name, const char*desc, Room* source, bool p) :Entity(name, desc), src(source), picked(p){}