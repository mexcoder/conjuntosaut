#include "automata.h"
#include "funciones.h"
#include "token.h"
#include <iostream>

using namespace std;

extern bool debug;

int trans[][43] = {
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 20,2 ,4 ,3 ,6 ,10,14,28,27,27,27,27,27,27,34,38, (int) error },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) showsets },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) sets },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) showset },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) doUnion },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,12,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) doIntersect },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,16,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,17,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,18,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,19,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) setUnion },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,21,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,23,0 ,0 ,44,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,25,0 ,24,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,26,0 ,25,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) set },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,24,0 ,0 ,0 , (int) errors },
	{ 27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27, (int) error},
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,29,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,30,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,31,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,32,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,33,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) setIntersect },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,35,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,36,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,37,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) doResta },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,39,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,40,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,41,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,42,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,43,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) setResta},
	{ 0 ,0 ,0 ,0 ,47,46,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,45,0 , (int) errors},
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,43,0 ,0 ,0 , (int) errors},
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,33,0 ,0 ,0 , (int) errors},
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,19,0 ,0 ,0 , (int) errors},
};



int automata::walk(int instruction){

	if(debug)
		cout<<"recv inst "<<instruction<<" : " << this->currentIndex << " -> ";

	//incomplete, will return latter
	this->currentIndex = trans[this->currentIndex][instruction];

	if(debug)
		cout<<this->currentIndex << endl;

	if(instruction == T_EOL){
		if(debug)
			cout<<"execute instruction at 0x"<<this->currentIndex<<endl;

		( ( void (*) (void) ) this->currentIndex ) ();
		this->currentIndex = 1;
		refreshTokens();
	}


	return this->currentIndex;
}