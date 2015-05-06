%s saveToken
	#include "token.h"
	#include "funciones.h"

	void Token(enum token);
	//void saveToken(char*);

%%

SET Token(T_SET);
SETS Token(T_SETS);
SHOWSET Token(T_SHOW_SET);
SHOWSETS Token(T_SHOW_SETS);
UNION Token(T_UNION);
SETUNION Token(T_SET_UNION);
INTERSECT Token(T_INTERSECT);
SETINTERSECT Token(T_SET_INTERSECT);
, Token(T_COMA);
\{ Token(T_LBR);
\} Token(T_RBR);
:= Token(T_ASIGN);
[[:blank:]] ;//just consume the character
[[:alpha:]_] Token(T_TOKEN);//<saveToken>[[:alpha:]] saveToken(yytext);
;?$ Token(T_EOL);

^exit|end|close|bye exitProgram();

. Token(T_STRING);

