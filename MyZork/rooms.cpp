#include"world.h"
#include<stdio.h>

void Room::Look()const
{
	printf("\n%s\n%s", name.c_str(), description.c_str());
}

Room::Room(const char* name, const char* descrip, const char* shrinkdesc) : ShrinkDesc(shrinkdesc), Entity(name, descrip){}


