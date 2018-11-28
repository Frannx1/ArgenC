#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"

#define STR_OVERHEAD 25
#define MAX_DIGITS 30

void generatePrint(ExpressionNode *node);
void generateAssign(AssignmentNode *node);
void generateWhile(WhileNode *node);
void generateIf(IfNode *node);
void generateFunctionCall(FunctionNode *node);
void generateForEach(ForeachNode *node);
void generateFor(ForNode *node);
void generateExit(void);
void generateBoolBinary(BoolNode *node, char* op);
void generateBoolCondition(BoolNode *node);
void generateBoolComparison(BoolNode *node, char* op);
void generateEquals(BoolNode *node);
void generateNotEquals(BoolNode *node);
char* getExpression(ExpressionNode *operation);
char * getArithmeticBinary(ExpressionNode *expr, char *funcName);
void generateAssignmentOfArrayment(ArrayAssignment *array);

void realize(StatementList *block) {
	while(block != NULL) {
		switch(block->type) {
			case ASSIGNMENT:
				generateAssign((AssignmentNode*)block->body);
				break;

			case ARRAY_ASSIGNMENT:
				generateAssignmentOfArrayment((ArrayAssignment*)block->body);
				break;

			case PRINT_CALL:
				generatePrint((ExpressionNode*)block->body);
				break;

			case WHILE_LOOP:
				generateWhile((WhileNode*) block->body);
				break;

			case IF_THEN_ELSE:
				generateIf((IfNode*)block->body);
				break;

			case FUNCTION_CALL:
				generateFunctionCall((FunctionNode*)block->body);
				break;

			case EXIT_CALL:
				generateExit();
				break;

			case FOREACH_LOOP:
				generateForEach((ForeachNode*)block->body);
				break;

			case FOR_LOOP:
				generateFor((ForNode*)block->body);
				break;

			default:
				break;
		}
		StatementList *prev = block;
		block = block->next;
		free(prev);
	}
}

void generateFunctionCall(FunctionNode *node) {
	switch(node->function) {
		case ARR_APPEND: 
		{
			char *expr = getExpression(node->second);
			printf("append(%d, %s);\n", *((int*)node->first), expr);
			free(expr);
			break;
		}
		case TO_UPPER:
			printf("toUpperString(%d);\n", *((int*)node->first));
			break;
		case TO_LOWER:
			printf("toLowerString(%d);\n", *((int*)node->first));
			break;
		case INCREMENT:
			printf("inc(%d);\n", *((int*)node->first));
			break;
		case DECREMENT:
			printf("dec(%d);\n", *((int*)node->first));
			break;
		case SCAN_READ:
			printf("scan(%d, %d);\n", *((int*)node->first), *((int*)node->second));
			break;
		default:
			fprintf(stderr, "Error. Operacion desconocida: %d", node->function);
			exit(1);
			break;
	}
}

void generateWhile(WhileNode *node) {
	printf("\n\nwhile(");
	generateBoolCondition(node->condition); 
	printf(") {\n");
	realize(node->body);
	printf("}\n\n");

}

void generateForEach(ForeachNode * node) {
	printf("resetIterator(getVariable(%d));", node->list);
	printf("\n\nwhile(hasNext(getVariable(%d))) {\n", node->list);
	printf("assign(%d, next(getVariable(%d)));\n", node->current,  node->list);
	realize(node->body);
	printf("}\n\n");
}

void generateFor(ForNode * node) {
	printf("\n\nfor(");
	generateAssign(node->asig);
	generateBoolCondition(node->condition);
	printf(";");	
	printf(") {\n");
	realize(node->body);
	printf("}\n\n");

}


void generateIf(IfNode *node) {
	printf("\n\nif(");
	generateBoolCondition(node->condition);
	printf("){\n");
	realize(node->body);
	printf("}\n");

	while(node->elseif != NULL) {
		node = node->elseif;
		printf("else if(");
		generateBoolCondition(node->condition);
		printf("){\n");
		realize(node->body);
		printf("} ");
	}


}


void generateAssign(AssignmentNode *node) {
	char * expression = getExpression(node->value);
	printf("assign(%d, %s);\n", node->var_id, expression);
	free(expression);
}


void generateAssignmentOfArrayment(ArrayAssignment *a) {
	ExpressionNode* array = a->array;
	ExpressionNode* value = a->value;
	printf("assignmentOfArray(");
	switch(array->type) {
		case INDEXED_ARRAY:
		{
			char * idx = getExpression((ExpressionNode*)array->right);
			char * val = getExpression(value);
			printf("getVariable(%d), %s, %s);\n", *((int*)array->left), idx, val);

			free(idx);

			break;
		}

		case NESTED_INDEXING:
		{
			char * idx = getExpression((ExpressionNode*)array->right);
			char * ary = getExpression((ExpressionNode*)array->left);
			char * val = getExpression(value);
			printf("%s, %s, %s);", ary, idx, val);
			free(idx);
			break;
		}

		default:
			break;

	}
}


void generatePrint(ExpressionNode *node) {
	char * expr = getExpression(node);
	printf("printVariable(%s, 1);\n", expr);
	free(expr);
}

