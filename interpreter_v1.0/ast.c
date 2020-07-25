/***************
 **** AST.C **** 
 ***************
 
 * Questo file c contiene:
 * - Le definizioni delle funzioni utili per gestire un AST
 * 
 * Bibliography:
 * Lecture materials of FLC course, prof. F. Scioscia
 * "flex & bison", by O'Reilly
 * "Compilers: Principles, Techniques and Tools", by Pearson
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include "ast.h"
#include "funcs.h"

/* symbol table */
/* hash a symbol */
 /* 
  * The hash function works this way: for each character, 
  * multiply the previous character by 9 and then XOR the character,
  * doing all the arithmetic as unsigned, which ignores overflows.
  */
static unsigned symhash(char *sym)
{
  unsigned int hash = 0;
  unsigned c;

  while((c = *sym++)) hash = hash * 9 ^ c;

  return hash;
}

/* 
 * THE lookup routine computes the ST entry index as the hash value
 * modulo the size of the symbol table, which was chosen a number with
 * no even factors, again to mix the hash bits up.
 */
struct symbol * lookup(char *sym)
{
  struct symbol *sp = &symtab[symhash(sym)%NHASH];
  int scount = NHASH;		/* how many have we looked at */

  while(--scount >= 0) {
    /* 
     * strcmp restituisce 0 se il confronto è =, quindi !strcmp restituisce 1 in caso di confronto = 
     * Se esiste un nome all'indirizzo sp, e questo nome coincide con quello memorizzato della sp, 
     * restituisce sp al lexer (che lo salva in yylval.sym)
     * Se !strcmp restituisce 0 significa che il confronto non è andato a buon fine, quindi si procede
     * con una scansione lineare della symbol table fino a trovare il nome cercato 
    */
    if(sp->name && !strcmp(sp->name, sym)) { return sp; }

    if(!sp->name) {		/* new entry */
      sp->name = strdup(sym);
      sp->val.value = 0;
      sp->func = NULL;
      sp->syms = NULL;
      sp->arrElemsAST = NULL;
      sp->type = STT_NOTYPE;
      sp->scope = ST_global;
      return sp;
    }

    if(++sp >= symtab+NHASH) sp = symtab; /* try the next entry */
  }
  yyerror("symbol table overflow\n");
  abort(); /* tried them all, table is full */

}

struct ast * newast(enum ntype nodetype, struct ast *l, struct ast *r)
{
  struct ast *a = malloc(sizeof(struct ast));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->l = l;
  a->r = r;
  return a;
}

struct ast * newnum(double d)
{
  struct numval *a = malloc(sizeof(struct numval));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'K';
  a->number = d;
  return (struct ast *)a;
}


struct ast * newstring(char *str)
{
  struct stringval *a = malloc(sizeof(struct stringval));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  a->nodetype = 'S';
  a->str = strdup(str);
  debug_print("newstring: '%s'\n", a->str);
  return (struct ast *)a;
}

struct ast * newinput()
{
  struct symref *a = malloc(sizeof(struct symref));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  a->nodetype = NT_input;

  return (struct ast *)a;

}

struct ast * newcmp(int cmptype, struct ast *l, struct ast *r)
{
  struct ast *a = malloc(sizeof(struct ast));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = '0' + cmptype;
  a->l = l;
  a->r = r;
  return a;
}

struct ast * newfunc(int functype, struct ast *l)
{
  struct fncall *a = malloc(sizeof(struct fncall));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'F';
  a->l = l;
  a->functype = functype;
  return (struct ast *)a;
}

struct ast * newcall(struct symbol *s, struct ast *l)
{
  struct ufncall *a = malloc(sizeof(struct ufncall));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'C';
  a->l = l;
  a->s = s;
  return (struct ast *)a;
}

struct ast * newref(struct symbol *s)
{
  struct symref *a = malloc(sizeof(struct symref));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'N';
  a->s = s;
  return (struct ast *)a;
}

struct ast * newTypeOf(struct symbol *s)
{
  struct symref *a = malloc(sizeof(struct symref));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = NT_typeof;
  a->s = s;
  return (struct ast *)a;
}

struct ast * newTypeOfExp(struct ast *l)
{
  struct ast *a = malloc(sizeof(struct ast));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = NT_typexp;
  a->l = l;
  return a;
}

struct ast * newIncrement(struct symbol *s, int postpre)
{
  struct symref *a = malloc(sizeof(struct symref));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  if (postpre == 0) {
    a->nodetype = 'P'; // postincrement
  } else { 
    a->nodetype = 'R'; // preincrement
  }

