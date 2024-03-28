#ifndef TEST_S21_FUNCS_H
#define TEST_S21_FUNCS_H

#include <check.h>
#include <string.h>

#include "../func/s21_string.h"
#include "../sscanf/s21_sscanf.h"

Suite *test_s21_to_upper();
Suite *test_s21_to_lower();
Suite *test_s21_insert();
Suite *test_s21_trim();
Suite *test_s21_sscanf();
Suite *test_s21_sprintf();

#endif