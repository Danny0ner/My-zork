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
	rooms.pushback(new Room("Cave", "You can't see very much, but it seems to be an aquamarine cave.", "You can see the enormous that this cave is now, you're amazed and you try to find something that you couldn't see before but you don't find nothing."));
	rooms.pushback(new Room("Garden", "The garden is like the one on alice in wonderland, it has a lot of colors and seems to a good place to stay.", "Being that small, you're so scared of all the insects of the garden, you should run out of here before they do something to you."));
	rooms.pushback(new Room("Temple", "A big stone temple stands at you, it seems to have more than ten thousand years of antiquity.", "You can see a little hole where you can see an Elixir, it seems to be magic, you'll have to investigate"));
	rooms.pushback(new Room("Strange Room", "at the moment that you enter on this room, you get scared, but you don't know why. You only know that you want to scape from there as fast as possible.", "Now this rooms is twice as scaring as before, you don't find anything good by staying here more."));
	rooms.pushback(new Room("Videogames' shop", "You always loved videogames, so this is like your paradise, you can see the shop assistant standing at the back of the shop. ", "The assistant of the shop now seems a giant (well, now he's a real giant for you), You better take care, you don't want he thinking that you're a bug."));
	rooms.pushback(new Room("Secret Room 1", "In the center of the room you can see a sphinx, it seems that want to talk with you.", "Nothing new, except for the key that you now can see under one of the spinx's foot."));
	rooms.pushback(new Room("A Kid's Room", "This place seems like a kid's room, it has a lot of toys. This room also its a bit creepy.", "This place seems a disney film now, you feel like in Toy Story. You also can see a key."));
	rooms.pushback(new Room("Wooden house", "you enter in a wood hause that is exactly like the one of a book that you did read when you were a child.", "A small katana was there all the time, but you couldn't see it. It's better having a weapon in this times."));
	rooms.pushback(new Room("Frozen Lake", "You can see a enormous frozen lake that could kill you if you were inside it in like 5 seconds.You'll prefer to take care with it.", "You can feel yourself freezing for the cold of the ice. You're too small so the ice and the cold has frozen your body. "));
	rooms.pushback(new Room("Beach", "You arrive at the beach, the sun reinforces you, it helps you to recover your forces.", "At the moment you Shrink, you get trapped by the sand and go to a room that was under the sand."));
	rooms.pushback(new Room("Secret Room 2", "In the center of the room you can see a sphinx, it seems that want to talk with you.", "Don't seems to be nothing new here."));
	

	exits.pushback(new Exit("Cave", "You can see a door that enters into darkness.", rooms[1], rooms[0], south, false, true));
	exits.pushback(new Exit("Cave", "You can see a cave.", rooms[2], rooms[0], west, false, true));
	exits.pushback(new Exit("Cave", "The door goes to the cave.", rooms[6], rooms[0], east, false, true));
	exits.pushback(new Exit("Cave", "You can see the entrance of a cave.", rooms[8], rooms[0], north, false, true));
	exits.pushback(new Exit("Garden", "You can see a door at the end. The sun enters through the door.", rooms[0], rooms[1], north, false, true));
	exits.pushback(new Exit("Garden", "at the entrance of the shop you can see a garden.", rooms[4], rooms[1], south, false, true));
	exits.pushback(new Exit("Videogames' Shop", "At the end of the garden you can see a videogames' shop.", rooms[1], rooms[4], north, false, true));
	exits.pushback(new Exit("Videogames' Shop", "The stairs go down to the videogames' Shop.", rooms[5], rooms[4], down, false, true));
	exits.pushback(new Exit("Secret Room 1", "You can see a stairs that go up to the attic.", rooms[4], rooms[5], up, true, false));
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
	exits.pushback(new Exit("Secret Room 2", "There is a trapdoor under your feet.Seems that you can go for there.", rooms[9], rooms[10], down, false, true));

	items.pushback(new Item("shield", "Seems to be a nice shield, it has the triforce simbol on it.", rooms[7],false, false, false));
	items.pushback(new Item("Secret Key", "This key has a triforce grabbed on it", rooms[6], false, true, false));
	items.pushback(new Item("Second Secret Key", "item 3", rooms[5], false, true, false));
	items.pushback(new Item("Book of Miracles", "This book have a name weitten with a pencil     'Ganondorf'.", rooms[3], false, false, false));
	items.pushback(new Item("Cold Spaghetti", "Someone thinks that he's good cooking, but he isn't.", rooms[8], false, false, false));
	items.pushback(new Item("Uchigatana", "This have been appearing in the whole dark souls saga, I love it <3.", rooms[7], false, true, false));
	items.pushback(new Item("Shovel", "An old rusty shovel that belonged to a knight for a long time. ", rooms[1], false, false, false));
	items.pushback(new Item("CD", "It's the CD of Kingdom Hearts 3. All the lovers of that saga would want to have it.", rooms[9], false, false, false));
	items.pushback(new Item("Elixir", "The walls of this temple says that this elixir could make you inmortal. You should keep it safe.", rooms[2], false, true, false));
	

}



