#ifndef S21_HELPER_H
#define S21_HELPER_H

typedef struct {
  unsigned int bits[4];
} s21_decimal;

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../arithmetic/s21_arithmetic.h"
#include "../converter/s21_converter.h"

#define MAX_DECIMAL 79228162514264337593543950335.0

void s21_unloader(s21_decimal *result);
int s21_exp_equaler(s21_decimal *value_1, s21_decimal *value_2, bool r);
void s21_clear_decimal(s21_decimal *num);
void s21_add_exp_decimal(s21_decimal *num, int exp);
int s21_calc_exp_decimal(s21_decimal num);
void s21_change_sign_decimal(s21_decimal *num, bool sign);
int s21_left_decimal(s21_decimal *num, int num_of_iter);
void s21_right_decimal(s21_decimal *num, size_t num_of_iter);
bool s21_is_zero(s21_decimal num);
int s21_mul_10(s21_decimal value, s21_decimal *result);
int s21_div_5(s21_decimal value, s21_decimal *result);
void s21_first_bit_right_side(s21_decimal num, int *k, int *i);
int s21_check_decimal(s21_decimal num);
void s21_print_decimal(s21_decimal num);
s21_decimal s21_div_5_full(s21_decimal value, s21_decimal *result);

#endif
