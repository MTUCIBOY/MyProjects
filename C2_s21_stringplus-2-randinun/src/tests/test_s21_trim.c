#include "test_s21_funcs.h"

START_TEST(test1_s21_trim) {
  const char* src1 = "Hello World!";
  const char* str1 = "Hd";

  const char* src2 = "    123 ";
  const char* str2 = " ";

  const char* src3 = "   123 ";
  const char* str3 = "12";

  const char* src4 = "1 1 1 1 ";
  const char* str4 = "1";

  const char* src5 = "";
  const char* str5 = "";

  const char* src6 = "222111";
  const char* str6 = "12";

  const char* src7 = "\n\n333\n\n\n\n\n";
  const char* str7 = "\n";

  char* res1 = s21_trim(src1, str1);
  char* res2 = s21_trim(src2, str2);
  char* res3 = s21_trim(src3, str3);
  char* res4 = s21_trim(src4, str4);
  char* res5 = s21_trim(src5, str5);
  char* res6 = s21_trim(src6, str6);
  char* res7 = s21_trim(src7, str7);

  ck_assert_str_eq("ello World!", res1);
  ck_assert_str_eq("123", res2);
  ck_assert_str_eq("   123 ", res3);
  ck_assert_str_eq(" 1 1 1 ", res4);
  ck_assert_str_eq("", res5);
  ck_assert_str_eq("", res6);
  ck_assert_str_eq("333", res7);

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
  free(res6);
  free(res7);
}
END_TEST

Suite* test_s21_trim() {
  Suite* suite = suite_create("s21_trim");
  TCase* tcase = tcase_create("s21_trim_tcase");

  tcase_add_test(tcase, test1_s21_trim);

  suite_add_tcase(suite, tcase);
  return suite;
}