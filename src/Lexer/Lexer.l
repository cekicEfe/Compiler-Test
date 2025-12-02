%{

#include <stdio.h>

#include "Parser.tab.hh"
#include "Lexer.h"

%}

%option c++
%option c++ noyywrap
%option yyclass="FooLexer"


%%


"#:T"       {printf("Found Token : T \n");return yy::parser::token::T_TRUE; }
"#:F"       {printf("Found Token : F \n");return yy::parser::token::T_FALSE;}

"#:t"       {printf("Found Token : T \n");return yy::parser::token::T_TRUE; }
"#:f"       {printf("Found Token : F \n");return yy::parser::token::T_FALSE;}

[0-9]+      {printf("Found Token : INTEGER \n");
             return yy::parser::token::T_INT;}

[-+]?[0-9]+\.[0-9]+([eE][+-]?[0-9]*)? {printf("Found Token : FLOAT \n");
                                       return yy::parser::token::T_FLOAT;}

[a-zA-Z_\-*+?\^%=!]+[0-9]*   {printf("Found Token : ATOM \n");return yy::parser::token::T_ATOM; }
#:[a-zA-Z_\-*+?\^%=!]+[0-9]* {printf("Found Token : KEYWORD \n");return yy::parser::token::T_KEYWORD;}

"'"  {printf("Found Token : QUOTE \n");return yy::parser::token::T_QUOTE;}

"("	 {printf("Found Token : LP_1 \n");return yy::parser::token::T_L_PAREN1;}
")"	 {printf("Found Token : RP_1 \n");return yy::parser::token::T_R_PAREN1;}
"()" {printf("Found Token : NIL_1 \n");return yy::parser::token::T_NIL;}

"["  {printf("Found Token : LP_2 \n");return yy::parser::token::T_L_PAREN2;}
"]"  {printf("Found Token : RP_2 \n");return yy::parser::token::T_R_PAREN2;}
"[]" {printf("Found Token : NIL_2 \n");return yy::parser::token::T_NIL;}

[ \t] ; // ignore all whitespace
[\n]  ;
.           {/* yyerror("Unknown Token") */;return yy::parser::token::YYerror;} 


%%
  
