#include "test_s21_funcs.h"

START_TEST(test1_s21_insert) {
  const char* src1 = "Hello World!";
  const char* str1 = "wonderfull ";
  size_t index1 = 6;

  const char* src2 = "ABC";
  const char* str2 = "123";
  size_t index2 = 0;

  const char* src3 = "School";
  const char* str3 = " 21";
  size_t index3 = 6;

  const char* src4 = "Hello";
  const char* str4 = "";
  size_t index4 = 3;

  const char* src5 = "";
  const char* str5 = "World!";
  size_t index5 = 0;

  const char* src6 = "";
  const char* str6 = "";
  size_t index6 = 0;

  char* res1 = s21_insert(src1, str1, index1);
  char* res2 = s21_insert(src2, str2, index2);
  char* res3 = s21_insert(src3, str3, index3);
  char* res4 = s21_insert(src4, str4, index4);
  char* res5 = s21_insert(src5, str5, index5);
  char* res6 = s21_insert(src6, str6, index6);

  ck_assert_str_eq("Hello wonderfull World!", res1);
  ck_assert_str_eq("123ABC", res2);
  ck_assert_str_eq("School 21", res3);
  ck_assert_str_eq("Hello", res4);
  ck_assert_str_eq("World!", res5);
  ck_assert_str_eq("", res6);

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
}
END_TEST

Suite* test_s21_insert() {
  Suite* suite = suite_create("s21_insert");
  TCase* tcase = tcase_create("s21_insert_tcase");

  tcase_add_test(tcase, test1_s21_insert);

  suite_add_tcase(suite, tcase);
  return suite;
}