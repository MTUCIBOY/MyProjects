#include "s21_helper.h"

void s21_right_decimal(s21_decimal *num, size_t num_of_iter) {
  for (; num_of_iter != 0; num_of_iter--) {
    num->bits[0] = num->bits[0] >> 1;
    if (num->bits[1] & 1) num->bits[0] |= 1 << 31;
    num->bits[1] = num->bits[1] >> 1;
    if (num->bits[2] & 1) num->bits[1] |= 1 << 31;
    num->bits[2] = num->bits[2] >> 1;
  }
}
