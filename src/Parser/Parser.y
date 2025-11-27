%{

#include <stdio.h>

void yyerror(char *ps, ...) {
  printf("%s <<- \n", ps);
}

int yylex();

%}

%token T_L_PARAN T_R_PARAN
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
  T_L_PARAN s_exp_list T_R_PARAN {}
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
