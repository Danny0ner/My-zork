#include"world.h"
#include<stdio.h>

void Room::Look()const
{
	printf("\n\t%s\n%s", name.c_str(), description.c_str());
}

void Room::LookShrink() const
{
	printf("\n\t%s\n%s", name.c_str(), ShrinkDesc.c_str());
}

Room::Room(const char* name, const char* descrip, const char* shrinkdesc) : ShrinkDesc(shrinkdesc), Entity(name, descrip){}


