#include "tests_math.h"

START_TEST(test_s21_acos_1) {
  ck_assert_int_eq(s21_acos(S21_NAN), acos(S21_NAN));
  ck_assert_int_eq(s21_acos(S21_POS_INF), acos(S21_POS_INF));
  ck_assert_int_eq(s21_acos(S21_NEG_INF), acos(S21_NEG_INF));

  for (float i = -1; i <= -0.9990; i += 0.0001) {
    ck_assert_float_eq(s21_acos(i), acos(i));
  }

  for (float i = 1; i <= 0.9990; i -= 0.0001) {
    ck_assert_float_eq(s21_acos(i), acos(i));
  }

  for (float i = -1; i <= 0; i += 0.1) {
    ck_assert_float_eq(s21_acos(i), acos(i));
  }

  for (float i = 1; i <= 0; i -= 0.1) {
    ck_assert_float_eq(s21_acos(i), acos(i));
  }

  ck_assert_int_eq(s21_acos(2), acos(2));
  ck_assert_int_eq(s21_acos(-2), acos(-2));
  ck_assert_int_eq(s21_acos(100), acos(100));
  ck_assert_int_eq(s21_acos(-100), acos(-100));
}
END_TEST

Suite* test_s21_acos() {
  Suite* suite = suite_create("s21_acos");
  TCase* tcase = tcase_create("s21_acos_tcase");

  tcase_add_test(tcase, test_s21_acos_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
