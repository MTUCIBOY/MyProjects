#include "tests_math.h"

START_TEST(tan_1) {
  for (int i = -10; i <= 10; i++) {
    ck_assert_double_eq_tol(tan(i), s21_tan(i), TEST_EPS);
  }
}
END_TEST

START_TEST(tan_2) {
  ck_assert_double_eq_tol(tan(1e10), s21_tan(1e10), TEST_EPS);
}
END_TEST

START_TEST(tan_3) {
  ck_assert_double_eq_tol(tan(-34.999843), s21_tan(-34.999843), TEST_EPS);
}
END_TEST

START_TEST(tan_4) {
  double num = S21_POS_INF;
  ck_assert_ldouble_nan(s21_tan(num));
}
END_TEST

START_TEST(tan_5) {
  double num = S21_NAN;
  ck_assert_ldouble_nan(s21_tan(num));
}
END_TEST

Suite *test_s21_tan(void) {
  Suite *s = suite_create("s21_tan");
  TCase *tc = tcase_create("s21_tan_tcase");

  tcase_add_test(tc, tan_1);
  tcase_add_test(tc, tan_2);
  tcase_add_test(tc, tan_3);
  tcase_add_test(tc, tan_4);
  tcase_add_test(tc, tan_5);

  suite_add_tcase(s, tc);
  return s;
}
