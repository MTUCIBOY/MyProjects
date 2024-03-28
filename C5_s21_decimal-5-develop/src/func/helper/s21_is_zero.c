#include "s21_helper.h"

bool s21_is_zero(s21_decimal num) {
  return (num.bits[0] == 0 && num.bits[1] == 0 && num.bits[2] == 0) ? true
                                                                    : false;
}
