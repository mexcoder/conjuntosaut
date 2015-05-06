#include "automata.h"
#include "funciones.h"
#include "token.h"

#include <iostream>
using namespace std;


int trans[][26] = {
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) &error },
	{ 20,2 ,4 ,3 ,6 ,10,14,14,0 ,0 ,0 ,0 ,0 ,0 , (int) error },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) sets },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) showsets },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) showset },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,9 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) doUnion },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,11,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,12,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) doIntersect },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,21,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,22,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,23,0 ,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,25,0 ,24,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,26,0 ,25,0 ,0 ,0 , (int) errors },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 , (int) set },
	{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,24,0 , (int) error  }
};



int automata::walk(int instruction){
	cout<<"recv inst "<<instruction<<" : " << this->currentIndex << " -> ";

	//incomplete, will return latter
	this->currentIndex = trans[this->currentIndex][instruction];
	
	cout<<this->currentIndex << endl;

	if(instruction == T_EOL){
		cout<<"execute instruction at 0x"<<this->currentIndex<<"("<<(int) (  errors )<<")"<<endl;
		( ( void (*) (void) ) this->currentIndex ) ();
		this->currentIndex = 1;
		refreshTokens();
	}


	return this->currentIndex;
}