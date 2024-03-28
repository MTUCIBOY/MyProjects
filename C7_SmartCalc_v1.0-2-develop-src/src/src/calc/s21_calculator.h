#ifndef LIST_PROC_H
#define LIST_PROC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int priority;
  char operand;
  double num;
  struct node* next;

} node;

// ( + , - ) - 0;
// ( * , / ) - 1;
// ( sin , cos ) - 2;
// ( ^ ) - 3;
// ),( - 4;

node* init_node(int priority, char operand, double num);
node* get_last(node* node_1);

void push_node(node** list, node* node_1);
void push(node** list, int priority, char operand, double num);
void push_back(node** list, int priority, char operand, double num);
node* pop(node** list);

// parser

int get_infix_list(char* str, node** list_1, double x);

int check_functions(char* str, int* counter);
int check_nums(char* str, int* count, double* num);
void init_function(node** list, int num);

// infix to postfix

void inf_to_post(node** list_1);
void extract(node** list_1, node** list_2, int priority_count);

// calculate

int calc_main(char* str, double* result, double x);
int calculate(node** list_1, double* res);
int operate(node** list_1, node** stack);

#endif
