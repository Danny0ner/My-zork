#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"


int GetCommand(Vector<MyString>&commands)
{

	if (commands[0] == "go")
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
	else if (commands[0] == "inventory")
	{
		return Inventory;
	}

	else if (commands[0] == "shrink")
	{
		return Shrink;
	}
	else if (commands[0] == "equip")
	{
		return Equip;
	}
	else if (commands[0] == "grow"){
		return Grow;
	}
	else if (commands[0] == "unequip"){
		return Unequip;
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