#include "s21_converter.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (isinf(src) || isnan(src) || (src > -1e-28 && src != 0 && src < 1e-28) ||
      src > MAX_DECIMAL || src < -MAX_DECIMAL)
    return 1;

  s21_clear_decimal(dst);
  if (src < 0) {
    src *= -1;
    s21_change_sign_decimal(dst, 1);
  }

  int exp = 0;

  for (; exp < 29 && src < MAX_DECIMAL && ((src - floor(src)) > 1e-28); exp++) {
    src *= 10;
  }
  s21_add_exp_decimal(dst, exp);

  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < 32; i++) {
      src /= 2;
      if (floor(src) != src) dst->bits[k] |= 1 << i;
      src = floor(src);
    }
  }

  if (src == 1)
    for (int k = 0; k < 3; k++) dst->bits[k] = UINT_MAX;

  return 0;
}
