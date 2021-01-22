#include "../tests/test_compiler/slc.h" // SemanticError
#include "codegen.h"
#include <stdio.h>

int currentLevel = 0;
int currentDispl = -1;
int labelCounter = 99;

static int nextLabel()
{
    return ++labelCounter;
}

static TypeDescr *getType(TreeNode *p)
{
    char *ident = p->symbol;
    SymbEntry *entry = searchSymbEntry(ident);
    if (entry->categ != S_TYPE) {
        printf("not a type: categ %d\n", entry->categ);
        exit(1);
    }
    return entry->descr->type;
}

void processVariables(TreeNode *p)
{
    p = p->components[0];
    //p = reverse(p);
    while (p) {
        processVarDecl(p);
        p = p->next;
    }
}

void processVarDecl(TreeNode *p)
{
    for (int i = 0; i < MAX_COMPS; ++i)
        printf("categ %d\n", p->components[i]->categ);
    TreeNode *vars = p->components[0]; /* reverse? */
    TypeDescr *type = getType(p->components[1]);
    SymbEntry *entry;
    while (vars) {
        Descr *varDescr = newVarDescr(currentDispl, type);
        entry = newSymbEntry(S_VAR, vars->symbol, currentLevel, varDescr);
        insertSymbolTable(entry);
        currentDispl += type->size;
        vars = vars->next;
    }
}

void processFuncDecl(TreeNode *p, bool isMain)
{
    TreeNode *header = p->components[0];
    TreeNode *block = p->components[1];
    char *name = header->components[0]->symbol;
    TypeDescr *resType = NULL;

    int lastDispl = -4;
    Descr *funcDescr = newFuncDescr(lastDispl, resType, NULL);
    SymbEntry *funcEntry = newSymbEntry(S_FUNC, name, currentLevel - 1, funcDescr);
    insertSymbolTable(funcEntry);
    
    if (isMain)
        printf("MAIN\n");
    processVariables(block->components[0]);
    printf("ALOC %d\n", currentDispl);
    printf("DLOC %d\n", currentDispl);
    if (isMain)
        printf("STOP\n");
}

void processProgram(void *p)
{
    if (!symbolTable)
        initSymbolTable();
    TreeNode *tree = p;
    if (!tree)
        return;
    else {
        if (tree->next)
            processProgram(tree->next);
        for (int i = 0; i < MAX_COMPS; i++)
            if (tree->components[i] || i == 0)
                processProgram(tree->components[i]);
        if (tree->categ == C_FUNCTION) {
            processFuncDecl(tree, true);
            //dumpSymbolTable();
        }
    }
}
