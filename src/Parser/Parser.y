%{

#include <stdio.h>

void yyerror(char *ps, ...) {
  printf("%s <<- \n", ps);
}

int yylex();

%}

%token T_L_PAREN1 T_R_PAREN1
%token T_L_PAREN2 T_R_PAREN2
%token T_ATOM T_KEYWORD T_SYMBOL T_NIL
%token T_FALSE T_TRUE
%token <float> T_FLOAT
%token <int> T_INT

%union{
  int num;
  float f;
  int bool;
}

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
| id s_exp_list    {printf("Found id s_exp list \n");}
;

id:
  T_FALSE    {}
| T_TRUE     {}
| T_INT      {}
| T_FLOAT    {}
| T_KEYWORD  {}
| T_SYMBOL   {}
| T_ATOM     {}
| T_NIL      {}
;

%%
