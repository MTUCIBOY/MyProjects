#include "s21_string.h"

void* s21_insert(const char* src, const char* str, size_t start_index) {
  //Объявление переменных
  void* head_result =
      malloc(sizeof(char) * s21_strlen(src) + s21_strlen(str) + 1);
  void* result = head_result;
  size_t mas_index = 0;

  /*Обработка ошибок
  Стартовый индекс больше, чем длина строки*/
  if (s21_strlen(src) < start_index) {
    free(head_result);
    return NULL;
  }

  //Алгоритм копирования
  while (*src || *str) {
    if (*str && mas_index == start_index) {
      *(char*)result = *str;
      result++;
      str++;
      mas_index++;
      start_index++;
    } else {
      *(char*)result = *src;
      result++;
      src++;
      mas_index++;
    }
  }

  //Указатель на конец строки и вывод
  *(char*)result = '\0';
  return head_result;
}