#include <stdio.h>

#include "s21_helper.h"

void s21_unloader(s21_decimal *result) {
  s21_decimal temp;
  s21_div_5_full(*result, &temp);
  s21_right_decimal(&temp, 1);
  s21_add_exp_decimal(&temp, s21_calc_exp_decimal(*result) - 1);
  while (s21_is_equal(*result, temp) && !s21_is_zero(*result)) {
    *result = temp;
    s21_div_5_full(*result, &temp);
    s21_right_decimal(&temp, 1);
    s21_add_exp_decimal(&temp, s21_calc_exp_decimal(*result) - 1);
  }
}
