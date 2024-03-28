#include "s21_other.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!s21_calc_exp_decimal(value)) {
    *result = value;
    return 0;
  }

  s21_decimal copy_value, one;

  copy_value = value;
  s21_from_int_to_decimal(-1, &one);

  s21_truncate(value, &value);
  s21_sub(copy_value, value, &copy_value);
  *result = value;

  if (result->bits[3] >> 31) s21_add(*result, one, result);

  return 0;
}
