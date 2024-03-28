#include "s21_helper.h"

int s21_mul_10(s21_decimal value, s21_decimal *result) {
  s21_clear_decimal(result);

  s21_decimal copy_value;
  int state[2] = {0};
  int exp_val = s21_calc_exp_decimal(value);
  bool sign = 0;

  copy_value = value;

  s21_add_exp_decimal(result, exp_val);

  // Sign
  if (value.bits[3] >> 31) {
    sign = 1;
    s21_change_sign_decimal(&value, 0);
  }

  // Algorithm
  state[0] = s21_left_decimal(&value, 1);

  if (!state[0]) state[1] = s21_add(value, *result, result);

  if (!state[0] && !state[1]) state[0] = s21_left_decimal(&value, 2);

  if (!state[0] && !state[1]) state[1] = s21_add(value, *result, result);

  if (sign) s21_change_sign_decimal(result, 1);

  // Error code
  int code = 0;
  for (int i = 0; i < 2; i++) {
    if (state[i]) {
      code = i + 1;
      break;
    }
  }

  if (code) *result = copy_value;

  return code;
}
