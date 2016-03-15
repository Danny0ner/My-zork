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
		"You arrive at the beach, the sun reinforces you, it helps you to recover your forces. You can see a trapdoor under your feet.",
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
		printf("Move Commands: 'go north' or 'go n'  'go south' or 'go s'  'go west' or go w'  'go east' or 'go e'  'go down' or 'go d'  'go up' or 'go u'\nLook Commands: 'look'  'look north'  'look south'  'look west' 'look east'\nEnter 'quit' to exit.");
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
	else if (strcmp("go", command) == 0){
		printf("Especify a direction pls.\n");
	}
	else if (strcmp("look", command) == 0){
		printf("\n%s\n", rooms[player[0].position].description);
	}
	else if (strcmp("look north", command) == 0){
		LookNorth();
	}
	else if (strcmp("look n", command) == 0){
		LookNorth();
	}
	else if (strcmp("look south", command) == 0){
		LookSouth();
	}
	else if (strcmp("look s", command) == 0){
		LookSouth();
	}
	else if (strcmp("go down", command) == 0){
		MoveDown();
	}
	else if (strcmp("go d", command) == 0){
		MoveDown();
	}
	else if (strcmp("look up", command) == 0){
		LookUp();
	}
	else if (strcmp("look u", command) == 0){
		LookUp();
	}
	else if (strcmp("look down", command) == 0){
		LookDown();
	}
	else if (strcmp("look d", command) == 0){
		LookDown();
	}
	else if (strcmp("look west", command) == 0){
		LookWest();
	}
	else if (strcmp("look w", command) == 0){
		LookWest();
	}
	else if (strcmp("look east", command) == 0){
		LookEast();
	}
	else if (strcmp("look e", command) == 0){
		LookEast();
	}
	else {
		printf("enter your command again pls.\n");
	}
}

