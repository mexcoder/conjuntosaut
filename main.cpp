#include <iostream>
#include "automata.h"
#include "token.h"

using namespace std;


automata aut;

extern "C" void Token(enum token);
extern "C" int yylex();

int main(void){
	
	cout<<"esperando instrucciones"<<endl;
	yylex();

}

extern "C" void Token(enum token t){

	cout<<t<<endl;
	return;
	
	int res = aut.walk(t);
	if( t == T_EOL){
		cout<<"ejecutar instruccion";
		refreshTokens();
	}
	
	if( t == T_ID)
		storeToken(yytext);

}