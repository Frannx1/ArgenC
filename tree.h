#ifndef tree_h
#define tree_h

#define BOOL_TRUE 1
#define BOOL_FALSE 0

typedef enum
{
	TRUE_LITERAL,
	FALSE_LITERAL,
	BOOL_AND,
	BOOL_NOT,
	BOOL_OR,
	COMP_LT,
	COMP_LE,
	COMP_EQ,
	COMP_NEQ,
	COMP_GT,
	COMP_GE
} bool_operation;


typedef enum{
	VARIABLE,
	INT_LITERAL,
	FLOAT_LITERAL,
	STR_LITERAL,
	ARRAY_LITERAL,
	INDEXED_ARRAY,
	NESTED_INDEXING,
	ARIT_UNARY_MINUS,
	ARIT_SUM,
	ARIT_SUB,
	ARIT_PROD,
	ARIT_DIV
} expr_type;


typedef enum{
	ASSIGNMENT,
	ARRAY_ASSIGNMENT,
	PRINT_CALL,
	WHILE_LOOP,
	FOREACH_LOOP,
	FOR_LOOP,
	IF_THEN_ELSE,
	EXIT_CALL,
	FUNCTION_CALL
} stmnt_type;


typedef enum{
	ARR_APPEND,
	TO_UPPER,
	TO_LOWER,
	INCREMENT,
	DECREMENT,
	SCAN_READ,
	SCAN_READ_ARR
} fn_type;

typedef struct StNode{
	stmnt_type type;
	void * body;
	struct StNode * next;
} StatementList;

typedef struct fncall{
	fn_type function;
	void* first;
	void* second;
	void* third;
} FunctionNode;

typedef struct block{
	void * node;
	stmnt_type type;
} Block;

typedef struct bc{
	bool_operation type;
	void * left;
	void * right;
} BoolNode;

typedef struct ar_n{
	expr_type type;
	void * left;
	void * right;
} ExpressionNode;

typedef struct expList{
	ExpressionNode * expression;
	struct expList* next;
} ExpressionList;

typedef struct asn{
	int var_id;
	ExpressionNode * value;
} AssignmentNode;

typedef struct wn{
	BoolNode * condition;
	StatementList * body;
} WhileNode;

typedef struct fen{
	int  list;
	int  current;
	StatementList * body;
} ForeachNode;

typedef struct fn{
	int  list;
	AssignmentNode * asig;
	BoolNode * condition;
	StatementList * body;
} ForNode;

typedef struct in{
	BoolNode * condition;
	StatementList * body;
	struct in * elseif;
} IfNode;

typedef struct arr_as {
	ExpressionNode * array;
	ExpressionNode * value;
} ArrayAssignment;

void produce(StatementList * block);

#endif
