%{

// Thank you for saving my ass:
// https://learnmoderncpp.com/2020/12/18/generating-c-programs-with-flex-and-bison-3/

#include "Parser.hpp"
#include "Scanner.hpp"
#define YY_DECL int calc::Scanner::lex(calc::Parser::semantic_type *yylval)

%}
 
%option c++ interactive noyywrap noyylineno nodefault outfile="Scanner.cpp"

 
%%

"define"   {
  printf("Found Token : Define \n");
  return Parser::token::T_DEFINE;
}
"cond"     {
  printf("Found Token : cond \n");
  return Parser::token::T_COND;
}
"define-class" {
  printf("Found Token : def-class");
  return Parser::token::T_DEFINE_CLASS;
}
"define-method" {
  printf("Found Token : def-method");
  return Parser::token::T_DEFINE_METHOD;
}
"class-instance" {
  printf("Found Token : class-instance");
  return Parser::token::T_CLASS_INSTANCE;
}
"method-instance" {
  printf("Found Token : method-instance");
  return Parser::token::T_METHOD_INSTANCE;
}
"eval"     {
  printf("Found Token : eval \n");
  return Parser::token::T_EVAL;
}
"read"     {
  printf("Found Token : read \n");
  return Parser::token::T_READ;
}
"lambda"   {
  printf("Found Token : lambda \n");
  return Parser::token::T_LAMBDA;
}



"#t"       {
  printf("Found Token : T \n");
  yylval->build<bool>(true);
  return Parser::token::T_TRUE;
}
"#f"       {
  printf("Found Token : F \n");
  yylval->build<bool>(false);
  return Parser::token::T_FALSE;
}
[0-9]+ {
  printf("Found Token : INTEGER \n");
  yylval->build<int>(std::stoi(yytext));
  return Parser::token::T_INT;
} 
[-+]?[0-9]+\.[0-9]+([eE][+-]?[0-9]*)? {
  printf("Found Token : FLOAT \n");
  yylval->build<float>(std::stof(yytext));
  return Parser::token::T_FLOAT;
}
#\\([a-zA-Z0-9]+) {
  printf("Found Token : CHAR \n");
  return Parser::token::T_CHAR;
}
\"([^\\\"]|\\.)*\" {
  printf("Found Token : STRING \n");
  yylval->build<std::string>(yytext);
  return Parser::token::T_STRING;
} 

[a-zA-Z_\-*+?\^%=!]+[0-9]*  {
  printf("Found Token : ATOM \n");
  yylval->build<std::string>(yytext);
  return Parser::token::T_ATOM;
}
:[a-zA-Z_\-*+?\^%=!]+[0-9]* {
  printf("Found Token : KEYWORD \n");
  yylval->build<std::string>(yytext);
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
