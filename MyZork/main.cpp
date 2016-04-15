#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

	World w;

	w.CreateWorld(); 
	printf("Hi!!!!   Welcome To my Zork\n\n");
	w.Help();
	
	MyString option;
	char command[70];
	int position = 0; 

	while (1){
		int opt;
		fflush(stdin);
		printf("\n> ");
		gets_s(command, 70);
		if (command[0] != NULL && command[0] != ' ')
		{
			Vector<MyString> commands = option.SplitString(" ", command);

			for (int i = 0; i < commands.size(); i++)
			{
				printf("%s\n", commands[i].c_str());
			}


			if (GetCommand(commands) == Movement)
			{
				w.Movement(position, commands);
			}

			else if (GetCommand(commands) == Look)
			{
				w.Look(position, commands);
			}

			else if (GetCommand(commands) == Open)
			{
				w.Open(position, commands);
			}


			else if (GetCommand(commands) == Close)
			{
				w.Close(position, commands);
			}


			else if (GetCommand(commands) == Pick)
			{
				w.Pick(commands);
			}


			else if (GetCommand(commands) == Close)
			{
				w.Drop(commands);
			}

			else if (GetCommand(commands) == Help)
			{
				w.Help();
			}

			else if (GetCommand(commands) == Invalid_command)
			{
				printf("Invalid command\n");
			}

			else if (GetCommand(commands) == Quit)
			{
				return 0;
			}
		}
	}

	return 0;
}

