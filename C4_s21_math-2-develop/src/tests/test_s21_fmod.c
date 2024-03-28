#include "tests_math.h"

START_TEST(test_s21_fmod_1) {
  ck_assert_int_eq(s21_fmod(S21_NAN, S21_NAN), fmod(S21_NAN, S21_NAN));
  ck_assert_int_eq(s21_fmod(S21_POS_INF, S21_POS_INF),
                   fmod(S21_POS_INF, S21_POS_INF));
  ck_assert_int_eq(s21_fmod(S21_NEG_INF, S21_NEG_INF),
                   fmod(S21_NEG_INF, S21_NEG_INF));

  ck_assert_int_eq(s21_fmod(1, S21_NAN), fmod(1, S21_NAN));
  ck_assert_int_eq(s21_fmod(1, S21_POS_INF), fmod(1, S21_POS_INF));
  ck_assert_int_eq(s21_fmod(1, S21_NEG_INF), fmod(1, S21_NEG_INF));

  ck_assert_int_eq(s21_fmod(S21_NAN, 1), fmod(S21_NAN, 1));
  ck_assert_int_eq(s21_fmod(S21_POS_INF, 1), fmod(S21_POS_INF, 1));
  ck_assert_int_eq(s21_fmod(S21_NEG_INF, 1), fmod(S21_NEG_INF, 1));

  for (float i = -10; i <= 10; i += 0.1) {
    for (float k = -10; k <= 10; k += 0.1)
      ck_assert_double_eq(s21_fmod(i, k), fmod(i, k));
  }
}
END_TEST

Suite* test_s21_fmod() {
  Suite* suite = suite_create("s21_fmod");
  TCase* tcase = tcase_create("s21_fmod_tcase");

  tcase_add_test(tcase, test_s21_fmod_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
