#include "s21_other.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  s21_clear_decimal(result);

  for (int k = 0; k < 4; k++) result->bits[k] = value.bits[k];

  result->bits[3] = result->bits[3] ^ (1 << 31);

  return 0;
}
