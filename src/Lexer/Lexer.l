%{
int count = 0;
%}


%%
[A-Z] {printf("%s capital letter\n", yytext);
       count++;}
.     {printf("%s not a capital letter\n", yytext);}
\n    {return 0;}
%%

int yywrap(){}

int main(){
  
  // yywrap() - wraps the above rule section
  /* yyin - takes the file pointer 
            which contains the input*/
  /* yylex() - this is the main flex function
            which runs the Rule Section*/
  // yytext is the text in the buffer
  
  FILE *fp;
  char filename[50];
  printf("Enter the filename: \n");
  scanf("%s",filename);
  fp = fopen(filename,"r");
  yyin = fp;
  
  yylex();
  printf("\nNumber of Capital letters " 
        "in the given input - %d\n", count);
  
  return 0;
}
