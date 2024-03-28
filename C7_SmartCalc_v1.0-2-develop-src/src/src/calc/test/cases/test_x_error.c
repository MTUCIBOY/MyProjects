#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../../s21_calculator.h"
#define LEN(express) (int)(sizeof(express) / sizeof(express[0]))

START_TEST(x_test_1) {
  char str[256] = "cos(x)";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, cos(x), DBL_EPSILON);
  }
}
END_TEST

START_TEST(x_test_2) {
  char str[256] = "sin(2 * x) + 5.5";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, sin(2 * x) + 5.5, DBL_EPSILON);
  }
}
END_TEST

START_TEST(x_test_3) {
  char str[256] = "9*ln(x*3.2)-2.987";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, 9 * log(x * 3.2) - 2.987, DBL_EPSILON);
  }
}
END_TEST

START_TEST(x_test_4) {
  char str[256] = "2 * log(x) + ln(x)";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, 2 * log10(x) + log(x), DBL_EPSILON);
  }
}
END_TEST

START_TEST(x_test_5) {
  char str[256] = "x mod 2";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, fmod(x, 2), DBL_EPSILON);
  }
}
END_TEST

START_TEST(x_test_6) {
  char str[256] = "94.0003+x*2";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, (94.0003 + x * 2), DBL_EPSILON);
  }
}
END_TEST

START_TEST(x_test_7) {
  char str[256] = "x+3+x^2-3";
  double result;
  int res = 0;

  for (int x = 1; x <= 5; ++x) {
    res = calc_main(str, &result, x);

    if (res) result = -1;

    ck_assert_ldouble_eq_tol(result, (x + 3 + pow(x, 2) - 3), DBL_EPSILON);
  }
}
END_TEST

START_TEST(err_test) {
  char *expressions[] = {"ln(9))", "sdfsdaf", "sig(21)+3",   "lot(25)",
                         "2++3-1", "--31-2",  "21()12.25.25"};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    int res = 0;
    double result = 0;
    res = calc_main(str, &result, 0.0);
    ck_assert_int_eq(res, 1);
  }
}
END_TEST

Suite *test_x_error() {
  Suite *suite = suite_create("x_error");

  TCase *tcase_x_err = tcase_create("test_x_error");

  tcase_add_test(tcase_x_err, x_test_1);
  tcase_add_test(tcase_x_err, x_test_2);
  tcase_add_test(tcase_x_err, x_test_3);
  tcase_add_test(tcase_x_err, x_test_4);
  tcase_add_test(tcase_x_err, x_test_5);
  tcase_add_test(tcase_x_err, x_test_6);
  tcase_add_test(tcase_x_err, x_test_7);
  tcase_add_test(tcase_x_err, err_test);

  suite_add_tcase(suite, tcase_x_err);

  return suite;
}
