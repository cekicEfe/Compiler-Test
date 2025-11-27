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

%%

input:
| sexp input
;

sexp:
  T_L_PARAN sexp_list T_R_PARAN {printf("Found sexp(s) in sexp \n");}
;

sexp_list:
| sexp sexp_list {printf("Found sexp in sexp list \n");}
| id sexp_list   {printf("Found id sexp list \n");}
;

id:
  T_FALSE
| T_TRUE
| T_KEYWORD
| T_SYMBOL
| T_ATOM
| T_NIL
;

%%
