%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);

struct _yy_string_MINE {
	char   *pStr;
	size_t str_size;
}typedef _yy_string_MINE;

%}

%union {
	int ival;
	float fval;
	_yy_string_MINE sVal;
}


%token<ival> T_INT
%token<fval> T_FLOAT

%token T_TRUE T_FALSE T_LEFT_P T_RIGHT_P T_ID 

//%left T_PLUS T_MINUS
//%left T_MULTIPLY T_DIVIDE

%type<ival> expression
%type<fval> mixed_expression

%start input

%%

input:
	| s_exp_list
	;

s_exp_list:
	| s_exp s_exp_list
	;

s_exp:
	| T_LEFT_P exp_list T_LEFT_P
	;

exp_list:
	| exp exp_list
	;

exp:
	| T_ID
	| T_INT
	| T_FLOAT
	;

%%

//int main() {
//	yyin = stdin;
//
//	do {
//		yyparse();
//	} while(!feof(yyin));
//
//	return 0;
//}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
