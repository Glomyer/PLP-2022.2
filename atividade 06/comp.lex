%{
/*1) Usando o seus conhecimentos em Flex e o material em anexo, crie um scanner que analise o seguinte código:*/
#define TRUE 1
#define FALSE 0

int line_number = 1;
void output(char* message, char* yytext, int line_break){
	printf("%d: ", line_number);
	
	if(line_break){
		// doesn't print the \n character in the message, only after it
		// increments the line number
		printf("%s: \"\\n\"", message);
		line_number++;
		printf("\n");
	}
	else {
		printf("%s: \"%s\"", message, yytext);
	}
	printf("\n");
}

%}
TIPO						(char|short|long|int|float|double)
DIGITO					[0-9]
NUMERO					[0-9]+(\.[0-9])
IDENTIFICADOR		[a-zA-Z][a-zA-z0-9]*
PALAVRA					[a-zA-Z]+
TAB							[\t]
LINHA						[\n]
%%
{LINHA}					output("Voce inseriu uma quebra de linha", "", TRUE);
{TIPO} 					output("Voce escreveu um tipo de dado", yytext, FALSE);
{DIGITO} 				output("Voce escreveu um digito", yytext, FALSE);
{IDENTIFICADOR}	output("Voce escreveu um identificador", yytext, FALSE);
{PALAVRA} 			output("Voce escreveu uma palavra", yytext, FALSE);
{TAB}						output("Voce inseriu um caracter de tabulacao","\\t", FALSE);
{NUMERO}				output("Voce escreveu um numero", yytext, FALSE);
" "							output("Voce escreveu um espaço em branco", yytext, FALSE);
";"							output("Voce escreveu um ponto-e-virgula", yytext, FALSE);
"="							output("Voce escreveu o operador de atribuicao", yytext, FALSE);
"+"							output("Voce escreveu o operador de adicao", yytext, FALSE);
"-"							output("Voce escreveu o operador de subtracao", yytext, FALSE);
"*"							output("Voce escreveu o operador de multiplicacao", yytext, FALSE);
"/"							output("Voce escreveu o operador de divisao", yytext, FALSE);
.      					output("Nao reconhecido", yytext, FALSE);
%%
int main(int argc, char* argv[])
{
	if(argc > 2)
	{
		printf("Missing input file\n");
		exit(-1);
	}
	yyin = fopen(argv[1], "r");
	yylex();
}
