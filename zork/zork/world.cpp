#include"World.h"
#include<stdio.h>
#include<string.h>


World::World()
{
	rooms = new Room[11];
	player = new Player;
	exits = new Exit[11];
}

void World::CreateWorld() const
{
	int  i;
	char *names[] = { "Cave", "Garden", "A kid's room", "temple", "frozen lake", "Beach", "Strange Roomm", "Videogames' shop", "wood house", "secret room 1", "secret room 2",};
	for (i = 0; i < 11; i++)
	{
		strcpy_s((rooms + i)->name, names[i]);
	}
	char *descriptions[] = {
		"Cave description",
		"garden description",
		"a kid's room description",
		"temple description",
		"frozen lake description",
		"beach description",
		"strange room description",
		"videogames' shop description",
		"Wood house description",
		"secret room 1 description",
		"secret room 2 description",
	};
	for (i = 0; i < 11; i++)
	{
		strcpy_s((rooms + i)->description, descriptions[i]);
	}
}

World::~World()
{
	delete[] rooms;
	delete player;
	delete[] exits;
}