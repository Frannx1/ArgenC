include Makefile.inc

COMPILER := argenCC
PARSER := parser.y
SCANNER := scanner.l

all:
	$(YACC) $(YACCFLAGS) $(PARSER)
	$(LEX) $(SCANNER)
	$(CC) $(CCFLAGS) y.tab.c lex.yy.c tree.c -o $(COMPILER).out
	chmod 777 ./ejemplos/exampleRunner.sh

clean:
	rm $(COMPILER).out
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	cd ejemplos; make clean

.PHONY: clean  all 