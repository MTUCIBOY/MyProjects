#include "s21_other.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!s21_calc_exp_decimal(value)) {
    *result = value;
    return 0;
  }

  s21_decimal copy_value, one, half;
  bool sign = 0;

  if (value.bits[3] >> 31) {
    sign = 1;
    s21_change_sign_decimal(&value, 0);
  }

  copy_value = value;
  s21_from_int_to_decimal(1, &one);
  s21_from_float_to_decimal(0.5, &half);

  s21_truncate(value, &value);
  s21_sub(copy_value, value, &copy_value);
  *result = value;

  if (s21_is_greater_or_equal(copy_value, half)) s21_add(*result, one, result);

  if (sign) s21_change_sign_decimal(result, 1);

  return 0;
}
