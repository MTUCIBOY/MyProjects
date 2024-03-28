#include "s21_helper.h"

int iloe(s21_decimal v1, s21_decimal v2) {
  int r = 1;
  for (int k = 2; k >= 0; k--) {
    if ((unsigned)v1.bits[k] != (unsigned)v2.bits[k]) {
      if ((unsigned)v1.bits[k] < (unsigned)v2.bits[k])
        r = 1;
      else
        r = 0;
      break;
    }
  }
  return r;
}

s21_decimal s21_div_5_full(s21_decimal value, s21_decimal *result) {
  s21_clear_decimal(result);

  s21_decimal t;
  s21_decimal td;
  s21_decimal td_l;
  s21_decimal zero;
  s21_decimal one;
  s21_decimal five;
  s21_decimal ten;
  bool sign = 0;
  int ms = 0;
  int exp = s21_calc_exp_decimal(value);
  int code = 0;

  s21_from_int_to_decimal(1, &one);
  s21_from_int_to_decimal(5, &t);
  s21_from_int_to_decimal(10, &ten);
  s21_from_int_to_decimal(5, &five);
  s21_from_int_to_decimal(10, &td_l);
  s21_clear_decimal(&zero);

  if (value.bits[3] >> 31) {
    s21_change_sign_decimal(&value, 0);
    sign = 1;
  }

  s21_add_exp_decimal(&value, 0);

  while (iloe(t, value) && !s21_left_decimal(&t, 1)) ms++;
  /*
  s21_from_float_to_decimal(50, &td);

  printf("\nvalue:\n");
  s21_print_decimal(value);
  printf("\ntd:\n");
  s21_print_decimal(td);

  s21_sub(value, td, &value);
  printf("\nvalue:\n");
  s21_print_decimal(value);

  printf("\nr:\n");
  s21_print_decimal(*result);
  printf("\n1:\n");
  s21_print_decimal(one);

  s21_add(*result, one, result);
  printf("\nr:\n");
  s21_print_decimal(*result);
  */
  if (!iloe(t, value) && iloe(five, t)) {
    s21_right_decimal(&t, 1);
    ms--;
  }
  td = t;
  while (ms >= 0 && !code && iloe(five, td)) {
    code = s21_left_decimal(result, 1);
    if (iloe(td, value) && !code) {
      s21_sub(value, td, &value);
      code = s21_add(*result, one, result);
    }
    ms--;
    s21_right_decimal(&td, 1);
  }
  if (sign) s21_change_sign_decimal(result, 1);

  s21_add_exp_decimal(result, exp);

  return value;
}
