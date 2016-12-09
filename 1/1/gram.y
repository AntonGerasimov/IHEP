%{

#include <stdio.h>
#include <string.h>
#include "./lib.h"
#define YYSTYPE char*
void yyerror(const char *str)
{
        fprintf(stderr,"ошибка: %s\n",str);
}
 
//int yywrap()
//{
//        return 1;
//} 
   

%}
%union {int num; char *abbr;}         /* Yacc definitions */
%start reaction
%token SEMICOLON 
%token PARTICLE

%%
reaction: 	particle SEMICOLON 
		{
			printf("New particle");
		}
		| reaction reaction		
		;
particle:	PARTICLE
		{
			printf("%s\n", $1);
//			$$= symbolVal($1);
		}
		;	
%%
int main(){
	Particle a;
	return yyparse();
}
