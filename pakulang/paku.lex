
%{
#define YYSTYPE double
#include "paku.tab.h" 
#include <stdlib.h>

void yyerror(char *s); 
%}

TIPO						(char|short|long|int|float|double)
DIGITO					[0-9]
NUMERO					[0-9]+(\.[0-9])
IDENTIFICADOR		[a-zA-Z][a-zA-z0-9]*
PALAVRA					[a-zA-Z]+
TAB							[\t]
LINHA						[\n]

%%
[0-9]+("."[0-9]+)? 	{ yylval = atof(yytext); return NUMBER; }
[\n]								{ return EOL; }
[+]									{ return PLUS; }
[-]									{ return MINUS; }
[/]									{ return DIVIDE; }
[*]									{ return TIMES; }
[\^]								{ return EXP; }
[%]									{ return MOD; }
[(]									{ return P_LEFT;}
[)]									{ return P_RIGHT;}
"print"							{ return PRINT;}
[[:space:]]					;
.										{ yyerror("Undefined token\n"); }

%%

int yywrap()
{
	return 1;
}
