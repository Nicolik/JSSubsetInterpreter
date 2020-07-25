/*****************
 **** FUNCS.H **** 
 *****************
 
 * Questo header file contiene:
 * - Dichiarazioni di funzioni di utilità
 
 */

/* handle the output of the interpreter */
void handleOutputSwitchStruct(struct ast *a); 

/* handle basic operations with arrays */
void printArrayDouble(double *dArr, int sizeOfArray);
void sprintArrayDouble(double *dArr, int sizeOfArray, char *str);
void asprintArrayDouble(double *dArr, int sizeOfArray, char **str);

/* converting symbol and struct to string */
void symbolToString(char **dest, struct symbol *s);
void structToString(char **dest, struct evalValueOfSymbol *s);

/* convert a list of double to an array of double */
double * listToArrayDoubleAST(struct arrayElemListAST *arrElems); 

/* count the number of elements in a list */
int countNumberOfListAST(struct arrayElemListAST *arrElems);

void clearScreen();

double getSizeOfArrayName(struct symbol *name);

/* push and pop operations for array */
double makePushOnArray(struct symbol *name, struct ast *valueToPush);
double makePopFromArray(struct symbol *name);

/* typeof */
double getTypeOf(struct symbol *name);
double getTypeOfExp(struct ast *a);

/* update depth on tree */
void updateDepth(struct ast * a, int depth);

/* get children of tree */
int getChildrenOfTree(struct ast * a);

/* check that in a[i], a is vector and i is possible index */
double checkRangeAndType(struct symbol *s, struct ast *l, int *flag);
double checkRangeAndTypeNoEval(struct symbol *s, int index, int *flag);
