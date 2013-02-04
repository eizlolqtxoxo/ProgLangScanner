%{
extern int lineno;
extern int number;
extern char string[];
#define NUMBER 1
#define STRING 2
%}

%%
[ \t] { ; }
[0-9]* {
       sscanf(yytext, "%d", &number);
       return NUMBER;
       }
[a-zA-Z][a-zA-Z0-9]* {
       sscanf(yytext, "%s", string);
       return STRING;
       }
\n {lineno++; return '\n';}
