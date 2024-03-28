#include "s21_comparison.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  // Sign
  if (((value_1.bits[3] >> 31) & 1) == 1 &&
      ((value_2.bits[3] >> 31) & 1) == 0 &&
      (!s21_is_zero(value_1) || !s21_is_zero(value_2))) {
    return 1;
  } else if (((value_1.bits[3] >> 31) & 1) == 0 &&
             ((value_2.bits[3] >> 31) & 1) == 1 &&
             (!s21_is_zero(value_1) || !s21_is_zero(value_2))) {
    return 0;
  }

  // EXP
  if (s21_calc_exp_decimal(value_1) != s21_calc_exp_decimal(value_2))
    s21_exp_equaler(&value_1, &value_2, 1);

  // NUM
  int code = 0;
  for (int k = 2; k >= 0; k--) {
    if (value_1.bits[k] > value_2.bits[k]) {
      if (value_1.bits[3] >> 31 && value_2.bits[3] >> 31)
        code = 1;
      else
        code = 0;

      return code;
    } else if (value_1.bits[k] < value_2.bits[k]) {
      if (value_1.bits[3] >> 31 && value_2.bits[3] >> 31)
        code = 0;
      else
        code = 1;

      return code;
    }
  }

  return 0;
}
