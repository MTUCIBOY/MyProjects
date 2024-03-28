#include "s21_converter.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_clear_decimal(dst);

  if (src < 0) {
    s21_change_sign_decimal(dst, 1);
    src *= -1;
  }

  //Внесение числа
  dst->bits[0] = src;

  return 0;
}
