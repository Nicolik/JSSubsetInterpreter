/*****************
 **** FUNCS.C **** 
 *****************
 
 * Questo file C contiene:
 * - Definizioni di funzioni di utilità
 
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "ast.h"
#include "funcs.h"

void handleOutputSwitchStruct(struct ast *a) 
{
  struct evalValueOfSymbol *evos = malloc(sizeof(struct evalValueOfSymbol));
  evos = evalStruct(a);
  debug_print("handleOutputSwitchStruct. Type: '%d'\n", evos->type);
  char *strPrint;
  structToString(&strPrint, evos);
  if (evos->type == STT_string) {
    printf(KGRE "= '%s'\n", strPrint);
  } else if (evos->type == STT_string_no) {
      
  } else {
    printf(KBLU "= %s\n", strPrint);
  }
  free(evos);
}

int countNumberOfListAST(struct arrayElemListAST *arrElems)
{
    int nargs;
    int i;
    double *arrayOfDouble;
    struct arrayElemListAST *arrayElems;
    struct arrayElemListAST *arrayElems2;
    arrayElems2 = arrayElems = arrElems;
    for(nargs = 0; arrayElems; arrayElems = arrayElems->next) {
        nargs++;
        debug_print("Passo: %d\n", nargs);
    }
    return nargs;
}

void printArrayDouble(double *dArr, int sizeOfArray) 
{
  int i;
  if (sizeOfArray > 0) {
      printf(KBLU "[");
    for (i = 0; i < sizeOfArray-1; i++) {
        printf("%4.4g, ", dArr[i]);
    }
    printf("%4.4g ]\n", dArr[sizeOfArray-1]);
  } else if (sizeOfArray == 0) {
      printf(KBLU "[]");
  } else {
      yyerror("Internal error: trying to print array with negative size");
  }
  
}

void sprintArrayDouble(double *dArr, int sizeOfArray, char *str) 
{
  int i;
  if (sizeOfArray > 0) {
      sprintf(str, "[");
    for (i = 0; i < sizeOfArray-1; i++) {
        sprintf(str, "%s%4.4g, ", str, dArr[i]);
    }
    sprintf(str, "%s%4.4g ]", str, dArr[sizeOfArray-1]);
    debug_print("sprintArrayDouble %s\n", str);
  } else if (sizeOfArray == 0) {
      sprintf(str, "[]");
  } else {
      yyerror("Internal error: trying to print array with negative size");
      sprintf(str, "[]");
  }
  
}

void asprintArrayDouble(double *dArr, int sizeOfArray, char **str) 
{
  int i;
  if (sizeOfArray > 0) {
      asprintf(str, "[");
    for (i = 0; i < sizeOfArray-1; i++) {
        asprintf(str, "%s%4.4g, ", *str, dArr[i]);
    }
    asprintf(str, "%s%4.4g ]", *str, dArr[sizeOfArray-1]);
    debug_print("sprintArrayDouble %s\n", *str);
  } else if (sizeOfArray == 0) {
      asprintf(str, "[]");
  } else {
      asprintf(str, "[]");
      yyerror("Internal error: trying to print array with negative size");
  }
}


double * listToArrayDoubleAST(struct arrayElemListAST *arrElems) 
{
    int nargs;
    int i;
    double *arrayOfDouble;
    struct evalValueOfSymbol *evos;

    struct arrayElemListAST *arrayElems;
    struct arrayElemListAST *arrayElems2;

    if (arrElems) {

        arrayElems2 = arrayElems = arrElems;

        for(nargs = 0; arrayElems; arrayElems = arrayElems->next) {
            nargs++;
            debug_print("Passo: %d\n", nargs);
        }
        
        arrayOfDouble = malloc(nargs * (sizeof(double)));
        evos = malloc(nargs * (sizeof(struct evalValueOfSymbol)));
        for (i = 0; i < nargs; i++) {
            evos = evalStruct(arrayElems2->valueAST);
            if (evos->type == STT_double) {
                arrayOfDouble[i] = evos->val.value;
            } else {
                yyerror("Semantic error. Trying to insert non-double element in array. Forcing to 0.");
                arrayOfDouble[i] = 0;
            }
            arrayElems2 = arrayElems2->next;
        }
    } else {
        arrayOfDouble = malloc(sizeof(double));
        *arrayOfDouble = 0;
    }
    return arrayOfDouble;
}

void symbolToString(char **dest, struct symbol *s)
{
    switch (s->type) {
        case STT_double:
            // asprintf(dest, "%4.4g", s->val.value);
            asprintf(dest, "%4.4g", s->val.value);
        break;
        case STT_array_double:
            asprintArrayDouble(s->val.array, s->sizeOfArray, dest);
        break;
        case STT_string:
            *dest = strdup(s->val.stringValue);
        break;
        case STT_NaN:
            asprintf(dest, "NaN");
        break;
        case STT_function:
            asprintf(dest, "[Function: %s]", s->name);
        break;
        case STT_NOTYPE:
            yyerror("Internal error. Trying to convert symbol with NOTYPE: '%s", s->name);
        break;
        default:
            yyerror("Internal error. Trying to convert symbol with NOTYPE (default): '%s", s->name);
        break;
    }
}

void structToString(char **dest, struct evalValueOfSymbol *s)
{
    switch (s->type) {
        case STT_double:
            asprintf(dest, "%4.4g", s->val.value);
        break;
        
        case STT_array_double:
            asprintArrayDouble(s->val.array, s->sizeOfArray, dest);
        break;
        
        case STT_string:
            *dest = strdup(s->val.stringValue);
        break;

        case STT_string_no:
            *dest = "";
        break;

        case STT_NaN:
            asprintf(dest, "NaN");
        break;
        
        case STT_function:
            asprintf(dest, "[Function: %s]", s->val.stringValue);
        break;
        
        case STT_NOTYPE:
            yyerror("Internal error. Trying to convert struct with NOTYPE");
            asprintf(dest, "NaN");
        break;
        
        default:
            yyerror("Internal error. Trying to convert struct evos with NOTYPE (default): ");
            asprintf(dest, "NaN");
        break;
    }
}

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
  printf("\n> ");
}

double getSizeOfArrayName(struct symbol *name) 
{
    return (double)name->sizeOfArray;
}

  // STT_double = 0,
  // STT_string,       // 1
  // STT_array_double  // 2 
double getTypeOf(struct symbol *name)
{
    switch (name->type) {
        case STT_double:
            printf(KBLU "'%s' is double\n" KNRM, name->name);
        break;

        case STT_string:
            printf(KBLU "'%s' is string\n" KNRM, name->name);
        break;

        case STT_array_double:
            printf(KBLU "'%s' is array of double\n" KNRM, name->name);
        break;

        case STT_function:
            printf(KBLU "'%s' is a function\n" KNRM, name->name);
        break;

        case STT_NOTYPE: 
            printf(KRED "'%s' is UNDEFINED\n" KNRM, name->name);
        break;
        
        case STT_NaN:
            printf(KBLU "'%s' is a NaN\n" KNRM, name->name);
        break;  

        default:
            printf(KRED "Internal error: %s is UNDEFINED\n" KNRM, name->name);
        break;
    }
    
    return (double)name->type;
}

double getTypeOfExp(struct ast *a)
{   
    enum symbTableType type;
    struct evalValueOfSymbol *evos = malloc(sizeof(struct evalValueOfSymbol));
    evos = evalStruct(a);
    type = evos->type;
    switch (type) {
        case STT_double:
            printf(KBLU "'%4.4g' is double\n" KNRM, evos->val.value);
        break;

        case STT_string:
            printf(KBLU "'%s' is string\n" KNRM, evos->val.stringValue);
        break;

        case STT_array_double:
            printArrayDouble(evos->val.array, evos->sizeOfArray);
            printf(KBLU "is array of double\n" KNRM);
        break;

        case STT_function:
            printf(KBLU "'%s' is a function\n" KNRM,  evos->val.stringValue);
        break;

        case STT_NOTYPE: 
            printf(KRED "'%s' is UNDEFINED\n" KNRM,  evos->val.stringValue);
        break;
        
        case STT_NaN:
            printf(KBLU "'%s' is a NaN\n" KNRM,  evos->val.stringValue);
        break;  

        default:
            printf(KRED "Internal error: %s is UNDEFINED\n" KNRM,  evos->val.stringValue);
        break;
    }
    
    return (double)type;
}


double checkRangeAndType(struct symbol *s, struct ast *l, int *flag)
{
  
  int index;
  double elem;
  char c;

  *flag = 0;
  
  index = (int)evalStruct(l)->val.value;

  if(index < 0) {
    yyerror("Semantic error. Index of array must be positive integer");
    return 0;
  }
  
  if (s->type == STT_string) {
      s->sizeOfArray = strlen(s->val.stringValue);
  }

  if (s->sizeOfArray > index) {

    if (s->type == STT_array_double) {
        elem = s->val.array[index];
        *flag = 1;
        return elem;
    } else if (s->type == STT_string) {
        c = s->val.stringValue[index];
        debug_print("= '%c'\n", c);
        debug_print("Elem = %c\n", c);
        elem = (int)c;
        return elem;
    }   
  } else {
    if (s->type == STT_double) {
        elem = 0;
        yyerror("Semantic error. '%s' is not array", s->name);
        return elem;
    } else {
        elem = 0;
        yyerror("Semantic error. Accessing array out of range");
        return elem;
    }
    
  }
  
  return elem;
}

double checkRangeAndTypeNoEval(struct symbol *s, int index, int *flag)
{
  
  double elem;
  char c;

  *flag = 0;
  

  if(index < 0) {
    yyerror("Semantic error. Index of array must be positive integer");
    return 0;
  }
  
  if (s->type == STT_string) {
      s->sizeOfArray = strlen(s->val.stringValue);
  }

  if (s->sizeOfArray > index) {

    if (s->type == STT_array_double) {
        elem = s->val.array[index];
        *flag = 1;
        return elem;
    } else if (s->type == STT_string) {
        c = s->val.stringValue[index];
        printf(KGRE "= '%c'\n" KNRM, c);
        debug_print("Elem = %c\n", c);
        elem = (int)c;
        return elem;
    }   
  } else {
    if (s->type == STT_double) {
        elem = 0;
        yyerror("Semantic error. '%s' is not array", s->name);
        return elem;
    } else {
        elem = 0;
        yyerror("Semantic error. Accessing array out of range");
        return elem;
    }
    
  }
  
  return elem;
}

// In this function we have to:
// 1) take an array of symbol s
// 2) Copy the array into another changing an element with given index
// 3) Putting the array back into symbol s
void replaceElement(int index, double arrElement, struct symbol **s)
{ 
  // check Range and Type
  double *arr;
  double *arrTemp;
  int sizeOfArray;
  int i;
  
  arrTemp = malloc(sizeof(double) * ((*s)->sizeOfArray));

  for (i = 0; i < (*s)->sizeOfArray; i++) {
    if (i != index) {
      arrTemp[i] = (*s)->val.array[i];
    } else {
      arrTemp[i] = arrElement;
    }
      
  }

  free((*s)->val.array);
    
  (*s)->val.array = malloc(sizeof(double) * sizeOfArray);

  for (i = 0; i < (*s)->sizeOfArray; i++) {
    (*s)->val.array[i] = arrTemp[i];
  }

  // sprintArrayDouble((*s)->val.array, (*s)->sizeOfArray, (*s)->strValueOfSymbol ); 

 }

double makePopFromArray(struct symbol *name) 
{
    double elemToPop;
    double *newArray;
    int i;

    --(name->sizeOfArray);
    elemToPop = name->val.array[(int)name->sizeOfArray];
    
    newArray = malloc(sizeof(double) * name->sizeOfArray);

    for (i = 0; i < name->sizeOfArray; i++) {
        newArray[i] = name->val.array[i];
    }

    free(name->val.array);

    name->val.array = newArray;

    return elemToPop;
}

double makePushOnArray(struct symbol *name, struct ast *valueToPush)
{
    double elemToPush;
    double *newArray;
    int i;

    struct evalValueOfSymbol *evos;

    ++(name->sizeOfArray);
    newArray = malloc(sizeof(double) * name->sizeOfArray);

    evos = malloc(sizeof(struct evalValueOfSymbol));

    evos = evalStruct(valueToPush);
    if (evos->type == STT_double) {
        elemToPush = evos->val.value;
    } else {
        elemToPush = 0.0;
        yyerror("Semantic error. Trying to make push() of non double element in array. Forcing to 0.");
    }

    for (i = 0; i < name->sizeOfArray-1; i++) {
        newArray[i] = name->val.array[i];
    }
    newArray[name->sizeOfArray-1] = elemToPush;

    free(name->val.array);

    name->val.array = newArray;

    return name->sizeOfArray;
}


void updateDepth(struct ast * a, int depth)
{
    if (a != NULL && a->nodetype == 'L') {
        a->depth = depth;
        updateDepth(a->l, depth + 1); // update left subtree
        updateDepth(a->r, depth + 1); // update right subtree
        debug_print("Deepth: %d\n", a->depth);
    }
}

int getChildrenOfTree(struct ast * a)
{   
    if (a == NULL || a->nodetype != 'L')
        return 0;
    return 1 + getChildrenOfTree(a->l) + getChildrenOfTree(a->r);
}

/******************
 ******************
 ****** MAIN ******
 ******************
 ******************/

