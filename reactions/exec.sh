#!/bin/bash
yacc -d gram.y
lex lex.l 
gcc lex.yy.c y.tab.c -o do
./do
