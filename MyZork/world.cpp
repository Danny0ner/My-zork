#include"world.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


World::World()
{
	player = new Player;
}

void World::CreateWorld() 
{
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
	exits.pushback(new Exit("Garden", "at the entrance of the shop you can see a garden.", rooms[4], rooms[1], south, false, true));
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


/* MOVEMENT FUNCTION */
void World::Movement(int &pos, Vector<MyString> &commands)
{
	fflush(stdin);

	int i, j; //counters that consider the correct room/exit when you move.

	player->player_pos = rooms[pos];

	if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "north" && commands[1] == "n") || commands[0] == "north" || commands[0] == "n")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)  //Case 1: the exit has a closed door you have to open first
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else  //Case 2: there is a room in the chosen direction and there isn't a closed door (sets a new position for the player).
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");  //Case 3: there isn't any room in the chosen direction
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "south" || commands[1] == "s") || commands[0] == "south" || commands[0] == "s")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "east" || commands[1] == "e") || commands[0] == "east" || commands[0] == "e")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "west" || commands[1] == "w") || commands[0] == "west" || commands[0] == "w")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "down" || commands[1] == "d") || commands[0] == "down" || commands[0] == "d")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "up" || commands[1] == "u") || commands[0] == "up" || commands[0] == "u")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}	
		}
		printf("\nYou can't move into that way.\n");
	}

	else
	{
		printf("\nYou have to specify in which direction you want to move.\n");
		return;
	}
}

void World::Look(int pos, Vector<MyString> &commands) const
{
	int i; //Countes to consider the correct room/exit when you are looking
	player->player_pos = rooms[pos];

	if (commands.size() == 2 && (commands[1] == "north" || commands[1] == "n" ))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north) //Case 2: name and description of the exit placed in the chosen direction
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");  //Case 3: there's no exit placed in the chosen direction
	}

	else if (commands.size() == 2 && (commands[1] == "south" || commands[1] == "s"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "east" || commands[1] == "e"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "west" || commands[1] == "w"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "up" || commands[1] == "u"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "down" || commands[1] == "d"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else //Case 1: name and description of the room you are.
	{
		rooms[pos]->Look();
		for (i = 0; i < NUM_ITEMS; i++)
		{
			if (player->player_pos == items[i]->src && items[i]->picked == false)
			{
				printf("\nItems you can find here:\n");
				items[i]->Look();
			}
		}
	}
}

void World::Help() const
{
}



void World::Open(int pos, Vector<MyString>&commands) const
{
	int i;  //Counter to consider the correct exit
	player->player_pos = rooms[pos];

	/*if ((commands.size() == 2 && (commands[1] == "north" || commands[1] == "n"))
	{
		printf("\nYou have to specify which door you want to open.\n");
		return;
	}*/

	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			//OPEN CONDITION: the exit you want to "open" has a door, and its door is closed
			if (exits[i]->src == player->player_pos && exits[i]->direction == north && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else
	{
	printf("\nYou have to specify which door you want to open.\n");
	return;
	}
}


void World::Close(int pos, Vector<MyString> &commands) const
{
	int i;
	player->player_pos = rooms[pos];

	/*if (close == close_door)
	{
		printf("\nYou have to specify which door you want to close.\n");
		return;
	}*/


	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door")
	{
		//CLOSE CONDITION: the exit you want to "close" has a door, and its door is opened
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}
}


void World::Pick(Vector<MyString> &commands)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (commands.size() == 2 && items[i]->name == commands[1] && exits[i]->src == player->player_pos && items[i]->picked == false)
		{
			items[i]->picked = true;
			player->num_items++;
			printf("You picked %s", items[i]->name.c_str());
			return;
		}
	}
	printf("There's any object with that name here.\n");
}

void World::Drop(Vector<MyString> &commands)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (commands.size() == 2 && items[i]->name == commands[1] && items[i]->picked == true)
		{
			items[i]->picked = false;
			items[i]->src = player->player_pos;
			printf("You droped %s", items[i]->name.c_str());
			return;
		}
	}
	printf("There's any object with that name here.\n");
}


World::~World()
{
	delete player;
	delete[] inventory;
}


