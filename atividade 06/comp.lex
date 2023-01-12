%{
/*1) Usando o seus conhecimentos em Flex e o material em anexo, crie um scanner que analise o seguinte código:*/
int line_number = 1;
%}
TIPO						(char|short|long|int|float|double)
DIGITO					[0-9]
NUMERO					[0-9]+(\.[0-9])
IDENTIFICADOR		[a-zA-Z][a-zA-z0-9]+
PALAVRA					[a-zA-Z]+
TAB							[\t]
LINHA						[\n]
%%
{LINHA}					printf("%d Voce inseriu uma quebra de linha: \"\\n\" \n\n", line_number++);
{TIPO} 					printf("Voce escreveu um tipo de dado: \"%s\"\n", yytext);
{DIGITO} 				printf("Voce escreveu um digito: \"%s\"\n", yytext);
{IDENTIFICADOR}	printf("Voce escreveu um identificador: \"%s\"\n", yytext);
{PALAVRA} 			printf("Voce escreveu uma palavra: \"%s\"\n", yytext);
{TAB}						printf("Voce inseriu um caracter de tabulacao: \"\\t\"\n");
{NUMERO}				printf("Voce escreveu um numero: \"%s\"\n", yytext);
" "							printf("Voce escreveu um espaço em branco: \"%s\"\n", yytext);
";"							printf("Voce escreveu um ponto-e-virgula: \"%s\"\n", yytext);
"="							printf("Voce escreveu o operador de atribuicao: \"%s\"\n", yytext);
"+"							printf("Voce escreveu o operador de adicao: \"%s\"\n", yytext);
.      					printf("Nao reconhecido:  \"%s\"\n", yytext);
%%
int main(int argc, char* argv[])
{
	if(argc > 2)
	{
		printf("Missing input file\n");exit(-1);
	}
	yyin = fopen(argv[1], "r");
	yylex();
}
