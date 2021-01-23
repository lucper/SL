#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>

SymbEntry *symbolTable = NULL;

static void freeTypeDescr(TypeDescr *typeDescr)
{
    free(typeDescr);
}

static void freeVarDescr(VarDescr *varDescr)
{
    freeTypeDescr(varDescr->type);
    free(varDescr);
}

static void freeConstDescr(ConstDescr *constDescr)
{
    freeTypeDescr(constDescr->type);
    free(constDescr);
}

static void freeParamDescr(ParamDescr *paramsDescr)
{
    ParamDescr *prev = NULL;
    while (paramsDescr) {
        freeTypeDescr(paramsDescr->type);
        prev = paramsDescr;
        paramsDescr = paramsDescr->next;
        free(prev);
    }
}

static void freeFuncDescr(FuncDescr *funcDescr)
{
    freeTypeDescr(funcDescr->result);
    freeParamDescr(funcDescr->params);
    free(funcDescr);
}

static void freeLabelDescr(LabelDescr *labelDescr)
{
    free(labelDescr);
}

static void freeDescr(SymbCateg categ, Descr *descr)
{
    if (categ == S_VAR)
        freeVarDescr(descr->variable);
    else if (categ == S_CONST)
        freeConstDescr(descr->constant);
    else if (categ == S_PARAM)
        freeParamDescr(descr->parameter);
    else if (categ == S_FUNC)
        freeFuncDescr(descr->function);
    else if (categ == S_LABEL)
        freeLabelDescr(descr->label);
    else if (categ == S_TYPE)
        freeTypeDescr(descr->type);
    else {
        printf("bad categ");
        exit(1);
    }
    free(descr);
}

Descr *newTypeDescr(int size, PredefType predefType)
{
    TypeDescr *typeDescr = malloc(sizeof(TypeDescr));
    typeDescr->size = size;
    typeDescr->predefType = predefType;
    Descr *descr = malloc(sizeof(Descr));
    descr->type = typeDescr;
    return descr;
}

Descr *newParamDescr(int displ, TypeDescr *type, Passage pass)
{
    ParamDescr *paramDescr = malloc(sizeof(ParamDescr));
    paramDescr->displ = displ;
    paramDescr->type = type;
    paramDescr->pass = pass;
    paramDescr->next = NULL;
    Descr *descr = malloc(sizeof(Descr));
    descr->parameter = paramDescr;
    return descr;
}

Descr *newFuncDescr(int displ, TypeDescr *result, ParamDescr *params)
{
    FuncDescr *funcDescr = malloc(sizeof(FuncDescr));
    funcDescr->displ = displ;
    funcDescr->result = result;
    funcDescr->params = params;
    Descr *descr = malloc(sizeof(Descr));
    descr->function = funcDescr;
    return descr;
}

Descr *newConstDescr(int value, TypeDescr *type)
{
    ConstDescr *constDescr = malloc(sizeof(ConstDescr));
    constDescr->value = value;
    constDescr->type = type;
    Descr *descr = malloc(sizeof(Descr));
    descr->constant = constDescr;
    return descr;
}

Descr *newVarDescr(int displ, TypeDescr *type)
{
    VarDescr *varDescr = malloc(sizeof(VarDescr));
    varDescr->displ = displ;
    varDescr->type = type;
    Descr *descr = malloc(sizeof(Descr));
    descr->variable = varDescr;
    return descr;
}

Descr *newLabelDescr(char *mepaLabel, bool defined)
{
    LabelDescr *labelDescr = malloc(sizeof(LabelDescr));
    labelDescr->mepaLabel = mepaLabel;
    labelDescr->defined = defined;
    Descr *descr = malloc(sizeof(Descr));
    descr->label = labelDescr;
    return descr;
}

void dumpSymbolTable()
{
    if (!symbolTable)
        printf("empty symbol table\n");
    else {
        SymbEntry *curr = symbolTable;
        while (curr) {
            printf("ident: %s | categ: %d | level: %d\n", curr->ident, curr->categ, curr->level);
            curr = curr->next;
        }
    }
}

void initSymbolTable()
{
    Descr *intDescr = newTypeDescr(1, T_INTEGER);
    SymbEntry *intType = newSymbEntry(S_TYPE, "integer", -1, intDescr);
    insertSymbolTable(intType);
    Descr *boolDescr = newTypeDescr(1, T_BOOLEAN);
    SymbEntry *boolType = newSymbEntry(S_TYPE, "boolean", -1, boolDescr);
    insertSymbolTable(boolType);
}

void freeSymbolTable()
{
    SymbEntry *prev = NULL;
    while (symbolTable) {
        freeDescr(symbolTable->categ, symbolTable->descr);
        prev = symbolTable;
        symbolTable = symbolTable->next;
        free(prev);
    }
}

SymbEntry *newSymbEntry(SymbCateg categ, char *ident, int level, Descr *descr)
{
    SymbEntry *newEntry = malloc(sizeof(SymbEntry));
    newEntry->categ = categ;
    newEntry->ident = ident;
    newEntry->level = level;
    newEntry->descr = descr;
    return newEntry;
}

SymbEntry *searchSymbEntry(char *ident)
{
    if (!symbolTable) {
        printf("nothing to search: empty symbol table\n");
        exit(1); // TODO: return error message
    } else {
        SymbEntry *currEntry = symbolTable;
        while (currEntry) {
            if (currEntry->ident == ident)
                return currEntry;
            currEntry = currEntry->next;
        }
        printf("%s not found in symbol table\n", ident);
        exit(1);
    }
}

void insertSymbolTable(SymbEntry *newEntry)
{
    if (symbolTable) {
        SymbEntry *existingEntry = searchSymbEntry(newEntry->ident);
        if (existingEntry->level == newEntry->level) {
            printf("%s and %s declared at the same level: not allowed\n", newEntry->ident, existingEntry->ident);
            exit(1); // TODO: return error message
        }
        newEntry->next = symbolTable;
    }
    symbolTable = newEntry;
}
