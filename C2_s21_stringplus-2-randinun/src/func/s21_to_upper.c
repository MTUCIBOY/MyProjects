#include "s21_string.h"

void* s21_to_upper(const char* str) {
  //Объявление переменных
  void* result = malloc(sizeof(char) * s21_strlen(str) + 1);
  void* head_result = result;

  //Основной алгоритм. Сравнивает коды АСКИ из нашей строки
  while (*str) {
    if (*str >= 'a' && *str <= 'z')
      *(char*)result = *str - 32;
    else
      *(char*)result = *str;
    result++;
    str++;
  }

  //Указатель на конец строки и вывод
  *(char*)result = '\0';
  return head_result;
}