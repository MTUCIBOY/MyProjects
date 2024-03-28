#include "s21_helper.h"

void s21_clear_decimal(s21_decimal *num) {
  for (int i = 0; i < 4; i++) num->bits[i] = 0;
}
