#include "s21_converter.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  long int abs_min_int = INT_MIN;
  abs_min_int *= -1;
  if (src.bits[1] != 0 || src.bits[2] != 0 ||
      (src.bits[0] > INT_MAX && !(src.bits[3] >> 1)) ||
      (src.bits[0] > abs_min_int && src.bits[3] >> 31))
    return 1;

  int dec_exp = s21_calc_exp_decimal(src);
  *dst = src.bits[0];

  if (dec_exp) *dst /= pow(10, dec_exp);

  if (src.bits[3] >> 31) *dst *= -1;

  return 0;
}
