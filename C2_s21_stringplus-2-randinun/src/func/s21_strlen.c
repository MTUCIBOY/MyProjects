#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t size = 0;

  while (*str) {
    size++;
    str++;
  }

  return size;
}