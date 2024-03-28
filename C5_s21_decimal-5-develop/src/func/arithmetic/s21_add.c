#include "s21_arithmetic.h"

static int s21_simple_add(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  /* if (s21_check_decimal(value_1) || s21_check_decimal(value_2))
    return 1; */

  s21_clear_decimal(result);

  int exp_val1 = s21_calc_exp_decimal(value_1);
  int exp_val2 = s21_calc_exp_decimal(value_2);
  int state = 0;

  // Sign
  if ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31) == 2)
    s21_change_sign_decimal(result, 1);

  // EXP
  if (exp_val1 != exp_val2) {
    if (s21_exp_equaler(&value_1, &value_2, 1)) {
      if (s21_calc_exp_decimal(value_1) != 0)
        s21_add_exp_decimal(result, s21_calc_exp_decimal(value_1));
    }
    s21_add_exp_decimal(result, s21_calc_exp_decimal(value_2));
  } else
    s21_add_exp_decimal(result, s21_calc_exp_decimal(value_1));

  // Algorithm
  /* if differnt signs */
  if ((((value_1.bits[3] >> 31) & 1) ^ ((value_2.bits[3] >> 31) & 1)) == 1) {
    if (value_2.bits[3] >> 31)
      s21_change_sign_decimal(&value_2, 0);
    else
      s21_change_sign_decimal(&value_2, 1);
    state = s21_sub(value_1, value_2, result);
  } else
    state = s21_simple_add(value_1, value_2, result);

  // Check
  if (state && result->bits[3] >> 31) state = 2;
  if (state) s21_clear_decimal(result);

  return state;
}

static int s21_simple_add(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result) {
  /* int bit = 0;
  int over_bit = 0;
  int exp_res = s21_calc_exp_decimal(*result);
  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < 32; i++) {
      bit += over_bit;
      over_bit = 0;
      bit += ((value_1.bits[k] >> i) & 1) + ((value_2.bits[k] >> i) & 1);
      if (bit > 1) {
        over_bit = 1;
        bit -= 2;
      }
      result->bits[k] |= bit << i;
      bit = 0;
    }
    if (k == 2 && over_bit && exp_res) {
      s21_add_exp_decimal(result, 0);
      s21_right_decimal(result, 1);
      result->bits[2] |= 1 << 31;
      s21_div_5(*result, result);
      s21_add_exp_decimal(result, exp_res - 1);
      over_bit = 0;
    }
  }

  return over_bit ? 1 : 0; */
  unsigned long sum_bytes = 0;
  bool overbit = 0;
  int exp_res = s21_calc_exp_decimal(*result);

  for (int k = 0; k < 3; k++) {
    sum_bytes = (long)value_1.bits[k] + (long)value_2.bits[k] + overbit;
    overbit = 0;
    if (sum_bytes > UINT_MAX) {
      sum_bytes -= UINT_MAX;
      sum_bytes--;
      overbit = 1;
    }
    result->bits[k] = sum_bytes;
  }
  if (overbit && exp_res) {
    s21_add_exp_decimal(result, 0);
    s21_right_decimal(result, 1);
    result->bits[2] |= 1 << 31;
    s21_div_5_full(*result, result);
    s21_add_exp_decimal(result, exp_res - 1);
    overbit = 0;
  }

  return overbit;
}