void generateBoolCondition(BoolNode *node) {
	switch(node->type) {

		case TRUE_LITERAL:
			printf("%d", BOOL_TRUE);
			break;

		case FALSE_LITERAL:
			printf("%d", BOOL_FALSE);
			break;

		case BOOL_NOT:
			printf("!");
			generateBoolCondition((BoolNode*)node->left);
			break;

		case BOOL_AND:
			generateBoolBinary(node, "&&");
			break;

		case BOOL_OR:
			generateBoolBinary(node, "||");
			break;

		case COMP_LT:
			generateBoolComparison(node, "<");
			break;

		case COMP_LE:
			generateBoolComparison(node, "<=");
			break;

		case COMP_EQ:
			generateEquals(node);
			break;

		case COMP_NEQ:
			generateNotEquals(node);
			break;

		case COMP_GT:
			generateBoolComparison(node, ">");
			break;

		case COMP_GE:
			generateBoolComparison(node, ">=");
			break;
	}
}


void generateBoolBinary(BoolNode *node, char *op) {
	printf("(");
	generateBoolCondition((BoolNode*)node->left);
	printf(" %s ", op);
	generateBoolCondition((BoolNode*)node->right);
	printf(")");
}

void generateBoolComparison(BoolNode *node, char *op) {
	char * first = getExpression((ExpressionNode*)node->left);
	char * second = getExpression((ExpressionNode*)node->right);

	printf("(compare(%s, %s) %s 0)", first, second, op);
	free(first);
	free(second);
}

void generateEquals(BoolNode *node) {
	char * first = getExpression((ExpressionNode*)node->left);
	char * second = getExpression((ExpressionNode*)node->right);

	printf("(areEquals(%s, %s))", first, second);
	free(first);
	free(second);
}

void generateNotEquals(BoolNode *node) {
	printf("!");
	generateEquals(node);
}

void generateExit(){
	printf("exit(0);\n");
}


char* getExpression(ExpressionNode *node) {
	char * result;
	switch(node->type) {
		case VARIABLE:
		{
			result = malloc(STR_OVERHEAD + MAX_DIGITS);
			sprintf(result, "getVariable(%d)", *(int*)node->left);
			free(node->left);
			break;
		}
		case STR_LITERAL:
		{
			char * str = (char*)node->left;
			result = malloc(STR_OVERHEAD + strlen(str));
			sprintf(result, "anonString(\"%s\")", str);
			free(node->left);
			break;
		}

		case INT_LITERAL:
		{
			result = malloc(STR_OVERHEAD + MAX_DIGITS);
			sprintf(result, "anonInteger(%d)", *((int*)node->left));
			free(node->left);
			break;
		}

		case FLOAT_LITERAL:
		{
			result = malloc(STR_OVERHEAD + MAX_DIGITS);
			sprintf(result, "anonFloat(%.5f)", *((float*)node->left));
			free(node->left);
			break;
		}

		case ARRAY_LITERAL:
		{
				result = malloc(STR_OVERHEAD);
				sprintf(result, "anonArray(%d", *((int*)node->right));
				ExpressionList * list = (ExpressionList*)node->left;
				while(list != NULL){
					char * expr = getExpression(list->expression);
					int len = strlen(result);
					result = realloc(result, len + strlen(expr) + 3);
					sprintf(result+len, ", %s", expr);
					free(expr);
					list = list->next;
				}
				int len = strlen(result);
				result = realloc(result, len + 2);
				sprintf(result+len, ")");

				return result;
			}

		case INDEXED_ARRAY:
		{
			char * idx = getExpression((ExpressionNode*)node->right);
			result = malloc(STR_OVERHEAD + strlen(idx));
			sprintf(result, "indexOfArray(getVariable(%d), %s)", *((int*)node->left), idx);
			free(idx);
			break;
		}

		case NESTED_INDEXING:
		{
			char * idx = getExpression((ExpressionNode*)node->right);
			char * ary = getExpression((ExpressionNode*)node->left);

			result = malloc(STR_OVERHEAD + strlen(idx) + strlen(ary));
			sprintf(result, "indexOfArray(%s, %s)", ary, idx);
			free(idx);

			break;
		}

		case ARIT_UNARY_MINUS: {
			char * expr = getExpression((ExpressionNode*)node->left);
			result = malloc(strlen(expr) + STR_OVERHEAD);
			sprintf(result, "minus(%s)", expr);

			free(expr);
			break;
		}

		case ARIT_SUM:
		{
			result = getArithmeticBinary(node, "sum");

			break;
		}


		case ARIT_SUB:
		{
			result = getArithmeticBinary(node, "substract");

			break;
		}

		case ARIT_PROD:
		{
			result = getArithmeticBinary(node, "product");
			break;
		}

		case ARIT_DIV:
		{
			result = getArithmeticBinary(node, "division");
		}

	}
	free(node);

	return result;
}

char * getArithmeticBinary(ExpressionNode *node, char *funcName){
			char * left = getExpression((ExpressionNode*)node->left);
			char * right = getExpression((ExpressionNode*)node->right);
			char * result = malloc(STR_OVERHEAD + strlen(left) + strlen(right) + 1);
			sprintf(result, "%s(%s, %s)", funcName, left, right);
			free(left);
			free(right);
			return result;
}

