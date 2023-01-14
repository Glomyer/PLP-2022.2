flex -o comp.lex.c comp.lex
gcc -o main comp.lex.c -ll
./main codigo.txt