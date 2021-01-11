
#include "../tests/test_compiler/slc.h" // SemanticError
#include "codegen.h"
#include <stdio.h>

#define INTEGER "integer"
#define BOOLEAN "boolean"

void processVariables(TreeNode *p)
{
    p = reverse(p);
    while (p) {
        processVarDecl(p);
        p = p->next;
    }
}

static TypeDescr *getType(TreeNode *p)
{
    /* TODO: verify if the checking is correct and
     * what to do if it is not integer nor boolean. */
    char *ident = p->symbol;
    TypeDescr *type = malloc(sizeof(TypeDescr));
    if (ident == INTEGER) {
        type->size = 1;
        type->predefType = T_INTEGER;
    } else if (ident == BOOLEAN) {
        type->size = 1;
        type->predefType = T_BOOLEAN;
    } else {
        printf("invalid type");
        exit(1);
    }
    return type;
}

static char *getIdent(TreeNode *p)
{
    return p->symbol;
}

void processVarDecl(TreeNode *p)
{
    TreeNode *vars = reverse(p->components[0]);
    TypeDescr *type = getType(p->components[1]);
    SymbEntry *entry;
    while (vars) {
        entry = newSymbEntry(S_VAR, getIdent(vars));
        entry->level = currentLevel; // include in newSymbentry?
        addVarDescr(entry, currentDispl, type);
        insertSymbolTable(entry);
        currentDispl += type->size;
    }
}

TypeDescr *processExpr(TreeNode *p)
{
    return NULL;
}

void processAssign(TreeNode *p)
{
    TreeNode *var = p->components[0];
    TreeNode *expr = p->components[1];
    SymbEntry *entry = searchSymbEntry(var->symbol);
    if (!entry)
        SemanticError("");
    if (entry->categ != S_VAR && entry->categ != S_PARAM)
        SemanticError("");
    TypeDescr *tvar = entry->descr.type;
    TypeDescr *texpr = processExpr(expr);
    if (tvar->predefType != texpr->predefType)
        SemanticError("");
    if (entry->categ == S_PARAM) {
        if (entry->descr.parameter.pass == P_REF)
            printf("STVI %d, %d\n", entry->level, entry->descr.parameter.displ);
        else
            printf("STVL %d, %d\n", entry->level, entry->descr.parameter.displ);
    }
    if (entry->categ == S_VAR)
        printf("STVL %d, %d\n", entry->level, entry->descr.variable.displ);
}

void processFuncDecl(TreeNode *p, bool isMain)
{
    char *name = getIdent(p->components[1]);
    printf("%s\n", name);
}

void processProgram(void *p)
{
    /* init symbol table */
    TreeNode *node = p;
    if (!node)
        return;
    else {
        if (node->next)
            processProgram(node->next);
        for (int i = 0; i < MAX_COMPS; i++)
            if (node->components[i])
                processProgram(node->components[i]);
        printf("categ %d\n", node->categ);
        if (node->categ == C_IDENTIFIER)
            printf("ident = %s\n", node->symbol);
    }
}
