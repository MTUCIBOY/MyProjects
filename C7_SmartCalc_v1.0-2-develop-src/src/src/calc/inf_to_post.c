#include <stdio.h>
#include <stdlib.h>

#include "s21_calculator.h"

void inf_to_post(node** list_1) {
  node* stack = NULL;
  node* exit = NULL;

  int priority_count = 0;

  while (*list_1 != NULL) {
    if ((*list_1)->operand == ')') {
      free(pop(list_1));
      extract(&stack, &exit, 5);

      if (stack == NULL)
        priority_count = 0;
      else
        priority_count = stack->priority;

    } else if ((*list_1)->operand == '(') {
      priority_count = 0;
      push_node(&stack, pop(list_1));

    } else if ((*list_1)->operand == 'n') {
      push_node(&exit, pop(list_1));

    } else if ((*list_1)->priority > priority_count) {
      priority_count = (*list_1)->priority;
      push_node(&stack, pop(list_1));

    } else {
      extract(&stack, &exit, priority_count);

      if (stack == NULL || stack->operand == '(') {
        priority_count = 0;
      } else {
        priority_count = stack->priority;
      }
    }
  }
  if (stack != NULL) extract(&stack, &exit, 5);

  while (exit != NULL) push_node(list_1, pop(&exit));

  // num - 0;
  // ( + , - ) - 1;
  // ( * , / ) - 2;
  // ( sin , cos ) - 3;
  // ( ^ ) - 4;
  // ),( - 5;
}

void extract(node** list_1, node** list_2, int priority_count) {
  while (*list_1 != NULL) {
    if (priority_count < (*list_1)->priority) {
      break;
    }

    if ((*list_1)->operand == '(') {
      free(pop(list_1));
      break;
    }

    push_node(list_2, pop(list_1));
  }
}
