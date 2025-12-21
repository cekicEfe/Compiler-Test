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

%token T_DEFINE T_COND T_EVAL T_READ T_LAMBDA
%token T_AS
%token T_ANY
%token T_DEFINE_CLASS   T_DEFINE_METHOD
%token T_CLASS_INSTANCE T_METHOD_INSTANCE

%token T_L_PAREN1 T_R_PAREN1
%token T_L_PAREN2 T_R_PAREN2
%token T_L_BRACK T_R_BRACK

%token <std::string> T_ATOM
%token <std::string> T_KEYWORD // Keyword means parameter names in functions !
// %token <std::string> T_SYMBOL

%token T_NIL
%token T_QUOTE T_QUASI_Q T_UNQUOTE T_SPLICE

%token <bool>  T_FALSE
%token <bool>  T_TRUE
%token <float> T_FLOAT
%token <int>   T_INT
%token <char>  T_CHAR
%token <std::string> T_STRING

%%

input:
| s_exp input ;
| define input ;
| define_class input ;
;


define:
  T_L_PAREN1 T_DEFINE T_ATOM id T_R_PAREN1 {
    std::cout << "Found define id pr1" << std::endl;
  }
| T_L_PAREN2 T_DEFINE T_ATOM id T_R_PAREN2 {
    std::cout << "Found define id pr2" << std::endl;
  }
;


define_class:
  T_L_PAREN1 T_DEFINE_CLASS T_ATOM T_AS T_ATOM define_class_method_list_pre T_R_PAREN1 {
    std::cout << "Found : define typeclass" << std::endl;
  }
| T_L_PAREN2 T_DEFINE_CLASS T_ATOM T_AS T_ATOM define_class_method_list_pre T_R_PAREN2 {
    std::cout << "Found : define typeclass" << std::endl;
  }
;
define_class_method_list_pre:
  T_L_PAREN1 define_class_method_list T_R_PAREN1;
| T_L_PAREN2 define_class_method_list T_R_PAREN2;
;
define_class_method_list:
| define_class_method define_class_method_list {
    std::cout << "Found : define typeclass method list" << std::endl;
  }
;
define_class_method:
  T_L_PAREN1 T_DEFINE_METHOD T_ATOM define_class_method_args T_R_PAREN1 {
    std::cout << "Found : define typeclass method" << std::endl;
  }
| T_L_PAREN2 T_DEFINE_METHOD T_ATOM define_class_method_args T_R_PAREN2 {
    std::cout << "Found : define typeclass method" << std::endl;
  }
;
define_class_method_args:
  T_L_PAREN1 args T_R_PAREN1 {
    std::cout << "Found : define typeclass method args" << std::endl;
  }
| T_L_PAREN2 args T_R_PAREN2 {
    std::cout << "Found : define typeclass method args" << std::endl;
  }
;
args:
| T_ATOM args {    
    std::cout << "Found : args" << std::endl;
}
;


s_exp:
  T_L_PAREN1 s_exp_list T_R_PAREN1 {
    std::cout << "Found s_exp type1" << std::endl;  
  }
| T_L_PAREN2 s_exp_list T_R_PAREN2 {
    std::cout << "Found s_exp type2" << std::endl;  
  }
| T_L_BRACK s_exp_no_list s_exp_no_list s_exp_no_list T_R_BRACK {
    std::cout << "Found s_exp infix" << std::endl;  
  }
;
s_exp_no_list:
  id    {}
| s_exp {}
;
s_exp_list:
| s_exp s_exp_list {
    printf("Found s_exp in s_exp list \n");
  }
| id s_exp_list    {
    printf("Found id in s_exp list \n");
  }
;


id:
  T_QUOTE s_exp   {
    printf("Found id : Quoted s_exp \n");
  }
| T_QUOTE id      {
    printf("Found id : Quoted id \n");
  }
| T_QUASI_Q id    {
    printf("Found id : Quasiquoted id \n");
  }
| T_QUASI_Q s_exp {
    printf("Found id : Quasiquoted s_exp \n");
  }
//| T_UNQUOTE id    {
//    printf("Found id : Unquoted id \n");
//  }
//| T_UNQUOTE s_exp {
//    printf("Found id : Unquoted s_exp \n");
//  }
//| T_SPLICE s_exp  {
//    printf("Found id : Spliced s_exp \n");
//  }
| T_FALSE         {
    printf("Found id : False \n");
    std::cout << "False" << std::endl;
  }
| T_TRUE          {
    printf("Found id : True \n");
    std::cout << "True" << std::endl;
  }
| T_INT           {
    printf("Found id : Int Const\n");
    std::cout << $1 << std::endl;
  }
| T_FLOAT         {
    printf("Found id : Float Const\n");
    std::cout << $1 << std::endl;
  }
| T_CHAR          {
    printf("Found id : Char Const\n");
  }
| T_STRING        {
    printf("Found id : String Const\n");
    std::cout << $1 << std::endl;
  }
| T_KEYWORD       {
    printf("Found id : Keyword \n");
    std::cout << $1 << std::endl;
  }
| T_ATOM          {
    printf("Found id : Atom \n");
    std::cout << $1 << std::endl;
  }
| T_NIL           {
    printf("Found id : Nil \n");
  }
;

%%

void calc::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
