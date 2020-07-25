 /******************
  **** PARSER.Y **** 
  ******************
 
 * Questo file permette di generare un parser tramite BISON
 * 
 * Bibliography:
 * Lecture materials of FLC course, prof. F. Scioscia
 * "flex & bison", by O'Reilly
 * "Compilers: Principles, Techniques and Tools", by Pearson
 
 */

%{

void yyerror(char *s, ...);

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../ast.h"
#include "../funcs.h"

struct symbol *symbTEMP; /* Questo puntatore a symbol table viene utilizzato per memorizzare temporaneamente i vettori */
/* the default evaluator will, by default, assign the most recently evaluated expression to the 
   special variable _ (underscore). */
%}

%locations

%union {
  struct ast *a;
  double d;
  char *str;
  struct symbol *sym;		/* which symbol */
  struct symlist *sl;
  struct arrayElemList *al;
  int fn;			/* which function */
}

%define parse.lac full
%define parse.error verbose

/* declare tokens */
%token <d> NUMBER
%token <sym> NAME 
%token <fn> BIFUNC
%token <str> STREXP STRERR

%token IF ELSE WHILE DO FOR
%token FUNCTION RETURN LENGTH TYPEOF 
%token PUSH POP
%token READ
%token ERRNAME

%left INCREMENT DECREMENT

%right '=' ASGNSUM ASGNDIF ASGNPROD ASGNDIV ASGNMOD

%left OR
%left AND

%left '|' /* bitwise OR */
%left '^' /* bitwise XOR */
%left '&' /* bitwise AND */

%nonassoc <fn> CMP

%left LEFTSHIFT RIGHTSHIFT

%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS UPLUS NOT '~' /* ~ is bitwise NOT */
%right POW

/* Giving more precedence to the ELSE stmt, we avoid shift/reduce conflict for dangling else */
%nonassoc "then"
%nonassoc ELSE

%type <a> stmt assignexp list bodylist explist functionbody returnstmt arrpushpop
%type <a> exp arithmexp logicexp bitwisexp incrmentexp 
%type <a> branchstmt loopstmt
%type <a> arraydecl arraydecls 
 
%type <sl> symlist 
%type <al> arrayelemsast arraydeclright

%start interprlist

%%  

stmt:   branchstmt      { $$ = $1; }
      | loopstmt        { $$ = $1; }
      | exp ';'         { $$ = $1; }            
      | arraydecl       { $$ = $1; }
      ; 

branchstmt:   IF '(' exp ')' bodylist         	 %prec "then"       { $$ = newflow('I', $3, $5, NULL); }
            | IF '(' exp ')' bodylist ELSE bodylist		              { $$ = newflow('I', $3, $5, $7); }
            ;

loopstmt:     WHILE '(' exp ')'  bodylist                         { $$ = newflow('W', $3, $5, NULL); }
            | DO bodylist WHILE '(' exp ')'                       { $$ = newflow(NT_dowhle, $5, $2, NULL); }
            | FOR '(' assignexp ';' exp ';' exp ')' bodylist      { $$ = newflowFor($5, $9, $3, $7); }
            ;
  
bodylist:   '{' list '}'     { $$ = $2; }
          | stmt             { $$ = $1; } 
          ;

list:  
              %empty               { $$ = NULL; }
              | list stmt          {    
                                      if ($1 == NULL)
                                        $$ = $2;
                                      else
                                        $$ = newast('L', $1, $2);
                                    }
              ;

arithmexp:    exp '+' exp              { $$ = newast('+', $1, $3); }
            | exp '-' exp              { $$ = newast('-', $1, $3); }
            | exp '*' exp              { $$ = newast('*', $1, $3); }
            | exp '/' exp              { $$ = newast('/', $1, $3); }
            | exp '%' exp              { $$ = newast('%', $1, $3); }
            | exp POW exp              { $$ = newast(NT_pow, $1, $3); }
            | '(' exp ')'              { $$ = $2; }
            | '-' exp %prec UMINUS     { $$ = newast('M', $2, NULL); }
            | '+' exp %prec UPLUS      { $$ = $2; }
            ;

logicexp:     exp AND exp              { $$ = newast('&', $1, $3); }
            | exp OR  exp              { $$ = newast('O', $1, $3); }
            | NOT exp                  { $$ = newast('!', $2, NULL); }
            ;

bitwisexp:    exp '|' exp              { $$ = newast('|', $1, $3); }
            | exp '^' exp              { $$ = newast('^', $1, $3); }
            | exp '&' exp              { $$ = newast('B', $1, $3); }
            | '~' exp                  { $$ = newast('~', $2, NULL); }
            | exp LEFTSHIFT exp        { $$ = newast(NT_lshift, $1, $3); }
            | exp RIGHTSHIFT exp       { $$ = newast(NT_rshift, $1, $3); }
            ;

incrmentexp:  NAME INCREMENT           { $$ = newIncrement($1, 0); }
            | NAME DECREMENT           { $$ = newDecrement($1, 0); }                                  
            | INCREMENT NAME           { $$ = newIncrement($2, 1); }
            | DECREMENT NAME           { $$ = newDecrement($2, 1); }
            ;

