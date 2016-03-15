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

void World::CreateWorld() const
{
	int  i;
	char *names[] = { "Cave", "Garden", "Temple", "Strange Room", "Videogames' shop", "Secret room 1", "A kid's room", "Wooden house", "Frozen Lake", "Beach", "Secret room 2",};
	for (i = 0; i < 11; i++)
	{
		strcpy_s((rooms + i)->name, names[i]);
	}
	char *descriptions[] = {
		"You can't see very much, but it seems to be an aquamarine cave. There you can see two weapones on the ground.",
		"The garden is like the one on alice in wonderland, it has a lot of colors and seems to a good place to stay.",
		"A big stone temple stands at you, it seems to have more than ten thousand years of antiquity.",
		"at the moment that you enter on this room, you get scared, but you don't know why. You only know that you want to scape from there as fast as possible.",
		"You always loved videogames, so this is like your paradise, you can see the shop assistant standing at the back of the shop. ",
		"In the center of the room you can see a sphinx, it seems that want to talk with you.",
		"This place seems like a kid's room, it has a lot of toys. This room also its a bit creepy.",
		"you enter in a wood hause that is exactly like the one of a book that you did read when you were a child.",
		"You can see a enormous frozen lake that could kill you if you were inside it in like 5 seconds. You'll prefer to take care with it.",
		"You arrive at the beach, the sun reinforces you, it helps you to recover your forces.",
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

void World::Command(){
	char command[20];
	printf("\n-");
	gets_s(command);

	if (strcmp("help", command) == 0){
		printf("Move Commands: 'go north' or 'go n'  'go south' or 'go s'  'go west' or go w'  'go east' or 'go e'\nLook Commands: 'look'  'look north'  'look south'  'look west' 'look east'\nEnter 'quit' to exit.");
	}
	else if (strcmp("quit", command) == 0){
		exit(0);
	}
	else if (strcmp("go north", command) == 0){
		MoveNorth();
	}
	else if (strcmp("go n", command) == 0){
		MoveNorth();
	}
	else if (strcmp("go south", command) == 0){
		MoveSouth();
	}
	else if (strcmp("go s", command) == 0){
		MoveSouth();
	}
	else if (strcmp("go west", command) == 0){
		MoveWest();
	}
	else if (strcmp("go w", command) == 0){
		MoveWest();
	}
	else if (strcmp("go east", command) == 0){
		MoveEast();
	}
	else if (strcmp("go e", command) == 0){
		MoveEast();
	}
	else {
		printf("enter your command again pls.");
	}
}

void World::CreateExits() const{
	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].description, "You can see a door at the end. The sun enters through the door.");
	exits[0].origen = &rooms[0];
	exits[0].destination = &rooms[1];
	exits[0].direction = north;

	strcpy_s(exits[1].name, "Garden");
	strcpy_s(exits[1].description, "You can see a door that enters into darkness.");
	exits[1].origen = &rooms[1];
	exits[1].destination = &rooms[0];
	exits[1].direction = south;

	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].description, "you can see light at the end of the path.");
	exits[0].origen = &rooms[0];
	exits[0].destination = &rooms[2];
	exits[0].direction = east;

	strcpy_s(exits[2].name, "Temple");
	strcpy_s(exits[2].description, "You can see a cave.");
	exits[2].origen = &rooms[2];
	exits[2].destination = &rooms[0];
	exits[2].direction = west;

	strcpy_s(exits[2].name, "Temple");
	strcpy_s(exits[2].description, "There's a strange door right there");
	exits[2].origen = &rooms[2];
	exits[2].destination = &rooms[3];
	exits[2].direction = east;

	strcpy_s(exits[3].name, "Strange room");
	strcpy_s(exits[3].description, "there's a door to exit this room.");
	exits[3].origen = &rooms[3];
	exits[3].destination = &rooms[2];
	exits[3].direction = west;

	strcpy_s(exits[1].name, "Garden");
	strcpy_s(exits[1].description, "You can see a videogames' shop.");
	exits[1].origen = &rooms[1];
	exits[1].destination = &rooms[4];
	exits[1].direction = north;

	strcpy_s(exits[4].name, "Videogames' shop");
	strcpy_s(exits[4].description, "at the entrance of the shop you can see a garden.");
	exits[4].origen = &rooms[4];
	exits[4].destination = &rooms[1];
	exits[4].direction = south;

	strcpy_s(exits[4].name, "Videogames' shop");
	strcpy_s(exits[4].description, "You can see a backdoor in the shop");
	exits[4].origen = &rooms[4];
	exits[4].destination = &rooms[5];
	exits[4].direction = north;

	strcpy_s(exits[5].name, "Secret Room 1");
	strcpy_s(exits[5].description, "You can see a door that is used to return to the videogames' shop");
	exits[5].origen = &rooms[5];
	exits[5].destination = &rooms[4];
	exits[5].direction = south;

	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].description, "Ther's a colored door in there.");
	exits[0].origen = &rooms[0];
	exits[0].destination = &rooms[6];
	exits[0].direction = west;

	strcpy_s(exits[6].name, "A kid's room");
	strcpy_s(exits[6].description, "The door goes to the cave.");
	exits[6].origen = &rooms[6];
	exits[6].destination = &rooms[0];
	exits[6].direction = east;

	strcpy_s(exits[6].name, "A kid's room");
	strcpy_s(exits[6].description, "there's a wooden door behind a wardrove.");
	exits[6].origen = &rooms[6];
	exits[6].destination = &rooms[7];
	exits[6].direction = west;

	strcpy_s(exits[7].name, "Wood House");
	strcpy_s(exits[7].description, "The door is colored like if it was made by a kid.");
	exits[7].origen = &rooms[7];
	exits[7].destination = &rooms[6];
	exits[7].direction = east;

	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].description, "An invernal wind comes from that exit.");
	exits[0].origen = &rooms[0];
	exits[0].destination = &rooms[8];
	exits[0].direction = south;

	strcpy_s(exits[8].name, "Frozen lake");
	strcpy_s(exits[8].description, "You can see the entrance of a cave.");
	exits[8].origen = &rooms[8];
	exits[8].destination = &rooms[0];
	exits[8].direction = north;

	strcpy_s(exits[8].name, "Frozen lake");
	strcpy_s(exits[8].description, "you can see a beach in the distance");
	exits[8].origen = &rooms[8];
	exits[8].destination = &rooms[9];
	exits[8].direction = south;

	strcpy_s(exits[9].name, "beach");
	strcpy_s(exits[9].description, "in the distance you can see a forzen lake");
	exits[9].origen = &rooms[9];
	exits[9].destination = &rooms[8];
	exits[9].direction = north;

	strcpy_s(exits[9].name, "Beach");
	strcpy_s(exits[9].description, "You can see a hidden door in a rock wall.");
	exits[9].origen = &rooms[9];
	exits[9].destination = &rooms[10];
	exits[9].direction = south;

	strcpy_s(exits[10].name, "Secret room 2");
	strcpy_s(exits[10].description, "The door goes back to the beach");
	exits[10].origen = &rooms[10];
	exits[10].destination = &rooms[9];
	exits[10].direction = north;
}
void  World::MoveNorth(){
	if (player[0].position == 0){ //go from cave to ggarden
		player[0].position = 1;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 1){ //from garden to videogames shop
		player[0].position = 4;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 4){ //from videogames shop to secret room 1
		player[0].position = 5;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 10){ //from secret room 2 to beach
		player[0].position = 9;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 9){ //from beach to frozen lake
		player[0].position = 8;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 8){ //from frozen lake to cave
		player[0].position = 0;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}

void World::MoveSouth(){
	if (player[0].position == 5){ //from secret room 1 to videogames' shop
		player[0].position = 4;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 4){ //from videogames's shop to garden
		player[0].position = 1;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 1){ //from garden to cave
		player[0].position = 0;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 0){ //from cave to frozen lake
		player[0].position = 8;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 8){ //from frozen lake to beach
		player[0].position = 9;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 9){ //from beach to secret room 2
		player[0].position = 10;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}

void World::MoveWest(){
	if (player[0].position == 0){ //from kid's room to wood house
		player[0].position = 6;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 6){ //from cave to kid's room
		player[0].position = 7;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 2){ //form temple to cave
		player[0].position = 0;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 3){ //from strange room to temple
		player[0].position = 2;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}

void World::MoveEast(){
	if (player[0].position == 7){ //from strange room to temple
		player[0].position = 6;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 6){
		player[0].position = 0;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 0){
		player[0].position = 2;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 2){
		player[0].position = 3;
		printf("\n%s\n\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}