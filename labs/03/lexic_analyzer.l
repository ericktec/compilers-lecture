%{
#include <stdio.h>  
%}

/* Regula expressions */
id [a-e]|[g-h]|[j-o]|[q-z]
inum [0-9]+
fnum [0-9]+.[0-9]+
comments \/\/(.+)



%%
{comments} ;
f       {fprintf(yyout, "floatdcl");}
i       {fprintf(yyout, "intdcl");}
p       {fprintf(yyout, "print");}
{id}    {fprintf(yyout, "id");}
=       {fprintf(yyout, "assign");}
\+      {fprintf(yyout, "plus");}
-       {fprintf(yyout, "minus");}
{inum}  {fprintf(yyout, "inum");}
{fnum}  {fprintf(yyout, "fnum");}
\/      {fprintf(yyout, "division");}
\*      {fprintf(yyout, "multiplication");}
%%


int main(int argc, char** argv) {

  if(argc != 2)
  {
    printf("Ups! Wrong input");
    return 1;
  }
  FILE *fileInput; 
  FILE *fileOutput; 

  fileInput = fopen(argv[1],"r");

  if(!fileInput)
  {
    printf("File does not exist\n");
    return 1;
  }

  fileOutput=fopen("lex.out","w"); 

  if(!fileOutput)
  {
    printf("Something went wrong while writing the file");
  }
  yyin = fileInput;
  yyout = fileOutput;

  yylex();
  fclose(yyin);
  fclose(yyout);
  return 0;
}