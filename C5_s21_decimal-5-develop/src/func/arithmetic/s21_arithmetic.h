#ifndef S21_ARITHMETIC_H
#define S21_ARITHMETIC_H

#include "../comparison/s21_comparison.h"
#include "../converter/s21_converter.h"
#include "../helper/s21_helper.h"
#include "../other/s21_other.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  // !S21_ARITHMETIC_H
