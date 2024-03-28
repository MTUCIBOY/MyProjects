#include "tests_math.h"

START_TEST(test_s21_cos_1) {
  ck_assert_int_eq(s21_cos(S21_NAN), cos(S21_NAN));
  ck_assert_int_eq(s21_cos(S21_POS_INF), cos(S21_POS_INF));
  ck_assert_int_eq(s21_cos(S21_NEG_INF), cos(S21_NEG_INF));

  for (float i = -1; i <= -0.9990; i += 0.0001) {
    ck_assert_float_eq(s21_cos(i), cos(i));
  }

  for (float i = 1; i <= 0.9990; i -= 0.0001) {
    ck_assert_float_eq(s21_cos(i), cos(i));
  }

  for (float i = -1; i <= 0; i += 0.1) {
    ck_assert_float_eq(s21_cos(i), cos(i));
  }

  for (float i = 1; i <= 0; i -= 0.1) {
    ck_assert_float_eq(s21_cos(i), cos(i));
  }
}
END_TEST

Suite* test_s21_cos() {
  Suite* suite = suite_create("s21_cos");
  TCase* tcase = tcase_create("s21_cos_tcase");

  tcase_add_test(tcase, test_s21_cos_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
