%{
#define YYSTYPE double
#include <stdio.h>
#include <math.h>
extern FILE* yyin;

void yyerror(char *s);
int yylex(void);
int yyparse();
%}

%token NUMBER EOL
%token PLUS MINUS DIVIDE TIMES
%token P_LEFT P_RIGHT
%token PRINT

%left PLUS MINUS
%left TIMES DIVIDE
%left P_LEFT P_RIGHT

%right EXP
%right MOD
%%

STATEMENT:
	STATEMENT EXPRESSION EOL {$$ = $2; printf("Resultado: %f\n", $2);}
	| PRINT_STATEMENT EOL
	;

PRINT_STATEMENT:
	| PRINT {printf("print executado\n");}
	;

EXPRESSION:
	NUMBER {$$ = $1;}
	|	EXPRESSION PLUS EXPRESSION {$$ = $1 + $3;}
	|	EXPRESSION MINUS EXPRESSION {$$ = $1 - $3;}
	|	EXPRESSION TIMES EXPRESSION {$$ = $1 * $3;}
	|	EXPRESSION DIVIDE EXPRESSION {$$ = $1 / $3;}
	| EXPRESSION EXP EXPRESSION {$$ = pow($1,$3);}
	| EXPRESSION MOD EXPRESSION { $$ = fmod($1, $3);}
	|	P_LEFT EXPRESSION P_RIGHT {$$ = $2;}
	|	PRINT P_LEFT EXPRESSION P_RIGHT {$$ = $2;}
	;


%%

void yyerror(char *s)
{
	printf("Error: %s\n", s);
	yyparse();
}

int main(int argc, char *argv[])
{
	if (argc == 1)
    {
		yyparse();
    }

	if (argc == 2)
	{
    	yyin = fopen(argv[1], "r");
		yyparse();
    }

	return 0;
}
