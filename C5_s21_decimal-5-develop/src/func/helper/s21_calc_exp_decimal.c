#include "s21_helper.h"

int s21_calc_exp_decimal(s21_decimal num) {
  s21_change_sign_decimal(&num, 0);

  return num.bits[3] >> 16;
}
