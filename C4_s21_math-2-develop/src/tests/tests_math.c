#include "tests_math.h"

void print_info(Suite *suite) {
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  if (failed_count != 0) {
    printf("FAILED\n");
  } else {
    printf("SUCCESS\n");
  }
}

int main() {
  Suite *suites[] = {
      test_s21_abs(),  test_s21_cos(),   test_s21_asin(), test_s21_acos(),
      test_s21_atan(), test_s21_ceil(),  test_s21_exp(),  test_s21_pow(),
      test_s21_fabs(), test_s21_floor(), test_s21_fmod(), test_s21_log(),
      test_s21_sin(),  test_s21_sqrt(),  test_s21_tan(),  NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    print_info(suites[i]);
  }

  return 0;
}
