%{
#include <stdio.h>
#include "y.tab.h"
//extern YYSTYPE yylval;
%}

%%
\;		return SEMICOLON;
[a-z][a-z]*	{yylval.abbr = strdup(yytext);return PARTICLE;}
%%
