#include "s21_calculator.h"

int calc_main(char* str, double* result, double x) {
  node* list_1 = NULL;
  int res = 0;
  *result = 0;

  if (!(res = get_infix_list(str, &list_1, x))) {
    inf_to_post(&list_1);

    res = calculate(&list_1, result);

  } else {
    while (list_1 != NULL) free(pop(&list_1));
  }

  return res;
}

int calculate(node** list_1, double* res) {
  node* stack = NULL;

  int check = 0;

  while (*list_1 != NULL) {
    if ((*list_1)->operand == 'n') {
      push_node(&stack, pop(list_1));
    } else {
      check = operate(list_1, &stack);
      if (check) {
        break;
      }
    }
  }

  if (stack != NULL && stack->next == NULL)
    *res = stack->num;
  else
    *res = 0;

  while (stack != NULL) free(pop(&stack));

  return check;
}

int operate(node** list_1, node** stack) {
  if ((*stack) == NULL) {
    return 1;
  }

  if ((*stack)->operand != 'n') {
    return 1;
  }

  int res = 0;

  double num1 = 0;
  double num2 = 0;

  char operand = (*list_1)->operand;
  free(pop(list_1));

  switch (operand) {
    case 's':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', sin(num1));
      break;
    case 'c':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', cos(num1));
      break;
    case 't':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', tan(num1));
      break;
    case 'S':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', asin(num1));
      break;
    case 'C':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', acos(num1));
      break;
    case 'T':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', atan(num1));
      break;
    case 'q':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', sqrt(num1));
      break;
    case 'l':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', log(num1));
      break;
    case 'L':
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', log10(num1));
      break;

    case 'm':
      if ((*stack)->next == NULL || (*stack)->next->operand != 'n') {
        res = 1;
        break;
      }
      num2 = (*stack)->num;
      free(pop(stack));
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', fmod(num1, num2));
      break;

    case '+':
      if ((*stack)->next == NULL || (*stack)->next->operand != 'n') {
        res = 1;
        break;
      }
      num1 = (*stack)->num;
      free(pop(stack));
      num2 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', num1 + num2);
      break;
    case '-':
      if ((*stack)->next == NULL || (*stack)->next->operand != 'n') {
        res = 1;
        break;
      }
      num2 = (*stack)->num;
      free(pop(stack));
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', num1 - num2);
      break;
    case '/':
      if ((*stack)->next == NULL || (*stack)->next->operand != 'n') {
        res = 1;
        break;
      }
      num2 = (*stack)->num;
      free(pop(stack));
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', num1 / num2);
      break;
    case '*':
      if ((*stack)->next == NULL || (*stack)->next->operand != 'n') {
        res = 1;
        break;
      }
      num1 = (*stack)->num;
      free(pop(stack));
      num2 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', num1 * num2);
      break;

    case '^':
      if ((*stack)->next == NULL || (*stack)->next->operand != 'n') {
        res = 1;
        break;
      }
      num2 = (*stack)->num;
      free(pop(stack));
      num1 = (*stack)->num;
      free(pop(stack));
      push(stack, 0, 'n', pow(num1, num2));
      break;
  }

  return res;
}
