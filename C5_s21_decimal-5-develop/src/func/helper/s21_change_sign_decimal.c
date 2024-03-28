#include "s21_helper.h"

void s21_change_sign_decimal(s21_decimal *num, bool sign) {
  if (sign)
    num->bits[3] = num->bits[3] | (1 << 31);
  else
    num->bits[3] = num->bits[3] & ~(1 << 31);
}
