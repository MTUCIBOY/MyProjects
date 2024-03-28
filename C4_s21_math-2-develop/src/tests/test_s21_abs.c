#include "tests_math.h"

START_TEST(test_s21_abs_1) {
  for (int i = INT16_MAX; i != 1;) {
    ck_assert_int_eq(s21_abs(i), abs(i));
    i *= -1;
    if (i < 0)
      i++;
    else
      i--;
  }
}
END_TEST

Suite* test_s21_abs() {
  Suite* suite = suite_create("s21_abs");
  TCase* tcase = tcase_create("s21_abs_tcase");

  tcase_add_test(tcase, test_s21_abs_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