int main(int argc, char *argv[])
{
    if (argc != 2) {
        interactiveOrFile = 1;
        printf(KCYA "Welcome to subset JS interpreter! \n");
        printf(KNRM "> "); 
        return yyparse();
    }

    interactiveOrFile = 0; 

    --argc;
    ++argv;

    if( (yyin = fopen(argv[0], "r")) == NULL) {
        printf (KRED "Error in opening: '%s'.\n" KNRM, argv[0]);
        return 0;
    }

    return yyparse();

}

/* debugging: dump out an AST */
int debug = 0;    // DEBUG DISABLED
// int debug = 1; // DEBUG ENABLED
// This function is not updated and work properly only with basic operations
void dumpast(struct ast *a, int level)
{

  printf("%*s", 2*level, "");	/* indent to this level */
  level++;

  if(!a) {
    printf("NULL\n");
    return;
  }

  switch(a->nodetype) {
    /* constant */
  case 'K': printf("number %4.4g\n", ((struct numval *)a)->number); break;

    /* string */ 
  case 'S': printf("string %s\n", ((struct stringval *)a)->str); break;

    /* name reference */
  case 'N': printf("ref %s\n", ((struct symref *)a)->s->name); break;

    /* assignment */
  case '=': printf("= %s\n", ((struct symref *)a)->s->name);
    dumpast( ((struct symasgn *)a)->v, level); return;

  case '[': printf("arrel %s\n", ((struct symarrayel *)a)->s->name); break;

    /* expressions */
  case '+': case '-': case '*': case '/': case '^': case '%': case 'L':
  case '1': case '2': case '3':
  case '4': case '5': case '6': 
  case '&': case 'O':
    printf("binop %c\n", a->nodetype);
    dumpast(a->l, level);
    dumpast(a->r, level);
    return;

  case '|': case 'M': case '!':
    printf("unop %c\n", a->nodetype);
    dumpast(a->l, level);
    return;

  case 'I': case 'W':
    printf("flow %c\n", a->nodetype);
    dumpast( ((struct flow *)a)->cond, level);
    if( ((struct flow *)a)->tl)
      dumpast( ((struct flow *)a)->tl, level);
    if( ((struct flow *)a)->el)
      dumpast( ((struct flow *)a)->el, level);
    return;
	              
  case 'F':
    printf("builtin %d\n", ((struct fncall *)a)->functype);
    dumpast(a->l, level);
    return;

  case 'C': printf("call %s\n", ((struct ufncall *)a)->s->name);
    dumpast(a->l, level);
    return;

  default: printf("bad %c\n", a->nodetype);
    return;
  }
}

