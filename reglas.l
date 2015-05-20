%option noyywrap
%option case-insensitive

%s saveToken
	#include "token.h"
	#include "funciones.h"

	void Token(enum token,char*);

%%

^exit|end|close|bye exitProgram();
DEBUG Token(T_DEBUG,yytext);

SET Token(T_SET,yytext);
SETS Token(T_SETS,yytext);
SHOWSET Token(T_SHOW_SET,yytext);
SHOWSETS Token(T_SHOW_SETS,yytext);
UNION Token(T_UNION,yytext);
SETUNION Token(T_SET_UNION,yytext);
INTERSECT Token(T_INTERSECT,yytext);
SETINTERSECT Token(T_SET_INTERSECT,yytext);
RESTA Token(T_RESTA,yytext);
SETRESTA Token(T_SET_RESTA,yytext);


, Token(T_COMA,yytext);
\{ Token(T_LBR,yytext);
\} Token(T_RBR,yytext);
:= Token(T_ASIGN,yytext);
[[:blank:]] ;//just consume the character
[[:alnum:]_]+ Token(T_TOKEN,yytext);
;?\n? Token(T_EOL,yytext);

. ;

