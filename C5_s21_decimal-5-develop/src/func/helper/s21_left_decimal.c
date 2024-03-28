#include "s21_helper.h"

int s21_left_decimal(s21_decimal *num, int num_of_iter) {
  int k, i;
  s21_first_bit_right_side(*num, &k, &i);

  if ((96 - num_of_iter - (k * 32 + i)) <= 0) return 1;

  for (; num_of_iter != 0; num_of_iter--) {
    num->bits[2] = num->bits[2] << 1;
    if ((num->bits[1] >> 31) & 1) num->bits[2] += 1;
    num->bits[1] = num->bits[1] << 1;
    if ((num->bits[0] >> 31) & 1) num->bits[1] += 1;
    num->bits[0] = num->bits[0] << 1;
  }

  return 0;
}
