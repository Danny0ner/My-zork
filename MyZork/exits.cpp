#include"world.h"
#include<stdio.h>

void Exit::Look()const
{
	printf("\n%s%s\n", name.c_str(), description.c_str());
}

Exit::Exit(const char* name, const char* descrip, Room* source, Room* dest, dir direct,bool d,bool o) :Entity(name, descrip), 
src(source), dst(dest), direction(direct),door(d),open(o){}