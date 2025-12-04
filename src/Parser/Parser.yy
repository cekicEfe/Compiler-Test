
%{

// Thank you for saving my ass:
// https://learnmoderncpp.com/2020/12/18/generating-c-programs-with-flex-and-bison-3/

#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>
%}
 
%require "3.7.4"
%language "C++"
%defines "Parser.hpp"
%output "Parser.cpp"
 
%define api.parser.class {Parser}
%define api.namespace {calc}
%define api.value.type variant
%parse-param {Scanner* scanner}
 
%code requires
{
    namespace calc {
        class Scanner;
    } // namespace calc
} // %code requires
 
%code
{
    #include "Scanner.hpp"
    #define yylex(x) scanner->lex(x)
}

%token T_ERROR
%token T_L_PAREN1 T_R_PAREN1
%token T_L_PAREN2 T_R_PAREN2
%token T_L_BRACK T_R_BRACK
%token T_ATOM T_KEYWORD T_SYMBOL T_NIL
%token T_QUOTE T_QUASI_Q T_UNQUOTE T_SPLICE
%token T_FALSE T_TRUE
%token <float> T_FLOAT
%token <int> T_INT
  
%%

input:
| s_exp input
;

s_exp:
  T_L_PAREN1 s_exp_list T_R_PAREN1 {}
| T_L_PAREN2 s_exp_list T_R_PAREN2 {}
| T_L_BRACK id id id T_R_BRACK {}
;

s_exp_list:
| s_exp s_exp_list {printf("Found s_exp in s_exp list \n");}
| id s_exp_list    {printf("Found id in s_exp list \n");}
;

id:
  T_QUOTE s_exp {printf("Found id : Quoted s_exp \n");}
| T_QUOTE id    {printf("Found id : Quoted id \n");}
| T_FALSE       {printf("Found id : False \n");}
| T_TRUE        {printf("Found id : True \n");}
| T_INT         {printf("Found id : Int \n");}
| T_FLOAT       {printf("Found id : Float \n");}
| T_KEYWORD     {printf("Found id : Keyword \n");}
| T_ATOM        {printf("Found id : Atom \n");}
| T_NIL         {printf("Found id : Nil \n");}
;

%%

void calc::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
