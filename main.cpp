#include <iostream>
#include "automata.h"
#include "token.h"
#include "funciones.h"

using namespace std;


automata aut;

extern "C" void Token(enum token,char* );
extern "C" int yylex();


void test(void);
void demoSet();

int main(void){
	demoSet();
	cout<<"esperando instrucciones"<<endl;
	yylex();

}

void demoSet(){

	storeToken("a");
	storeToken("a");
	storeToken("b");
	storeToken("c");
	set();
	refreshTokens();
	storeToken("b");
	storeToken("a");
	storeToken("b");
	storeToken("f");
	set();
	refreshTokens();

}

void test(void){

	cout<< "testing set:"<<endl;
	demoSet();
	showsets();
	storeToken("a");
	storeToken("b");
	storeToken("c");
	cout<< "testing showset:"<<endl;
	showset();
	cout<< "testing operations:"<<endl;
	doUnion();
	doIntersect();
	cout<< "testing set_operations:"<<endl;
	setUnion();
	showsets();
	setIntersect();
	showsets();
}


extern "C" void Token(enum token t,char* text){

	cout<<t<<"  ->  "<<text<<endl;

	if( t == T_TOKEN){

	 	storeToken(text);

	 }

	
	int res = aut.walk(t);
	
	return;

}