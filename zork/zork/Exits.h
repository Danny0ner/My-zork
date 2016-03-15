enum directions {north, south, west, east};

class Exit
{
public:
	char name[20];
	char description[200];
	directions direction;
	Room* origen;
	Room* destination;

};