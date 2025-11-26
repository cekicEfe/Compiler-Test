%{

#include <stdio.h>
#include "Parser.tab.h"

%}

ATOM [a-zA-Z\+\-\*\/\?\&\%\#\^\|\\\$\=\{\}\@]

%%

"True"   {return T_TRUE;}
"False"  {return T_FALSE;}

[ \t\n]	; // ignore all whitespace

[0-9]*([0-9]\.?|\.[0-9])[0-9]*([Ee][-+]?[0-9]+) {yylval.fval = atof(yytext);
                                                 printf("Found float : %s ",yytext);
                                                 return T_FLOAT;}

[ATOM]+                                         {return SYMBOL;}

[0-9]+ {yylval.ival = atoi(yytext);
        printf("Found float : %s ",yytext);
        return T_INT;}

 "("		   {printf("Found \("      );return T_LEFT_P;    }
 ")"		   {printf("Found \)"      );return T_RIGHT_P;   }

%%

//\n		   {printf("Found new line");return T_NEWLINE;  }
//"+"		   {printf("Found \+"      );return T_PLUS;     }
//"-"		   {printf("Found \-"      );return T_MINUS;    }
//"*"		   {printf("Found \*"      );return T_MULTIPLY; }
//"/"		   {printf("Found dash"    );return T_DIVIDE;   }

int yywrap(){}
