%{

#include <stdio.h>
#include "Parser.tab.h"

void yyerror(char *ps, ...);

%}

%%


"#:T"       {printf("Found : T \n");return T_TRUE; }
"#:F"       {printf("Found : F \n");return T_FALSE;}

"#:t"       {printf("Found : T \n");return T_TRUE; }
"#:f"       {printf("Found : F \n");return T_FALSE;}

[0-9]+      {printf("Found : INTEGER \n");
             return T_INT;}

[-+]?[0-9]+\.[0-9]+([eE][+-]?[0-9]*)? {printf("Found : FLOAT \n");
                                       return T_FLOAT;}

[a-zA-Z_\-*+?^%=!]+[0-9]*   {printf("Found : ATOM \n");return T_ATOM; }
'[a-zA-Z_\-*+?^%=!]+[0-9]*  {printf("Found : SYMBOL \n");return T_SYMBOL;}
#:[a-zA-Z_\-*+?^%=!]+[0-9]* {printf("Found : KEYWORD \n");return T_KEYWORD;}

"("		     {printf("Found : LP_1 \n");return T_L_PAREN1;}
")"		     {printf("Found : RP_1 \n");return T_R_PAREN1;}
"()"       {printf("Found : NIL_1 \n");return T_NIL;}

"["  {printf("Found : LP_2 \n");return T_L_PAREN2;}
"]"  {printf("Found : RP_2 \n");return T_R_PAREN2;}
"[]" {printf("Found : NIL_2 \n");return T_NIL;}

[ \t] ; // ignore all whitespace
[\n]  ;
.           {yyerror("Unknown Token");return YYerror;} 


%%


int yywrap() {
  return 1;
}
  
