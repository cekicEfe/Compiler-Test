%{   

#include "Parser.h"
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;

%}

%option noyywrap

DIGIT    [0-9]
LETTER   [a-zA-Z]
   
%%

"-"            {return MINUS;}
"+"            {return PLUS;}
"*"            {return MULT;}
"/"            {return DIV;}
"="            {return EQUAL;}
"("            {return L_PAREN;}
")"            {return R_PAREN;}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?) {yylval.dval = atof(yytext); return NUMBER;}

[ \t]+         {/* ignore spaces */}

"\n"           {return END;}

.              {printf("Error at line %d: unrecognized symbol \"%s\"\n", yylloc.first_line, yytext); exit(0);}

%%

//int yywrap() {
//   // open next reference or source file and start scanning
//   if((yyin = compiler->getNextFile()) != NULL) {
//      line = 0; // reset line counter for next source file
//      return 0;
//   }
//   return 1;
//}
