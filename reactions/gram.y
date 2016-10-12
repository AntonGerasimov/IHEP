%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *str)
{
        fprintf(stderr,"ошибка: %s\n",str);
}
 
int yywrap()
{
        return 1;
} 
  
int main()
{
        yyparse();
} 

%}

%token PLUS MINUS ARROW SEMICOLON PARTICLE WHITESPACE

%%
reactions	: reaction
		| reactions reaction
		;
reaction	: particles ARROW particles SEMICOLON
		{
			printf("Reaction\n");
		}
		;
particles	: particle WHITESPACE
		| particles particle 
		;
particle	: PARTICLE state 	
		{
		printf("I found a patricle\n");
		}	
		;
state		: PLUS | MINUS | WHITESPACE
		;
%%
