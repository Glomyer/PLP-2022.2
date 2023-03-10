/*
	Calculadora v.4 - Lê de arquivos ou linha de comando
	Jucimar Jr
*/

%{
#define YYSTYPE double
#include <stdio.h>
#include <math.h>
extern FILE* yyin;

void yyerror(char *s);
int yylex(void);
int yyparse();

double modulo(int a, int b){
	return a%b;
}

%}

%token NUMBER EOL
%token PLUS MINUS DIVIDE TIMES
%token P_LEFT P_RIGHT

%left PLUS MINUS
%left TIMES DIVIDE
%left P_LEFT P_RIGHT

%right EXP
%right MOD
%%

STATEMENT:
	STATEMENT EXPRESSION EOL {$$ = $2; printf("Resultado: %f\n", $2);}
	|
	;

EXPRESSION:
	NUMBER {$$ = $1;}
	|	EXPRESSION PLUS EXPRESSION {$$ = $1 + $3;}
	|	EXPRESSION MINUS EXPRESSION {$$ = $1 - $3;}
	|	EXPRESSION TIMES EXPRESSION {$$ = $1 * $3;}
	|	EXPRESSION DIVIDE EXPRESSION {$$ = $1 / $3;}
	| EXPRESSION EXP EXPRESSION {$$=pow($1,$3);}
	| EXPRESSION MOD EXPRESSION { $$ = modulo($1, $3); }
	|	P_LEFT EXPRESSION P_RIGHT {$$ = $2;}
	;


%%

void yyerror(char *s)
{
	printf("Error: %s\n", s);
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
