#include "s21_other.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!s21_calc_exp_decimal(value)) {
    *result = value;
    return 0;
  }
  s21_clear_decimal(result);

  int exp_val = s21_calc_exp_decimal(value);

  *result = value;
  while (exp_val) {
    exp_val--;
    s21_add_exp_decimal(result, exp_val);
    s21_right_decimal(result, 1);
    s21_div_5_full(*result, result);
  }

  return 0;
}
