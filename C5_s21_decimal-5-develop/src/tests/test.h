#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_decimal.h"

#define MINUS 2147483648
#define MAX_DEC powf(2.0f, 96.0f) - 1.0
#define MIN_DEC -powf(2.0f, 96.0f) + 1.0

Suite *convertors_suite(void);
Suite *comparison_suite(void);
Suite *other_suite(void);
Suite *arithmetic_suite(void);
Suite *helper_suite(void);

#endif
