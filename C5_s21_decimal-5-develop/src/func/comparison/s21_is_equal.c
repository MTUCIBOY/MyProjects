#include "s21_comparison.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  // Zero
  if (s21_is_zero(value_1) && s21_is_zero(value_2)) return 1;

  // EXP
  if (s21_calc_exp_decimal(value_1) != s21_calc_exp_decimal(value_2))
    s21_exp_equaler(&value_1, &value_2, 1);

  // NUM
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < 32; i++) {
      if (((value_1.bits[k] >> i) & 1) != ((value_2.bits[k] >> i) & 1))
        return 0;
    }
  }
  return 1;
}
