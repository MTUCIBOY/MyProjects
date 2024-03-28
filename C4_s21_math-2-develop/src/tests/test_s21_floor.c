#include "tests_math.h"

START_TEST(test_s21_floor_1) {
  ck_assert_int_eq(s21_floor(S21_NAN), floor(S21_NAN));
  ck_assert_int_eq(s21_floor(S21_POS_INF), floor(S21_POS_INF));
  ck_assert_int_eq(s21_floor(S21_NEG_INF), floor(S21_NEG_INF));

  for (float i = -5; i <= 5; i += 0.001) {
    ck_assert_float_eq(s21_floor(i), floor(i));
  }

  ck_assert_float_eq(s21_floor(12345.12345), floor(12345.12345));
  ck_assert_float_eq(s21_floor(-12345.12345), floor(-12345.12345));
}
END_TEST

Suite* test_s21_floor() {
  Suite* suite = suite_create("s21_floor");
  TCase* tcase = tcase_create("s21_floor_tcase");

  tcase_add_test(tcase, test_s21_floor_1);

  suite_add_tcase(suite, tcase);
  return suite;
}