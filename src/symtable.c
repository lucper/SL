#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

SymbEntry *symbolTable = NULL;

static SymbEntry *symbolTableCpy = NULL;

static bool declaredAtSameLevel(SymbEntry *entry1, SymbEntry *entry2);
static void freeTypeDescr(TypeDescr *typeDescr);
static void freeParamDescr(ParamDescr *paramDescr);
static void freeVarDescr(VarDescr *varDescr);
static void freeConstDescr(ConstDescr *constDescr);
static void freeLabelDescr(LabelDescr *labelDescr);
static void freeDescr(SymbCateg categ, Descr *descr);
static void freeParams(SymbEntry *params);
static void freeFuncDescr(FuncDescr *funcDescr);

static bool declaredAtSameLevel(SymbEntry *entry1, SymbEntry *entry2)
{
    int entry1Level = entry1->level;
    int entry2Level = entry2->level;
    return entry1Level == entry2Level && entry1Level != -1;
}

static void freeTypeDescr(TypeDescr *typeDescr)
{
    free(typeDescr);
}

static void freeParamDescr(ParamDescr *paramDescr)
{
	freeTypeDescr(paramDescr->type);
	free(paramDescr);
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

static void freeLabelDescr(LabelDescr *labelDescr)
{
    free(labelDescr->mepaLabel);
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

static void freeParams(SymbEntry *params)
{	
    SymbEntry *prev = NULL;
    while (params) {
        freeDescr(params->categ, params->descr);
        free(params->ident);
        prev = params;
        params = params->next;
        free(prev);
    }
}

static void freeFuncDescr(FuncDescr *funcDescr)
{
    freeTypeDescr(funcDescr->result);
    freeParams(funcDescr->params);
    free(funcDescr);
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
    Descr *descr = malloc(sizeof(Descr));
    descr->parameter = paramDescr;
    return descr;
}

Descr *newFuncDescr(int displ, TypeDescr *result, SymbEntry *params)
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
    labelDescr->mepaLabel = malloc(strlen(mepaLabel) + 1);
    strcpy(labelDescr->mepaLabel, mepaLabel);
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
    SymbEntry *trueConst = newSymbEntry(S_CONST, "true", -1, boolDescr);
    insertSymbolTable(trueConst);
    SymbEntry *falseConst = newSymbEntry(S_CONST, "false", -1, boolDescr);
    insertSymbolTable(falseConst);
	SymbEntry *writeFunc = newSymbEntry(S_FUNC, "write", -1, NULL); /* "pseudo" function: no Descr */
	insertSymbolTable(writeFunc);
	SymbEntry *readFunc = newSymbEntry(S_FUNC, "read", -1, NULL); /* "pseudo" function: no Descr */
	insertSymbolTable(readFunc);
}

void freeSymbolTable()
{
    SymbEntry *prev = NULL;
    while (symbolTable) {
        freeDescr(symbolTable->categ, symbolTable->descr);
        free(symbolTable->ident);
        prev = symbolTable;
        symbolTable = symbolTable->next;
        free(prev);
    }
}

SymbEntry *newSymbEntry(SymbCateg categ, char *ident, int level, Descr *descr)
{
    SymbEntry *newEntry = malloc(sizeof(SymbEntry));
    newEntry->categ = categ;
    newEntry->ident = malloc(strlen(ident) + 1);
    strcpy(newEntry->ident, ident);
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
            if (strcmp(currEntry->ident, ident) == 0) {
                return currEntry;
            }
            currEntry = currEntry->next;
        }
        return NULL;
    }
}

void insertSymbolTable(SymbEntry *newEntry)
{
    if (symbolTable) {
        SymbEntry *existingEntry = searchSymbEntry(newEntry->ident);
        if (existingEntry && declaredAtSameLevel(existingEntry, newEntry)) {
            printf("%s and %s declared at the same level: not allowed\n", newEntry->ident, existingEntry->ident);
            exit(1); // TODO: return error message
        }
        newEntry->next = symbolTable;
    }
    symbolTable = newEntry;
}

void saveSymbolTable()
{
	symbolTableCpy = symbolTable;
}

void restoreSymbolTable()
{
	/* split params from table */
	SymbEntry *curr = symbolTable;
	while (curr->next != symbolTableCpy)
		curr = curr->next;
	curr->next = NULL;

	/* free params from top of table */	
	freeParams(symbolTable);

	/* restore */
	symbolTable = symbolTableCpy;
}

void loadParamsSymbolTable(SymbEntry *params)
{
	symbolTable = params;
	while (params->next)
		params = params->next;
	params->next = symbolTableCpy;
}
