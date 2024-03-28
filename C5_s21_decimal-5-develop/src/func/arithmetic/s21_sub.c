#include "s21_arithmetic.h"

static int s21_simple_sub(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_clear_decimal(result);

  // Comp
  s21_decimal buf;
  bool sign_val1 = 0, sign_val2 = 0, switch_flag = 0;
  int state = 0;

  // Sign
  if (value_2.bits[3] >> 31) {
    sign_val2 = 0;
    s21_change_sign_decimal(&value_2, 0);
  } else {
    sign_val2 = 1;
    s21_change_sign_decimal(&value_2, 1);
  }

  // Flipping
  if (value_1.bits[3] >> 31) {
    sign_val1 = 1;
    s21_change_sign_decimal(&value_1, 0);
  }

  if (value_2.bits[3] >> 31) {
    sign_val2 = 1;
    s21_change_sign_decimal(&value_2, 0);
  }

  if (s21_is_less(value_1, value_2)) {
    switch_flag = 1;
    buf = value_1;
    value_1 = value_2;
    value_2 = buf;
  }

  if (switch_flag) {
    s21_change_sign_decimal(&value_1, sign_val2);
    s21_change_sign_decimal(&value_2, sign_val1);
  } else {
    s21_change_sign_decimal(&value_2, sign_val2);
    s21_change_sign_decimal(&value_1, sign_val1);
  }

  // EXP
  int exp_val1 = s21_calc_exp_decimal(value_1);
  int exp_val2 = s21_calc_exp_decimal(value_2);
  if (exp_val1 != exp_val2) {
    if (s21_exp_equaler(&value_1, &value_2, 1)) {
      if (s21_calc_exp_decimal(value_1) != 0)
        s21_add_exp_decimal(result, s21_calc_exp_decimal(value_1));
    }
    s21_add_exp_decimal(result, s21_calc_exp_decimal(value_2));
  } else
    s21_add_exp_decimal(result, s21_calc_exp_decimal(value_1));

  // Algorithm
  if (((value_1.bits[3] >> 31) == 0 && (value_2.bits[3] >> 31) == 0) ||
      ((value_1.bits[3] >> 31) == 1 && (value_2.bits[3] >> 31) == 1))
    state = s21_add(value_1, value_2, result);
  else
    state = s21_simple_sub(value_1, value_2, result);

  // Sign result
  if (switch_flag)
    s21_change_sign_decimal(result, sign_val2);
  else
    s21_change_sign_decimal(result, sign_val1);

  // s21_unloader(result);

  if (state && result->bits[3] >> 31) state = 2;
  if (state) s21_clear_decimal(result);

  return state;
}

static int s21_simple_sub(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result) {
  bool over_bit = 0;
  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < 32; i++) {
      if (over_bit && ((value_1.bits[k] >> i) & 1)) {
        value_1.bits[k] &= ~(1 << i);
        over_bit = 0;
      } else if (over_bit) {
        value_1.bits[k] |= 1 << i;
      }

      if (!over_bit && ((value_1.bits[k] >> i) & 1) == 0 &&
          ((value_2.bits[k] >> i) & 1) == 1) {
        over_bit = 1;
        result->bits[k] |= 1 << i;
        continue;
      }

      result->bits[k] |=
          (((value_1.bits[k] >> i) & 1) - ((value_2.bits[k] >> i) & 1)) << i;
    }
  }

  return over_bit;
}
