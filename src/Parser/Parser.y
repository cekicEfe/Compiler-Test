%{

#include <stdio.h>

%}

%token T_L_PARAN T_R_PARAN
%token T_ATOM T_SYMBOL T_KEYWORD
%token T_FALSE T_TRUE
%token T_QUOTED

%%

input:
  %empty
| s_exp input {printf("input");}
;

s_exp:
  L_PARAN s_exp_list R_PARAN {printf("s_exp");}
;

s_exp_list:
  id
| s_exp_list id      {printf("s_exp_list");}
| s_exp              {printf("???");}
;

id:
  T_ATOM
| T_SYMBOL
| T_KEYWORD
;
	
%%
