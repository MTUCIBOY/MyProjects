/*!
 * \file
 * \brief Back headerfile.
 *
 * Here all libs, structs and declaration functions used in back part of project
 */
#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*!
 * \brief Macro used in stack functions. It is used when the system has not
 * allocated memory after malloc call. It is only necessary for readability.
 */
#define OUT_OF_MEMORY 1

/*!
 * \brief Enum is necessary for defining the function in calculations.
 *
 * The value of the parameters is determined by the difference between the
 * beginning of the string and the pointer to the current string element. The
 * string is located in the file parcer_calc.c, called p3[]. It contains the
 * names of all functions.
 */
enum funcs {
  COS = 0,
  SIN = 3,
  TAN = 6,
  ACOS = 9,
  ASIN = 13,
  ATAN = 17,
  SQRT = 21,
  LN = 25,
  LOG = 27,
  MOD = 30
};

/*!
 * \brief Structure representing a stack for numbers
 *
 * \param nums - mas pointer
 * \param size_nums - how much memory we have
 * \param top_nums - top of stack, index last item in stack
 */
typedef struct stack_nums {
  double *nums;
  int size_nums;
  int top_nums;
} stack_n;

/*!
 * \brief Struct like stack_n, but use char pointer
 */
typedef struct stack_lexems {
  char *lexemes;
  int size_lexemes;
  int top_lexemes;
} stack_l;

/* Stack funcs */
stack_n *init_stack_n(size_t size_nums);
stack_l *init_stack_l(size_t size_lexemes);
bool isEmptyNum(stack_n *stack);
bool isEmptyLexeme(stack_l *stack);
double popNum(stack_n *stack);
char popLexeme(stack_l *stack);
double headNum(stack_n *stack);
char headLexeme(stack_l *stack);
void pushNum(stack_n *stack, double num);
void pushLexeme(stack_l *stack, char lexeme);
void free_stack_n(stack_n *stack);
void free_stack_l(stack_l *stack);

/* Calc funcs */

/*!
 * \brief Basic function to translate from infix notation to Polish notation and
 * set the result.
 *
 * The function uses two stacks, one for numbers and one for
 * tokens. It translates the string from infix notation to Polish and when the
 * first numbers are ready to be counted, it immediately counts them and returns
 * the result to the stack with numbers. This algorithm takes place until the
 * end of the string.
 *
 * \warning If there are some elements left in the stacks,
 * the function considers it an error and the code parameter becomes 1 and the
 * result is 0. The same happens if an unknown element is found in the string.
 *
 * \param[in] expression Expression string.
 * \param[out] code Status code; 1 - error, 0 - no error.
 *
 * \return The function returns the result of calculating an expression of
 * double type.
 */
double calc(char *expression, bool *error);
/*!
 * \brief Function for defining the current function
 *
 * The switch function, which I've put separately so that it doesn't bloat the
 * code of the calc function.
 */
char *switch_funcs(char *lexeme);
/*!
 * \brief Function for counting binary operations.
 */
double calc_binary(double first_arg, double second_arg, char operation);
/*!
 * \brief Function for counting unary operations.
 */
double calc_unary(double arg, char operation);
/*!
 * \brief Function for calling calc_unary and calc_binary functions.
 */
bool calc_expression(char operation, stack_n *nums);

#endif  // MAIN_H
