%{

#include <stdio.h>
#include "src/Parser/Parser.tab.h"

%}

ATOM [a-zA-Z\+\-\*\/\?\&\%\#\^\|\\\$\=\{\}\@]

%%


"#:T"   {return T_TRUE; }
"#:F"   {return T_FALSE;}

"#:t"   {return T_TRUE; }
"#:f"   {return T_FALSE;}


[ \t\n]	; // ignore all whitespace


[ATOM]+                             {return T_ATOM;    }
\'[ATOM]+                           {return T_SYMBOL;  }
\#\:[ATOM]+                         {return T_KEYWORD; }


"("		     {printf("Found \("      );return T_L_PARAN; }
")"		     {printf("Found \)"      );return T_R_PARAN; }


%%


//[0-9]+ {yylval.ival = atoi(yytext);
//        printf("Found float : %s ",yytext);
//        return T_INT;}


//[0-9]*([0-9]\.?|\.[0-9])[0-9]*([Ee][-+]?[0-9]+) {yylval.fval = atof(yytext);
//                                                 printf("Found float : %s ",yytext);
//                                                 return T_FLOAT;}


//\n		   {printf("Found new line");return T_NEWLINE;  }
//"+"		   {printf("Found \+"      );return T_PLUS;     }
//"-"		   {printf("Found \-"      );return T_MINUS;    }
//"*"		   {printf("Found \*"      );return T_MULTIPLY; }
//"/"		   {printf("Found dash"    );return T_DIVIDE;   }


; int yywrap(){}
