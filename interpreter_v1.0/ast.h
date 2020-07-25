/***************
 **** AST.H **** 
 ***************
 * Author: Nicola Altini
 * 
 * Questo header file contiene:
 * - Le definizioni delle strutture dati utili a costruire un AST 
 * - Le dichiarazioni delle funzioni utili per gestire un AST
 * 
 * Bibliography:
 * Lecture materials of FLC course, prof. F. Scioscia
 * "Flex & Bison", by O'Reilly
 * "Compilers: Principles, Techniques and Tools", by Pearson
 
 */

/*
 * Declarations for interpreter
 */

#include <stdio.h>

#define KNRM "\x1B[0m"
#define KCYA "\x1B[36m"
#define KMAG "\x1B[35m"
#define KBLU "\x1B[34m"
#define KYEL "\x1B[33m"
#define KGRE "\x1B[32m"
#define KRED "\x1B[31m"

#define DEBUGTEST 0
#define debug_print(fmt, ...) \
        do { if (DEBUGTEST) fprintf(stderr,KCYA fmt KNRM, ##__VA_ARGS__); } while (0)

#define TOOMANYERRORS 20
#define INPUTBUFFER 50
#define TTYSHELL2 "/dev/ttys000"
#define TTYSHELL "/dev/tty"

FILE *currentFile;
int fd;
fpos_t pos;

int interactiveOrFile;

extern FILE *yyin;

extern int yyparse();
extern int numberOfErrors;

typedef union valueOfSymbol {
  double value;
  char *stringValue;
  double *array;
} valueOfSymbol;

enum symbTableType {
  STT_double = 0,
  STT_string,        // 1
  STT_array_double,  // 2 
  STT_function,      // 3
  STT_NOTYPE,        // 4
  STT_NaN,           // 5
  STT_just_asgn,     // 6 
  STT_string_no      // 7
};

enum scopeType {
  ST_global = 0,
  ST_function
};

struct evalValueOfSymbol {
  valueOfSymbol val;
  int sizeOfArray;
  enum symbTableType type; 
};

/*
  A symbol element of the symbol table
  type = 0 --> val.double
  type = 1 --> val.stringValue
  type = 2 --> val.array
*/
struct symbol {		
  char *name;                     /* a variable name */
  enum symbTableType type;        /* type of the variable */ 
  int sizeOfArray;                /* size of array (if any) */
  valueOfSymbol val;              /* value of symbol */
  struct ast *func;	              /* stmt for the function */
  struct symlist *syms;           /* list of dummy args */
  int numberOfArguments;          /* number of args for funcs */
  struct arrayElemListAST *arrElemsAST; /* list of AST values of array */
  enum scopeType scope;           /* scope of variable */
};

/* simple symtab of fixed size */
#define NHASH 9997

struct symbol symtab[NHASH];

struct symbol *lookup(char*);

/* list of symbols, for an argument list */
struct symlist {
  struct symbol *sym;   /* pointer to symbol */ 
  struct symlist *next; /* pointer to next element of the list */
};

/* list of AST, for an array elements list */
struct arrayElemListAST {
  struct ast *valueAST;          /* ast of value of element */
  struct arrayElemListAST *next; /* pointer to next element of the list */
};

struct symlist * newsymlist(struct symbol *sym, struct symlist *next);
struct arrayElemListAST * newElemListAST(struct ast *a, struct arrayElemListAST *next);

void symlistfree(struct symlist *sl);
void arrayElemListFreeAST(struct arrayElemListAST *sl);

/* node types
 *  + - * / |
 *  0-7 comparison ops, bit coded 04 equal, 02 less, 01 greater
 *  M unary minus
 *  L statement list
 *  I IF statement
 *  W WHILE statement
 *  N symbol ref
 *  = assignment
 *  S list of symbols
 *  F built in function call
 *  C user function call
 *  V array defined by user
 *  S stringval 
 */ 

enum ntype {
  NT_sum    = '+',
  NT_diff   = '-',
  NT_prod   = '*',
  NT_div    = '/',
  NT_bitwor = '|',
  NT_btwxor = '^',
  NT_btwand = 'B',
  NT_btwnot = '~',
  NT_modul  = '%',
  NT_grea   = '1', // >
  NT_less   = '2', // < 
  NT_noteq  = '3', // =!
  NT_equal  = '4', // ==
  NT_grequ  = '5', // >=
  NT_lesseq = '6', // <=
  NT_uminus = 'M',
  NT_list   = 'L',
  NT_ifelse = 'I',
  NT_while  = 'W',
  NT_ref    = 'N', // New reference
  NT_assign = '=',
  NT_builfn = 'F',
  NT_userfn = 'C',
  NT_aronly = 'U',
  NT_string = 'S',
  NT_logand = '&',
  NT_logor  = 'O', // Logic OR
  NT_lognot = '!', 
  NT_evarel = '[', // evaluation of ARray Element
  NT_starel = ']', // Set of Array Element
  NT_postin = 'P', // Post increment node
  NT_postde = 'D', // Post decrement node
  NT_prein  = 'R', // Post increment node
  NT_prede  = 'E', // Post decrement node
  NT_forlop = 'X', // For loop
  NT_push   = 'H', // push array
  NT_pop    = 'Z', // pop array
  NT_arrlen = 'Q', // get array length 
  NT_const  = 'K',
  NT_typeof = '?',
  NT_typexp = 266,
  NT_asgsum = '(', // NAME+=exp
  NT_asgdif = ')', // NAME-=exp  
  NT_pow    = 257,
  NT_asgprd = 258,
  NT_asgdiv = 259,
  NT_asgmod = 260,
  NT_dowhle = 261,
  NT_lshift = 262,
  NT_rshift = 263,
  NT_input  = 265
};

enum bifs {			/* built-in functions */
  B_sqrt      = 1,
  B_exp       = 2,      
  B_log       = 3,
  B_print     = 4,
  B_rand      = 5,
  B_printstr  = 6, 
  B_abs       = 7    
};



/* nodes in the Abstract Syntax Tree */
/* all have common initial nodetype */

struct ast {
  enum ntype nodetype;
  struct ast *l;
  struct ast *r;
  int depth;
};

struct fncall {			/* built-in function */
  enum ntype nodetype;			/* type F */
  struct ast *l;
  enum bifs functype;
};

struct ufncall {		/* user function */
  enum ntype nodetype;			/* type C */
  struct ast *l;		/* list of arguments */
  struct symbol *s;
};

struct funcDef {
  enum ntype nodetype; 
  struct symbol *s;
  struct symlist *paramList;
  struct ast *stmts;
};

struct arrayDef {
  enum ntype nodetype;
  struct symbol *s;
  struct arrayElemListAST *arrElems; 
};

struct flow {
  enum ntype nodetype;			/* type I or W */
  struct ast *cond;	/* condition */
  struct ast *tl;		/* then or do list */
  struct ast *el;		/* optional else list */
};

struct flowFor {
  enum ntype nodetype;			          /* type X */
  struct ast *cond;	          /* condition (i < n) */
  struct ast *tl;		          /* then or do list {...} */ 
  struct ast *initialAsgn;		/* initial assignment (i = 0) */
  struct ast *finalIncrement; /* final increment (i++) */
};

struct numval {
  enum ntype nodetype;			/* type K */
  double number;
};

struct stringval {
  enum ntype nodetype;     /* type NT_string */
  char *str;
};

/* 
  * N = New reference
  * P = Post increment 
  * Z = Pop
  * Q = Get array length
  */
struct symref {
  enum ntype nodetype;			/* type N or P or Z or Q */ 
  struct symbol *s;
};

struct symasgn {
  enum ntype nodetype;			/* type = */  /* type H --> push */
  struct symbol *s;
  struct ast *v;		/* value */
};

struct symasgnArray {
  enum ntype nodetype;			/* type ] */
  struct symbol *s;
  struct ast *index;		/* index */
  struct ast *value;    /* value to set in array */
};

struct symarrayel {
  enum ntype nodetype;     /* type [ */
  struct symbol *s;
  struct ast *index;
};

/* build an AST */
struct ast * newast(enum ntype nodetype, struct ast *l, struct ast *r);
struct ast * newcmp(int cmptype, struct ast *l, struct ast *r);
struct ast * newfunc(int functype, struct ast *l);
struct ast * newcall(struct symbol *s, struct ast *l);

/* pick an element of given index from a declared array */
struct ast * newarrayelast(struct symbol *s, struct ast *l);

struct ast * newarray(struct symbol *s);

struct ast * newref(struct symbol *s);

struct ast * newTypeOf(struct symbol *s);
struct ast * newTypeOfExp(struct ast *l);

struct ast * newasgn(struct symbol *s, struct ast *v);
struct ast * newasgnsumdif(struct symbol *s, struct ast *v, int type);

struct ast * newasgnArray(struct symbol *s, struct ast *index, struct ast *value);

struct ast * newnum(double d);

struct ast * newstring(char *str);

struct ast * newinput();

/* flow instruction (IF/THEN/ELSE and WHILE/DO) */
struct ast * newflow(enum ntype nodetype, struct ast *cond, struct ast *tl, struct ast *tr);
/* flow instruction (FOR) */
struct ast * newflowFor(struct ast *cond, struct ast *tl, struct ast *initialAsgn, struct ast *finalIncrement);

/* post/pre increment and decrement */
struct ast * newIncrement(struct symbol *s, int postpre); //postpre = 0 --> post | postpre = 1 --> pre
struct ast * newDecrement(struct symbol *s, int postpre);

/* define a function */
void dodef(struct symbol *name, struct symlist *syms, struct ast *func);

/* define an array */
void dodefArray(struct symbol *name, struct arrayElemListAST *arrElems);
struct ast * dodefArrayAST(struct symbol *name, struct arrayElemListAST *arrElems);

/* push and pop operations for array */
struct ast * makePushOnArrayAST(struct symbol *name, struct ast * valueToPush);
struct ast * makePopFromArrayAST(struct symbol *name);
struct ast * getSizeOfArrayNameAST(struct symbol *name);

/* evaluate an AST */
/* The eval function is the heart of the project */
struct evalValueOfSymbol * evalStruct(struct ast *);

/* make possible things as a[i] = c; */ 
void replaceElement(int index, double arrElement, struct symbol **s);

/* delete and free an AST */
void treefree(struct ast *);

/* interface to the lexer */
extern int yylineno; /* from lexer */
extern void yyerror(char *s, ...);

extern int debug;
extern char * yytext;
void dumpast(struct ast *a, int level);


