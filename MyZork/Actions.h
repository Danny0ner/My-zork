#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action { Move, Look, Open, Close, Pick, Drop, Help, Quit,Inventory, Shrink, Equip, Grow, Unequip, Invalid_command };
int GetCommand(Vector<String>&);
#endif