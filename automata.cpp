#include "automata.h"
#include "funciones.h"

int trans[][26] = {{0}}; /*{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*error)(void)},
{20,2,4,3,6,10,14,14,0,0,0,0,0,0,void (*error)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*sets)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*showsets)(void)},
{0,0,0,0,0,0,0,0,0,0,5,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,ACTSHOWSET},
{0,0,0,0,0,0,0,0,0,0,7,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,8,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,9,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,ACTUNION},
{0,0,0,0,0,0,0,0,0,0,0,0,11,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,12,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,13,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,ACTINTERSECT},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,21,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,22,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,23,0,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,25,0,24,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,26,0,25,0,0,0,void (*errors)(void)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,ACTSET},
{0,0,0,0,0,0,0,0,0,0,0,0,24,0,void (*errors)(void)}}*/


int automata::walk(int instruction){

	//incomplete, will return latter
	int i = this->currentIndex = trans[currentIndex][instruction];

	if(instruction == T_EOL)
		this->currentIndex = 1;

	return i;
}