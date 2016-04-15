#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"


int GetCommand(Vector<MyString>&commands)
{

	if (commands[0] == "go" || commands[0] == "n" || commands[0] == "s" || commands[0] == "e" ||
		commands[0] == "w" || commands[0] == "d" || commands[0] == "u" || commands[0] == "north" ||
		commands[0] == "south" || commands[0] == "east" || commands[0] == "west" || commands[0] == "up" || 
		commands[0] == "down")
	{
		return Movement;
	}
	else if (commands[0] == "look")
	{
		return Look;
	}
	else if (commands[0] == "open")
	{
		return Open;
	}

	else if (commands[0] == "close")
	{
		return Close;
	}

	else if (commands[0] == "pick")
	{
		return Pick;
	}


	else if (commands[0] == "drop")
	{
		return Drop;
	}

	else if (commands[0] == "help")
	{
		return Help;
	}

	else if (commands[0] == "quit")
	{
		return Quit;
	}

	else
	{
		return Invalid_command;
	}



}