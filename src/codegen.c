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

static bool isVoidFunc(TreeNode *p)
{
    return p->categ == C_FUNCTION_HEADER && p->components[1]->categ == C_FORMAL_PARAMS;
}

static TypeDescr *getType(TreeNode *p)
{
    char *ident = p->components[0]->symbol;
    SymbEntry *entry = searchSymbEntry(ident);
    if (!entry) {
        printf("%s not found in symbol table\n", ident);
        exit(1);
    }
    if (entry->categ != S_TYPE) {
        printf("not a type: %s\n", entry->ident);
        exit(1);
    }
    return entry->descr->type;
}

static void processBlock(TreeNode *block)
{
    TreeNode *currComp;
    for (int i = 0; i < MAX_COMPS; i++) {
        currComp = block->components[i];
        if (currComp) {
            if (currComp->categ == C_VARIABLES)
                processVariables(currComp);
            else if (currComp->categ == C_LABELS)
                ;
            else if (currComp->categ == C_FUNCTIONS)
                processFunctions(currComp);
            else if (currComp->categ == C_BODY)
                ;
        }
    }
}

void processVariables(TreeNode *p)
{
    p = p->components[0];
    p = reverse(p);
    while (p) {
        processVarDecl(p);
        p = p->next;
    }
}

void processVarDecl(TreeNode *p)
{
    TreeNode *identList = p->components[0]; /* reverse? */
    TypeDescr *type = getType(p->components[1]);
    SymbEntry *entry;
    while (identList) {
        Descr *varDescr = newVarDescr(currentDispl, type);
        entry = newSymbEntry(S_VAR, identList->symbol, currentLevel, varDescr);
        insertSymbolTable(entry);
        currentDispl += type->size;
        identList = identList->next;
    }
}

void processFunctions(TreeNode *p)
{
    ;
}

void processFuncDecl(TreeNode *p, bool isMain)
{
    int lastDispl = -4, entLabel, retLabel;
    currentLevel++;

    /*** HEADER ***/
    TreeNode *header = p->components[0];
    TypeDescr *resType = NULL;
    char *name;
    if (isVoidFunc(header))
        name = header->components[0]->symbol;
    else {
        name = header->components[1]->symbol;
        resType = getType(header->components[0]);
    }
    if (resType) /* if function returns value, reserve positions for return value */
        lastDispl -= resType->size;
    ParamDescr *params = NULL; // TODO: processParams
    Descr *funcDescr = newFuncDescr(lastDispl, resType, params);
    SymbEntry *funcEntry = newSymbEntry(S_FUNC, name, currentLevel - 1, funcDescr);
    insertSymbolTable(funcEntry);
    // saveSymbolTable();
    /**************/
   
    if (isMain)
        printf("MAIN\n");
    else {
        entLabel = nextLabel();
        retLabel = nextLabel();
        printf("L%d: ENFN %d\n", entLabel, currentLevel);
    }
    
    /*** BLOCK ***/
    TreeNode *block = p->components[1];
    processBlock(block);
    /*************/
    
    if (isMain)
        printf("STOP\n");
    else {
        printf("RTRN %d\n", -lastDispl-4);
        currentLevel--;
        //restoreSymbolTable();
    }
}

void processProgram(void *p)
{
    if (!symbolTable)
        initSymbolTable();
    TreeNode *program = p;
    processFuncDecl(program->components[0], true);
    //freeStack();
    //freeSymbolTable();
}
