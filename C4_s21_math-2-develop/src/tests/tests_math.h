#ifndef TEST_S21_FUNCS_H
#define TEST_S21_FUNCS_H

#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

#define TEST_EPS (1e-6)

Suite *test_s21_abs();
Suite *test_s21_cos();
Suite *test_s21_asin();
Suite *test_s21_acos();
Suite *test_s21_atan();
Suite *test_s21_ceil();
Suite *test_s21_anysqrt();
Suite *test_s21_exp();
Suite *test_s21_pow();
Suite *test_s21_fabs();
Suite *test_s21_floor();
Suite *test_s21_fmod();
Suite *test_s21_log();
Suite *test_s21_sin();
Suite *test_s21_sqrt();
Suite *test_s21_tan();

#endif
