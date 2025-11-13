%option noyywrap

%{

#include <stdio.h>
#define YY_DECL int yylex()

//#include "Parser.tab.h"

%}

%%

"True"   {return T_TRUE;}
"False"  {return T_FALSE;}

[ \t]	; // ignore all whitespace

[0-9]*([0-9]\.?|\.[0-9])[0-9]*([Ee][-+]?[0-9]+) {yylval.fval = atof(yytext);
                                                 printf("Found float : %s ",yytext);
                                                 return T_FLOAT;}

[0-9]+ {yylval.ival = atoi(yytext);
        printf("Found float : %s ",yytext);
        return T_INT;}

\n		   {printf("Found new line");return T_NEWLINE;  }
"+"		   {printf("Found \+"      );return T_PLUS;     }
"-"		   {printf("Found \-"      );return T_MINUS;    }
"*"		   {printf("Found \*"      );return T_MULTIPLY; }
"/"		   {printf("Found dash"    );return T_DIVIDE;   }
"("		   {printf("Found \("      );return T_LEFT_P;    }
")"		   {printf("Found \)"      );return T_RIGHT_P;   }

%%

int yywrap(){}

int main(){
  
  // Uncomment the lines below 
  // to take input from file
  // FILE *fp;
  // char filename[50];
  // printf("Enter the filename: \n");
  // scanf("%s",filename);
  // fp = fopen(filename,"r");
  // yyin = fp;
  
  yylex();
  
  return 0;
}
