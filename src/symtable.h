#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <stdbool.h>

/* Type Descriptor */
typedef enum {
    T_INTEGER = 1,
    T_BOOLEAN
} PredefType;

typedef enum {
    T_PREDEF = 1,
    T_ARRAY
} TypeConstr;

typedef struct _typeDescr {
    TypeConstr constr;
    int size;
    union {
        struct {struct _typeDescr *element; int numElements;} t_array;
        PredefType t_predef;
    } descr;
} TypeDescr;

/* Paraneters Descriptor */
typedef struct _paramDescr {
    struct _paramDescr *next;
} ParamDescr; /* ??? */

/* Symbol Table */
typedef enum {
    S_CONST = 1,
    S_VAR,
    S_PARAM,
    S_FUNC,
    S_LABEL,
    S_TYPE
} SymbCateg;

typedef enum {
    P_VALUE = 1,
    P_REF
} Passage;

typedef struct _symbEntry {
    SymbCateg categ;
    char *ident;
    int level;
    struct _symbEntry *next;
    union {
        struct {int value; TypeDescr *ctype;} s_constant;
        struct {int vdispl; TypeDescr *vtype;} s_variable;
        struct {int pdispl; TypeDescr *ptype; Passage pass;} s_parameter;
        struct {int fdispl; TypeDescr *result; ParamDescr *params;} s_function;
        struct {char *label; bool defined;} s_label;
        struct {TypeDescr *type;} s_type;
    } descr;
} SymbEntry;

SymbEntry *searchSymbEntry(char *ident);
SymbEntry *newSymbEntry(SymbCateg categ, char *ident);
void insertSymbolTable(SymbEntry *ste);
void saveSymbolTable(); /* ??? */
void restoreSymbolTable(); /* ??? */
void loadFormalsSymbolTable(SymbEntry *formals); /* ??? */

#endif /* SYMTABLE_H */
