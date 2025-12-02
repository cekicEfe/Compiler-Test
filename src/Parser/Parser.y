
%require "3.2"
%language "c++"

%code requires {
    #include <string>
    #include "Lexer.h"
}

%define api.value.type {std::string}

%parse-param {FooLexer &lexer}

%header

%code {
    #define yylex lexer.yylex
}

%token T_L_PAREN1 T_R_PAREN1
%token T_L_PAREN2 T_R_PAREN2
%token T_ATOM T_KEYWORD T_SYMBOL T_NIL T_QUOTE
%token T_FALSE T_TRUE
%token T_FLOAT
%token T_INT

%%

input:
| s_exp input
;

s_exp:
  T_L_PAREN1 s_exp_list T_R_PAREN1 {}
| T_L_PAREN2 s_exp_list T_R_PAREN2 {}
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

void yy::parser::error(const std::string &message)
{
    std::cerr << "Error: " << message << std::endl;
}
