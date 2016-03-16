#include "World.h"
#include <stdio.h>
#include <stdlib.h>
#include "Exits.h"
#include "Room.h"
//Moving Functions
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
	if (player[0].position == 0){//from kid's room to wood house
		if (exits[0].door == 0){
			player[0].position = 6;
			printf("\n\t%s\n", (rooms[player[0].position].name));
			printf("%s\n", (rooms[player[0].position].description));
		}
		if (exits[0].door == 1){
			printf("\nThe door is closed\n");
		}
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
		printf("\n%s\n", (rooms[player[0].position].description));
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

//Looking functions
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