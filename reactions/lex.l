%{
#include <stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
%}

%%
"+"	return PLUS;
"-"	return MINUS;
"-->"	return ARROW;
";"	return SEMICOLON;
[a-z]	return PARTICLE;
%%
