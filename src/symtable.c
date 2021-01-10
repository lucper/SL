#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>

int currentLevel = 0;
int currentDispl = -1;
SymbEntry *symbolTable = NULL;

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
