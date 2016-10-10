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
  
main()
{
        yyparse();
} 

%}

%token PLUS MINUS ARROW SEMICOLON PARTICLE

%%
reaction:
	PARTICLE PLUS PARTICLE ARROW PARTICLE PLUS PARTICLE SEMICOLON
	{
		printf("Reaction\n");
	}
	;
%%
