#include <iostream>
#include "automata.h"
#include "token.h"
#include "funciones.h"

using namespace std;


automata aut;

extern "C" void Token(enum token,char* );
extern "C" int yylex();

int main(void){
	
	cout<<"esperando instrucciones"<<endl;
	yylex();

}

extern "C" void Token(enum token t,char* text){

	cout<<t<<"  ->  "<<text<<endl;

	if( t == T_TOKEN)
	 	cout << "storing token"<<endl;//storeToken(text);

	if( t == T_EOL){
	 	cout<<"ejecutar instruccion"<<endl;
	 	refreshTokens();
	}

	return;
	
	int res = aut.walk(t);
	
	

}