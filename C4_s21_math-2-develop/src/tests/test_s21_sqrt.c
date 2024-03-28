#include "tests_math.h"

START_TEST(test_s21_sqrt_1) {
  ck_assert_int_eq(s21_sqrt(S21_NAN), sqrt(S21_NAN));
  ck_assert_int_eq(s21_sqrt(S21_POS_INF), sqrt(S21_POS_INF));
  ck_assert_int_eq(s21_sqrt(S21_NEG_INF), sqrt(S21_NEG_INF));

  for (float i = 0; i <= 10; i += 0.1) {
    ck_assert_float_eq(s21_sqrt(i), sqrt(i));
  }
}
END_TEST

Suite* test_s21_sqrt() {
  Suite* suite = suite_create("s21_sqrt");
  TCase* tcase = tcase_create("s21_sqrt_tcase");

  tcase_add_test(tcase, test_s21_sqrt_1);

  suite_add_tcase(suite, tcase);
  return suite;
}