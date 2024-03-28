#include "s21_calculator.h"

int get_infix_list(char* str, node** list_1, double x) {
  *list_1 = NULL;

  int brack_count = 0;
  int counter = 0;
  int res = 0;
  double num = 0;
  int length = strlen(str);
  while (counter < length) {
    if ((str[counter] >= 'a') && (str[counter] <= 'z')) {
      if (str[counter] == 'x') {
        push_back(list_1, 0, 'n', x);
        counter++;
      } else {
        res = check_functions(str + counter, &counter);

        if (res < 0)
          break;
        else {
          init_function(list_1, res);
          res = 0;
        }
      }

    } else if (str[counter] == '(') {
      push_back(list_1, 5, '(', 0.0);

      if ((counter < length - 1) && (str[counter + 1] == '-')) {
        push_back(list_1, 0, 'n', 0.0);
      }

      brack_count++;
      counter++;

    } else if (str[counter] == ')') {
      push_back(list_1, 5, ')', 0.0);
      brack_count--;
      counter++;

    } else if (((str[counter] > 47) && (str[counter] < 58)) ||
               str[counter] == '.') {
      res = check_nums(str, &counter, &num);

      if (res != 0) break;

      push_back(list_1, 0, 'n', num);

      counter++;

    } else if ((str[counter] == '+') || (str[counter] == '-') ||
               (str[counter] == '*') || (str[counter] == '/') ||
               (str[counter] == '^')) {
      if (str[counter] == '^') push_back(list_1, 4, str[counter], 0.0);

      if ((str[counter] == '+') || (str[counter] == '-')) {
        if ((str[counter] == '-') && counter == 0)
          push_back(list_1, 0, 'n', 0.0);

        push_back(list_1, 1, str[counter], 0.0);
      }

      if ((str[counter] == '*') || (str[counter] == '/'))
        push_back(list_1, 2, str[counter], 0.0);

      counter++;

    } else {
      counter++;
    }
  }

  if (res < 0 || brack_count != 0) {
    return 1;
  } else {
    return 0;
  }
}

int check_functions(char* str, int* counter) {
  int res = -1;

  char* math[10];

  math[0] = "sin";
  math[1] = "cos";
  math[2] = "tan";
  math[3] = "asin";
  math[4] = "acos";
  math[5] = "atan";
  math[6] = "sqrt";
  math[7] = "ln";
  math[8] = "log";
  math[9] = "mod";

  for (int i = 0; i < 10; i++) {
    if (strncmp(str, math[i], strlen(math[i])) == 0) {
      /*printf("match: %s\n", math[i]);*/
      *counter += strlen(math[i]);
      res = i;
      break;
    }
  }

  return res;
}
// num - 0;
// ( + , - ) - 1;
// ( * , / ) - 2;
// ( sin , cos ) - 3;
// ( ^ ) - 4;
// ),( - 5;

void init_function(node** list, int num) {
  switch (num) {
    case 0:
      push_back(list, 3, 's', 0.0);
      break;
    case 1:
      push_back(list, 3, 'c', 0.0);
      break;
    case 2:
      push_back(list, 3, 't', 0.0);
      break;
    case 3:
      push_back(list, 3, 'S', 0.0);
      break;
    case 4:
      push_back(list, 3, 'C', 0.0);
      break;
    case 5:
      push_back(list, 3, 'T', 0.0);
      break;
    case 6:
      push_back(list, 3, 'q', 0.0);
      break;
    case 7:
      push_back(list, 3, 'l', 0.0);
      break;
    case 8:
      push_back(list, 3, 'L', 0.0);
      break;
    case 9:
      push_back(list, 2, 'm', 0.0);
      break;
  }
}

int check_nums(char* str, int* count, double* num) {
  int res = 0;
  int dots = 0;
  int num_len = 0;

  while (((str[*count + num_len] > 47) && (str[*count + num_len] < 58)) ||
         (str[*count + num_len] == '.')) {
    if (str[*count + num_len] == '.') dots++;
    num_len++;
  }

  if (dots > 1) res = -1;
  *num = atof(str + *count);

  *count += (num_len - 1);

  return res;
}
