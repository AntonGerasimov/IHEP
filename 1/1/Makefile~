exe: lex.yy.c y.tab.c
	cc -o $@ $^

y.tab.c y.tab.h: gram.y
	yacc -d $<

lex.yy.c: lex.l
	lex $<

clean: 
	rm -f lex.yy.c y.tab.[ch] *~ exe *.o
