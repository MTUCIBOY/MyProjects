#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../../s21_calculator.h"
#define LEN(express) (int)(sizeof(express) / sizeof(express[0]))

START_TEST(arithmetic_test) {
  char *expressions[] = {
      "2 + (48.643 - 394) * 4",
      "-4 + 9.004 - (583 * (-3)) / 9.05",
      "0.35 * 30485",
      "47mod 5 / 3",
      "-(-5.537 +89.097 - 325) * (-(-5))",
      "757.09 * (-495)",
      "93.0543 + 5^3",
      "11^5 / 7.08",
      "3 * (-sqrt(4 + 9))",
      "sqrt(2^2 + 7^2) * 32 - 9 /3.98",
  };
  double answer_list[] = {
      2 + (48.643 - 394) * 4,
      (-4 + 9.004 - (583 * (-3)) / 9.05),
      0.35 * 30485,
      (47 % 5) / 3.0,
      -(-5.537 + 89.097 - 325) * -(-5),
      757.09 * -495,
      93.0543 + pow(5, 3),
      pow(11, 5) / 7.08,
      3 * (-sqrt(4 + 9)),
      sqrt(pow(2, 2) + pow(7, 2)) * 32 - 9 / 3.98,
  };
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(sin_test) {
  char *expressions[] = {"sin(0)",
                         "sin(1)",
                         "sin(3.141593)+sin(-45)",
                         "sin(3.141593/2)",
                         "sin(-3.141593/2)",
                         "2*sin(3*3.141593/2)",
                         "sin (-3*3.141593/2)",
                         "sin(5.1234567890123456)",
                         "3+(-sin(9+9))"};
  double answer_list[] = {sin(0),
                          sin(1),
                          sin(3.141593) + sin(-45),
                          sin(3.141593 / 2),
                          sin(-3.141593 / 2),
                          2 * sin(3 * 3.141593 / 2),
                          sin(-3 * 3.141593 / 2),
                          sin(5.1234567890123456),
                          3 + -sin(9 + 9)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(cos_test) {
  char *expressions[] = {"cos(0)",
                         "cos(3.1415926)+cos(-45)",
                         "cos(3.1415926/2)",
                         "cos(-3.1415926/2)",
                         "2*cos(3*3.1415926/2)",
                         "cos(-3*3.1415926/2)",
                         "cos(5.1234567890123456)",
                         "3+(-cos(9+9))"};
  double answer_list[] = {cos(0),
                          cos(3.1415926) + cos(-45),
                          cos(3.1415926 / 2),
                          cos(-3.1415926 / 2),
                          2 * cos(3 * 3.1415926 / 2),
                          cos(-3 * 3.1415926 / 2),
                          cos(5.1234567890123456),
                          3 + -cos(9 + 9)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(tan_test) {
  char *expressions[] = {"tan(0)",
                         "tan(3.1415926)+tan(-45)",
                         "tan(3.1415926/2)",
                         "tan(-3.1415926/2)",
                         "2*tan(3*3.1415926/2)",
                         "tan(-3*3.1415926/2)",
                         "tan(5.1234567890123456)",
                         "3+(-tan(9 + 9))"};
  double answer_list[] = {tan(0),
                          tan(3.1415926) + tan(-45),
                          tan(3.1415926 / 2),
                          tan(-3.1415926 / 2),
                          2 * tan(3 * 3.1415926 / 2),
                          tan(-3 * 3.1415926 / 2),
                          tan(5.1234567890123456),
                          3 + -tan(9 + 9)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(asin_test) {
  char *expressions[] = {"asin(0)",
                         "asin(1)",
                         "asin(-1)",
                         "asin(-0.7)+94*4",
                         "9*asin(0.0001)-2.987",
                         "asin (-0.8/2)",
                         "asin(0.1234567890123456)",
                         "3+(-asin(-0.007))"};
  double answer_list[] = {asin(0),
                          asin(1),
                          asin(-1),
                          asin(-0.7) + 94 * 4,
                          9 * asin(0.0001) - 2.987,
                          asin(-0.8 / 2),
                          asin(0.1234567890123456),
                          3 + -asin(-0.007)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(acos_test) {
  char *expressions[] = {"acos(0)",
                         "acos(1)",
                         "acos(-1)",
                         "acos(-0.7) + 94 * 4",
                         "9*acos(0.0001)-2.987",
                         "acos(-0.8/2)",
                         "acos(0.1234567890123456)",
                         "3+(-acos(-0.007))"};
  double answer_list[] = {acos(0),
                          acos(1),
                          acos(-1),
                          acos(-0.7) + 94 * 4,
                          9 * acos(0.0001) - 2.987,
                          acos(-0.8 / 2),
                          acos(0.1234567890123456),
                          3 + -acos(-0.007)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(atan_test) {
  char *expressions[] = {"atan(0)",
                         "atan(1)",
                         "atan(-1)",
                         "atan(-0.7)+94*4",
                         "9*atan(0.0001)-2.987",
                         "2*atan(1 / 2)",
                         "atan(-0.8/2)",
                         "atan(0.1234567890123456)",
                         "3+(-atan(-0.007))"};
  double answer_list[] = {atan(0),
                          atan(1),
                          atan(-1),
                          atan(-0.7) + 94 * 4,
                          9 * atan(0.0001) - 2.987,
                          2 * atan(1 / 2.0),
                          atan(-0.8 / 2),
                          atan(0.1234567890123456),
                          3 + -atan(-0.007)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

START_TEST(ln_log_test) {
  char *expressions[] = {"ln(9)",
                         "log(1)",
                         "log(10)",
                         "log(25)",
                         "ln(348*8-293)+93234",
                         "9*ln(83*32)-2.987",
                         "ln(0.8/2)",
                         "ln(0.1234567890123456)",
                         "3+(-ln(0.007))"};
  double answer_list[] = {log(9),
                          log10(1),
                          log10(10),
                          log10(25),
                          log(348 * 8 - 293) + 93234,
                          9 * log(83 * 32) - 2.987,
                          log(0.8 / 2),
                          log(0.1234567890123456),
                          3 + -log(0.007)};
  for (int i = 0; i < LEN(expressions); ++i) {
    char str[256];
    strcpy(str, expressions[i]);
    double result = 0;
    calc_main(str, &result, 0.0);
    ck_assert_ldouble_eq_tol(result, answer_list[i], DBL_EPSILON);
  }
}
END_TEST

Suite *test_arithmetic() {
  Suite *suite = suite_create("arithmetic");

  TCase *tcase_arithmetic = tcase_create("test_arithmetic");

  tcase_add_test(tcase_arithmetic, arithmetic_test);
  tcase_add_test(tcase_arithmetic, sin_test);
  tcase_add_test(tcase_arithmetic, cos_test);
  tcase_add_test(tcase_arithmetic, tan_test);
  tcase_add_test(tcase_arithmetic, asin_test);
  tcase_add_test(tcase_arithmetic, acos_test);
  tcase_add_test(tcase_arithmetic, atan_test);
  tcase_add_test(tcase_arithmetic, ln_log_test);

  suite_add_tcase(suite, tcase_arithmetic);

  return suite;
}
