#include "s21_converter.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;

  int pow_two = 0;
  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < 32; i++) {
      *dst += ((src.bits[k] >> i) & 1) * pow(2, pow_two);
      pow_two++;
    }
  }

  *dst /= pow(10, s21_calc_exp_decimal(src));

  if (src.bits[3] >> 31) *dst *= -1;

  return 0;
}
