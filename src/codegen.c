#include "slc.h" // mandatory for submission
#include "codegen.h"
#include <stdio.h>
#include <string.h>

int currentLevel = -1;
int currentDispl = 0;
int labelCounter = 99;

static int nextLabel();
static bool isVoidFunc(TreeNode *p);
static bool labeledStatement(TreeNode *p);
static TypeDescr *getType(TreeNode *p);
static void processBlock(TreeNode *block);
static TypeDescr *processBinExpr(TreeNode *expr);
static TypeDescr *processUniExpr(TreeNode *expr);
static TypeDescr *processFuncCall(TreeNode *p);
static SymbEntry *processParams(TreeNode *p, int *displ);
static TypeDescr *processSimpExpr(TreeNode *p);
static TypeDescr *processTerms(TreeNode *p);
static TypeDescr *processFactor(TreeNode *p);
static char *mepaBinOp(TreeNode *p);
static bool compatibleTypes(TreeNode *p, TypeDescr *type1, TypeDescr *type2);

static int nextLabel()
{
    return ++labelCounter;
}

static bool isVoidFunc(TreeNode *p)
{
    return p->categ == C_FUNCTION_HEADER && p->components[1]->categ == C_PARAMS;
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

static TypeDescr *processFuncCall(TreeNode *p)
{
	char *ident = p->components[0]->symbol;
	SymbEntry *entry = searchSymbEntry(ident);
	if (!entry)
		printf("semantic error: %s undefined\n", ident);
	if (entry->categ != S_FUNC)
		printf("semantic error: %s not a function\n", ident);
	TreeNode *exprList = reverse(p->components[1]);
	if (strcmp(entry->ident, "write") == 0) {
		while (exprList) {
			processExpr(exprList->components[0]);
			printf("PRNT\n");
			exprList = exprList->next;
		}
		return NULL;
	} else if (strcmp(entry->ident, "read") == 0) {
		while (exprList) {
			printf("READ\n");
			processExpr(exprList->components[0]); /* TODO: must print STVL */
			exprList = exprList->next;
		}
		return NULL;
	} else {
		if (entry->descr->function->result) { /* if function returns value, alloc memory for it */
			printf("ALOC 1\n"); /* TODO: implement processReturn (?) to dealloc */
			return entry->descr->function->result;
		}
		return NULL; /* TODO: (?) */
	}
}

static SymbEntry *processParams(TreeNode *p, int *displ)
{
	if (!p) /* if there are no parameters */
		return NULL;
	TreeNode *paramList = p->components[0]; /* TODO: reverse? */
	ParamDescr *paramsDescr = NULL;
	SymbEntry *params = NULL, *curr;
	while (paramList) {
		TreeNode *param = paramList->components[0];
		TypeDescr *type = getType(param->components[1]);
		TreeNode *identList = param->components[0]; /* TODO: reverse? */
		while (identList) {
			char *ident = identList->components[0]->symbol;
			Descr *descr;
			if (param->categ == C_REF_PARAM)
				descr = newParamDescr(*++displ, type, P_REF); /* TODO: check displ */
			else if (param->categ == C_VAL_PARAM)
				descr = newParamDescr(*++displ, type, P_VAL); /* TODO: check displ */
			curr = newSymbEntry(S_PARAM, ident, currentLevel, descr);
			if (!params)
				params = curr;
			curr->next = params;
			params = curr;
			identList = identList->next;
		}
		paramList = paramList->next;
	}

	/* DEBUGGING */
	for (SymbEntry *curr = params; curr != NULL; curr = curr->next) {
		printf("param ident: %s\n", curr->ident);
	}	

	return params;
}

static char *mepaBinOp(TreeNode *p)
{
	/* C_ADDOP, C_RELOP, C_MULOP */
	switch (p->components[0]->categ) {
		case C_PLUS:
			return "ADDD";
		case C_MINUS:
			return "SUBT";
		case C_MULTIPLY:
			return "MULT";
		default: /* TODO: remove later */
			printf("Op not implemented yet\n");
			exit(1);
	}
}

static bool compatibleTypes(TreeNode *p, TypeDescr *type1, TypeDescr *type2)
{
	if (p->categ == C_RELOP) {
		return type1->predefType == T_BOOLEAN && type2->predefType == T_BOOLEAN;
	} else {
		return type1->predefType == T_INTEGER && type2->predefType == T_INTEGER;
	}
}

static TypeDescr *processTerms(TreeNode *p)
{
	TreeNode *terms = reverse(p);
	TreeNode *op = NULL;
	TypeDescr *prevType = NULL, *currType;
	while (terms) {
		bool singleFactor = terms->components[0]->categ == C_FACTOR;
		if (singleFactor)
			currType = processFactor(terms->components[0]);
		else {
			op = terms->components[0];
			currType = processFactor(terms->components[1]);
		} 
		if (op) {
			if (prevType && !compatibleTypes(op, prevType, currType)) {
				printf("semantic error: incompatible types\n");
				exit(1);
			}
			printf("%s\n", mepaBinOp(op));
		}
		prevType = currType;
		terms = terms->next;
	}
	return currType;
}

static TypeDescr *processFactor(TreeNode *p)
{
	Categ categ = p->components[0]->categ;
	if (categ == C_VARIABLE) {
		char *ident = p->components[0]->components[0]->symbol;
		SymbEntry *entry = searchSymbEntry(ident);
    	if (!entry)
        	printf("semantic error: %s undefined\n", ident);
    	if (entry->categ != S_VAR && entry->categ != S_PARAM)
	      	printf("semantic error: %s not variable nor parameter\n", entry->ident);

    	/* !!! TODO: fix instructions !!! */
		if (entry->categ == S_PARAM) {
        	int level = entry->level;
        	int displ = entry->descr->parameter->displ;
        	Passage pass = entry->descr->parameter->pass;
        	if (pass == P_REF)
            	printf("STVI %d,%d\n", level, displ);
        	else
            	printf("STVL %d,%d\n", level, displ);
			return entry->descr->parameter->type;
    	} else {
        	printf("LDVL %d,%d\n", entry->level, entry->descr->variable->displ);
			return entry->descr->variable->type;
		}
		/* !!! */
	} else if (categ == C_INTEGER) {
      	printf("LDCT %s\n", p->components[0]->symbol);
     	return newTypeDescr(1, T_INTEGER)->type;
	} else if (categ == C_BOOLEAN) {
		printf("LDCT %c\n", strcmp(p->components[0]->symbol, "true") == 0 ? '1' : '0');
		return newTypeDescr(1, T_BOOLEAN)->type;
	} else if (categ == C_FUNCTION_CALL) {
		return processFuncCall(p->components[0]);
	} else if (categ == C_EXPRESSION) {
		return processExpr(p->components[0]);
	} else {
		printf("error: not a C_FACTOR");
		exit(1);	
	}
}

static TypeDescr *processSimpExpr(TreeNode *p)
{
	TreeNode *exprs = reverse(p);
	TreeNode *op = NULL;
	TypeDescr *prevType = NULL, *currType;
	while (exprs) {
		bool singleTerm = exprs->components[0]->categ == C_TERMS;
		if (singleTerm)
			currType = processTerms(exprs->components[0]);
		else {
			op = exprs->components[0];
			currType = processTerms(exprs->components[1]);
		}
		if (op) {
			if (prevType && !compatibleTypes(op, prevType, currType)) {
				printf("semantic error: incompatible types\n");
				exit(1);
			}
			printf("%s\n", mepaBinOp(op));
		}
		prevType = currType;
		exprs = exprs->next;
	}
	return currType;
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
        printf("semantic error: %s undefined\n", ident);
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
    SymbEntry *params;
    if (isVoidFunc(header)) {
        name = header->components[0]->symbol;
		params = processParams(header->components[1], &lastDispl);
	} else {
        name = header->components[1]->symbol;
		params = processParams(header->components[2], &lastDispl);
        resType = getType(header->components[0]);
    }
    if (resType) /* if function returns value, reserve positions for return value */
        lastDispl -= resType->size;
    Descr *funcDescr = newFuncDescr(lastDispl, resType, params);
    SymbEntry *funcEntry = newSymbEntry(S_FUNC, name, currentLevel - 1, funcDescr);
    insertSymbolTable(funcEntry);
	saveSymbolTable();
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
		restoreSymbolTable();
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
