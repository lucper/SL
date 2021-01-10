#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>

int currentLevel = 0;
int currentDispl = -1;

SymbEntry *newSymbEntry(SymbCateg categ, char *ident)
{
    SymbEntry *ste = malloc(sizeof(SymbEntry));
    ste->categ = categ;
    ste->ident = ident;
    ste->level = currentLevel;
    /* switch (categ) { fill descr? } */
    return ste;
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

void insertSymbolTable(SymbEntry *ste)
{
    if (!symbolTable)
        symbolTable = ste;
    else {
        ste->next = symbolTable;
        symbolTable = ste;
    }
}
