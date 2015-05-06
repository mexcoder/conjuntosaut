#include "funiones.h"
#include "conjuntos.h"
#include <vector>;

vector<string> tokenList;

void refreshTokens(){

    tokenList.clear();

}

void storeToken(char * t){

    tokenList.push_back(t);

}


extern "C" void new_Item(char *it){
    
    name = string(it);
    
    item = new vector<string>();
    
}

extern "C" void addItem(char *it){
    
    item->push_back(string(it));
    
}

extern "C" void commitSet(){
    
    c.addItem(name,item);
    
}


void errors(){//error de sintanxis
    cout<<"error de sintaxis en el comando"<<endl;
    
}

void error(){
	cout<<"Comando desconocido: \"" << yytext << "\"";
}

extern "C" void exitProgram(){
	cout<<"saliendo del programa"<<endl;
	exit(0);
}

void sets(){
    
    
    vector<string> a = c.getSetNames();
    
    for(auto str : a){
        cout<<str<<", ";
    }
    cout<<endl;
    
}

extern "C" void PrepareTokens(){
    
    tokenList.c1 = "";
    tokenList.c2 = "";
    tokenList.c3 = "";
    
}

extern "C" void addToken(char *token){
    
    string t = string(token);
    
    if(tokenList.c1 == ""){
        tokenList.c1 = t;
    }
    else if(tokenList.c2 == ""){
        tokenList.c2 = t;
    }
    else{
        tokenList.c3 = t;
    }

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
        cout<<" }"<<endl;
        
    }
    
}

void printset(string tittle,vector <string> source){

    cout<<tittle<<" = { ";
    
    for(int x=0;x<source.size();x++){
        
        cout<<source[x];
        
        if(x<(source.size()-1))//pretty print
            cout<<", ";
    }
    
    cout<<" }"<<endl;
    
}

extern "C" void runIns(tipoIns ins){
    
    vector<string> res;
    
    if(tokenList.c1 == "" || tokenList.c2 == ""){
        cout<<"faltan argumentos";
        return;
    }
    if( ( ins == setUNION || ins == setINTERSEC ) && tokenList.c3 == ""){
        cout<<"faltan argumentos";
        return;
    }
    
    
    switch (ins) {
            
        case UNION:
            res = c.Union(tokenList.c1,tokenList.c2);
            break;
        case INTERSEC:
            res = c.intersection(tokenList.c1,tokenList.c2);
            break;
            

        case setINTERSEC:
            res = c.setIntersection(tokenList.c1,tokenList.c2,tokenList.c3);
            break;
        case setUNION:
            res = c.setUnion(tokenList.c1,tokenList.c2,tokenList.c3);
            break;

    }
    
    printset("resultado",res);
}