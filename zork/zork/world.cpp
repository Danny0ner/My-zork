#include "World.h"
#include "Exits.h"
#include "Room.h"
#include "Vector.h"
#include "My string.h"
#include "Entity.h"
#include "Player.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXITTS 20

World::World()
{
	player = new Player;
}
void World::CreateWorld(){
	rooms.pushback(new Room("Cave", " You can't see very much, but it seems to be an aquamarine cave. There you can see two weapones on the ground."));
	rooms.pushback(new Room("Garden", "The garden is like the one on alice in wonderland, it has a lot of colors and seems to a good place to stay."));
	rooms.pushback(new Room("Temple", "A big stone temple stands at you, it seems to have more than ten thousand years of antiquity."));
	rooms.pushback(new Room("Strange Room", "at the moment that you enter on this room, you get scared, but you don't know why. You only know that you want to scape from there as fast as possible."));
	rooms.pushback(new Room("Videogames' shop", "You always loved videogames, so this is like your paradise, you can see the shop assistant standing at the back of the shop. "));
	rooms.pushback(new Room("Secret Room 1", "In the center of the room you can see a sphinx, it seems that want to talk with you."));
	rooms.pushback(new Room("A Kid's Room", "This place seems like a kid's room, it has a lot of toys. This room also its a bit creepy."));
	rooms.pushback(new Room("Wooden house", "you enter in a wood hause that is exactly like the one of a book that you did read when you were a child."));
	rooms.pushback(new Room("Frozen Lake", "You can see a enormous frozen lake that could kill you if you were inside it in like 5 seconds.You'll prefer to take care with it."));
	rooms.pushback(new Room("Beach", "You arrive at the beach, the sun reinforces you, it helps you to recover your forces.You can see a trapdoor under your feet."));
	rooms.pushback(new Room("Secret Room 2", "In the center of the room you can see a sphinx, it seems that want to talk with you."));

	exits.pushback(new Exit("Cave", "You can see a door that enters into darkness.", rooms[1], rooms[0], south, false, true));
	exits.pushback(new Exit("Cave", "You can see a cave.", rooms[2], rooms[0], west, false, true));
	exits.pushback(new Exit("Cave", "The door goes to the cave.", rooms[6], rooms[0], east, false, true));
	exits.pushback(new Exit("Cave", "You can see the entrance of a cave.", rooms[8], rooms[0], north, false, true));
	exits.pushback(new Exit("Garden", "You can see a door at the end. The sun enters through the door.", rooms[0], rooms[1], north, false, true));
	exits.pushback(new Exit("Garden", "at the entrance of the shop you can see a garden.", rooms[4], rooms[1], north, false, true));
	exits.pushback(new Exit("Videogames' Shop", "At the end of the garden you can see a videogames' shop.", rooms[1], rooms[4], north, false, true));
	exits.pushback(new Exit("Videogames' Shop", "The stairs go down to the videogames' Shop.", rooms[5], rooms[4], down, false, true));
	exits.pushback(new Exit("Secret Room 1", "You can see a stairs that go up to the attic.", rooms[4], rooms[5], up, false, true));
	exits.pushback(new Exit("Temple", "you can see light at the end of the path.", rooms[0], rooms[2], east, false, true));
	exits.pushback(new Exit("Temple", "there's a door to exit this room.", rooms[3], rooms[2], west, false, true));
	exits.pushback(new Exit("Strange Room", "There's a strange door right there.", rooms[2], rooms[3], east, false, true));
	exits.pushback(new Exit("A Kid's Room", "There's a colored door right there.", rooms[0], rooms[6], west, false, true));
	exits.pushback(new Exit("A Kid's Room", "The door is colored like if it was made by a kid.", rooms[7], rooms[6], east, false, true));
	exits.pushback(new Exit("wooden House", "You can see a wooden door behind a wardrove.", rooms[6], rooms[7], west, false, true));
	exits.pushback(new Exit("Frozen Lake", "An invernal wind comes from that exit.", rooms[0], rooms[8], south, false, true));
	exits.pushback(new Exit("Frozen Lake", "in the distance you can see a forzen lake", rooms[9], rooms[8], north, false, true));
	exits.pushback(new Exit("Beach", "you can see a beach in the distance", rooms[8], rooms[9], south, false, true));
	exits.pushback(new Exit("Beach", "The stairs goes back to the beach.", rooms[10], rooms[9], up, false, true));
	exits.pushback(new Exit("Secret Room 2", "There is a trapdoor under your feet. Seems that you can go for there.", rooms[9], rooms[10], down, false, true));
}

