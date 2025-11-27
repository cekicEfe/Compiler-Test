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

[0-9]+ {printf("Found : INTEGER \n");
        return T_INT;}

[-+]?[0-9]+\.[0-9]+([eE][+-]?[0-9]*)? {printf("Found : FLOAT \n");
                                       return T_FLOAT;}

[a-zA-Z][a-zA-Z0-9_\-*+?^%=!]*   {printf("Found : ATOM \n");return T_ATOM; }
'[a-zA-Z][a-zA-Z0-9_\-*+?^%=!]*  {printf("Found : SYMBOL \n");return T_SYMBOL;}
#:[a-zA-Z][a-zA-Z0-9_\-*+?^%=!]* {printf("Found : KEYWORD \n");return T_KEYWORD;}

"("		      {printf("Found : LP \n");return T_L_PARAN;}
")"		      {printf("Found : RP \n");return T_R_PARAN;}
"'()"        {printf("Found : NIL \n");return T_NIL;}

[ \t] ; // ignore all whitespace
[\n]  ;
.           {yyerror("Unknown Token");return YYerror;} 


%%


int yywrap() {
  return 1;
}
  
