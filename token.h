/**
* Enum que contiene el nombre de los tokens que seran reconocidos
* por flex y que seran pasados al automata
**/

enum token{
	T_SET, 			//0
	T_SHOW_SETS,	//1
	T_SHOW_SET,		//2	
	T_SETS,			//3
	T_UNION,		//4	
	T_INTERSECT,	//5	
	T_SET_UNION,	//6
	T_SET_INTERSECT,//7		
	T_COMA,			//8
	T_LBR,			//9
	T_RBR,			//10
	T_ASIGN,		//11
	T_TOKEN,		//12
	T_STRING,		//13
	T_RESTA,		//14
	T_SET_RESTA,	//15
	T_EOL,			//16
	T_WHITESPACE,	//17	
	T_DEBUG			//18
};