#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

	World map;

	map.CreateWorld(); 
	printf("\t\t\t Welcome To my Zork\n\n");
	printf("Hi!! Welcome to my own Zork. I hope you enojoy it as much i did doing it (sometimes it has been horrible). Btw, press help if you want to see the comands. Enjoy<3\n\n");

	printf("\tCave\nYou can't see very much, but it seems to be an aquamarine cave.\n\n");
	
	MyString option;
	char command[70];
	int position = 0; 

	while (1){
		fflush(stdin);
		printf("\n\n> ");
		gets_s(command, 70);
		if (command[0] != NULL && command[0] != ' ')
		{
			Vector<MyString> commands = option.SplitString(" ", command);

				if (GetCommand(commands) == Move)         map.Movement(position, commands);

				else if (GetCommand(commands) == Look)        map.Look(position, commands);

				else if (GetCommand(commands) == Open)        map.Open(position, commands);

				else if (GetCommand(commands) == Close)       map.Close(position, commands);

				else if (GetCommand(commands) == Pick)        map.Pick(commands);

				else if (GetCommand(commands) == Drop)        map.Drop(commands);

				else if (GetCommand(commands) == Inventory)   map.Inventory();

				else if (GetCommand(commands) == Help)        map.Help();
				
				else if (GetCommand(commands) == Shrink)      map.Shrink();

				else if (GetCommand(commands) == Grow)        map.Grow();

				else if (GetCommand(commands) == Unequip)      map.Unequip(commands);

				else if (GetCommand(commands) == Equip)       map.Equip(commands);

				else if (GetCommand(commands) == Invalid_command)      printf("Invalid command, try again pls\n");

				else if (GetCommand(commands) == Quit)        return 0;
		}

	}

	return 0;
}

