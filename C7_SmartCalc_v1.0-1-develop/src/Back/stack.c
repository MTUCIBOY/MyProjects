#include "main.h"

stack_n *init_stack_n(size_t size_nums) {
  stack_n *stack = (stack_n *)malloc(sizeof(stack_n));

  if (stack == NULL) exit(OUT_OF_MEMORY);

  stack->nums = (double *)malloc(size_nums * sizeof(double));

  if (stack->nums == NULL) exit(OUT_OF_MEMORY);

  stack->size_nums = size_nums;
  stack->top_nums = -1;

  return stack;
}

stack_l *init_stack_l(size_t size_lexemes) {
  stack_l *stack = (stack_l *)malloc(sizeof(stack_l));

  if (stack == NULL) exit(OUT_OF_MEMORY);

  stack->lexemes = (char *)malloc(size_lexemes * sizeof(char));

  if (stack->lexemes == NULL) exit(OUT_OF_MEMORY);

  stack->size_lexemes = size_lexemes;
  stack->top_lexemes = -1;

  return stack;
}

bool isEmptyNum(stack_n *stack) { return stack->top_nums == -1 ? 1 : 0; }
bool isEmptyLexeme(stack_l *stack) { return stack->top_lexemes == -1 ? 1 : 0; }
double popNum(stack_n *stack) { return stack->nums[stack->top_nums--]; }
char popLexeme(stack_l *stack) { return stack->lexemes[stack->top_lexemes--]; }
double headNum(stack_n *stack) { return stack->nums[stack->top_nums]; }
char headLexeme(stack_l *stack) { return stack->lexemes[stack->top_lexemes]; }

void pushNum(stack_n *stack, double num) {
  if (stack->size_nums - 1 == stack->top_nums) {
    stack->size_nums *= 2;
    stack->nums =
        (double *)realloc(stack->nums, stack->size_nums * sizeof(double));

    if (stack->nums == NULL) exit(OUT_OF_MEMORY);
  }

  stack->nums[++stack->top_nums] = num;
}

void pushLexeme(stack_l *stack, char lexeme) {
  if (stack->size_lexemes - 1 == stack->top_lexemes) {
    stack->size_lexemes *= 2;
    stack->lexemes =
        (char *)realloc(stack->lexemes, stack->size_lexemes * sizeof(char));

    if (stack->lexemes == NULL) exit(OUT_OF_MEMORY);
  }

  stack->lexemes[++stack->top_lexemes] = lexeme;
}

void free_stack_n(stack_n *stack) {
  if (stack->nums) free(stack->nums);
  free(stack);
}

void free_stack_l(stack_l *stack) {
  if (stack->lexemes) free(stack->lexemes);
  free(stack);
}
