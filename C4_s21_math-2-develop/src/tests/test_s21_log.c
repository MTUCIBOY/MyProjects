#include "tests_math.h"

START_TEST(log_int_1) {
  int kek = 1;
  ck_assert_double_eq_tol(s21_log(kek), log(kek), TEST_EPS);
}
END_TEST

START_TEST(log_int_2) {
  int kek = 100320320;
  ck_assert_double_eq_tol(s21_log(kek), log(kek), TEST_EPS);
}
END_TEST

START_TEST(log_int_3) {
  int kek = -329329312;
  ck_assert_double_nan(s21_log(kek));
  ck_assert_double_nan(log(kek));
}
END_TEST

START_TEST(log_double_1) {
  double kek = 32382873272.21312;
  ck_assert_double_eq_tol(s21_log(kek), log(kek), TEST_EPS);
}
END_TEST

START_TEST(log_double_2) {
  double kek = -31212.12122;
  ck_assert_double_nan(s21_log(kek));
  ck_assert_double_nan(log(kek));
}
END_TEST

START_TEST(log_INF_1) {
  double kek = S21_POS_INF;
  ck_assert_double_infinite(s21_log(kek));
  ck_assert_double_infinite(s21_log(kek));
}
END_TEST

START_TEST(log_NAN_1) {
  double kek = 0;
  ck_assert_double_infinite(s21_log(kek));
  ck_assert_double_infinite(s21_log(kek));
}
END_TEST

Suite *test_s21_log() {
  Suite *s = suite_create("s21_log");
  TCase *tc = tcase_create("s21_log_tcase");

  tcase_add_test(tc, log_int_1);
  tcase_add_test(tc, log_int_2);
  tcase_add_test(tc, log_int_3);
  tcase_add_test(tc, log_double_1);
  tcase_add_test(tc, log_double_2);
  tcase_add_test(tc, log_INF_1);
  tcase_add_test(tc, log_NAN_1);

  suite_add_tcase(s, tc);

  return s;
}