#include "../tests/test_compiler/slc.h" // SemanticError
#include "codegen.h"
#include <stdio.h>

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
