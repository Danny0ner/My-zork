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
		"You can't see very much, but it seems to be an aquamarine cave. There you can see two weapones on the ground.",
		"The garden is like the one on alice in wonderland, it has a lot of colors and seems to a good place to stay.",
		"This place seems like a kid's room, it has a lot of toys. This room also its a bit creepy.",
		"a big stone temple stands at you, it seems to have more than ten thousand years of antiquity.",
		"You can see a enormous frozen lake that could kill you if you were inside it in like 5 seconds. You'll prefer to take care with it.",
		"You arrive at the beach, the sun reinforces you, it helps you to recover your forces.",
		"at the moment that you enter on this room, you get scared, but you don't know why. You only know that you want to scape from there as fast as possible.",
		"You always loved videogames, so this is like your paradise, you can see the shop assistant standing at the back of the shop.",
		"you enter in a wood hause that is exactly like the one of a book that you did read when you were a child.",
		"In the center of the room you can see a sphinx, it seems that want to talk with you.",
		"In the center of the room you can see a sphinx, it seems that want to talk with you.",
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