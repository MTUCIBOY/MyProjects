#include "s21_calculator.h"

node* init_node(int priority, char operand, double num) {
  node* node_1 = (node*)malloc(sizeof(node));

  node_1->priority = priority;
  node_1->operand = operand;
  node_1->num = num;
  node_1->next = NULL;

  return node_1;
}

// ( + , - ) - 0;
// ( * , / ) - 1;
// ( sin , cos ) - 2;
// ( ^ ) - 3;
// ),( - 4;

node* get_last(node* node_1) {
  if (node_1 == NULL) {
    return NULL;
  }

  if (node_1->next != NULL)
    return get_last(node_1->next);
  else
    return node_1;
}

void push(node** list, int priority, char operand, double num) {
  node* node_1 = init_node(priority, operand, num);

  node_1->next = *list;
  *list = node_1;
}

void push_back(node** list, int priority, char operand, double num) {
  if (*list != NULL) {
    node* tmp = get_last(*list);

    node* node_1 = init_node(priority, operand, num);

    tmp->next = node_1;

  } else {
    push(list, priority, operand, num);
  }
}

void push_node(node** list, node* node_1) {
  node_1->next = *list;
  *list = node_1;
}

node* pop(node** list) {
  node* tmp = NULL;

  if (*list != NULL) {
    tmp = *list;
    if ((*list)->next != NULL)
      *list = (*list)->next;
    else
      *list = NULL;

    tmp->next = NULL;

  } else
    return tmp;

  return tmp;
}
