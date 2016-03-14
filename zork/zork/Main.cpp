#include"world.h"
#include <stdio.h>
#include <string.h>

int main()
{
	World map;
	map.CreateWorld();
	printf("Welcome to my zork!!!\n\n");
	printf("Move Commands: 'go north' or 'go n'  'go south' or 'go s'  'go west' or go w'  'go east' or 'go e'\nLook Commands: 'look'  'look north'  'look south'  'look west' 'look east'\nEnter 'quit' to exit.\n\n");
	printf("%s", map.rooms[0].name);
	

	getchar();
	return 0;
}