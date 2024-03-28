#include "main.h"

const char p0[] = "+-)";
const char p1[] = "*/";
const char p2[] = "^";
const char p3[] = "cossintanacosasinatansqrtlnlogmod";
const char p4[] = "(";
const char *priority[] = {p0, p1, p2, p3, p4};

double calc(char *expression, bool *error) {
  *error = 0;
  char copy_expression[strlen(expression)];
  strcpy(copy_expression, expression);

  char *current_item = strtok(copy_expression, " ");
  stack_n *stack_priority = init_stack_n(4), *polish_nums = init_stack_n(4);
  stack_l *polish_lexeme = init_stack_l(4);
  size_t num_of_priority = 0;
  char *lexeme = NULL;
  double num = 0, result = 0;
  bool flag_minus = 0;

  while (current_item) {
    /* Num processing */
    if ((*current_item >= '0' && *current_item <= '9') ||
        *current_item == '.' ||
        (*current_item == '-' && current_item[1] != '\0')) {
      if (sscanf(current_item, "%lf", &num) == 0) *error = 1;
      if (flag_minus) {
        num *= -1;
      }
      pushNum(polish_nums, num);
      current_item = strtok(NULL, " ");
      continue;
    }
    flag_minus = 0;

    /* Finding lexeme */
    while (lexeme == NULL && num_of_priority < 5) {
      lexeme = strstr(priority[num_of_priority], current_item);
      num_of_priority++;
    }
    num_of_priority--;

    if (lexeme == NULL) {
      *error = 1;
      break;
    }

    /* If lexeme is func */
    if (num_of_priority == 3) {
      lexeme = switch_funcs(lexeme);
    }

    if (*lexeme == '-') {
      flag_minus = 1;
      if (!isEmptyNum(polish_nums) &&
          ((current_item[2] >= '0' && current_item[2] <= '9') ||
           current_item[2] == '.'))
        lexeme = "+";
      else if (isEmptyNum(polish_nums)) {
        num_of_priority = 0;
        lexeme = NULL;
        current_item = strtok(NULL, " ");
        continue;
      }
    }

    /* Push in result */
    while (!isEmptyLexeme(polish_lexeme) && !(*error) &&
           num_of_priority <= headNum(stack_priority) &&
           headLexeme(polish_lexeme) != '(') {
      *error = calc_expression(popLexeme(polish_lexeme), polish_nums);
      popNum(stack_priority);
    }

    if (*error) break;

    /* Wipe open backet */
    if (!isEmptyLexeme(polish_lexeme) && *lexeme == ')' &&
        headLexeme(polish_lexeme) == '(')
      polish_lexeme->top_lexemes--;

    /* Push current lexeme in stack */
    if (*lexeme != ')') {
      pushLexeme(polish_lexeme, *lexeme);
      pushNum(stack_priority, num_of_priority);
    }
    num_of_priority = 0;
    lexeme = NULL;
    current_item = strtok(NULL, " ");
  }

  /* Calc remiender lexemes in stack */
  while (!(*error) && !isEmptyLexeme(polish_lexeme))
    *error = calc_expression(popLexeme(polish_lexeme), polish_nums);

  if (!isEmptyLexeme(polish_lexeme) || polish_nums->top_nums != 0) *error = 1;

  result = *error ? 0 : popNum(polish_nums);

  free_stack_l(polish_lexeme);
  free_stack_n(stack_priority);
  free_stack_n(polish_nums);

  return result;
}

char *switch_funcs(char *lexeme) {
  switch ((long int)(lexeme - p3)) {
    case COS:
      lexeme = "A";
      break;
    case SIN:
      lexeme = "B";
      break;
    case TAN:
      lexeme = "C";
      break;
    case ACOS:
      lexeme = "D";
      break;
    case ASIN:
      lexeme = "E";
      break;
    case ATAN:
      lexeme = "F";
      break;
    case SQRT:
      lexeme = "G";
      break;
    case LN:
      lexeme = "H";
      break;
    case LOG:
      lexeme = "I";
      break;
    case MOD:
      lexeme = "M";
      break;
  }

  return lexeme;
}

double calc_binary(double first_arg, double second_arg, char operation) {
  double result = 0;

  switch (operation) {
    case '+':
      result = first_arg + second_arg;
      break;
    case '-':
      result = first_arg - second_arg;
      break;
    case '*':
      result = first_arg * second_arg;
      break;
    case '/':
      result = first_arg / second_arg;
      break;
    case '^':
      result = pow(first_arg, second_arg);
      break;
    case 'M':
      result = fmod(first_arg, second_arg);
      break;
  }

  return result;
}

double calc_unary(double arg, char operation) {
  double result = 0;

  switch (operation) {
    case 'A':
      result = cos(arg);
      break;
    case 'B':
      result = sin(arg);
      break;
    case 'C':
      result = tan(arg);
      break;
    case 'D':
      result = acos(arg);
      break;
    case 'E':
      result = asin(arg);
      break;
    case 'F':
      result = atan(arg);
      break;
    case 'G':
      result = sqrt(arg);
      break;
    case 'H':
      result = log(arg);
      break;
    case 'I':
      result = log10(arg);
      break;
  }

  return result;
}

bool calc_expression(char operation, stack_n *nums) {
  double first_arg = 0, second_arg = 0;
  bool code = 0;
  if (!isEmptyNum(nums) && operation >= 'A' && operation <= 'I') {
    first_arg = popNum(nums);
    pushNum(nums, calc_unary(first_arg, operation));
  } else if (nums->top_nums > 0) {
    second_arg = popNum(nums);
    first_arg = popNum(nums);
    pushNum(nums, calc_binary(first_arg, second_arg, operation));
  } else
    code = 1;
  return code;
}
