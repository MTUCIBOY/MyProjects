#include "s21_arithmetic.h"

static int s21_simple_add(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_clear_decimal(result);
  bool sign = 0;
  int k, i;
  int state[2] = {0};
  int exp_res = s21_calc_exp_decimal(value_1) + s21_calc_exp_decimal(value_2);
  int exp_val1 = s21_calc_exp_decimal(value_1);
  s21_add_exp_decimal(result, exp_res);
  s21_decimal r;

  // Sign
  if ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31) == 1) sign = 1;

  s21_change_sign_decimal(&value_1, 0);
  s21_change_sign_decimal(&value_2, 0);

  // Algorithm
  s21_first_bit_right_side(value_2, &k, &i);
  for (; k >= 0 && !state[0] && !state[1]; k--) {
    for (; i >= 0 && !state[0] && !state[1]; i--) {
      if (s21_left_decimal(result, 1)) {
        state[0] = s21_add(*result, *result, result);
        s21_add_exp_decimal(&value_1, 0);
        s21_div_5_full(value_1, &value_1);
        s21_right_decimal(&value_1, 1);
        exp_val1--;
        s21_add_exp_decimal(&value_1, exp_val1);
      }
      if ((value_2.bits[k] >> i) & 1)
        state[1] = s21_simple_add(*result, value_1, result);
    }
    i = 31;
  }

  // Round
  exp_res = s21_calc_exp_decimal(*result);
  s21_add_exp_decimal(result, 0);
  while (exp_res > 28) {
    r = s21_div_5_full(*result, result);
    s21_left_decimal(&r, 1);
    if (result->bits[0] & 1) r.bits[0]++;
    s21_right_decimal(result, 1);
    if (r.bits[0] > 5)
      result->bits[0]++;
    else if (r.bits[0] == 5) {
      if (result->bits[0] & 1) result->bits[0]++;
    }
    exp_res--;
  }
  s21_add_exp_decimal(result, exp_res);

  // less decimal
  s21_unloader(result);

  if (sign) s21_change_sign_decimal(result, 1);

  // Check
  int code = 0;
  for (int i = 0; i < 2; i++) {
    if (state[i]) {
      code = state[i];
      if (result->bits[3] >> 31) code++;
      s21_clear_decimal(result);
      break;
    }
  }

  return code;
}

static int s21_simple_add(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *result) {
  unsigned long sum_bytes = 0;
  bool overbit = 0;

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

  return overbit;
}