/* MOVEMENT FUNCTION */
void World::Movement(int &pos, Vector<String> &commands)
{
	fflush(stdin);

	int i, y; //counters that consider the correct room/exit when you move.

	player->player_pos = rooms[pos];

	if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "north" || commands[1] == "n"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north)
			{
				player->player_pos = exits[i]->dst;
				for (y = 0; y < NUM_ROOMS; y++)
				{
					if (exits[i]->dst == rooms[y])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = y;
							if (player->shrink == false){
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->description.c_str());
								printf("\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
								
									
								}
								return;
								
							}
							else {
								if (player->player_pos == rooms[8]){
									printf("\n\t%s\n%s\n\n", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
									Die();
								}
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
								printf("\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
								}
								return;
							}
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "south" || commands[1] == "s"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south)
			{
				player->player_pos = exits[i]->dst;
				for (y = 0; y < NUM_ROOMS; y++)
				{
					if (exits[i]->dst == rooms[y])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = y;
							if (player->shrink == false){
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->description.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
									
								}	
								return;
							}
							else {
								if (player->player_pos == rooms[0]){
									printf("\n\t%s\n%s\n\n", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
									Die();
								}
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
								}
								return;
							}
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "east" || commands[1] == "e"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east)
			{
				player->player_pos = exits[i]->dst;
				for (y = 0; y < NUM_ROOMS; y++)
				{
					if (exits[i]->dst == rooms[y])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = y;
							if (player->shrink == false){
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->description.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}

								}
								return;
							}
							else {
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
							
								}
								return;
							}
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "west" || commands[1] == "w"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west)
			{
				player->player_pos = exits[i]->dst;
				for (y = 0; y < NUM_ROOMS; y++)
				{
					if (exits[i]->dst == rooms[y])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = y;
							if (player->shrink == false){
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->description.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
									
								}
								return;
							}
							else {
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
									
								}
								return;
							}
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "down" || commands[1] == "d"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down)
			{
				player->player_pos = exits[i]->dst;
				for (y = 0; y < NUM_ROOMS; y++)
				{
					if (exits[i]->dst == rooms[y])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							if (player->shrink == false){
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->description.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
									
								}
								return;
							}
							else {
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
								}
								return;
							}
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "up" || commands[1] == "u"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up && player->shrink == false)
			{
				
				player->player_pos = exits[i]->dst;
				for (y = 0; y < NUM_ROOMS; y++)
				{
					if (exits[i]->dst == rooms[y])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else 
						{
							pos = y;
							if (player->shrink == false){
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->description.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
									
								}
								return;
							}
							else {
								printf("\n\t%s\n%s", rooms[y]->name.c_str(), rooms[y]->ShrinkDesc.c_str());
								printf("\n\nItems you can find here:\n\n");
								for (i = 0; i < NUM_ITEMS; i++)
								{
									if (player->player_pos == items[i]->src && items[i]->picked == false)
									{
										if (player->shrink == items[i]->shrink){
											items[i]->Look();
										}
									}
								}
								return;
							}
						}
					}
				}
			}
		}
		if (player->shrink == true){
			printf("you're to tinny to try to go up. Maybe if you grow up...");
		}
		else{
			printf("\nYou can't move into that way.\n");
		}
	}

	else
	{
		printf("\nThat's not a right direction to go, try with north, south, east or west.\n");
		return;
	}
}

void World::Look(int pos, Vector<String> &commands) const
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
		printf("\nThere's nothing of interest there.\n");  //Case 3: there's no exit placed in the chosen direction
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
		printf("\nThere's nothing of interest there.\n");
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
		printf("\nThere's nothing of interest there.\n");
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
		printf("\nThere's nothing of interest there.\n");
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
		printf("\nThere's nothing of interest there.\n");
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
		printf("\nThere's nothing of interest there.\n");
	}

	else
	{
		if (player->shrink == false){
			rooms[pos]->Look();
		}
		if (player->shrink == true){
			rooms[pos]->LookShrink();
		}
		printf("\n\nItems you can find here:\n");
		for (i = 0; i < NUM_ITEMS; i++)
		{
			if (player->player_pos == items[i]->src && items[i]->picked == false)
			{
				if (player->shrink == items[i]->shrink){
					items[i]->Look();
				}
			}
		}
	}
}

