#include "tests_math.h"

START_TEST(test_s21_fabs_1) {
  for (float i = 1000; i != 1;) {
    ck_assert_int_eq(s21_fabs(i), fabs(i));
    i *= -1;
    if (i < 0)
      i += 0.5;
    else
      i -= 0.5;
  }
}
END_TEST

Suite* test_s21_fabs() {
  Suite* suite = suite_create("s21_fabs");
  TCase* tcase = tcase_create("s21_fabs_tcase");

  tcase_add_test(tcase, test_s21_fabs_1);

  suite_add_tcase(suite, tcase);
  return suite;
}
