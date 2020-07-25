#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/time.h>
#include "ast.h"
#include "funcs.h"

/***********************************
 ** STATIC FUNCTIONS DECLARATIONS **
 ***********************************
In classic C static functions are functions that are only visible to other functions in the same file 
(more precisely the same translation unit).
*/

/* Function to return a value when a builtin function is called  */
static struct evalValueOfSymbol * callbuiltin(struct fncall *);

/* Function to return a value when a user defined function is called */
static double calluser(struct ufncall *);

/* Function calluser ehnanced for supporting struct */
static struct evalValueOfSymbol * calluserStruct(struct ufncall *);

/*************************************
 ** **** EVAL FUNC DEFINITION  *******
 *************************************/

/* The most important function perhaps: 'eval' is able to walk the ast */

struct evalValueOfSymbol * evalStruct(struct ast *a)
{
  double v;
  char *c;
  char *e;
  double *arrDoub;
  valueOfSymbol vos; 
  struct evalValueOfSymbol *evos = malloc(sizeof(struct evalValueOfSymbol));
  double arrElement;
  int index; 
  int *flag;

  int i;

  int sizeOfArray = 0;

  enum symbTableType type; 

  struct evalValueOfSymbol *evosL = malloc(sizeof(struct evalValueOfSymbol));
  struct evalValueOfSymbol *evosR = malloc(sizeof(struct evalValueOfSymbol));
  if(!evosL || !evosR) {
    yyerror("out of space");
    exit(0);
  }
  /*
  struct evalValueOfSymbol *evosCond = malloc(sizeof(struct evalValueOfSymbol));
  struct evalValueOfSymbol *evosTl = malloc(sizeof(struct evalValueOfSymbol));
  struct evalValueOfSymbol *evosEl = malloc(sizeof(struct evalValueOfSymbol));
*/
  flag = malloc(sizeof(int));

  if(!a) {
    yyerror("Internal error, null eval");
    return evos;
  }