World::~World()
{}


void World::Command() {

	player[0].position = rooms[0];

	char command[20];

	char *help;
	char *first;
	char *second;

	int i = 0;
	while (1){
		do{

			gets_s(command);
			if (strcmp(command, "quit") == 0){ exit(0); }
			first = strtok_s(command, " ", &help);
		} while (first == NULL);
		second = strtok_s(NULL, " ", &help);
		if (strcmp(command, "help") == 0 || strcmp(command, "HELP") == 0 || strcmp(command, "Help") == 0)
		{
			printf("Hi, and Wellcome to my zork\n\nComands:\n\n'help' for show this help again\n 'go' and a direction to move around the map.\n'look' for receive the description of the room\n'open' for open a doors and other stuff\n'close' for close a door or other stuff\n'quit' for quite the game\n\n");

		}
		//-------------------------------------------------------------------------------------------//
		else if (strcmp(command, "go") == 0 || strcmp(command, "Go") == 0 || strcmp(command, "GO") == 0)
		{

			if (second == NULL){
				printf("Writte a right command please ( 'GO' 'Direction'?");   //if the player do not writte a second word, the program will ask again
			}
			else if (strcmp(second, "north") == 0 || strcmp(second, "n") == 0 || strcmp(second, "N") == 0 || strcmp(second, "NORTH") == 0 || strcmp(second, "North") == 0){
				for (i = 0; i <= EXITTS; i++)
				{
					if ((exits[i]->direction == north) && (exits[i]->origin == (player[0].position)))
					{
						printf("\n\t%s\n%s\n", exits[i]->name, exits[i]->description);
						(player[0].position) = (exits[i]->destination);
						break;
					}
					if (i == EXITTS && exits[i]->origin != player[0].position){
						printf("\n>There's no way there\n");

					}
				}

			}
			else if (strcmp(second, "south") == 0 || strcmp(second, "s") == 0 || strcmp(second, "S") == 0 || strcmp(second, "SOUTH") == 0 || strcmp(second, "South") == 0){
				for (i = 0; i <= EXITTS; i++)
				{
					if ((exits[i]->direction == south) && (exits[i]->origin == (player[0].position)))
					{

						printf("\n\t%s\n%s\n", exits[i]->name, exits[i]->description);
						(player[0].position) = (exits[i]->destination);
						break;
					}
					if (i == EXITTS && exits[i]->origin != player[0].position){
						printf("\n>There's no way there\n");
						break;
					}
				}
			}

			else if (strcmp(second, "west") == 0 || strcmp(second, "w") == 0 || strcmp(second, "W") == 0 || strcmp(second, "WEST") == 0 || strcmp(second, "West") == 0){
				for (i = 0; i <= EXITTS; i++)
				{
					if ((exits[i]->direction == west) && (exits[i]->origin == (player[0].position)))
					{

						printf("\n\t%s\n%s\n", exits[i]->name, exits[i]->description);
						(player[0].position) = (exits[i]->destination);
						break;
					}

				}
			}
			else if (strcmp(second, "east") == 0 || strcmp(second, "e") == 0 || strcmp(second, "E") == 0 || strcmp(second, "EAST") == 0 || strcmp(second, "East") == 0)
			{
				for (i = 0; i <= EXITTS; i++)
				{
					if ((exits[i]->direction == east) && (exits[i]->origin == (player[0].position)))
					{
						printf("\n\t%s\n%s\n", exits[i]->name, exits[i]->description);
						(player[0].position) = (exits[i]->destination);
						break;
					}if (i == EXITTS && exits[i]->origin != player[0].position){
						printf("\n>There's no way there\n");
						break;
					}

				}

			}

			else if (strcmp(second, "up") == 0 || strcmp(second, "UP") == 0)
			{
				for (i = 0; i <= EXITTS; i++)
				{
					if ((exits[i]->direction == up) && (exits[i]->origin == (player[0].position)))
					{
						printf("\n\t%s\n%s\n", exits[i]->name, exits[i]->description);
						(player[0].position) = (exits[i]->destination);
						break;
					}if (i == EXITTS && exits[i]->origin != player[0].position){
						printf("\n>There's no way there\n");
						break;
					}

				}

			}
			else if (strcmp(second, "down") == 0 || strcmp(second, "DOWN") == 0 || strcmp(second, "Down"))
			{
				for (i = 0; i <= EXITTS; i++)
				{
					if ((exits[i]->direction == down) && (exits[i]->origin == (player[0].position)))
					{
						printf("\n\t%s\n%s\n", exits[i]->name, exits[i]->description);
						(player[0].position) = (exits[i]->destination);
						break;
					}if (i == EXITTS && exits[i]->origin != player[0].position){
						printf("\n>There's no way there\n");
						break;
					}

				}

			}

			else {
				printf("\n>There's no way there\n"); break;
			}

		}


		//------------------------------------------------------------------------------------//
		else if (strcmp(command, "look") == 0 || strcmp(command, "LOOK") == 0 || strcmp(command, "Look") == 0) {

			printf("\n%s\n", player[0].description);

		}
		//------------------------------------------------------------------------------------//
		else if (strcmp(command, "open") == 0 || strcmp(command, "OPEN") == 0 || strcmp(command, "Open") == 0){
			if (second == NULL){
				printf("Writte a right command please ( 'Open' 'Direction'?");
			}
			else if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "N") == 0 || strcmp(second, "n") == 0){

				for (i = 0; i < EXITTS; i++)
				{
					if ((exits[i]->direction == north) && (exits[i]->open == close) && (exits[i]->origin == (player[0].position)))
					{
						exits[i]->open = open;
						printf("\n You open the North Door\n");
						break;
					}
					else if ((exits[i]->direction == north) && (exits[i]->open == open) && (exits[i]->origin == (player[0].position))){
						printf("\n>This door is already open\n");
					}
					else if ((exits[i]->direction == north) && (exits[i]->origin == (player[0].position))){
						printf("\n>You can't open this door\n"); break;

					}
				}

			}
			else if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "S") == 0 || strcmp(second, "s") == 0){

				for (i = 0; i < EXITTS; i++)
				{
					if ((exits[i]->direction == south) && (exits[i]->open == close) && (exits[i]->origin == (player[0].position)))
					{
						exits[i]->open = open;
						printf("\n You open the South Door\n");
						break;
					}
					else if ((exits[i]->direction == south) && (exits[i]->open == open) && (exits[i]->origin == (player[0].position))){
						printf("\n>This door is already open\n");
					}
					else if ((exits[i]->direction == south) && (exits[i]->origin == (player[0].position))){
						printf("\n>You can't open this door\n"); break;

					}
				}

			}
		}
		//--------------------------------------------------------------------//
		else if (strcmp(command, "close") == 0 || strcmp(command, "CLOSE") == 0 || strcmp(command, "close") == 0){
			if (second == NULL){
				printf("Writte a right command please ( 'close' 'Direction'?");
			}
			else if (strcmp(second, "north") == 0 || strcmp(second, "North") == 0 || strcmp(second, "N") == 0 || strcmp(second, "n") == 0){

				for (i = 0; i < EXITTS; i++)
				{
					if ((exits[i]->direction == north) && (exits[i]->open == open) && (exits[i]->origin == (player[0].position)))
					{
						exits[i]->open = close;
						printf("\n You close the North Door\n");
						break;
					}
					else if ((exits[i]->direction == north) && (exits[i]->open == close) && (exits[i]->origin == (player[0].position))){
						printf("\n>This door is already closed\n");
					}
					else if ((exits[i]->direction == north) && (exits[i]->origin == (player[0].position))){
						printf("\n>You can't close this door\n"); break;

					}
				}

			}
			else if (strcmp(second, "south") == 0 || strcmp(second, "South") == 0 || strcmp(second, "S") == 0 || strcmp(second, "s") == 0){

				for (i = 0; i < EXITTS; i++)
				{
					if ((exits[i]->direction == south) && (exits[i]->open == open) && (exits[i]->origin == (player[0].position)))
					{
						exits[i]->open = close;
						printf("\n You close the South Door\n");
						break;
					}
					else if ((exits[i]->direction == south) && (exits[i]->open == close) && (exits[i]->origin == (player[0].position))){
						printf("\n>This door is already closed\n");
					}
					else if ((exits[i]->direction == south) && (exits[i]->origin == (player[0].position))){
						printf("\n>You can't close this door\n"); break;

					}
				}

			}
		}
	}
};

