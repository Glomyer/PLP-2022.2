calc: paku.y paku.lex
	bison -d paku.y
	flex -o paku.lex.c paku.lex
	gcc -o main paku.lex.c paku.tab.c -ll -lm 

clean:
	rm -f *.c *.h main
