#include "tests_math.h"

START_TEST(test_s21_ceil_1) {
  ck_assert_int_eq(s21_ceil(S21_NAN), ceil(S21_NAN));
  ck_assert_int_eq(s21_ceil(S21_POS_INF), ceil(S21_POS_INF));
  ck_assert_int_eq(s21_ceil(S21_NEG_INF), ceil(S21_NEG_INF));

  for (float i = -10; i <= 10; i += 0.1) {
    ck_assert_float_eq(s21_ceil(i), ceil(i));
  }
}
END_TEST

Suite* test_s21_ceil() {
  Suite* suite = suite_create("s21_ceil");
  TCase* tcase = tcase_create("s21_ceil_tcase");

  tcase_add_test(tcase, test_s21_ceil_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
