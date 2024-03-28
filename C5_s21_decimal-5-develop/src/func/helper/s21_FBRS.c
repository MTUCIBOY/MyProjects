#include "s21_helper.h"

void s21_first_bit_right_side(s21_decimal num, int *k, int *i) {
  for (*k = 2; *k >= 0; (*k)--) {
    for (*i = 31; *i >= 0; (*i)--) {
      if ((num.bits[*k] >> *i) & 1) return;
    }
  }
}