void World::Help() const
{
	printf("The directions that you can use to go are 'north', 'south' 'west', east', 'up' and 'down'\n\nTo move write 'go' and a directions\n\nTo look in a directions write 'look' and a direction\n\nTo open doors write 'open' and a direction\n\n Write 'pick' or 'drop' and an item name to pick/drop it\n\nWrite 'equip' or 'unequip' and the name of the time you want to equip/unequip\n\nWrite 'inventory' to see the items that you have in your inventory\n\nWrite 'shrink' and 'grow' to do it. You can shrink and grow whenever you want, use it to find new objects etc.\n\nWrite 'quit' to exit.");
}



void World::Open(int pos, Vector<String>&commands) const
{
	int i;  
	player->player_pos = rooms[pos];

	if (commands.size() == 2 && (commands[1] == "north" || commands[1] == "n"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "south" || commands[1] == "s"))
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

	else if (commands.size() == 2 && (commands[1] == "east" || commands[1] == "e"))
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

	else if (commands.size() == 2 && (commands[1] == "west" || commands[1] == "w"))
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

	else if (commands.size() == 2 && (commands[1] == "up" || commands[1] == "u"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == rooms[4] && items[1]->picked == true)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
			else if (exits[i]->src == rooms[4] && items[1]->picked == false){
				printf("Seems that you won't open this door without a key.\n");
				return;
			}
			else if (exits[i]->src == player->player_pos && exits[i]->direction == up && exits[i]->open == false && player->player_pos != rooms[4])
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "down" || commands[1] == "d"))
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
	printf("\nSpecify which door you want to open pls.\n");
	return;
	}
}


void World::Close(int pos, Vector<String> &commands) const
{
	int i;
	player->player_pos = rooms[pos];


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


void World::Pick(Vector<String> &commands)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (commands[1] == "Cold" && items[i]->src == player->player_pos && items[i]->picked == false){
			if (player->shrink == items[i]->shrink){
				items[i]->picked = true;
				printf("You picked %s\n", items[i]->name.c_str());
				return;
			}
		}
		else if (commands[1] == "Second" && items[i]->src == player->player_pos && items[i]->picked == false){
			if (player->shrink == items[i]->shrink){
				items[i]->picked = true;
				printf("You picked %s\n", items[i]->name.c_str());
				return;
			}
		}
		else if (commands[1] == "Book" && items[i]->src == player->player_pos && items[i]->picked == false){
			if (player->shrink == items[i]->shrink){
				items[i]->picked = true;
				printf("You picked %s\n", items[i]->name.c_str());
				return;
			}
		}
		else if (commands[1] == "Secret" && items[i]->src == player->player_pos && items[i]->picked == false){
			if (player->shrink == items[i]->shrink){
				items[i]->picked = true;
				printf("You picked %s\n", items[i]->name.c_str());
				return;
			}
		}
		else if (commands.size() == 2 && commands[1] == items[i]->name && items[i]->src == player->player_pos && items[i]->picked == false)
		{
			if (player->shrink == items[i]->shrink){
				items[i]->picked = true;
				player->num_items++;
				printf("You picked %s\n", items[i]->name.c_str());
				return;
			}
		}
	}
	printf("There's any object with that name here.\n");
}


void World::Drop(Vector<String> &commands)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (commands.size() == 2 && items[i]->name == commands[1] && items[i]->picked == true)
		{
			items[i]->picked = false;
			items[i]->src = player->player_pos;
			printf("You droped %s\n", items[i]->name.c_str());
			player->num_items--;
			return;
		}
	}
	printf("There's any object with that name in your inventory.\n");
}

void World::Inventory() const
{
	int i;
	if (player->num_items > 0)
	{
		printf("You have:\n\n");
		for (i = 0; i < NUM_ITEMS; i++)
		{
			if (items[i]->picked == true)
			{
				printf("%s -%s\n", items[i]->name.c_str(), items[i]->description.c_str());
			}
		}
	}
	else
	{
		printf("You don't have items in your inventory\n");
	}
}

void World::Shrink(){
	if (player->shrink == true){
		printf("You're shrinked, you won't shrink more, don't try it.");
	}
	else if (player->player_pos == rooms[8]){
		printf("%s\n", rooms[8]->ShrinkDesc.c_str());
		Die();
	}
	else if (player->player_pos == rooms[9]){
		printf("%s\n", rooms[9]->ShrinkDesc.c_str());
		printf("\n\t%s\n%s", rooms[10]->name.c_str(), rooms[10]->description.c_str());
		player->shrink = true;
	}
	else {
		player->shrink = true;
		printf("You can feel your body and all your pertenances shrinking with you.");
	}
}

