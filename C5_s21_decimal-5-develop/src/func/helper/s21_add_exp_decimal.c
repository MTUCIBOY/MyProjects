#include "s21_helper.h"

void s21_add_exp_decimal(s21_decimal *num, int exp) {
  // reset exp
  bool sign = 0;
  if (num->bits[3] >> 31) sign = 1;
  num->bits[3] = 0;

  if (exp < 0) exp = 0;
  if (exp > 56) exp = 56;

  // Add exp
  num->bits[3] = exp << 16;

  // Return sign
  if (sign) num->bits[3] |= 1 << 31;
}
