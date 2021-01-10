#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>

int currentLevel = 0;
int currentDispl = -1;
SymbEntry *symbolTable = NULL;

void addConstDescr(SymbEntry *entry, int value, TypeDescr *type)
{
    entry->descr.constant.value = value;
    entry->descr.constant.type = type;
}

void addVarDescr(SymbEntry *entry, int displ, TypeDescr *type)
{
    entry->descr.variable.displ = displ;
    entry->descr.variable.type = type;
}

void addFuncDescr(SymbEntry *entry, int displ, TypeDescr *type, ParamDescr *param)
{
    entry->descr.function.displ = displ;
    entry->descr.function.result = type;
    entry->descr.function.params = param;
}

void addLabelDescr(SymbEntry *entry, char *mepaLabel, bool defined)
{
    entry->descr.label.mepaLabel = mepaLabel;
    entry->descr.label.defined = defined;
}

void addParamDescr(SymbEntry *entry)
{
    return;
}

SymbEntry *newSymbEntry(SymbCateg categ, char *ident)
{
    SymbEntry *newEntry = malloc(sizeof(SymbEntry));
    newEntry->categ = categ;
    newEntry->ident = ident;
    // newEntry->level = currentLevel;
    return newEntry;
}

SymbEntry *searchSymbEntry(char *ident)
{
    if (!symbolTable) {
        printf("nothing to search: empty symbol table");
        exit(1); // TODO: return error message
    } else {
        SymbEntry *currEntry = symbolTable;
        while (currEntry) {
            if (currEntry->ident == ident)
                return currEntry;
            currEntry = currEntry->next;
        }
        return NULL;
    }
}

void insertSymbolTable(SymbEntry *newEntry)
{
    if (!symbolTable)
        symbolTable = newEntry;
    else {
        SymbEntry *existingEntry = searchSymbEntry(newEntry->ident);
        if (existingEntry && existingEntry->level == newEntry->level) {
            printf("%s and %s declared at the same level: not allowed", newEntry->ident, existingEntry->ident);
            exit(1); // TODO: return error message
        }
        newEntry->next = symbolTable;
        symbolTable = newEntry;
    }
}
