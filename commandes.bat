bison -d ChakibAmmarBoudjelal.y
flex ChakibAmmarBoudjelal.l
gcc ChakibAmmarBoudjelal.tab.c lex.yy.c -lfl -ly -o c