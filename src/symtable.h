#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <stdbool.h>

/* Descriptors */
// typedef enum {T_PREDEF = 1, T_ARRAY, T_FUNC} TypeConstr;
typedef enum {T_INTEGER = 1, T_BOOLEAN} PredefType;
typedef struct _typeDescr {
    // TypeConstr constr;
    int size;
    PredefType predefType;
} TypeDescr;

typedef enum {P_VALUE = 1, P_REF} Passage;
typedef struct _paramDescr {
    int displ;
    TypeDescr *type;
    Passage pass;
    struct _paramDescr *next;
} ParamDescr;

typedef struct {
    int displ;
    TypeDescr *result;
    ParamDescr *params;
} FuncDescr;

typedef struct {
    int value;
    TypeDescr *type;
} ConstDescr;

typedef struct {
    int displ;
    TypeDescr *type;
} VarDescr;

typedef struct {
    char *mepaLabel;
    bool defined;
} LabelDescr;

/* Symbol Table */
typedef enum {
    S_CONST = 1,
    S_VAR,
    S_PARAM,
    S_FUNC,
    S_LABEL,
    S_TYPE
} SymbCateg;

typedef struct _symbEntry {
    SymbCateg categ;
    char *ident;
    int level;
    struct _symbEntry *next;
    union {
        ConstDescr constant;
        VarDescr variable;
        FuncDescr function;
        ParamDescr parameter;
        LabelDescr label;
        TypeDescr *type;
    } descr;
} SymbEntry;

SymbEntry *searchSymbEntry(char *ident);
SymbEntry *newSymbEntry(SymbCateg categ, char *ident);
void insertSymbolTable(SymbEntry *entry);
void saveSymbolTable(); /* ??? */
void restoreSymbolTable(); /* ??? */
void loadFormalsSymbolTable(SymbEntry *formals); /* ??? */

void addConstDescr(SymbEntry *entry, int value, TypeDescr *type);
void addVarDescr(SymbEntry *entry, int displ, TypeDescr *type);
void addFuncDescr(SymbEntry *entry, int displ, TypeDescr *type, ParamDescr *param);
void addLabelDescr(SymbEntry *entry, char *mepaLabel, bool defined);
// void addParamDescr(SymbEntry *entry);

extern SymbEntry *symbolTable;
extern int currentLevel;
extern int currentDispl;

#endif /* SYMTABLE_H */
