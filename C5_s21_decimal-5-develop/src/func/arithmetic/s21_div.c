#include "s21_arithmetic.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // Div 0
  if (s21_is_zero(value_2)) return 3;

  s21_clear_decimal(result);
  bool sign = 0;

  // Sign
  if ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31) == 1) sign = 1;

  s21_change_sign_decimal(&value_1, 0);
  s21_change_sign_decimal(&value_2, 0);

  // EXP
  if (s21_calc_exp_decimal(value_1) != s21_calc_exp_decimal(value_2)) {
    if (s21_exp_equaler(&value_1, &value_2, 1)) {
      if (s21_calc_exp_decimal(value_1) != 0)
        s21_add_exp_decimal(result, s21_calc_exp_decimal(value_1));
    }
    s21_add_exp_decimal(result, s21_calc_exp_decimal(value_2));
  } else
    s21_add_exp_decimal(result, s21_calc_exp_decimal(value_1));

  // Algorithm
  s21_decimal zero;
  s21_from_int_to_decimal(0, &zero);
  s21_decimal one;
  s21_from_int_to_decimal(1, &one);
  s21_decimal d;
  d = value_2;
  s21_decimal td;
  td = value_2;
  int code = 0;

  while (s21_is_less_or_equal(td, value_1) && !code) {
    d = td;
    code += s21_left_decimal(&td, 1);
  }

  s21_add_exp_decimal(result, 0);

  while (!s21_is_equal(d, value_2)) {
    if (s21_is_less_or_equal(d, value_1)) {
      s21_add(*result, one, result);
      s21_sub(value_1, d, &value_1);
    }
    s21_left_decimal(result, 1);
    s21_right_decimal(&d, 1);
  }
  if (s21_is_less_or_equal(d, value_1)) {
    s21_add(*result, one, result);
    s21_sub(value_1, d, &value_1);
  }

  code = 0;
  int exp = 0;

  while (!s21_is_equal(value_1, zero) && !code && exp < 28) {
    // printf("exp = %d\n", exp);
    code += s21_mul_10(*result, result);
    code += s21_mul_10(value_1, &value_1);
    while (s21_is_less_or_equal(d, value_1)) {
      // printf("add one\n");
      code += s21_add(*result, one, result);
      code += s21_sub(value_1, d, &value_1);
    }
    exp++;

    if (!code) s21_add_exp_decimal(result, exp);
    s21_add_exp_decimal(&one, exp);
  }

  if (exp == 28 && !code && !s21_is_zero(value_1)) {
    s21_decimal t;
    s21_add_exp_decimal(&one, 28);
    s21_add(*result, one, &t);
    if (!s21_is_zero(t)) {
      *result = t;
    }
  }

  if (sign) s21_change_sign_decimal(result, 1);

  return 0;
}