exp: exp CMP exp              { $$ = newcmp($2, $1, $3); }
   | arithmexp                { $$ = $1; }
   | logicexp                 { $$ = $1; }    
   | bitwisexp                { $$ = $1; }
   | NUMBER                   { $$ = newnum($1);  }
   | BIFUNC '(' exp ')'       { $$ = newfunc($1, $3); }
   | TYPEOF '(' exp ')'       { $$ = newTypeOfExp($3); }
   | TYPEOF '(' arraydecls ')' { $$ = newTypeOfExp($3); } 
   | NAME                     { 
                                  if($1->type == STT_NOTYPE && $1->scope != ST_function) {
                                    yyerror("Semantic error. The variable '%s' is not defined yet.", $1->name); YYERROR; 
                                  }
                                  debug_print("new name '%s' used in exp with scope: '%d' (0 = global, 1 = function) \n", $1->name, $1->scope);
                                  $$ = newref($1); 
                              }
   | ERRNAME                  { YYERROR; }
   | assignexp                { $$ = $1; }
   | NAME '(' explist ')'     { $$ = newcall($1, $3); }
   | NAME '(' ')'             { $$ = newcall($1, NULL); }
   | NAME '[' exp ']'         { $$ = newarrayelast($1, $3); }
   | NAME '[' exp ']' '=' exp { $$ = newasgnArray($1, $3, $6); }
   | arrpushpop               { $$ = $1; }  
   | incrmentexp              { $$ = $1; }
   | STREXP                   { $$ = newstring($1);  debug_print("Defined string exp\n");  }
   | STRERR                   { YYERROR; }
   | READ '(' ')'             { $$ = newinput(); }
  ;

assignexp: NAME '=' exp      { $$ = newasgn($1, $3); }
         | NAME ASGNSUM exp  { $$ = newasgnsumdif($1, $3, 0); }
         | NAME ASGNDIF exp  { $$ = newasgnsumdif($1, $3, 1); }
         | NAME ASGNPROD exp { $$ = newasgnsumdif($1, $3, 2); }
         | NAME ASGNDIV exp  { $$ = newasgnsumdif($1, $3, 3); }
         | NAME ASGNMOD exp  { $$ = newasgnsumdif($1, $3, 4); }
        ;

arraydeclright:   '[' arrayelemsast ']'     { $$ = $2; } 
                | '[' ']'                   { $$ = NULL; }     
        ;

arraydecl: arraydecls ';'
         ;

arraydecls:  NAME '=' arraydeclright      { 
                                              $$ = dodefArrayAST($1, $3); 
                                              printf(KMAG "Defined array %s\n" KNRM, $1->name); 
                                              debug_print("array declaration \n"); 
                                              }
           | arraydeclright             {   
                                              symbTEMP = lookup("_");
                                              $$ = dodefArrayAST(symbTEMP, $1); 
                                              printf(KMAG "Defined array\n" KNRM); 
                                              debug_print("array declaration \n"); 
                                              }                                                                       
        ;

arrayelemsast:  exp                     { $$ = newElemListAST ($1, NULL); debug_print("AST elem list allocation LAST \n"); }
              | exp ',' arrayelemsast   { $$ = newElemListAST ($1, $3); debug_print("AST elem list allocation \n"); }
              ;

arrpushpop:   NAME '.' LENGTH             { $$ = getSizeOfArrayNameAST($1); }       
            | NAME '.' PUSH '(' exp ')'   { $$ = makePushOnArrayAST($1, $5); }
            | NAME '.' POP  '(' ')'       { $$ = makePopFromArrayAST($1); }
            ;

explist:    exp             
        |   exp ',' explist  { $$ = newast('L', $1, $3); }
        ;

symlist: NAME               { $1->scope = ST_function; $$ = newsymlist($1, NULL); debug_print("sym list allocation LAST \n");}
        | NAME ',' symlist  { $1->scope = ST_function; $$ = newsymlist($1, $3);   debug_print("sym list allocation \n");}
        ;

functionbody: list returnstmt { 
                                        if ($1 == NULL)
                                          $$ = $2;
                                        else
                                          $$ = newast('L', $1, $2); 
                                      }
            ;

returnstmt:  RETURN ';'     { $$ = newnum(0); }
           | RETURN exp ';' { $$ = $2; }      
           ;

funcdecl:  FUNCTION NAME '(' symlist ')' '{' functionbody '}'   {
                                                                  dodef($2, $4, $7); 
                                                                  printf(KMAG "Defined function %s\n", $2->name);                                                              
                                                                }       
            ;                                                

funcnoparamdecl:  FUNCTION NAME '(' ')' '{' functionbody '}'   {
                                                                  dodef($2, NULL, $6);
                                                                  printf(KMAG "Defined function %s\n", $2->name);                                                              
                                                                }       
            ;     

funcdecls:  funcdecl
          | funcnoparamdecl
          ;

interprlist:  %empty 
            | interprlist stmt {
                                if(debug) dumpast($2, 0);                      
                                handleOutputSwitchStruct($2);
                                if(interactiveOrFile) printf(KNRM "> ");
                                treefree($2);
                              }
            | interprlist funcdecls  {
                              if(interactiveOrFile) printf(KNRM "> ");
                            }
                
            | interprlist error {  if(interactiveOrFile) printf("> "); /*yyerrok; */ } 
            ; 

%%

void yyerror(char *s, ...)
{
  va_list ap;
  va_start(ap, s);

  if (numberOfErrors < TOOMANYERRORS) {
    // fprintf(stderr, KRED "Line %d: error: ", yylineno);
    fprintf(stderr, KRED "Line %d:[%d-%d]: error: ", yylineno, yylloc.first_column, yylloc.last_column);
    vfprintf(stderr, s, ap);
    fprintf(stderr, KNRM "\n");
  } else {
    fprintf(stderr, KRED "Too many errors in your program (more than %d). Exit.\n" KNRM, TOOMANYERRORS);
    exit(0);
  }
  
  numberOfErrors++;
}
