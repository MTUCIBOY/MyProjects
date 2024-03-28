#include "tests_math.h"

START_TEST(test_s21_atan_1) {
  ck_assert_int_eq(s21_atan(S21_NAN), atan(S21_NAN));
  ck_assert_int_eq(s21_atan(S21_POS_INF), atan(S21_POS_INF));
  ck_assert_int_eq(s21_atan(S21_NEG_INF), atan(S21_NEG_INF));

  for (float i = -1; i <= -0.9990; i += 0.0001) {
    ck_assert_float_eq(s21_atan(i), atan(i));
  }

  for (float i = 1; i <= 0.9990; i -= 0.0001) {
    ck_assert_float_eq(s21_atan(i), atan(i));
  }

  for (float i = -1; i <= 0; i += 0.1) {
    ck_assert_float_eq(s21_atan(i), atan(i));
  }

  for (float i = 1; i <= 0; i -= 0.1) {
    ck_assert_float_eq(s21_atan(i), atan(i));
  }
}
END_TEST

Suite* test_s21_atan() {
  Suite* suite = suite_create("s21_atan");
  TCase* tcase = tcase_create("s21_atan_tcase");

  tcase_add_test(tcase, test_s21_atan_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