  a->s = s;
  
  return (struct ast *)a;

}

struct ast * newDecrement(struct symbol *s, int postpre)
{
  struct symref *a = malloc(sizeof(struct symref));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  if (postpre == 0) {
    a->nodetype = 'D';  // postdecrement
  } else {
    a->nodetype = 'E';  // predecrement
  }

  a->s = s;
  
  return (struct ast *)a;

}


struct ast * newasgn(struct symbol *s, struct ast *v)
{
  struct symasgn *a = malloc(sizeof(struct symasgn));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  
  if (s->type == STT_NOTYPE) s->type = STT_just_asgn;

  a->nodetype = '=';
  a->s = s;
  a->v = v;
  return (struct ast *)a;
}

struct ast * newasgnsumdif(struct symbol *s, struct ast *v, int type)
{
  struct symasgn *a = malloc(sizeof(struct symasgn));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  if (type == 0) {
    a->nodetype = NT_asgsum;
  } else if (type == 1) {
    a->nodetype = NT_asgdif;
  } else if (type == 2) {
    a->nodetype = NT_asgprd;
  } else if (type == 3) {
    a->nodetype = NT_asgdiv;
  } else if (type == 4) {
    a->nodetype = NT_asgmod;
  } else {
    yyerror("internal error: bad type %d", type);
  }
  a->s = s;
  a->v = v;
  return (struct ast *)a;
}

struct ast * newasgnArray(struct symbol *s, struct ast *index, struct ast *value)
{
  struct symasgnArray *a = malloc(sizeof(struct symasgnArray));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  a->nodetype = ']';
  a->index = index;
  a->value = value;
  a->s = s;
  return (struct ast *)a;
}

struct ast * newarrayelast(struct symbol *s, struct ast *l)
{
   struct symarrayel *a = malloc(sizeof(struct symarrayel)); 
   
   if(!a) {
    yyerror("out of space");
    exit(0);
  }

  a->nodetype = '[';
  a->s = s;
  a->index = l;
  return (struct ast *)a;

}


struct ast * newflow(enum ntype nodetype, struct ast *cond, struct ast *tl, struct ast *el)
{
  struct flow *a = malloc(sizeof(struct flow));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->cond = cond;
  a->tl = tl;
  a->el = el;
  return (struct ast *)a;
}

struct ast * newflowFor(struct ast *cond, struct ast *tl, struct ast *initialAsgn, struct ast *finalIncrement)
{
  struct flowFor *a = malloc(sizeof(struct flowFor));
  
  if(!a) {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 'X';
  a->cond = cond;
  a->tl = tl;
  a->initialAsgn = initialAsgn;
  a->finalIncrement = finalIncrement;
  return (struct ast *)a;
}

struct symlist * newsymlist(struct symbol *sym, struct symlist *next)
{
  struct symlist *sl = malloc(sizeof(struct symlist));
  
  if(!sl) {
    yyerror("out of space");
    exit(0);
  }
  sl->sym = sym;
  sl->next = next;
  return sl;
}


struct arrayElemListAST * newElemListAST(struct ast *a, struct arrayElemListAST *next)
{
  struct arrayElemListAST *sl = malloc(sizeof(struct arrayElemListAST));

  if(!sl) {
    yyerror("out of space");
    exit(0);
  }

  sl->next = next;
  sl->valueAST = a;
  return sl;
}


struct ast * makePushOnArrayAST(struct symbol *name, struct ast * valueToPush)
{
  struct symasgn *a = malloc(sizeof(struct symasgn));

  if(!a) {
    yyerror("out of space");
    exit(0);
  }

  a->nodetype = 'H';
  a->s = name;
  a->v = valueToPush;

  return (struct ast *)a;
}

struct ast * makePopFromArrayAST(struct symbol *name)
{
    struct symref *a = malloc(sizeof(struct symref));

    if(!a) {
      yyerror("out of space");
      exit(0);
    }

    a->nodetype = 'Z';
    a->s = name;

    return (struct ast *)a;
}

struct ast * getSizeOfArrayNameAST(struct symbol *name)
{
    struct symref *a = malloc(sizeof(struct symref));

    if(!a) {
      yyerror("out of space");
      exit(0);
    }

    a->nodetype = 'Q';
    a->s = name;

