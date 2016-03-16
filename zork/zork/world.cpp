#include"World.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


World::World()
{
	rooms = new Room[11];
	player = new Player;
	exits = new Exit[40];
}

World::~World()
{
	delete[] rooms;
	delete player;
	delete[] exits;
}

void World::Command(){
	char command[20];
	printf("\n-");
	gets_s(command);

	if (strcmp("help", command) == 0){
		printf("hello");
	}
	else if (strcmp("quit", command) == 0){
		exit(0);
	}
	else if ((strcmp("go north", command) == 0) || (strcmp("go n", command) == 0)){
		MoveNorth();
	}
	else if ((strcmp("go south", command) == 0) || (strcmp("go s", command) == 0)){
		MoveSouth();
	}
	
	else if ((strcmp("go west", command) == 0) || (strcmp("go w", command) == 0)){
		MoveWest();
	}
	else if ((strcmp("go east", command) == 0) || (strcmp("go e", command) == 0)){
		MoveEast();
	}
	else if (strcmp("go down", command) == 0){
		MoveDown();
	}
	else if (strcmp("go up", command) == 0){
		MoveUp();
	}
	else if (strcmp("go", command) == 0){
		printf("Especify a direction pls.\n");
	}
	else if (strcmp("look", command) == 0){
		printf("\n%s\n", rooms[player[0].position].description);
	}
	else if ((strcmp("look north", command) == 0) || (strcmp("look n", command) == 0)){
		LookNorth();
	}
	else if ((strcmp("look south", command) == 0) || (strcmp("look s", command) == 0)){
		LookSouth();
	}
	else if ((strcmp("look west", command) == 0) || (strcmp("look w", command) == 0)){
		LookWest();
	}

	else if ((strcmp("look east", command) == 0) || (strcmp("look e", command) == 0)){
		LookEast();
	}
	else if (strcmp("look up", command) == 0){
		LookUp();
	}
	else if (strcmp("look down", command) == 0){
		LookDown();
	}
	else if (strcmp("open door", command) == 0){
		OpenDoor();
	}
	else if (strcmp("close door", command) == 0){
		CloseDoor();
	}
	else {
		printf("enter your command again pls.\n");
	}
}