void World::CreateExits() const{
	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].descriptionN, "You can see a door at the end. The sun enters through the door.");


	strcpy_s(exits[1].name, "Garden");
	strcpy_s(exits[1].descriptionS, "You can see a door that enters into darkness.");
	

	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].descriptionE, "you can see light at the end of the path.");
	
	strcpy_s(exits[2].name, "Temple");
	strcpy_s(exits[2].descriptionW, "You can see a cave.");


	strcpy_s(exits[2].name, "Temple");
	strcpy_s(exits[2].descriptionE, "There's a strange door right there");
	

	strcpy_s(exits[3].name, "Strange room");
	strcpy_s(exits[3].descriptionW, "there's a door to exit this room.");
	

	strcpy_s(exits[1].name, "Garden");
	strcpy_s(exits[1].descriptionN, "You can see a videogames' shop.");
	

	strcpy_s(exits[4].name, "Videogames' shop");
	strcpy_s(exits[4].descriptionS, "at the entrance of the shop you can see a garden.");
	

	strcpy_s(exits[4].name, "Videogames' shop");
	strcpy_s(exits[4].descriptionN, "You can see a backdoor in the shop");


	strcpy_s(exits[4].name, "Videogames' shop");
	strcpy_s(exits[4].descriptionU, "There are a stair that goes up to another room");
	

	strcpy_s(exits[5].name, "Secret Room 1");
	strcpy_s(exits[5].descriptionS, "That trapdoor goes back to the videogames' shop.");
	
	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].descriptionW, "Ther's a colored door in there.");


	strcpy_s(exits[6].name, "A kid's room");
	strcpy_s(exits[6].descriptionE, "The door goes to the cave.");
	

	strcpy_s(exits[6].name, "A kid's room");
	strcpy_s(exits[6].descriptionW, "there's a wooden door behind a wardrove.");
	

	strcpy_s(exits[7].name, "Wood House");
	strcpy_s(exits[7].descriptionE, "The door is colored like if it was made by a kid.");


	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].descriptionS, "An invernal wind comes from that exit.");
	

	strcpy_s(exits[8].name, "Frozen lake");
	strcpy_s(exits[8].descriptionN, "You can see the entrance of a cave.");
	

	strcpy_s(exits[8].name, "Frozen lake");
	strcpy_s(exits[8].descriptionS, "you can see a beach in the distance");
	

	strcpy_s(exits[9].name, "beach");
	strcpy_s(exits[9].descriptionN, "in the distance you can see a forzen lake");

	strcpy_s(exits[9].name, "beach");
	strcpy_s(exits[9].descriptionD, "There is a trapdoor under your feet. Seems that you can go for there.");


	strcpy_s(exits[10].name, "Secret room 2");
	strcpy_s(exits[10].descriptionU, "The stairs goes back to the beach.");
}
void  World::MoveNorth(){
	if (player[0].position == 0){ //go from cave to ggarden
		player[0].position = 1;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 1){ //from garden to videogames shop
		player[0].position = 4;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 10){ //from secret room 2 to beach
		player[0].position = 9;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 9){ //from beach to frozen lake
		player[0].position = 8;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 8){ //from frozen lake to cave
		player[0].position = 0;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}

void World::MoveSouth(){
	if (player[0].position == 5){ //from secret room 1 to videogames' shop
		player[0].position = 4;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 4){ //from videogames's shop to garden
		player[0].position = 1;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 1){ //from garden to cave
		player[0].position = 0;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 0){ //from cave to frozen lake
		player[0].position = 8;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 8){ //from frozen lake to beach
		player[0].position = 9;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}

void World::MoveWest(){
	if (player[0].position == 0){ //from kid's room to wood house
		player[0].position = 6;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 6){ //from cave to kid's room
		player[0].position = 7;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 2){ //form temple to cave
		player[0].position = 0;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 3){ //from strange room to temple
		player[0].position = 2;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}

void World::MoveEast(){
	if (player[0].position == 7){ //from strange room to temple
		player[0].position = 6;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 6){
		player[0].position = 0;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n\t%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 0){
		player[0].position = 2;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 2){
		player[0].position = 3;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("there's no way to go in this direction.");
	}
}
void World::LookNorth(){
	if (player[0].position == 0){
		printf("\n%s\n", exits[player[0].position].descriptionN);
	}
	else if (player[0].position == 1){
		printf("\n%s\n", exits[player[0].position].descriptionN);
	}
	else if (player[0].position == 4){
		printf("\n%s\n", exits[player[0].position].descriptionN);
	}
	else if (player[0].position == 8){
		printf("\n%s\n", exits[player[0].position].descriptionN);
	}
	else if (player[0].position == 9){
		printf("\n%s\n", exits[player[0].position].descriptionN);
	}
	else if (player[0].position == 10){
		printf("\n%s\n", exits[player[0].position].descriptionN);
	}
	else {
		printf("There's nothing of interest in that way.");
	}
}
void World::LookSouth(){
	if (player[0].position == 0){
		printf("\n%s\n", exits[player[0].position].descriptionS);
	}
	else if (player[0].position == 1){
		printf("\n%s\n", exits[player[0].position].descriptionS);
	}
	else if (player[0].position == 4){
		printf("\n%s\n", exits[player[0].position].descriptionS);
	}
	else if (player[0].position == 5){
		printf("\n%s\n", exits[player[0].position].descriptionS);
	}
	else if (player[0].position == 8){
		printf("\n%s\n", exits[player[0].position].descriptionS);
	}
	else if (player[0].position == 9){
		printf("\n%s\n", exits[player[0].position].descriptionS);
	}
}
void World::MoveDown(){
	if (player[0].position == 9){ //from beach to secret room 2
		player[0].position = 10;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 5){ //from videogames shop to secret room 1
		player[0].position = 4;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else {
		printf("There's no way to in that direction");
	}
}
void World::MoveUp(){
	if (player[0].position == 4){ //from videogames shop to secret room 1
		player[0].position = 5;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
	else if (player[0].position == 10){ //from videogames shop to secret room 1
		player[0].position = 9;
		printf("\n\t%s\n", (rooms[player[0].position].name));
		printf("\n%s\n", (rooms[player[0].position].description));
	}
}

void World::LookDown(){
	if (player[0].position == 9){
		printf("\n%s\n", exits[player[0].position].descriptionD);
	}
	else if (player[0].position == 5){
		printf("\n%s\n", exits[player[0].position].descriptionD);
	}
	else {
		printf("nothing of interest there\n");
	}
}
void World::LookUp(){
	if (player[0].position == 4){
		printf("\n%s\n", exits[player[0].position].descriptionU);
	}
	else if (player[0].position == 10){
		printf("\n%s\n", exits[player[0].position].descriptionU);
	}
	else {
		printf("nothing of interest in there\n");
	}
}
void World::LookEast(){
	if (player[0].position == 0){
		printf("\n%s\n", exits[player[0].position].descriptionE);
	}
	else if (player[0].position == 2){
		printf("\n%s\n", exits[player[0].position].descriptionE);
	}
	else if (player[0].position == 6){
		printf("\n%s\n", exits[player[0].position].descriptionE);
	}
	else if (player[0].position == 7){
		printf("\n%s\n", exits[player[0].position].descriptionE);
	}
	else {
		printf("Nothing of interest there\n.");
	}
}
void World::LookWest(){
	if (player[0].position == 3){
		printf("\n%s\n", exits[player[0].position].descriptionW);
	}
	else if (player[0].position == 2){
		printf("\n%s\n", exits[player[0].position].descriptionW);
	}
	else if (player[0].position == 0){
		printf("\n%s\n", exits[player[0].position].descriptionW);
	}
	else if (player[0].position == 6){
		printf("\n%s\n", exits[player[0].position].descriptionW);
	}
	else {
		printf("nothing of interest there.\n");
	}

}