void World::Equip(Vector<String> &commands){
	if (player->equiped == true){
		printf("you already have an equiped item. Try to unequip your equiped item first.");
		return;
	}
	else {
		if (commands[1] == "shovel" && items[6]->picked == true) {
			player->equiped = true;
			items[6]->equiped = true;
			printf("You equiped %s", items[6]->name.c_str());
			return;
			}
		else if (commands[1] == "Book" && items[3]->picked == true) {
			player->equiped = true;
			items[3]->equiped = true;
			printf("You equiped %s", items[3]->name.c_str());
			return;
		}
		else if (commands[1] == "Uchigatana" && items[5]->picked == true) {
			player->equiped = true;
			items[5]->equiped = true;
			printf("You equiped %s", items[5]->name.c_str());
			return;
		}
		else if (commands[1] == "CD" && items[7]->picked == true) {
			player->equiped = true;
			items[7]->equiped = true;
			printf("You equiped %s", items[7]->name.c_str());
			return;
		}
		else if (commands[1] == "Cold" && items[4]->picked == true) {
			player->equiped = true;
			items[4]->equiped = true;
			printf("You equiped %s", items[4]->name.c_str());
			return;
		}
		else if (commands[1] == "Secret" && items[1]->picked == true) {
			player->equiped = true;
			items[1]->equiped = true;
			printf("You equiped %s", items[1]->name.c_str());
			return;
		}
		else if (commands[1] == "Second" && items[2]->picked == true) {
			player->equiped = true;
			items[2]->equiped = true;
			printf("You equiped %s", items[2]->name.c_str());
			return;
		}
		else if (commands[1] == "Elixir" && items[8]->picked == true) {
			player->equiped = true;
			items[8]->equiped = true;
			printf("You equiped %s", items[8]->name.c_str());
			return;
		}
		else if (commands[1] == "Shield" && items[0]->picked == true) {
			player->equiped = true;
			items[0]->equiped = true;
			printf("You equiped %s", items[0]->name.c_str());
			return;
		}
	}
}
void World::Grow(){
	if (player->shrink == false){
		printf("don't try to grow more, you have so much to live for.");
	}
	else if (player->player_pos == rooms[9] && player->shrink == true){
		printf("At the moment you start to grow, you get through the sand and go again to the surface o the beach.\n");
		printf("\n\t%s\n%s", rooms[9]->name.c_str(), rooms[9]->description.c_str());
		player->shrink = false;
	}
	else {
		player->shrink = false;
		printf("You start to grow at the same time that your pertenences do");
	}

}
void World::Unequip(Vector<String> &commands){
	if (player->equiped == false){
		printf("you don't have an item equiped.");
		return;
	}
	else {
		if (commands[1] == "shovel" && items[6]->equiped == true) {
			player->equiped = false;
			items[6]->equiped = false;
			printf("You unequiped %s", items[6]->name.c_str());
			return;
		}
		else if (commands[1] == "Book" && items[3]->equiped == true) {
			player->equiped = false;
			items[3]->equiped = false;
			printf("You unequiped %s", items[3]->name.c_str());
			return;
		}
		else if (commands[1] == "Uchigatana" && items[5]->equiped == true) {
			player->equiped = false;
			items[5]->equiped = false;
			printf("You unequiped %s", items[5]->name.c_str());
			return;
		}
		else if (commands[1] == "CD" && items[7]->equiped == true) {
			player->equiped = false;
			items[7]->equiped = false;
			printf("You unequiped %s", items[7]->name.c_str());
			return;
		}
		else if (commands[1] == "Cold" && items[4]->equiped == true) {
			player->equiped = false;
			items[4]->equiped = false;
			printf("You unequiped %s", items[4]->name.c_str());
			return;
		}
		else if (commands[1] == "Secret" && items[1]->equiped == true) {
			player->equiped = false;
			items[1]->equiped = false;
			printf("You unequiped %s", items[1]->name.c_str());
			return;
		}
		else if (commands[1] == "Second" && items[2]->equiped == true) {
			player->equiped = false;
			items[2]->equiped = false;
			printf("You unequiped %s", items[2]->name.c_str());
			return;
		}
		else if (commands[1] == "Elixir" && items[8]->equiped == true) {
			player->equiped = false;
			items[8]->equiped = false;
			printf("You unequiped %s", items[8]->name.c_str());
			return;
		}
		else if (commands[1] == "Shield" && items[0]->equiped == true) {
			player->equiped = false;
			items[0]->equiped = false;
			printf("You unequiped %s", items[0]->name.c_str());
			return;
		}
	}

}
void World::Die() const{
	printf("You died, Try again soon <3.");
	getchar();
	exit(0);
}


World::~World()
{
	delete player;

}


