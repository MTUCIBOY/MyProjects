#include "test_s21_funcs.h"

START_TEST(test1_s21_to_upper) {
  const char *str1 = "Hello, World!";
  const char *str2 = "123abc";
  const char *str3 = "";
  const char *str4 = "##12#&*^%^(_)*h*_!**J909";
  const char *str5 = "\nABc\n";

  char *res1 = s21_to_upper(str1);
  char *res2 = s21_to_upper(str2);
  char *res3 = s21_to_upper(str3);
  char *res4 = s21_to_upper(str4);
  char *res5 = s21_to_upper(str5);

  ck_assert_str_eq("HELLO, WORLD!", res1);
  ck_assert_str_eq("123ABC", res2);
  ck_assert_str_eq("", res3);
  ck_assert_str_eq("##12#&*^%^(_)*H*_!**J909", res4);
  ck_assert_str_eq("\nABC\n", res5);

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

Suite *test_s21_to_upper() {
  Suite *suite = suite_create("s21_to_upper");
  TCase *tcase = tcase_create("s21_to_upper_tcase");

  tcase_add_test(tcase, test1_s21_to_upper);

  suite_add_tcase(suite, tcase);
  return suite;
}