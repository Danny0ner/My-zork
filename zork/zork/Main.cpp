#include"world.h"
#include <stdio.h>
#include <string.h>

int main()
{
	World map;
	map.CreateWorld();
	map.CreateExits();
	printf("\t\tWelcome to my zork!!!\n\n");
	printf("Press help anytime you want to see the commands. Enjoy!!\n\n");
	printf("\t%s\n", map.rooms[0].name);
	printf("\n%s\n", map.rooms[0].description);

	while (1){
		map.Command();
	}

	getchar();
	return 0;
}