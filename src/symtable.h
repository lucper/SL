#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <stdbool.h>

typedef struct _symbEntry SymbEntry;

/* Descriptors */
typedef enum {T_INTEGER = 1, T_BOOLEAN} PredefType;
typedef struct {
    int size;
    PredefType predefType;
} TypeDescr;

typedef enum {P_VAL = 1, P_REF} Passage;
typedef struct {
    int displ;
    TypeDescr *type;
    Passage pass;
} ParamDescr;

typedef struct {
    int displ;
    TypeDescr *result;
    SymbEntry *params;
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
typedef union {
    TypeDescr *type;
    ParamDescr *parameter;
    FuncDescr *function;
    ConstDescr *constant;
    VarDescr *variable;
    LabelDescr *label;
} Descr;
struct _symbEntry {
    SymbCateg categ;
    char *ident;
    int level;
    struct _symbEntry *next;
    Descr *descr;
};

SymbEntry *searchSymbEntry(char *ident);
SymbEntry *newSymbEntry(SymbCateg categ, char *ident, int level, Descr *descr);
void insertSymbolTable(SymbEntry *entry);
void saveSymbolTable();
void restoreSymbolTable();
void loadParamsSymbolTable(SymbEntry *params);

Descr *newTypeDescr(int size, PredefType predefType);
Descr *newParamDescr(int displ, TypeDescr *type, Passage pass);
Descr *newFuncDescr(int displ, TypeDescr *result, SymbEntry *params);
Descr *newConstDescr(int value, TypeDescr *type);
Descr *newVarDescr(int displ, TypeDescr *type);
Descr *newLabelDescr(char *mepaLabel, bool defined);

void initSymbolTable();
void freeSymbolTable();
void dumpSymbolTable();

extern SymbEntry *symbolTable;

#endif /* SYMTABLE_H */
