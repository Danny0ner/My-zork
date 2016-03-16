#include "World.h"
#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "Room.h"
#include <string.h>

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

void World::OpenDoor(){
	if ((player[0].position == 0) && (exits[0].door == 1)){
		printf("you opened the door");
		exits[0].door = 0;
	}
	else if ((player[0].position == 6) && (exits[0].door == 1)){
		printf("you opened the door");
		exits[0].door = 0;
	}
	else if ((player[0].position == 0) && (exits[0].door == 0)){
		printf("The door is already open");
	}
	else if ((player[0].position == 6) && (exits[0].door == 0)){
		printf("The door is already open");
	}
	else {
		printf("There's no door to open here");
	}
}

void World::CloseDoor(){
	if ((player[0].position == 0) && (exits[0].door == 0)){
		printf("\nyou closed the door\n");
		exits[0].door = 1;
	}
	else if ((player[0].position == 6) && (exits[0].door == 0)){
		printf("\nyou closed the door\n");
		exits[0].door = 1;
	}
	else if ((player[0].position == 0) && (exits[0].door == 1)){
		printf("\nThe door is already closed\n");
	}
	else if ((player[0].position == 6) && (exits[0].door == 1)){
		printf("\nThe door is already closed\n");
	}
	else {
		printf("\nThere's no door to close here\n");
	}
}