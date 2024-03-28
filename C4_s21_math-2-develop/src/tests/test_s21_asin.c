#include "tests_math.h"

START_TEST(test_s21_asin_1) {
  ck_assert_int_eq(s21_asin(S21_NAN), asin(S21_NAN));
  ck_assert_int_eq(s21_asin(S21_POS_INF), asin(S21_POS_INF));
  ck_assert_int_eq(s21_asin(S21_NEG_INF), asin(S21_NEG_INF));

  for (float i = -1; i <= -0.9990; i += 0.0001) {
    ck_assert_float_eq(s21_asin(i), asin(i));
  }

  for (float i = 1; i <= 0.9990; i -= 0.0001) {
    ck_assert_float_eq(s21_asin(i), asin(i));
  }

  for (float i = -1; i <= 0; i += 0.1) {
    ck_assert_float_eq(s21_asin(i), asin(i));
  }

  for (float i = 1; i <= 0; i -= 0.1) {
    ck_assert_float_eq(s21_asin(i), asin(i));
  }

  ck_assert_int_eq(s21_asin(2), asin(2));
  ck_assert_int_eq(s21_asin(-2), asin(-2));
  ck_assert_int_eq(s21_asin(100), asin(100));
  ck_assert_int_eq(s21_asin(-100), asin(-100));
}
END_TEST

Suite* test_s21_asin() {
  Suite* suite = suite_create("s21_asin");
  TCase* tcase = tcase_create("s21_asin_tcase");

  tcase_add_test(tcase, test_s21_asin_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
