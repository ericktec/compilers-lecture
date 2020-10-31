%{
#include <stdio.h>  
#include "y.tab.h"
#include <string.h>
%}

/* Regula expressions */
comments \/\/(.+)
id [a-e]|[g-h]|[j-o]|[q-z]
inum [0-9]+
fnum [0-9]+.[0-9]+




%%
{comments} ;
f       {return FLOATDCL;}
i       {return INTDCL;}
p       {return PRINT;}
{id}    {yylval.id = yytext[0]; return ID; }
"="     {return ASSIGN;}
"+"     {return PLUS;}
"-"     {return MINUS;}
{inum}  {yylval.integer = atoi(yytext); return INUM;}
{fnum}  {yylval.floatNumber = atof(yytext); return FNUM;}
"/"     {return DIVISION;}
"*"     {return MULTIPLICATION;}
%%


// int main(int argc, char** argv) {

//   if(argc != 2)
//   {
//     printf("Ups! Wrong input");
//     return 1;
//   }
//   FILE *fileInput; 
//   FILE *fileOutput; 

//   fileInput = fopen(argv[1],"r");

//   if(!fileInput)
//   {
//     printf("File does not exist\n");
//     return 1;
//   }

  
//   yyin = fileInput;


//   yylex();
//   fclose(yyin);
//   return 0;
// }