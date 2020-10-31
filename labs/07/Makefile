
all:
	lex recursive_parser_tree.l
	yacc -d semantic_analyzer.y
	gcc y.tab.c lex.yy.c -o lexic_analyzer
	./lexic_analyzer input.txt

clean:
	rm -rf lexic_analyzer
	rm -rf lex.yy.c
	rm -rf y.tab.c
	rm -rf y.tab.h
	rm -rf y.tab.h.gch