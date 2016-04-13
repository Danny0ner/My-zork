#include"world.h"
#include <stdio.h>
#include <string.h>

int main()
{
	World map;
	map.CreateWorld();
	map.CreateExits();
	printf("\t\t\tWelcome to my zork!!!\n\n");
	printf("Press help anytime you want to see the commands. Enjoy!!<3<3\n\n");
	while (1){
		map.Command();
	}

	getchar();
	return 0;
}