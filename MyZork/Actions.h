#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action { Move, Look, Open, Close, Pick, Drop, Help, Quit, Invalid_command, Inventory, Shrink, Equip, Grow, Unequip };
int GetCommand(Vector<MyString>&);

#endif