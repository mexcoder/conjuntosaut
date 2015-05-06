#include "automata.h"
#include "funciones.h"
#include "token.h"

int trans[][26] = {
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) error },
{20,2 ,4 ,3 ,6 ,10,14,14,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) error },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) sets },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) showsets },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) showset },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) doUnion },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,12,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) doIntersect },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,21,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,23,0 ,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,25,0 ,24,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,26,0 ,25,0 ,0 ,0 , (int) (void (*) (void) ) errors },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) (void (*) (void) ) set },
{0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,24,0 , (int) (void (*) (void) ) errors }
};


int automata::walk(int instruction){

	//incomplete, will return latter
	int i = this->currentIndex = trans[currentIndex][instruction];

	if(instruction == T_EOL)
		this->currentIndex = 1;

	return i;
}