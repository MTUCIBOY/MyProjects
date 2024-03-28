#include <stdio.h>

#include "s21_helper.h"

int s21_div_5(s21_decimal value, s21_decimal *result) {
  s21_clear_decimal(result);

  s21_decimal t;
  s21_decimal td;
  s21_decimal td_mul_10;
  s21_decimal zero;
  s21_decimal one;
  s21_decimal five;
  s21_decimal ten;
  bool sign = 0;
  int ms = 0;
  int code_mul = 0;

  s21_from_int_to_decimal(1, &one);
  s21_from_int_to_decimal(5, &t);
  s21_from_int_to_decimal(10, &ten);
  s21_from_int_to_decimal(5, &five);
  s21_from_int_to_decimal(50, &td_mul_10);
  s21_clear_decimal(&zero);

  if (value.bits[3] >> 31) {
    s21_change_sign_decimal(&value, 0);
    sign = 1;
  }

  while (s21_is_less_or_equal(t, value) && !s21_mul_10(t, &t)) ms++;

  s21_add_exp_decimal(&value, 0);

  while (ms > 0) {
    s21_mul_10(*result, result);
    s21_from_int_to_decimal(5, &td);
    td_mul_10 = td;
    while (s21_is_less_or_equal(td_mul_10, value) && !code_mul) {
      td = td_mul_10;
      code_mul = s21_mul_10(td_mul_10, &td_mul_10);
    }
    while (s21_is_less_or_equal(td, value)) {
      s21_sub(value, td, &value);
      s21_add(*result, one, result);
    }
    ms--;
    code_mul = 0;
  }

  if (sign) s21_change_sign_decimal(result, 1);

  return 0;
}
