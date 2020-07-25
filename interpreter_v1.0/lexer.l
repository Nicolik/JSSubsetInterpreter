 /*****************
  **** LEXER.L **** 
  *****************
 
 * Questo file permette di generare un lexer tramite FLEX
 * 
 * Bibliography:
 * Lecture materials of FLC course, prof. F. Scioscia
 * "flex & bison", by O'Reilly
 * "Compilers: Principles, Techniques and Tools", by Pearson

 */


%option noyywrap nodefault yylineno
%{
#include "../ast.h"
#include "../funcs.h"
#include "parser.tab.h"

#define YY_USER_ACTION  yylloc.first_line = yylloc.last_line; \
                        yylloc.first_column = yylloc.last_column; \
                        for (int i = 0; yytext[i] != '\0'; i++) { \
                            if(yytext[i] == '\n') { \
                                yylloc.last_line++; \
                                yylloc.last_column = 0; \
                            } \
                            else { \
                                yylloc.last_column++; \
                            } \ 
                        }

void genericString();
void genericStringHalf();
void printErrorNumbers();

int numberOfErrors = 0;

%}

/* float exponent */
EXP	([Ee][-+]?[0-9]+)

%%
 /* single character ops */
"+" |
"-" |
"*" |
"/" |
"%" |
"=" |
"," |
";" |
"(" |
")" |
"{" |
"}" |
\[  |
\]  |
"."      { return yytext[0]; }

 /* post-increment operator */
 "++" { return INCREMENT; }
 "--" { return DECREMENT; }

 /* exponentiation */
 "**" { return POW; }

 /* Assignment by sum, difference, prod, division or module */
"+="  { return ASGNSUM; }
"-="  {  return ASGNDIF; }
"*="  {  return ASGNPROD; }
"/="  {  return ASGNDIV; }
"%="  {  return ASGNMOD; }

 /* comparison ops */
">"     { yylval.fn = 1; return CMP; }
"<"     { yylval.fn = 2; return CMP; }
"!="    { yylval.fn = 3; return CMP; }
"=="    { yylval.fn = 4; return CMP; }
">="    { yylval.fn = 5; return CMP; }
"<="    { yylval.fn = 6; return CMP; }

 /* logical ops */
"&&"    { return AND; }
"||"    { return OR;  }
"!"     { return NOT; }

 /* logical bitwise ops */
"|" |       /* bitwise OR  */
"&" |       /* bitwise AND */
"^" |       /* bitwise XOR */
"~"         /* bitwise NOT */ { return yytext[0]; }

 /* left and right bitwise shift */
"<<" {  return LEFTSHIFT; }
">>" {  return RIGHTSHIFT; }

 /* keywords */
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"do"        { return DO; }
"for"       { return FOR; }
"function"  { return FUNCTION; }
"return"    { return RETURN; }

  /* Perhaps these should not be keywords */
"length"    { return LENGTH; }
"push"      { return PUSH; }
"pop"       { return POP; }

   /* Keywords to handle REPL */
"exit" | 
"quit" |
<<EOF>>  { printErrorNumbers(); }

"clear"          { clearScreen(); }

 /* built in functions */
"abs"       { yylval.fn = B_abs;        return BIFUNC; }
"sqrt"      { yylval.fn = B_sqrt;       return BIFUNC; }
"exp"       { yylval.fn = B_exp;        return BIFUNC; }
"log"       { yylval.fn = B_log;        return BIFUNC; }
"printInt"  { yylval.fn = B_print;      return BIFUNC; }
"rand"      { yylval.fn = B_rand;       return BIFUNC; }
"print"     { yylval.fn = B_printstr;   return BIFUNC; }

 /* read function for taking inputs */
"readline"      { return READ; }

 /* JS built in */
"typeof"    { return TYPEOF; }

 /* debug hack */
"debug"[0-9]+ { debug = atoi(&yytext[5]); printf(KCYA "debug set to %d\n", debug); }

 /* names */
[_a-zA-Z][_a-zA-Z0-9]*  { yylval.sym = lookup(yytext); return NAME; }
[0-9]+[_a-zA-Z][_a-zA-Z0-9]* { yyerror("Lexical error. Identifier name: '%s' starts with a number.", yytext); return ERRNAME; }

 /* numbers */ 
 /* doubles */
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUMBER; }
 
 /* string */    
["]([^"\\\n]|\\.|\\\n)*["]         { genericString(); return STREXP; }
["]([^"\\\n]|\\.|\\\n)*$           { genericStringHalf(); yyerror("Lexical error. Unterminated string: '%s'", yylval.str); return STRERR; }

 /* comments */
"//".*                                        { }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]           { }
[/][*].*$                                     { yyerror("Lexical error. Unclosed comment");  }

[ \t\n\r]   /* ignore white space */ 

.	{   if ((int)yytext[0] >= 0)     
            yyerror("Lexical error. Unknown character: '%c'. ASCII: %d\n", *yytext, (int)yytext[0] );
    } /* simply ignore not ASCII characters, otherwise report lexical error */

%%

void genericString() {
    yylval.str = malloc(yyleng - 1);             
    memcpy (yylval.str, yytext + 1, yyleng - 2); 
    yylval.str[yyleng - 2] = 0;                  
}

void genericStringHalf() {
    yylval.str = malloc(yyleng - 1);             
    memcpy (yylval.str, yytext + 1, yyleng - 1); 
    yylval.str[yyleng - 1] = 0;                  
}

void printErrorNumbers() {
    debug_print("printErrorNumbers\n");
    if (numberOfErrors == 0) {
        exit(0);
        return; 
    } else {
        printf(KRED "Found: %d errors\n", numberOfErrors);
    }
    exit(0);
}
   