/*
void World::CreateExits() const{

	strcpy_s(exits[0].name, "Cave");
	strcpy_s(exits[0].description, rooms[0].description);
	exits[0].origin = &rooms[1];
	exits[0].destination = &rooms[0];
	exits[0].direction = south;

	strcpy_s(exits[1].name, "Cave");
	strcpy_s(exits[1].description, rooms[0].description);
	exits[1].origin = &rooms[8];
	exits[1].destination = &rooms[0];
	exits[1].direction = north;

	strcpy_s(exits[2].name, "Cave");
	strcpy_s(exits[2].description, rooms[0].description);
	exits[2].origin = &rooms[2];
	exits[2].destination = &rooms[0];
	exits[2].direction = west;

	strcpy_s(exits[3].name, "Cave");
	strcpy_s(exits[3].description, rooms[0].description);
	exits[3].origin = &rooms[6];
	exits[3].destination = &rooms[0];
	exits[3].direction = east;

	strcpy_s(exits[4].name, "Garden");
	strcpy_s(exits[4].description, rooms[1].description);
	exits[4].origin = &rooms[0];
	exits[4].destination = &rooms[1];
	exits[4].direction = north;


	strcpy_s(exits[5].name, "Garden");
	strcpy_s(exits[5].description, rooms[1].description);
	exits[5].origin = &rooms[4];
	exits[5].destination = &rooms[1];
	exits[5].direction = south;

	strcpy_s(exits[6].name, "Videogames' shop");
	strcpy_s(exits[6].description, rooms[4].description);
	exits[6].origin = &rooms[1];
	exits[6].destination = &rooms[4];
	exits[6].direction = north;

	strcpy_s(exits[7].name, "Videogames' shop");
	strcpy_s(exits[7].description, rooms[4].description);
	exits[7].origin = &rooms[5];
	exits[7].destination = &rooms[4];
	exits[7].direction = down;


	strcpy_s(exits[8].name, "Secret Room 1");
	strcpy_s(exits[8].description, rooms[5].description);
	exits[8].origin = &rooms[4];
	exits[8].destination = &rooms[5];
	exits[8].direction = up;



	strcpy_s(exits[9].name, "Temple");
	strcpy_s(exits[9].description, rooms[2].description);
	exits[9].origin = &rooms[0];
	exits[9].destination = &rooms[2];
	exits[9].direction = east;


	strcpy_s(exits[10].name, "Temple");
	strcpy_s(exits[10].description, rooms[2].description);
	exits[10].origin = &rooms[3];
	exits[10].destination = &rooms[2];
	exits[10].direction = west;



	strcpy_s(exits[11].name, "Strange room");
	strcpy_s(exits[11].description, rooms[3].description);
	exits[11].origin = &rooms[2];
	exits[11].destination = &rooms[3];
	exits[11].direction = east;


	strcpy_s(exits[12].name, "A kid's room");
	strcpy_s(exits[12].description, rooms[6].description);
	exits[12].origin = &rooms[0];
	exits[12].destination = &rooms[6];
	exits[12].direction = west;


	strcpy_s(exits[13].name, "A kid's room");
	strcpy_s(exits[13].description, rooms[6].description);
	exits[13].origin = &rooms[7];
	exits[13].destination = &rooms[6];
	exits[13].direction = east;


	strcpy_s(exits[14].name, "Wood House");
	strcpy_s(exits[14].description, rooms[7].description);
	exits[14].origin = &rooms[6];
	exits[14].destination = &rooms[7];
	exits[14].direction = west;


	strcpy_s(exits[15].name, "Frozen lake");
	strcpy_s(exits[15].description, rooms[8].description);
	exits[15].origin = &rooms[0];
	exits[15].destination = &rooms[8];
	exits[15].direction = south;


	strcpy_s(exits[16].name, "Frozen lake");
	strcpy_s(exits[16].description, rooms[8].description);
	exits[16].origin = &rooms[9];
	exits[16].destination = &rooms[8];
	exits[16].direction = north;


	strcpy_s(exits[17].name, "beach");
	strcpy_s(exits[17].description, rooms[9].description);
	exits[17].origin = &rooms[8];
	exits[17].destination = &rooms[9];
	exits[17].direction = south;


	strcpy_s(exits[18].name, "beach");
	strcpy_s(exits[18].description, rooms[9].description);
	exits[18].origin = &rooms[10];
	exits[18].destination = &rooms[9];
	exits[18].direction = up;


	strcpy_s(exits[19].name, "Secret room 2");
	strcpy_s(exits[19].description, rooms[10].description);
	exits[19].origin = &rooms[9];
	exits[19].destination = &rooms[10];
	exits[19].direction = down;
}
*/