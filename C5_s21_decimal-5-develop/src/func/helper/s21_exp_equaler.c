#include <math.h>
#include <stdlib.h>

#include "s21_helper.h"

void bank_round(s21_decimal *val);

int s21_exp_equaler(s21_decimal *value_1, s21_decimal *value_2, bool r) {
  int exp_value1 = s21_calc_exp_decimal(*value_1),
      exp_value2 = s21_calc_exp_decimal(*value_2);
  int state[2] = {0};

  s21_decimal copy_val1;
  s21_decimal copy_val2;
  copy_val1 = *value_1;
  copy_val2 = *value_2;

  /* Normalization */
  while (exp_value1 < exp_value2 && !state[0]) {
    state[0] = s21_mul_10(*value_1, value_1);
    exp_value1++;
  }
  s21_add_exp_decimal(value_1, exp_value1);

  if (!state[0]) {
    while (exp_value1 > exp_value2 && !state[1]) {
      state[1] = s21_mul_10(*value_2, value_2);
      exp_value2++;
    }
    s21_add_exp_decimal(value_2, exp_value2);
  }

  // printf("%d %d\n", state[0], state[1]);

  /* Normalization if overflow */
  /* if (state[0] || state[1]) {
    state[0] = 0;
    state[1] = 0;
    exp_value1 = s21_calc_exp_decimal(copy_val1);
    exp_value2 = s21_calc_exp_decimal(copy_val2);
    while (exp_value1 > exp_value2 && !state[0]) {
      s21_add_exp_decimal(value_1, exp_value1 + 1);
      state[0] = s21_div_5_full(*value_1, value_1);
      s21_right_decimal(value_1, 1);
      exp_value1--;
    }
    s21_add_exp_decimal(value_1, exp_value1);

    if (!state[0]) {
      while (exp_value1 < exp_value2 && !state[1]) {
        s21_add_exp_decimal(value_2, exp_value2 + 1);
        state[1] = s21_div_5_full(*value_2, value_2);
        s21_right_decimal(value_2, 1);
        exp_value2--;
      }
    }
    s21_add_exp_decimal(value_2, exp_value2);
  } */
  // printf("%d %d\n", state[0], state[1]);

  /* Round nums */
  if ((state[0] || state[1]) && r) {
    bool sign_val1 = 0, sign_val2 = 0, round_1 = 0, round_2 = 0;
    *value_1 = copy_val1;
    *value_2 = copy_val2;

    /* Sign nums */
    if (value_1->bits[3] >> 31) {
      s21_change_sign_decimal(value_1, 0);
      sign_val1 = 1;
    }

    if (value_2->bits[3] >> 31) {
      s21_change_sign_decimal(value_2, 0);
      sign_val2 = 1;
    }

    /* Round less */
    if (s21_calc_exp_decimal(*value_1) > s21_calc_exp_decimal(*value_2)) {
      bank_round(value_1);
      round_1 = 1;
    } else {
      bank_round(value_2);
      round_2 = 1;
      /* s21_round(*value_2, value_2);
      if (s21_is_zero(*value_2))
        value_2->bits[0] = 1; */
    }

    /* Return signs */
    if (sign_val1) s21_change_sign_decimal(value_1, 1);
    if (sign_val2) s21_change_sign_decimal(value_2, 1);

    if (round_1 || round_2) s21_exp_equaler(value_1, value_2, 1);
    s21_exp_equaler(value_1, value_2, 0);
  }

  int code = 0;
  for (int i = 0; i < 2; i++) {
    if (state[i]) code = 1;
  }

  return code;
}

void bank_round(s21_decimal *val) {
  s21_decimal temp;
  s21_decimal ten = {{10, 0, 0, 0}};
  int exp_val = s21_calc_exp_decimal(*val);
  s21_add_exp_decimal(val, 0);
  if (s21_is_greater_or_equal(*val, ten)) {
    temp = s21_div_5_full(*val, val);
    if (val->bits[0] & 1) temp.bits[0]++;
    s21_right_decimal(val, 1);
    if (temp.bits[0] > 5)
      val->bits[0]++;
    else if (temp.bits[0] == 5) {
      if (val->bits[0] & 1) val->bits[0]++;
    }
    s21_add_exp_decimal(val, exp_val - 1);
  } else if (val->bits[0] >= 5) {
    val->bits[0] = 1;
    s21_add_exp_decimal(val, exp_val - 1);
  }
}
