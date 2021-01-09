#include <stdbool.h>

/* Type Descriptors */
typedef enum {
    T_PREDEF = 1,
    T_ARRAY
} TypeConstr;

typedef struct {
    /* either boolean or integer */
} PredefType;

typedef struct {
    int numElements;
    TypeDescr *element;
} ArrayType;

typedef struct _typeDescr {
    TypeConstr constr; /* must be removed!? */
    int size; /* 1 for ints and bools, n for arrays */
    union {
        PredefType predefType;
        ArrayType arrayType;
    } descr;
} TypeDescr;

/* Symbol Table entries categories */
typedef enum {
    S_CONST = 1,
    S_VAR,
    S_PARAM,
    S_FUNC,
    S_LABEL,
    S_TYPE
} SymbCateg;

typedef struct {
    int value;
    TypeDescr *type;
} Constant; /* S_CONST */ 

typedef struct {
    int displ;
    TypeDescr *type;
} Variable; /* S_VAR */

typedef enum {P_VALUE = 1, P_REFERENCE} Passage;
typedef struct {
    int displ;
    TypeDescr *type;
    Passage pass;
} Parameter; /* S_PARAM */

typedef struct {
    int displ;
    TypeDescr *type;
    ParamDescr *params; // TODO
} Function; /* S_FUNC */

typedef struct {
    char *mepaLabel;
    bool defined;
} Label; /* S_LABEL */

typedef struct {
    TypeDescr *type;
} Type; /* S_TYPE */

typedef struct _symbEntry {
    SymbCateg categ; /* must be removed!? */
    char *ident;
    int level;
    struct _symbEntry *next;
    union {
        Constant const;
        Variable var;
        Parameter param;
        Function func;
        Label label;
        Type type;        
    } descr;
} SymbEntry;

SymbEntry *initSymTable();