    return (struct ast *)a;
}

void symlistfree(struct symlist *sl)
{
  struct symlist *nsl;

  while(sl) {
    nsl = sl->next;
    free(sl);
    sl = nsl;
  }
}

void arrayElemListFreeAST(struct arrayElemListAST *sl)
{
  struct arrayElemListAST *nsl;

  while(sl) {
    nsl = sl->next;
    free(sl);
    sl = nsl;
  }
}


/* define a function */
void dodef(struct symbol *name, struct symlist *syms, struct ast *func)
{
  struct symlist *sl;
  int nargs;

  if(name->syms) symlistfree(name->syms);
  if(name->func) treefree(name->func);
  name->syms = syms;
  name->func = func;
  name->type = STT_function;

  sl = syms;
  
  for(nargs = 0; sl; sl = sl->next) {
    nargs++;
    debug_print("NARGS (dodef): %d\n",nargs);
    sl->sym->scope = ST_global;
  }

  name->numberOfArguments = nargs;   
}

// define an array  
void dodefArray(struct symbol *name, struct arrayElemListAST *arrElems)
{
  double *arrDouble;
  int nargs;
  struct arrayElemList *el;

  // if(name->arrElems) arrayElemListFree(name->arrElems);
  name->arrElemsAST = arrElems;
  
  arrDouble = listToArrayDoubleAST(arrElems);
  nargs = countNumberOfListAST(arrElems);

  name->sizeOfArray = nargs;
  name->val.array = arrDouble;
  name->type = STT_array_double;
    
}

// define an array AST
struct ast * dodefArrayAST(struct symbol *name, struct arrayElemListAST *arrElems)
{
    struct arrayDef *a = malloc(sizeof(struct arrayDef));

    if(!a) {
      yyerror("out of space");
      exit(0);
    }

    a->nodetype = 'U';
    a->s = name;
    a->arrElems = arrElems;
    a->s->type = STT_array_double;
    return (struct ast *)a;
    
}

void treefree(struct ast *a)
{
  switch(a->nodetype) {

    /* two subtrees */
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case NT_pow:
  case '^':  case '|':  case 'B':  /* logical binary bitwise operators XOR, OR, AND */
  case NT_lshift: case NT_rshift:  /* logical bitwise left/right shift */
  case '1':  case '2':  case '3':  case '4':  case '5':  case '6':
  case 'L':
  case '&':  case 'O':  /* logical binary operators */
    if(a->r) treefree(a->r);

    /* one subtree */
  case '!': /* logical unary NOT operator */
  case '~': /* logical unary bitwise NOT operator */
  case 'M': case 'C': case 'F': case NT_typexp:
    if(a->l) treefree(a->l);

    /* no subtree */
  case 'K': case 'N': case 'S': case NT_input:
  case 'P': case 'D': /* post increment && post decrement */
  case 'R': case 'E': /* pre increment && pre decrement */
  case 'Z': case 'Q': /* pop on array && length of array */
  case NT_typeof:     /* node typeof */
    break;

  case '=': case 'H': /* asgn or push on array */
  case NT_asgsum: case NT_asgdif: /* asgnsum or asgndif */
  case NT_asgprd: case NT_asgdiv: case NT_asgmod:
    free( ((struct symasgn *)a)->v);
    break;

  case 'I': case 'W': case NT_dowhle: /* if/then/else , while , do/while  */ 
    free( ((struct flow *)a)->cond);
    if( ((struct flow *)a)->tl) free( ((struct flow *)a)->tl);
    if( ((struct flow *)a)->el) free( ((struct flow *)a)->el);
    break;

  case 'X': /* for loop */
    free( ((struct flowFor *)a)->cond);
    if( ((struct flowFor *)a)->tl) free( ((struct flowFor *)a)->tl);
    if( ((struct flowFor *)a)->initialAsgn) free( ((struct flowFor *)a)->initialAsgn);
    if( ((struct flowFor *)a)->finalIncrement) free( ((struct flowFor *)a)->finalIncrement);
    break;

  case 'U':
  /*
    if ( ((struct arrayDef *)a)->s ) free ( ((struct arrayDef *)a)->s );
    if ( ((struct arrayDef *)a)->arrElems )free ( ((struct arrayDef *)a)->arrElems); */
    break;
  case '[':
    free(((struct symarrayel *)a)->index);
    break;
  case ']':
    free(((struct symasgnArray *)a)->index);
    free(((struct symasgnArray *)a)->value);
    break;

  default: printf(KRED "internal error: free bad node %c\n" KNRM, a->nodetype);
  }	  
  
  free(a); /* always free the node itself */

}


