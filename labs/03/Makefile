all:
	python3 code_generator.py --stress
	lex lexic_analyzer.l
	gcc lex.yy.c -o lexical_scan -lfl
	./lexical_scan random_code.ac


clean:
	rm -rf lexical_scan
	rm -rf random_code.ac
	rm -rf lex.out
	rm -rf lex.yy.c
