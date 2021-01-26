#include "slc.h" // mandatory for submission
#include "codegen.h"
#include <stdio.h>
#include <string.h>

int currentLevel = -1;
int currentDispl = 0;
int labelCounter = 99;

static int nextLabel()
{
    return ++labelCounter;
}

static bool isVoidFunc(TreeNode *p)
{
    return p->categ == C_FUNCTION_HEADER && p->components[1]->categ == C_FORMAL_PARAMS;
}

static bool labeledStatement(TreeNode *p)
{
    return p->components[1] != NULL;
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
        if (block->components[i]) {
            currComp = block->components[i];
            if (currComp->categ == C_VARIABLES) {
                processVariables(currComp);
            }
            else if (currComp->categ == C_LABELS)
                ;
            else if (currComp->categ == C_FUNCTIONS)
                processFunctions(currComp);
            else if (currComp->categ == C_BODY) {
                TreeNode *stmts = reverse(currComp->components[0]);
                while (stmts) {
                    processStatement(stmts->components[0]);
                    stmts = stmts->next;
                }
            }
        }
    }
}

static TypeDescr *processBinExpr(TreeNode *expr)
{
    return NULL;
}

static TypeDescr *processUniExpr(TreeNode *expr)
{
    return NULL;
}

static TypeDescr *processSimpExpr(TreeNode *expr)
{
    bool singleTerm = expr->components[0]->categ == C_TERM; 
    if (singleTerm) {
		TreeNode *factor = expr->components[0]->components[0]->components[0];
        if (factor->categ == C_INTEGER) {
            printf("LVCT %s\n", factor->symbol);
            return newTypeDescr(1, T_INTEGER)->type;
        } else if (factor->categ == C_BOOLEAN) {
			printf("LVCT %c\n", strcmp(factor->symbol, "true") == 0 ? '1' : '0');
			return newTypeDescr(1, T_BOOLEAN)->type;
		} else if (factor->categ == C_VARIABLE) {
			char *ident = factor->components[0]->symbol;
			SymbEntry *entry = searchSymbEntry(ident);
    		if (!entry)
        		printf("semantic error: %s undefined\n", entry->ident);
    		if (entry->categ != S_VAR && entry->categ != S_PARAM)
        		printf("semantic error: %s not variable nor parameter\n", entry->ident);
			printf("LDVL %d,%d\n", entry->level, entry->descr->variable->displ);
			return entry->descr->variable->type;
		} else if (factor->categ == C_FUNCTION_CALL) {
			return NULL; /* TODO */
		} else if (factor->categ == C_EXPRESSION) {
			return processExpr(factor);
		} else {
			printf("not a C_FACTOR node\n");
			exit(1);
		}
    } else {
        return NULL;
    }
}

static void processExprList(TreeNode *p)
{
	TreeNode *exprList = p; /* reverse? */
	while (exprList) {
		processExpr(exprList->components[0]);
		exprList = exprList->next;
	}
}

static void processFuncCall(TreeNode *p)
{
	; /* TODO */
}

TypeDescr *processExpr(TreeNode *p)
{
    TreeNode *expr = p->components[0]; /* can be NULL! */
    if (expr->categ == C_SIMPLE_EXPRESSION)
        return processSimpExpr(expr);
    else if (expr->categ == C_BINOP_EXPRESSION)
        return processBinExpr(expr);
    else if (expr->categ == C_UNOP_EXPRESSION)
        return processUniExpr(expr);
    else {
        printf("not expression\n");
        exit(1);
    }        
}

void processAssign(TreeNode *assign)
{
    TreeNode *variable = assign->components[0];
    TreeNode *expression = assign->components[1];
    char *ident = variable->components[0]->symbol;
    SymbEntry *entry = searchSymbEntry(ident);
    if (!entry)
        printf("semantic error: %s undefined\n", entry->ident);
    if (entry->categ != S_VAR && entry->categ != S_PARAM)
        printf("semantic error: %s not variable nor parameter\n", entry->ident);
    TypeDescr *variableType = entry->descr->variable->type;
    TypeDescr *expressionType = processExpr(expression);
    if (variableType->predefType != expressionType->predefType)
        printf("semantic error: incompatible types\n");
    if (entry->categ == S_PARAM) {
        int level = entry->level;
        int displ = entry->descr->parameter->displ;
        Passage pass = entry->descr->parameter->pass;
        if (pass == P_REF)
            printf("STVI %d,%d\n", level, displ);
        else
            printf("STVL %d,%d\n", level, displ);
    } else
        printf("STVL %d,%d\n", entry->level, entry->descr->variable->displ);
}

void processStatement(TreeNode *stmt)
{
    if (labeledStatement(stmt)) {
        ;
    } else {
        TreeNode *unlabeledStmt = stmt->components[0]->components[0];
        if (unlabeledStmt->categ == C_ASSIGNMENT) {
            processAssign(unlabeledStmt);
        } else if (unlabeledStmt->categ == C_FUNCTION_CALL_STATEMENT) {
			processFuncCall(unlabeledStmt->components[0]);	
		} else ; /* TODO */ 
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
    printf("ALOC %d\n", currentDispl);
}

void processVarDecl(TreeNode *p)
{
    TreeNode *identList = reverse(p->components[0]); /* need to reverse? */
    TypeDescr *type = getType(p->components[1]);
    SymbEntry *entry;
    char *ident;
    Descr *varDescr;
    while (identList) {
        varDescr = newVarDescr(currentDispl, type);
        ident = identList->components[0]->symbol;
        entry = newSymbEntry(S_VAR, ident, currentLevel, varDescr);
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

    printf("DLOC %d\n", currentDispl);

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
    printf("END\n");
    //freeStack();
    //freeSymbolTable();
}
