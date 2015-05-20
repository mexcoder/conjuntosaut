#include <iostream>
#include <cstdio>
#include "automata.h"
#include "token.h"
#include "funciones.h"

#pragma clang diagnostic ignored "-Wc++11-compat-deprecated-writable-strings"
using namespace std;


automata aut;

extern "C" void Token(enum token,char* );
extern "C" int yylex();
extern "C" FILE * yyin;

bool debug = false;
bool ignore = false;

void test(void);
void demoSet();

int main(int argc, char *argv[]){

	if(argc == 1){ //sin parametros
		demoSet();
		showsets();
		cout<<"esperando instrucciones"<<endl;
		
	}
	else{//el primer parametro deberia ser el archivo

		yyin = fopen(argv[1],"r");

		if(yyin == NULL)
		{
			cout<<"error al leer el archivo";
			return -1;
		}

		cout<<"leyendo instrucciones del archivo \""<<argv[1]<<"\""<<endl;
	}
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

	if(debug == true)
		cout<<t<<"  ->  "<<text<<endl;

	if(ignore && t == T_EOL){
		ignore = false;
		return;
	}

	if(ignore)
		return;

	if(t == T_DEBUG){

		debug = !debug; //toggle
		ignore =true; //ignore the rest of the line 

		cout << (debug ? "debug mode eneabled" : "debug mode disabled");
		cout << endl;

		return;

	}

	if( t == T_TOKEN){

	 	storeToken(text);

	 }

	
	int res = aut.walk(t);
	
	return;

}