%{

// Thank you for saving my ass:
// https://learnmoderncpp.com/2020/12/18/generating-c-programs-with-flex-and-bison-3/

#include "Parser.hpp"
#include "Scanner.hpp"
#define YY_DECL int calc::Scanner::lex(calc::Parser::semantic_type *yylval)

%}
 
%option c++ interactive noyywrap noyylineno nodefault outfile="Scanner.cpp"

 
%%
 
"#T"       {printf("Found Token : T \n");return Parser::token::T_TRUE; }
"#F"       {printf("Found Token : F \n");return Parser::token::T_FALSE;}

"#t"       {printf("Found Token : T \n");return Parser::token::T_TRUE; }
"#f"       {printf("Found Token : F \n");return Parser::token::T_FALSE;}

[0-9]+ {
  printf("Found Token : INTEGER \n");
  return Parser::token::T_INT;
}
  
[-+]?[0-9]+\.[0-9]+([eE][+-]?[0-9]*)? {
  printf("Found Token : FLOAT \n");
  return Parser::token::T_FLOAT;
}

#\\([a-zA-Z0-9]+) {
  printf("Found Token : CHAR \n");
  return Parser::token::T_CHAR;
}

\"([^\\\"]|\\.)*\" {
  printf("Found Token : STRING \n");
  return Parser::token::T_STRING;
} 


[a-zA-Z_\-*+?\^%=!]+[0-9]*  {
  printf("Found Token : ATOM \n");
  return Parser::token::T_ATOM;
}
:[a-zA-Z_\-*+?\^%=!]+[0-9]* {
  printf("Found Token : KEYWORD \n");
  return Parser::token::T_KEYWORD;
}

"'"  {printf("Found Token : QUOTE \n");return Parser::token::T_QUOTE;}
"`"  {printf("Found Token : QUASIQUOTE \n");return Parser::token::T_QUASI_Q;}
","  {printf("Found Token : UNQUOTE \n");return Parser::token::T_UNQUOTE;}
",@" {printf("Found Token : SPLICE \n");return Parser::token::T_SPLICE;}

"("	 {printf("Found Token : LP_1 \n");return Parser::token::T_L_PAREN1;}
")"	 {printf("Found Token : RP_1 \n");return Parser::token::T_R_PAREN1;}
"()" {printf("Found Token : NIL_1 \n");return Parser::token::T_NIL;}

"["  {printf("Found Token : LP_2 \n");return Parser::token::T_L_PAREN2;}
"]"  {printf("Found Token : RP_2 \n");return Parser::token::T_R_PAREN2;}
"[]" {printf("Found Token : NIL_2 \n");return Parser::token::T_NIL;}

"{"  {printf("Found Token : LP_2 \n");return Parser::token::T_L_BRACK;}
"}"  {printf("Found Token : RP_2 \n");return Parser::token::T_R_BRACK;}
"{}" {printf("Found Token : NIL_2 \n");return Parser::token::T_NIL;}

[ \t]; // ignore all whitespace
[\n] ;
.    ;

%%
 
//.    {return Parser::token::T_ERROR;} 
int yyFlexLexer::yylex() {
    throw std::runtime_error("Bad call to yyFlexLexer::yylex()");
}
