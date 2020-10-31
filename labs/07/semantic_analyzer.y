%{
#include <stdio.h>
#include <stdlib.h>

%}

%union {
int integer;
float floatNumber;
char id;
}

%token ASSIGN
%token FLOATDCL INTDCL PRINT ID
%token PLUS MINUS INUM FNUM DIVISION MULTIPLICATION
%left MULTIPLICATION DIVISION
%type <floatNumber>FNUM
%type <id>ID
%type <integer>INUM

%left PLUS MINUS



%%

list: /*empty */
        |
      list stat
      {printf("List -> {List, Stat}\n");}
        

stat:   
        ID ASSIGN expr {printf("Stat -> {%c, \"=\", Expr}\n", $1);}
        |
        INTDCL ID {printf("Stat -> {INTDCL, %c}\n", $2);}
        |
        
        FLOATDCL ID {printf("Stat -> {FLOATDCL, %c}\n",$2);}
        |
        PRINT ID {printf("Stat -> {Print, %c}\n", $2);}
        ;
expr:    '(' expr ')'
        |
        expr MULTIPLICATION expr {printf("Expr -> {Expr, \"*\" Expr}\n");}
        |
        expr DIVISION expr {printf("Expr -> {Expr, \"/\" Expr}\n");}
        |       
        expr PLUS expr {printf("Expr -> {Expr, \"+\" Expr}\n");}
        |
        expr MINUS expr {printf("Expr -> {Expr, \"-\" Expr}\n");}
        |
        ID {printf("Expr -> {%c}\n", $1)}
        |
        number {printf("Expr -> {Number}\n");}
        ;
        
number: INUM{printf("Number -> {%d}\n", $1);}
        |
        FNUM{printf("Number -> {%f}\n", $1);}
          ;

%%

extern int yylex();
extern int yyparse();
extern FILE *yyin;

int main(int argc, char** argv) {
  if(argc != 2)
  {
    printf("Ups! Wrong input");
    return 1;
  }
	// open a file handle to a particular file:
	FILE *myfile = fopen(argv[1], "r");
	// make sure it is valid:
	if (!myfile) {
		printf("Error wrong file");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
  /* digraph D {

  A -> {B, C, D} -> {F}

} */

  printf("digraph D {\n");
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));

  printf("}\n");

  printf("Success parssing\n");

}

void yyerror(char *s) {
	printf("Error %s\n", s);
	// might as well halt now:
	exit(-1);
}


yywrap(){
  return(1);
}