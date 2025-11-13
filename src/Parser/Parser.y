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
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT_P T_RIGHT_P T_TRUE T_FALSE
%token T_NEWLINE T_QUIT
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE

%type<ival> expression
%type<fval> mixed_expression

%start input

%%

input:
	| calculation line
	;

s_exp_list:
	| T_LEFT_P exp T_RIGHT_P {}


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
