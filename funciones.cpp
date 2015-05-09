#include <iostream>
#include "funciones.h"
#include "conjuntos.h"
#include <vector>
#include <string>
#include "tipoIns.h"
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<string> tokenList;
conjuntos c;
extern "C" char *yytext;

/******unexposed********/
void printset(string tittle,vector <string> source){

    cout<<tittle<<" = { ";
    
    for(int x=0;x<source.size();x++){
        
        cout<<source[x];
        
        if(x<(source.size()-1))//pretty print
            cout<<", ";
    }
    
    cout<<" }"<<endl;
    
}

//ugly piece of shit
void runIns(tipoIns ins){
    
    vector<string> res;
    
    if(tokenList.size() < 2){
        cout<<"faltan argumentos"<<endl;
        return;
    }
    if( ( ins == setUNION || ins == setINTERSEC ) && tokenList.size() < 3){
        cout<<"faltan argumentos"<<endl;
        return;
    }
    
    
    switch (ins) {
            
        case UNION:
            res = c.Union(tokenList[0],tokenList[1]);
            break;
        case INTERSEC:
            res = c.intersection(tokenList[0],tokenList[1]);
            break;
            

        case setINTERSEC:
            res = c.setIntersection(tokenList[2],tokenList[1],tokenList[0]);
            break;
        case setUNION:
            res = c.setUnion(tokenList[2],tokenList[0],tokenList[0]);
            break;

        case RESTA:
            res = c.resta(tokenList[0],tokenList[1]);
            break;
        case setRESTA:
            res = c.setResta(tokenList[1],tokenList[2],tokenList[0]);
            break;

    }
    
    printset("resultado",res);
}

/**********exposed**********/


void error(){

    cout<<"Comando desconocido"<<endl;//: \"" << "cmd to be added" << "\"";

}

void errors(){//error de sintanxis

    cout<<"error de sintaxis en el comando"<<endl;
    
}

void sets(){
    
    
    vector<string> a = c.getSetNames();
    
    for(auto str : a){
        cout<<str<<", ";
    }
    cout<<endl;
    
}

void showsets(){

    auto map = c.getSets();
    auto keys = c.getSetNames();
    
    for(auto key : keys){
        
        cout<<key<<" = { ";
        for(int x=0;x<map[key].size();x++){
            cout<<map[key][x];
            
            if(x<(map[key].size()-1))//pretty print
                cout<<", ";
        }
        cout<<" }" << endl;
        
    }
    
}

void refreshTokens(){

    tokenList.clear();

}

void storeToken(char * t){

    tokenList.push_back(t);

}

void doUnion(){

    runIns(UNION);

}

void doResta(){

    runIns(RESTA);

}

void setResta(){

    runIns(setRESTA);

}

void doIntersect(){

    runIns(INTERSEC);

}

void setUnion(){

    runIns(setUNION);

}
void setIntersect(){

    runIns(setINTERSEC);

}

void set(){

    //reverse so we can use back and pop_back
    reverse(tokenList.begin(),tokenList.end());
    //extract the name of the set
    string name = tokenList.back();
    //pop it out of the list
    tokenList.pop_back();
    c.addItem(name,tokenList);

}

void showset(){

    printset(tokenList[0],c.getSet(tokenList[0]));

}


extern "C" void exitProgram(){
	cout<<"saliendo del programa"<<endl;
	exit(0);
}