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
reactions: 	reaction
		| reactions reaction
		;
reaction: 	particles ARROW particles SEMICOLON
		{
			printf("Reaction\n");
		}
		;
particles: 	particle
		| particles WHITESPACE particle 
		;
particle: 	PARTICLE state 	
		{
		printf("I found a patricle with state\n");
		}
		|
		PARTICLE	
		{
		printf("Ifound a particle without state\n");
		}
		;
state		: PLUS | MINUS 
		;
%%

//
//
//     Each abbreviation has a number -  OR-code,  which  serve  to
//  order  names  in final state, in this number, following numbers
//  are packed from left to right: NB, NS, NM, II, NP, NC.
//
//   NB (2 FIGURES)= B+10  for mesons and baryons with /B/ <=4; B -
//                         baryon number
//                 = 2     for abbreviations from classes 7) and 9)
//                 = 4     for abbreviations from class 6
//                 = 6     for PHOTON
//                 = 8     for LEPTONS
//                 = 16    for heavy nuclei with /B/>4
//                 = 18    for abbreviations DD, NON-RES
//  NS (1 FIGURE ) = 3+/S/ for mesons, where S-strangeness
//                 = 7-/S/ for baryons except Z*
//                 = 2     for Z*
//                 = 6     for charmed mesons
//                 = 7    for beauty mesons,
//                 = 8    for charmed baryons.
//                 = 9     for beauty baryons.
//  NM (4 FIGURES) = 9000-M for baryons with /b/<=4, where M - mass
//                   in MeV.
//                 = 1000+M for mesons
//                 = 1000+10*/B/+5 for nuclei with /B/>4.
//                 = 1000+10*/B/+5+N for isotopes where -5<=N<=4
//  NI (1 FIGURE ) = 2*I+3, where I - isotopic spin
//  NP (1 FIGURE ) = 7 for particles, 3 for  antiparticles,  6  for
//                   KS, 4 for KL.
//
//  NC (1 FIGURE ) = C+5, where  C  -  charge.  For  heavy  nucleus
//                   (NB=16) NI, NP, NC contain charge of nuclei.
