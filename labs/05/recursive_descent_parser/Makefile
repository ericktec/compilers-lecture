
all:
	yacc -d recursive_parser_tree.y
	lex recursive_parser_tree.l
	gcc y.tab.c lex.yy.c -o recursive_parser_tree

clean:
	rm -rf recursive_parser_tree
	rm -rf lex.yy.c
	rm -rf y.tab.c
	rm -rf y.tab.h
	rm -rf y.tab.h.gch