  switch(a->nodetype) {
    /* constant */
  case 'K': v = ((struct numval *)a)->number;
            vos.value = v;
            type = STT_double;
            break;

    /* string */ 
  case 'S': 
  // case NT_string: 
            c = ((struct stringval *)a)->str; 
            vos.stringValue = c;
            type = STT_string;
            break;

    /* name reference */
  case 'N': 
            if (((struct symref *)a)->s->type == STT_double) {
                v = ((struct symref *)a)->s->val.value; 
                vos.value = v;
                type = STT_double; 
            } else if (((struct symref *)a)->s->type == STT_string) {
                c = ((struct symref *)a)->s->val.stringValue; 
                vos.stringValue = c;
                type = STT_string;
            } else if ( ((struct symref *)a)->s->type == STT_array_double) {
                arrDoub = malloc(sizeof(double) * ((struct symref *)a)->s->sizeOfArray);
                    for(i = 0; i < ((struct symref *)a)->s->sizeOfArray; i++) {
                      arrDoub[i] = ((struct symref *)a)->s->val.array[i];
                      debug_print("STT_array_double [%d]: %4.4g\n", i, ((struct symref *)a)->s->val.array[i]);
                    }
                // arrDoub = ((struct symref *)a)->s->val.array;
                vos.array = arrDoub;
                type = STT_array_double;
                sizeOfArray = ((struct symref *)a)->s->sizeOfArray;
            } else if (((struct symref *)a)->s->type == STT_NaN) {
                type = STT_NaN;
            } else if ( ((struct symref *)a)->s->type == STT_function) {
                debug_print("Type of reference: STT_function, '%s'\n", ((struct symref *)a)->s->name);
                asprintf(&vos.stringValue, "%s", ((struct symref *)a)->s->name );
                type = STT_function;
            } else if ( ((struct symref *)a)->s->type == STT_NOTYPE) {
                if ( ((struct symref *)a)->s->scope == ST_function ) {
                    v = ((struct symref *)a)->s->val.value; 
                    vos.value = v;
                    type = STT_double;
                } else {
                    yyerror("Semantic error. Referencing variable: '%s' with no type.", ((struct symref *)a)->s->name);
                }        
            }
            break;

    /* post increment operator */
  case 'P': if ( ((struct symref *)a)->s->type == STT_double || ((struct symref *)a)->s->scope == ST_function ) {
              v = ((struct symref *)a)->s->val.value; 
              vos.value = v;
              ((struct symref *)a)->s->val.value++; 
              type = STT_double;
            } else {
              yyerror("Semantic error. Post increment cannot be applied to NON-double identifiers.");
              type = STT_NaN;
            }
            
            break;
  
      /* post decrement operator */
  case 'D': if ( ((struct symref *)a)->s->type == STT_double || ((struct symref *)a)->s->scope == ST_function ) {
              v = ((struct symref *)a)->s->val.value; 
              vos.value = v;
              ((struct symref *)a)->s->val.value--; 
              type = STT_double;
            } else {
              yyerror("Semantic error. Post decrement cannot be applied to NON-double identifiers.");
              type = STT_NaN;
            }
            break;

      /* pre increment operator */
  case 'R': if ( ((struct symref *)a)->s->type == STT_double || ((struct symref *)a)->s->scope == ST_function ) {
              ((struct symref *)a)->s->val.value++;
              v = ((struct symref *)a)->s->val.value; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Pre increment cannot be applied to NON-double identifiers.");
              type = STT_NaN;
            }
            break;

       /* pre decrement operator */
  case 'E': if ( ((struct symref *)a)->s->type == STT_double || ((struct symref *)a)->s->scope == ST_function ) {
              ((struct symref *)a)->s->val.value--;
              v = ((struct symref *)a)->s->val.value; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Pre decrement cannot be applied to NON-double identifiers.");
              type = STT_NaN;
            }
            break;

    /* get array element */
  case '[': 
            v = checkRangeAndType( ((struct symarrayel *)a)->s, ((struct symarrayel *)a)->index, flag);
            if ( ((struct symarrayel *)a)->s->type == STT_array_double ) {
              vos.value = v;
              type = STT_double;
            } else if  ( ((struct symarrayel *)a)->s->type == STT_string ) {
              asprintf(&vos.stringValue, "%c", (int)v);
              type = STT_string;
            }
            
        break;

    /* set array element */
  case ']':
            arrElement = evalStruct( ((struct symasgnArray *)a)->value )->val.value;
            index = (int)evalStruct( ((struct symasgnArray *)a)->index )->val.value;
            v = checkRangeAndTypeNoEval( ((struct symasgnArray *)a)->s, index, flag ); 
            if (*flag) {
              replaceElement(index, arrElement, &(((struct symasgnArray *)a)->s));
              vos.value = arrElement;
              debug_print("flag = True. case ']' vos.value =, %4.4g\n", vos.value);
            } else {
              if (((struct symasgnArray *)a)->s->type == STT_string) {
                yyerror("Semantic error. '%s' is string, invalid operation", ((struct symasgnArray *)a)->s->name);
              }
              vos.value = 0;
              debug_print("flag = False. case ']' vos.value =, %4.4g\n", vos.value);
            }        
            type = STT_double; 
        break;

  // push operation for array
  case 'H':
        if (((struct symasgn *)a)->s->type == STT_array_double) {
          v = makePushOnArray( ((struct symasgn *)a)->s, ((struct symasgn *)a)->v);
        } else {
          v = 0;
          yyerror("Semantic error. Trying to make push on non-array variable: '%s'", ((struct symasgn *)a)->s->name);
        }
        vos.value = v;
        type = STT_double;
        break;

  // pop operation for array
  case 'Z':
        if ( ((struct symref *)a)->s->type == STT_array_double) {
          if ( ((struct symref *)a)->s->sizeOfArray > 0 ) {
            v = makePopFromArray( ((struct symref *)a)->s);
          } else {
            v = 0;
            yyerror("Semantic error. Trying to make pop on empty array: '%s'", ((struct symref *)a)->s->name);
          }     
        } else {
          v = 0;
          yyerror("Semantic error. Trying to make pop on non-array variable: '%s'", ((struct symref *)a)->s->name);
        }
        vos.value = v;
        type = STT_double;
        break;

  // get length of array
  case 'Q':
        if ( ((struct symref *)a)->s->type == STT_array_double )   {
          v = getSizeOfArrayName( ((struct symref *)a)->s);
        } else if ( ((struct symref *)a)->s->type == STT_string  ) {
          v = strlen( ((struct symref *)a)->s->val.stringValue );
        } else {
          v = 0;
          yyerror("Semantic error. Trying to get length on non-array variable: '%s'", ((struct symref *)a)->s->name);
        }
        vos.value = v;
        type = STT_double;
        break;

  // get type of variable
  case NT_typeof:
        v = getTypeOf(((struct symref *)a)->s);
        vos.value = v;
        type = STT_double;
        break;

  case NT_typexp:
        v = getTypeOfExp(a->l);
        vos.value = v;
        type = STT_double;
        break;
    /* assignment */
  // case '=': v = ((struct symasgn *)a)->s->value = evalStruct(((struct symasgn *)a)->v); break;

  case '=': evos = evalStruct(((struct symasgn *)a)->v);
            switch (evos->type) {
                case STT_double:
                    v = ((struct symasgn *)a)->s->val.value = evos->val.value; 
                    vos.value = v;
                    type = STT_double;
                    debug_print("%s has type STT_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
                break;
                case STT_string: case STT_string_no:
                    structToString(&c, evos); 
                    ((struct symasgn *)a)->s->val.stringValue = strdup(c);     
                    vos.stringValue = strdup(c);                 
                    type = STT_string;
                    debug_print("case '=': '%s' has type STT_string in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
                break;
                case STT_array_double:
                    ((struct symasgn *)a)->s->sizeOfArray = evos->sizeOfArray;
                    debug_print("SizeOfArray: %d\n", evos->sizeOfArray);
                    ((struct symasgn *)a)->s->val.array = malloc(sizeof(double) * evos->sizeOfArray);
                    for(i = 0; i < ((struct symasgn *)a)->s->sizeOfArray; i++) {
                      ((struct symasgn *)a)->s->val.array[i] = evos->val.array[i];
                      debug_print("'=' STT_array_double [%d]: %4.4g\n", i, ((struct symasgn *)a)->s->val.array[i]);
                    }
                    ((struct symasgn *)a)->s->type = evos->type;
                    debug_print("%s has type STT_array_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
                    return evos;
                break;
                case STT_function:                  
                    debug_print("STT_function\n");
                    yyerror("Semantic error. Trying to assign function to other variable");
                
                case STT_NaN:
                    type = STT_NaN;
                    evos->type = STT_NaN;
                    debug_print("%s has type STT_NaN in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);  
                break;
                case STT_NOTYPE:
                    yyerror("Semantic error. It is not possible assign NOTYPE to '%s'", ((struct symasgn *)a)->s->name);
                break;
                case STT_just_asgn: 
                break;
            }
            
            ((struct symasgn *)a)->s->type = type;
            evos->val = vos;
            evos->type = type;
            return evos;

            break;

  case NT_asgsum: 
            evos = evalStruct(a->r);
            if ( ((struct symasgn *)a)->s->type == STT_double && evos->type == STT_double) {
                v = ((struct symasgn *)a)->s->val.value += evalStruct(((struct symasgn *)a)->v)->val.value; 
                vos.value = v;
                type = STT_double;
                debug_print("%s has type STT_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
            }   else {
                char *al;
                char *ar;
            
                symbolToString(&al, ((struct symasgn *)a)->s);
       
                structToString(&ar, evos);
                asprintf(&c, "%s%s", al, ar);
                debug_print("Result of asprintf: '%s'\n", c);
                ((struct symasgn *)a)->s->val.stringValue = c;
                type = STT_string;
                ((struct symasgn *)a)->s->type = type;
                vos.stringValue = c;
                debug_print("%s has type STT_string in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
            }   
            break;
  case NT_asgdif: 
            evos = evalStruct(a->r);
            if ( ((struct symasgn *)a)->s->type == STT_double && evos->type == STT_double ) {
                v = ((struct symasgn *)a)->s->val.value -= evalStruct(((struct symasgn *)a)->v)->val.value; 
                vos.value = v;
                type = STT_double;
                debug_print("%s has type STT_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
            }   else {
                type = STT_NaN;
                ((struct symasgn *)a)->s->type = type;
            }   
            break;
  case NT_asgprd: 
            if ( ((struct symasgn *)a)->s->type == STT_double && (evalStruct(a->r)->type == STT_double) ) {
                v = ((struct symasgn *)a)->s->val.value *= evalStruct(((struct symasgn *)a)->v)->val.value; 
                vos.value = v;
                type = STT_double;
                debug_print("%s has type STT_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
            }   else {         
                type = STT_NaN;
                ((struct symasgn *)a)->s->type = type;
            }   
            break;
  case NT_asgdiv: 
            if ( ((struct symasgn *)a)->s->type == STT_double && (evalStruct(a->r)->type == STT_double) ) {
                v = ((struct symasgn *)a)->s->val.value /= evalStruct(((struct symasgn *)a)->v)->val.value; 
                vos.value = v;
                type = STT_double;
                debug_print("%s has type STT_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
            }   else {

                type = STT_NaN;
                ((struct symasgn *)a)->s->type = type;
            }   
            break;
  case NT_asgmod: 
            if ( ((struct symasgn *)a)->s->type == STT_double && (evalStruct(a->r)->type == STT_double) ) {
                v = fmod(((struct symasgn *)a)->s->val.value, evalStruct(((struct symasgn *)a)->v)->val.value); // v = a->s % a->v // a-> = v
                ((struct symasgn *)a)->s->val.value = v;
                vos.value = v;

                type = STT_double;
                debug_print("%s has type STT_double in SYMBOL TABLE!\n", ((struct symasgn *)a)->s->name);
            }   else {
            
                type = STT_NaN;
                ((struct symasgn *)a)->s->type = type;
            }
            break;

    /* expressions */
  case '+': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if ( (evosL->type == STT_double) && ( evosR->type == STT_double) ) {
                v = evosL->val.value + evosR->val.value; 
                vos.value = v;
                type = STT_double;
            } else {
                char *al;
                char *ar;
                structToString(&al, evosL);
                structToString(&ar, evosR);
                asprintf(&c, "%s%s", al, ar);
    
                vos.stringValue = c;
                type = STT_string;
            }
            break;
  case '-': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if ( (evosL->type == STT_double) && (evosR->type == STT_double) ) {
                v = evosL->val.value - evosR->val.value;
                vos.value = v;
                type = STT_double;
            } else {
                type = STT_NaN;
            }
            break;
  case '*': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if ( (evosL->type == STT_double) && (evosR->type == STT_double) ) {
                v = evosL->val.value * evosR->val.value;
                vos.value = v;
                type = STT_double;
            } else {
                type = STT_NaN;
            }
            break;
  case '/': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if ( (evosL->type == STT_double) && (evosR->type == STT_double) ) {
                v = evosL->val.value / evosR->val.value;
                vos.value = v;
                type = STT_double;
            } else {
                type = STT_NaN;
            }
            break;

            /* exponentiation */
  case NT_pow: 
            evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if ( (evosL->type == STT_double) && ( evosR->type == STT_double) ) {
                v = pow(evosL->val.value, evosR->val.value); 
                vos.value = v;
                type = STT_double;
            } else {
                type = STT_NaN;
            }
            break;

  case '%': 
            evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if ( (evosL->type == STT_double) && (evosR->type == STT_double) ) {
                v = fmod( evosL->val.value, evosR->val.value); 
                vos.value = v;
                type = STT_double;
            } else {
                type = STT_NaN;
            }
            break;    

              /* unary minus */       
  case 'M': evosL = evalStruct(a->l);
            if ( evosL->type == STT_double ) {
                v = -(evosL->val.value);
                vos.value = v;
                type = STT_double;
            } else {
                type = STT_NaN;
            }
            break;

            /* bitwise xor */
  case '^': v = ((int)((evalStruct(a->l)->val.value)) ^ ((int)(evalStruct(a->r)->val.value))); 
            vos.value = v;
            type = STT_double;
            break;           

            /* bitwise and */
  case 'B': v = ((int)((evalStruct(a->l)->val.value)) & ((int)(evalStruct(a->r)->val.value))); 
            vos.value = v;
            type = STT_double;
            break;           
            /* bitwise or */           
  case '|': v = ((int)((evalStruct(a->l)->val.value)) | ((int)(evalStruct(a->r)->val.value))); 
            vos.value = v;
            type = STT_double;
            break;        
            /* bitwise not */
  case '~': v = ~((int)((evalStruct(a->l)->val.value))); 
            vos.value = v;
            type = STT_double;
            break;        
            /* bitwise left shift */
  case NT_lshift: v = ((int)((evalStruct(a->l)->val.value)) << ((int)(evalStruct(a->r)->val.value))); 
            vos.value = v;
            type = STT_double;
            break;  
            /* bitwise right shift */   
  case NT_rshift: v = ((int)((evalStruct(a->l)->val.value)) >> ((int)(evalStruct(a->r)->val.value))); 
            vos.value = v;
            type = STT_double;
            break;  

    /* logical expression */
  case '&': v = evalStruct(a->l)->val.value && evalStruct(a->r)->val.value; 
            vos.value = v;
            type = STT_double;
            break;
  case 'O': v = evalStruct(a->l)->val.value || evalStruct(a->r)->val.value; 
            vos.value = v;
            type = STT_double;
            break;
  case '!': v = !evalStruct(a->l)->val.value; 
            vos.value = v;
            type = STT_double;
            break;

    /* comparisons */
  case '1': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if (evosL->type == STT_double && evosR->type == STT_double) {
              v = (evosL->val.value > evosR->val.value)? 1 : 0; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Trying to compare NON STT_double variables. Always return FALSE");
              vos.value = 0.0; 
              type = STT_double;  
            }           
            break;
  case '2': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if (evosL->type == STT_double && evosR->type == STT_double) {
              v = (evosL->val.value < evosR->val.value)? 1 : 0; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Trying to compare NON STT_double variables. Always return FALSE");
              vos.value = 0.0; 
              type = STT_double;  
            }         
         
            break;
  case '3': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if (evosL->type == STT_double && evosR->type == STT_double) {
              v = (evosL->val.value != evosR->val.value)? 1 : 0; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Trying to compare NON STT_double variables. Always return FALSE");
              vos.value = 0.0; 
              type = STT_double;  
            }           
            break;
  case '4': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if (evosL->type == STT_double && evosR->type == STT_double) {
              v = (evosL->val.value == evosR->val.value)? 1 : 0; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Trying to compare NON STT_double variables. Always return FALSE");
              vos.value = 0.0; 
              type = STT_double;  
            }           
            break;
  case '5': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if (evosL->type == STT_double && evosR->type == STT_double) {
              v = (evosL->val.value >= evosR->val.value)? 1 : 0; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Trying to compare NON STT_double variables. Always return FALSE");
              vos.value = 0.0; 
              type = STT_double;  
            }           
            break;
  case '6': evosL = evalStruct(a->l);
            evosR = evalStruct(a->r);
            if (evosL->type == STT_double && evosR->type == STT_double) {
              v = (evosL->val.value <= evosR->val.value)? 1 : 0; 
              vos.value = v;
              type = STT_double;
            } else {
              yyerror("Semantic error. Trying to compare NON STT_double variables. Always return FALSE");
              vos.value = 0.0; 
              type = STT_double;  
            }           
            break;

  /* control flow */
  /* null if/else/do expressions allowed in the grammar, so check for them */
  case 'I':
    evosL = evalStruct( ((struct flow *)a)->cond );
    if ( evosL->val.value != 0) {
      if( ((struct flow *)a)->tl) {
          evosR = evalStruct( ((struct flow *)a)->tl);
          debug_print("if YES if YES \n");
      } else {
          evosR->val.value = 0.0; // a default value 
          evosR->type = STT_NaN;
          evosR->sizeOfArray = 0;
          debug_print("if YES if NO \n");
      }
          
    } else {
        if( ((struct flow *)a)->el) {
          evosR = evalStruct(((struct flow *)a)->el);
          debug_print("if NO if YES \n");
        } else {
          evosR->val.value = 0.0;		// a default value 
          evosR->type = STT_NaN;
          evosR->sizeOfArray = 0;
          debug_print("if NO if NO \n");
        }
          
      }
    type = evosR->type;
    sizeOfArray = evosR->sizeOfArray;
    vos = evosR->val;
    break;

  /* while loop */
  case 'W':
    v = 0.0;		/* a default value */
    evosR->val.value = v;
    if( ((struct flow *)a)->tl) {
      while( evalStruct(((struct flow *)a)->cond)->val.value != 0)
        evosR =  evalStruct(((struct flow *)a)->tl);
      }
  
    type = evosR->type;
    sizeOfArray = evosR->sizeOfArray;
    vos = evosR->val;
    break;			/* last value is value */
	
  /* do while loop */
  case NT_dowhle: 
    v = 0.0;		/* a default value */
    evosR->val.value = v;

    if( ((struct flow *)a)->tl) {
      do {
        evosR = evalStruct(((struct flow *)a)->tl);
      } while( evalStruct(((struct flow *)a)->cond)->val.value != 0);
        
    }

    type = evosR->type;
    sizeOfArray = evosR->sizeOfArray;
    vos = evosR->val;
    break;			/* last value is value */

  /* for loop */
  case 'X':
    v = 0.0;		/* a default value */
    evosR->val.value = v;

    if( ((struct flow *)a)->tl) {  
      evalStruct(((struct flowFor *)a)->initialAsgn); // i = 0
      while( evalStruct(((struct flow *)a)->cond)->val.value != 0) { // i < n
        evosR = evalStruct(((struct flow *)a)->tl);
        evalStruct(((struct flowFor *)a)->finalIncrement); // i++
      }    
    }
  
    type = evosR->type;
    sizeOfArray = evosR->sizeOfArray;
    vos = evosR->val;
    break;			/* last value is value */

  /* list of instructions */
  case 'L': evosL = evalStruct(a->l); 
            evosR = evalStruct(a->r);
            return evosR;
            break;

  /* call to builtin function */
  case 'F': evos = callbuiltin((struct fncall *)a);
            return evos;
            break;

  /* call to user defined function */
  case 'C': if( ((struct ufncall *)a)->s->type == STT_function ) {
              evos = calluserStruct((struct ufncall *)a);
              return evos;
            } else {
              yyerror("Semantic error. The identifier '%s' is not a function", ((struct ufncall *)a)->s->name);
              evos->sizeOfArray = 0;
              evos->type = STT_NOTYPE;
              return evos;
            }
              
            break;

  /* call to input function */
  case NT_input: 
            c = malloc(sizeof(char) * INPUTBUFFER);

            // prepare to save current yyin
            fflush(yyin);
            fgetpos(yyin, &pos);
            fd = dup(fileno(yyin));
            // redirecting yyin to shell
            freopen(TTYSHELL, "r", yyin);   

            printf(KYEL "Input  => " KNRM);
            fgets(c, INPUTBUFFER, yyin);

            // setting back precedent yyin
            fflush(yyin);
            dup2(fd, fileno(yyin));
            close(fd);
            clearerr(yyin);
            fsetpos(yyin, &pos);

            // check if input is double
            errno = 0;
            v = strtod(c, &e);
            if ( (*e == '\0') || (isspace(*e) != 0) ) {
              evos->type = STT_double;
              evos->val.value = v; 
              evos->sizeOfArray = 0;
            } else {
              evos->type = STT_string;
              evos->val.stringValue = strtok(c, "\n");
              evos->sizeOfArray = strlen(c);
            }           
   
            free(c);
            debug_print("Scan value evos->val.value: %4.4g\n", evos->val.value );
            return evos;

            break;

  case 'U': debug_print("Node of type 'U'\n");
          dodefArray( ((struct arrayDef *)a)->s, ((struct arrayDef *)a)->arrElems );
          vos.array = ((struct arrayDef *)a)->s->val.array;
          type = STT_array_double;
          sizeOfArray = ((struct arrayDef *)a)->s->sizeOfArray;
          break;

  default: printf(KRED "internal error (evalStruct): bad node '%c'\n" KNRM, a->nodetype);
  }
  
  if(evosL)     free(evosL);
  if(evosR)     free(evosR);
  /*
  if(evosCond)  free(evosCond);
  if(evosTl)    free(evosTl);
  if(evosEl)    free(evosEl);*/

  
  evos->val = vos;
  evos->type = type;
  evos->sizeOfArray = sizeOfArray;
  debug_print("Return evos. Type: '%d', SizeOfArray: '%d'\n", evos->type, evos->sizeOfArray);
  return evos;
}

/***********************************
 ** STATIC FUNCTIONS DEFINITIONS ***
 ***********************************/
/*
 * ATTENTION
 * After this point there are the static function
 * C static functions cannot be colled outstide of this file
 */

static struct evalValueOfSymbol * callbuiltin(struct fncall *f)
{
  enum bifs functype = f->functype;
  double v;
  char *s;
  valueOfSymbol vos;
  
  char *printStr;

  struct evalValueOfSymbol *evos = malloc(sizeof(struct evalValueOfSymbol));
  evos = evalStruct(f->l);
  enum symbTableType type; 
  vos = evos->val;
  if (functype == B_printstr) s = vos.stringValue;
  else v = vos.value;
  
  struct timeval t1;
  gettimeofday(&t1, NULL);
  srand(t1.tv_usec * t1.tv_sec);

 switch(functype) {
 case B_sqrt:
    vos.value = sqrt(v);
    type = STT_double;
    break;
 case B_exp:
    vos.value = exp(v);
    type = STT_double;
    break;
 case B_log:
    vos.value = log(v);
    type = STT_double;
    break;
 case B_print:
    asprintf(&s, "%f", v);
    v = atof(s);
    printf(KBLU "OutputInt => %4.4g\n" KNRM, v);
    vos.value = v;
    type = STT_double;
    break;
 case B_rand:
    if (v == 0) {
      vos.value = 0;
    } else {
      vos.value = (int)rand() % (int)v;
    }    
    type = STT_double;
    break;
 case B_abs:
    vos.value = abs((int)v);
    type = STT_double;
    break;

 case B_printstr:
    structToString(&printStr, evos);
    vos.stringValue = strdup(printStr);
    printf(KMAG "Output <= " KNRM);
    printf(KGRE "'%s'\n" KNRM, printStr);
    type = STT_string_no;
    break;
 
 default:
    yyerror("Internal error. Unknown built-in function '%d'", functype);
    vos.value = 0.0;
 
    type = STT_NaN;
    break;
 }
 evos->type = type;
 evos->val = vos;
 return evos;
}

static double calluser(struct ufncall *f)
{
  struct symbol *fn = f->s;	/* function name */
  struct symlist *sl;		    /* dummy arguments */
  struct ast *args = f->l;	/* actual arguments */
  struct ast *al;           
  double *oldval, *newval;	/* saved arg values */
  double v;
  int nargs;
  int actualArgs;          
  int i;

  if(!fn->func) {
    yyerror("Internal error. Call to undefined built-in function", fn->name);
    return 0;
  }

  /* count the arguments */
  sl = fn->syms;
  for(nargs = 0; sl; sl = sl->next)
    nargs++;

  /* Calculate the depth of AST of parameters */
  al = args;
  /* Label each node with its depth */
  updateDepth(al, 0);
  /* Get number of actual arguments by getting tree depth */
  
  actualArgs = getChildrenOfTree(al);
  debug_print("Depth of tree of actual arguments: %d\n", actualArgs);
  actualArgs++;
  debug_print("Actual arguments: %d\n", actualArgs);
  
  /* check if the number of arguments is correct */
  
  if (f->s->numberOfArguments == actualArgs) { 
    debug_print("Correct number of arguments: %d\n", f->s->numberOfArguments);
  } else {
    yyerror("Semantic error. Mismatch in number of args in call to '%s'. Expected: '%d', Found: '%d'", fn->name, f->s->numberOfArguments, actualArgs);
    return 0.0;
  }

  /* prepare to save them */
  oldval = (double *)malloc(nargs * sizeof(double));
  newval = (double *)malloc(nargs * sizeof(double));
  if(!oldval || !newval) {
    yyerror("Out of space in %s", fn->name); return 0.0;
  }
  
  /* evaluate the arguments */
  for(i = 0; i < nargs; i++) {
    if(!args) {
      yyerror("Semantic error. Too few arguments in call to '%s'", fn->name);
      free(oldval); free(newval);
      return 0;
    }

    if(args->nodetype == 'L') {	/* if this is a list node */
      // newval[i] = eval(args->l).value;
      newval[i] = evalStruct(args->l)->val.value;
      debug_print("args->nodetype == L: newval[%d] = %4.4g\n", i, newval[i]);
      args = args->r;
    } else {			/* if it's the end of the list */
      // newval[i] = eval(args).value;
      newval[i] = evalStruct(args)->val.value;
      debug_print("args->nodetype != L: newval[%d] = %4.4g\n", i, newval[i]);
      args = NULL;
    }
  }
		     
  /* save old values of dummies, assign new ones */
  sl = fn->syms;
  for(i = 0; i < nargs; i++) {
    struct symbol *s = sl->sym;
    oldval[i] = s->val.value;
    s->val.value = newval[i];
    sl = sl->next;
  }

  free(newval);

  /* evaluate the function */
  /* 
   * fn is a pointer to function in symbol table  
   * fn->func is a pointer to ast which contains the list of stmts for fn
   */
  // v = eval(fn->func).value;
  v = evalStruct(fn->func)->val.value;
  debug_print("The value is: %4.4g\n", v);

  /* put the dummies back */
  sl = fn->syms;
  for(i = 0; i < nargs; i++) {
    struct symbol *s = sl->sym;

    s->val.value = oldval[i];
    sl = sl->next;
  }

  free(oldval);
  return v;
}


static struct evalValueOfSymbol * calluserStruct(struct ufncall *f)
{
  struct symbol *fn = f->s;	/* function name */
  struct symlist *sl;		    /* dummy arguments */
  struct ast *args = f->l;	/* actual arguments */
  struct ast *al;           

  struct evalValueOfSymbol *oldevos; // = malloc(sizeof(struct evalValueOfSymbol));  /* old args evos */ 
  struct evalValueOfSymbol *newevos; // = malloc(sizeof(struct evalValueOfSymbol));  /* new args evos */

  double v;
  int nargs;
  int actualArgs;          
  int i;

  struct evalValueOfSymbol *evos = malloc(sizeof(struct evalValueOfSymbol));
  char *strPrint;

  if(!fn->func) {
    yyerror("Semantic error. Call to undefined function", fn->name);
    evos->val.value = 0.0;
    evos->type = STT_NOTYPE;
    evos->sizeOfArray = 0;
    return evos;
  }

  /* count the arguments */
  sl = fn->syms;
  for(nargs = 0; sl; sl = sl->next)
    nargs++;

  /* Calculate the depth of AST of parameters */
  al = args;
  /* Label each node with its depth */
  updateDepth(al, 0);
  /* Get number of actual arguments by getting tree depth */
  
  if(f->l) { 
    actualArgs = getChildrenOfTree(al);
    debug_print("Depth of tree of actual arguments: %d\n", actualArgs);
    actualArgs++;
    debug_print("Actual arguments: %d\n", actualArgs);
  } else {
    actualArgs = 0;
  }
  
  /* check if the number of arguments is correct */
  
  if (f->s->numberOfArguments == actualArgs) { 
    debug_print("Correct number of arguments: %d\n", f->s->numberOfArguments);
  } else {
    yyerror("Semantic error. Mismatch in number of args in call to '%s'. Expected: '%d', Found: '%d'", fn->name, f->s->numberOfArguments, actualArgs);
    // return 0.0;
    evos->val.value = 0.0;
    evos->type = STT_NOTYPE;
    evos->sizeOfArray = 0;
    return evos;
  }

  /* prepare to save them */

  /* evos values */
  oldevos = malloc(nargs * sizeof(struct evalValueOfSymbol));
  newevos = malloc(nargs * sizeof(struct evalValueOfSymbol));
  
  if(!oldevos || !newevos) {
    yyerror("Out of space in %s", fn->name); 
    evos->val.value = 0.0;
    evos->type = STT_NOTYPE;
    return evos;
  }

  /* evaluate the arguments */
  for(i = 0; i < nargs; i++) {
    if(!args) {
      yyerror("Semantic error. Too few args in call to '%s'", fn->name);
      free(oldevos); free(newevos);
      return 0;
    }

    if(args->nodetype == 'L') {	/* if this is a list node */
      newevos[i] = *evalStruct(args->l);
      structToString(&strPrint, &newevos[i]);
      debug_print("args->nodetype == L: newevos[%d] = %s\n", i, strPrint);
      args = args->r;
    } else {			/* if it's the end of the list */
      newevos[i] = *evalStruct(args);
      structToString(&strPrint, &newevos[i]);
      debug_print("args->nodetype == L: newevos[%d] = %s\n", i, strPrint);
      args = NULL;
    }
  }
		     
  /* save old values of dummies, assign new ones */

  sl = fn->syms;
  for(i = 0; i < nargs; i++) {
    struct symbol *s = sl->sym;

    oldevos[i].val = s->val;
    oldevos[i].sizeOfArray = s->sizeOfArray;
    oldevos[i].type = s->type;

    s->val = newevos[i].val;
    s->sizeOfArray = newevos[i].sizeOfArray;
    s->type = newevos[i].type;

    sl = sl->next;
  }

  free(newevos);

  /* evaluate the function */
  /* 
   * fn is a pointer to function in symbol table  
   * fn->func is a pointer to ast which contains the list of stmts for fn
   */

  evos = evalStruct(fn->func);
  debug_print("The type of evos is: '%d'\n", evos->type);
  structToString(&strPrint, evos);

  debug_print("The value is: %s\n", strPrint);

  /* put the dummies back */
  sl = fn->syms;
  for(i = 0; i < nargs; i++) {
    struct symbol *s = sl->sym;

    s->val = oldevos[i].val;
    s->sizeOfArray = oldevos[i].sizeOfArray;
    s->type = oldevos[i].type;

    sl = sl->next;
  }

  free(oldevos);

  return evos;
}
