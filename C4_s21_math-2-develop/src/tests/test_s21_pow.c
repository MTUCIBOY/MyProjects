#include "tests_math.h"

START_TEST(pow_1) {
  double x = 2.5;
  double y = 2.5;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_2) {
  double x = 0.0;
  double y = 5.78;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_3) {
  double x = -42.576899;
  double y = 3;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_4) {
  double x = 0.0;
  double y = -3;
  ck_assert_double_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow_5) {
  double x = 0.0;
  double y = -0.01;
  ck_assert_double_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow_6) {
  double x = 0.0;
  double y = 3.0;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_7) {
  double x = -4.5;
  double y = 3.55;
  ck_assert_double_nan(s21_pow(x, y));
  ck_assert_double_nan(pow(x, y));
}
END_TEST

START_TEST(pow_8) {
  double x = -0.5;
  double y = INFINITY;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_9) {
  double x = -0.5;
  double y = -INFINITY;
  ck_assert_double_infinite(s21_pow(x, y));
  ck_assert_double_infinite(pow(x, y));
}
END_TEST

START_TEST(pow_10) {
  double x = -INFINITY;
  double y = -3.0;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_11) {
  double x = -INFINITY;
  double y = -4.0;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_12) {
  double x = -INFINITY;
  double y = 3.0;
  ck_assert_double_infinite(s21_pow(x, y));
  ck_assert_double_infinite(pow(x, y));
}
END_TEST

START_TEST(pow_13) {
  double x = -INFINITY;
  double y = 4.0;
  ck_assert_double_infinite(s21_pow(x, y));
  ck_assert_double_infinite(pow(x, y));
}
END_TEST

START_TEST(pow_14) {
  double x = 1.0;
  double y = 12;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_15) {
  double x = -1.0;
  double y = INFINITY;
  ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), TEST_EPS);
}
END_TEST

START_TEST(pow_nan) {
  double x = NAN;
  double y = 3.55;
  ck_assert_double_nan(s21_pow(x, y));
  ck_assert_double_nan(pow(x, y));
}
END_TEST

START_TEST(pow_nnan) {
  double x = -NAN;
  double y = 3.55;
  ck_assert_double_nan(s21_pow(x, y));
  ck_assert_double_nan(pow(x, y));
}
END_TEST

START_TEST(pow_inf) {
  double x = INFINITY;
  double y = 0.4;
  ck_assert_double_infinite(s21_pow(x, y));
  ck_assert_double_infinite(pow(x, y));
}
END_TEST

START_TEST(pow_exp_inf) {
  double x = 1.11;
  double y = INFINITY;
  ck_assert_double_infinite(s21_pow(x, y));
  ck_assert_double_infinite(pow(x, y));
}
END_TEST

Suite *test_s21_pow(void) {
  Suite *s = suite_create("s21_pow");
  TCase *tc = tcase_create("s21_pow_tcase");

  tcase_add_test(tc, pow_1);
  tcase_add_test(tc, pow_2);
  tcase_add_test(tc, pow_3);
  tcase_add_test(tc, pow_4);
  tcase_add_test(tc, pow_5);
  tcase_add_test(tc, pow_6);
  tcase_add_test(tc, pow_7);
  tcase_add_test(tc, pow_8);
  tcase_add_test(tc, pow_9);
  tcase_add_test(tc, pow_10);
  tcase_add_test(tc, pow_11);
  tcase_add_test(tc, pow_12);
  tcase_add_test(tc, pow_13);
  tcase_add_test(tc, pow_14);
  tcase_add_test(tc, pow_15);
  tcase_add_test(tc, pow_nan);
  tcase_add_test(tc, pow_nnan);
  tcase_add_test(tc, pow_inf);
  tcase_add_test(tc, pow_exp_inf);
  suite_add_tcase(s, tc);
  return s;
}
