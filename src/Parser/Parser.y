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
%token T_FLOAT T_INT
%%

input:
| sexp input
;

sexp:
  T_L_PARAN sexp_list T_R_PARAN {}
;

sexp_list:
| sexp sexp_list {printf("Found sexp in sexp list \n");}
| id sexp_list   {printf("Found id sexp list \n");}
;

id:
  T_FALSE
| T_TRUE
| T_INT
| T_FLOAT
| T_KEYWORD
| T_SYMBOL
| T_ATOM
| T_NIL
;

%%
