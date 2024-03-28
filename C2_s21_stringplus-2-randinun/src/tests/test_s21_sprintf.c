#include <check.h>
#include <stdint.h>
#include <string.h>

#include "../sprintf/s21_sprintf.h"

#define STR_LEN 512

START_TEST(sprintf_spec_c_1) {
  char format[] = "%c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_2) {
  char format[] = "str: %c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_3) {
  char format[] = "%cstr1";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_4) {
  char format[] = "%c%c";
  char str1[100];
  char str2[100];
  char ch1 = 'H';
  char ch2 = 'e';

  int res1 = s21_sprintf(str1, format, ch1, ch2);
  int res2 = sprintf(str2, format, ch1, ch2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_5) {
  char format[] = "%c %c";
  char str1[100];
  char str2[100];
  char ch1 = 'H';
  char ch2 = 'e';

  int res1 = s21_sprintf(str1, format, ch1, ch2);
  int res2 = sprintf(str2, format, ch1, ch2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_6) {
  char format[] = "%cstr\n%c";
  char str1[100];
  char str2[100];
  char ch1 = 'H';
  char ch2 = 'e';

  int res1 = s21_sprintf(str1, format, ch1, ch2);
  int res2 = sprintf(str2, format, ch1, ch2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_7) {
  char format[] = "%c\t%c";
  char str1[100];
  char str2[100];
  char ch1 = 'H';
  char ch2 = 'e';

  int res1 = s21_sprintf(str1, format, ch1, ch2);
  int res2 = sprintf(str2, format, ch1, ch2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_1) {
  char format[] = "%-c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_2) {
  char format[] = "%+c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_3) {
  char format[] = "% c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_4) {
  char format[] = "%#c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_5) {
  char format[] = "%0c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_6) {
  char format[] = "%-+c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_7) {
  char format[] = "%-+ c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_8) {
  char format[] = "%-+ #c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_9) {
  char format[] = "%-+ #0c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_10) {
  char format[] = "%+#-0 c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_11) {
  char format[] = "%10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_12) {
  char format[] = "%-10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_13) {
  char format[] = "%+10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_14) {
  char format[] = "% 10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_15) {
  char format[] = "%#10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_16) {
  char format[] = "%010c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_17) {
  char format[] = "%-+10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_18) {
  char format[] = "%-+ 10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_19) {
  char format[] = "%-+ #10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_20) {
  char format[] = "%-+ #010c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_21) {
  char format[] = "%+#-0 10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_22) {
  char format[] = "%+#-0 *c";
  char str1[100];
  char str2[100];
  char ch = 'H';
  int d = 10;

  int res1 = s21_sprintf(str1, format, d, ch);
  int res2 = sprintf(str2, format, d, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_23) {
  char format[] = "%.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_24) {
  char format[] = "%-.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_25) {
  char format[] = "%+.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_26) {
  char format[] = "% .10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_27) {
  char format[] = "%#.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_28) {
  char format[] = "%0.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_29) {
  char format[] = "%-+.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_30) {
  char format[] = "%-+ .10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_31) {
  char format[] = "%-+ #.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_32) {
  char format[] = "%-+ #0.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_33) {
  char format[] = "%+#-0 .10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_34) {
  char format[] = "%+#-0 .*c";
  char str1[100];
  char str2[100];
  char ch = 'H';
  int d = 10;

  int res1 = s21_sprintf(str1, format, d, ch);
  int res2 = sprintf(str2, format, d, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_35) {
  char format[] = "%+#-0 10.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_36) {
  char format[] = "%+#-0 10.3c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_flags_37) {
  char format[] = "%+#-0 3.10c";
  char str1[100];
  char str2[100];
  char ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_c_long_1) {
  char format[] = "%lc";
  char str1[100];
  char str2[100];
  wchar_t ch = 'H';

  int res1 = s21_sprintf(str1, format, ch);
  int res2 = sprintf(str2, format, ch);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_1) {
  char format[] = "%d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_2) {
  char format[] = "str: %d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_3) {
  char format[] = "%dstr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_4) {
  char format[] = "%d%d";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_5) {
  char format[] = "%d %d";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_6) {
  char format[] = "%dstr\n%d";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_7) {
  char format[] = "%d\t%d";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_1) {
  char format[] = "%-d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_2) {
  char format[] = "%+d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_3) {
  char format[] = "% d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_4) {
  char format[] = "%#d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_5) {
  char format[] = "%0d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_6) {
  char format[] = "%-+d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_7) {
  char format[] = "%-+ d";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_8) {
  char format[] = "%-+ #d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_9) {
  char format[] = "%-+ #0d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_10) {
  char format[] = "%+#-0 d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_11) {
  char format[] = "%10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_12) {
  char format[] = "%-10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_13) {
  char format[] = "%+10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_14) {
  char format[] = "% 10d";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_15) {
  char format[] = "%#10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_16) {
  char format[] = "%010d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_17) {
  char format[] = "%+010d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_18) {
  char format[] = "%-+ 10d";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_19) {
  char format[] = "%-+ #10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_20) {
  char format[] = "%-+ #010d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_21) {
  char format[] = "%+#-0 10d";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_22) {
  char format[] = "%+#-0 *d";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_23) {
  char format[] = "%.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_24) {
  char format[] = "%.0d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_25) {
  char format[] = "%.2d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_26) {
  char format[] = "%.3d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_27) {
  char format[] = "%-.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_28) {
  char format[] = "%+.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_29) {
  char format[] = "% .10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_30) {
  char format[] = "%#.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_31) {
  char format[] = "%0.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_32) {
  char format[] = "%-+.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_33) {
  char format[] = "%-+ .10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_34) {
  char format[] = "%-+ #.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_35) {
  char format[] = "%-+ #0.10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_36) {
  char format[] = "%+#-0 .10d";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_37) {
  char format[] = "%+#-0 .*d";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_38) {
  char format[] = "%+#-0 10.10d";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_39) {
  char format[] = "%+#-0 10.3d";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_flags_40) {
  char format[] = "%+#-0 3.10d";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_long_1) {
  char format[] = "%hd";
  char str1[100];
  char str2[100];
  short int d = INT8_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_long_2) {
  char format[] = "%ld";
  char str1[100];
  char str2[100];
  long int d = INT32_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_d_long_3) {
  char format[] = "%lld";
  char str1[100];
  char str2[100];
  long long int d = INT64_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_1) {
  char format[] = "%i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_2) {
  char format[] = "str: %i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_3) {
  char format[] = "%istr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_4) {
  char format[] = "%i%i";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_5) {
  char format[] = "%i %i";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_6) {
  char format[] = "%istr\n%i";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_7) {
  char format[] = "%i\t%i";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_1) {
  char format[] = "%-i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_2) {
  char format[] = "%+i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_3) {
  char format[] = "% i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_4) {
  char format[] = "%#i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_5) {
  char format[] = "%0i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_6) {
  char format[] = "%-+i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_7) {
  char format[] = "%-+ i";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_8) {
  char format[] = "%-+ #i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_9) {
  char format[] = "%-+ #0i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_10) {
  char format[] = "%+#-0 i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_11) {
  char format[] = "%10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_12) {
  char format[] = "%-10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_13) {
  char format[] = "%+10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_14) {
  char format[] = "% 10i";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_15) {
  char format[] = "%#10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_16) {
  char format[] = "%010i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_17) {
  char format[] = "%-+10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_18) {
  char format[] = "%-+ 10i";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_19) {
  char format[] = "%-+ #10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_20) {
  char format[] = "%-+ #010i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_21) {
  char format[] = "%+#-0 10i";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_22) {
  char format[] = "%+#-0 *i";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_23) {
  char format[] = "%.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_24) {
  char format[] = "%.0i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_25) {
  char format[] = "%.2i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_26) {
  char format[] = "%.3i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_27) {
  char format[] = "%-.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_28) {
  char format[] = "%+.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_29) {
  char format[] = "% .10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_30) {
  char format[] = "%#.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_31) {
  char format[] = "%0.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_32) {
  char format[] = "%-+.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_33) {
  char format[] = "%-+ .10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_34) {
  char format[] = "%-+ #.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_35) {
  char format[] = "%-+ #0.10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_36) {
  char format[] = "%+#-0 .10i";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_37) {
  char format[] = "%+#-0 .*i";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_38) {
  char format[] = "%+#-0 10.10i";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_39) {
  char format[] = "%+#-0 10.3i";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_flags_40) {
  char format[] = "%+#-0 3.10i";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_long_1) {
  char format[] = "%hi";
  char str1[100];
  char str2[100];
  short int d = INT8_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_long_2) {
  char format[] = "%li";
  char str1[100];
  char str2[100];
  long int d = INT32_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_i_long_3) {
  char format[] = "%lli";
  char str1[100];
  char str2[100];
  long long int d = INT64_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_1) {
  char format[] = "%e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_2) {
  char format[] = "str: %e";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_3) {
  char format[] = "%estr1";
  char str1[100];
  char str2[100];
  float num = +123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_4) {
  char format[] = "%e%e";
  char str1[100];
  char str2[100];
  float num1 = 123.02;
  float num2 = 1.33;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_5) {
  char format[] = "%e %e";
  char str1[100];
  char str2[100];
  float num1 = 0.873;
  float num2 = 1234.2;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_6) {
  char format[] = "%estr\n%e";
  char str1[100];
  char str2[100];
  float num1 = 0;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_7) {
  char format[] = "%e\t%e";
  char str1[100];
  char str2[100];
  float num1 = -2;
  float num2 = 57.58;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_1) {
  char format[] = "%-e";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_2) {
  char format[] = "%+e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_3) {
  char format[] = "% e";
  char str1[100];
  char str2[100];
  float num = -13.1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_4) {
  char format[] = "%#e";
  char str1[100];
  char str2[100];
  float num = 12.0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_5) {
  char format[] = "%0e";
  char str1[100];
  char str2[100];
  float num = 1233.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_6) {
  char format[] = "%-+e";
  char str1[100];
  char str2[100];
  float num = 0.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_7) {
  char format[] = "%-+ e";
  char str1[100];
  char str2[100];
  float num = 33.33;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_8) {
  char format[] = "%-+ #e";
  char str1[100];
  char str2[100];
  float num = 103.1157;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_9) {
  char format[] = "%-+ #0e";
  char str1[100];
  char str2[100];
  float num = 23.127;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_10) {
  char format[] = "%+#-0 e";
  char str1[100];
  char str2[100];
  float num = -123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_11) {
  char format[] = "%10e";
  char str1[100];
  char str2[100];
  float num = 123123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_12) {
  char format[] = "%-10e";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_13) {
  char format[] = "%+10e";
  char str1[100];
  char str2[100];
  float num = -1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_14) {
  char format[] = "% 10e";
  char str1[100];
  char str2[100];
  float num = 0.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_15) {
  char format[] = "%#10e";
  char str1[100];
  char str2[100];
  float num = 0.999999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_16) {
  char format[] = "%010e";
  char str1[100];
  char str2[100];
  float num = 9.99999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_17) {
  char format[] = "%-+10e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_18) {
  char format[] = "%-+ 10e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_19) {
  char format[] = "%-+ #10e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_20) {
  char format[] = "%-+ #010e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_21) {
  char format[] = "%+#-0 10e";
  char str1[100];
  char str2[100];
  float num = 0.10203;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_22) {
  char format[] = "%+#-0 *e";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_23) {
  char format[] = "%.6e";
  char str1[100];
  char str2[100];
  float num = 1243.3;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_24) {
  char format[] = "%.0e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_25) {
  char format[] = "%.2e";
  char str1[100];
  char str2[100];
  float num = -20.00123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_26) {
  char format[] = "%.3e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_27) {
  char format[] = "%-.6e";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_28) {
  char format[] = "%+.6e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_29) {
  char format[] = "% .6e";
  char str1[100];
  char str2[100];
  float num = 1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_30) {
  char format[] = "%#.6e";
  char str1[100];
  char str2[100];
  float num = 103.100001;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_31) {
  char format[] = "%0.6e";
  char str1[100];
  char str2[100];
  float num = 0.999999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_32) {
  char format[] = "%-+.6e";
  char str1[100];
  char str2[100];
  float num = 100;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_33) {
  char format[] = "%-+ .6e";
  char str1[100];
  char str2[100];
  float num = 10033.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_34) {
  char format[] = "%-+ #.6e";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_35) {
  char format[] = "%-+ #0.6e";
  char str1[100];
  char str2[100];
  float num = -1.00003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_36) {
  char format[] = "%+#-0 .6e";
  char str1[100];
  char str2[100];
  float num = 0.13;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_37) {
  char format[] = "%+#-0 .*e";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_38) {
  char format[] = "%+#-0 10.6e";
  char str1[100];
  char str2[100];
  float num = 3.12301;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_39) {
  char format[] = "%+#-0 10.3e";
  char str1[100];
  char str2[100];
  float num = 23.12003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_flags_40) {
  char format[] = "%+#-0 3.6e";
  char str1[100];
  char str2[100];
  float num = 103.023;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_long_1) {
  char format[] = "%le";
  char str1[100];
  char str2[100];
  double num = 13000000000000000;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_e_long_2) {
  char format[] = "%Le";
  char str1[100];
  char str2[100];
  long double num = 1e-309;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_1) {
  char format[] = "%E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_2) {
  char format[] = "str: %E";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_3) {
  char format[] = "%Estr1";
  char str1[100];
  char str2[100];
  float num = +123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_4) {
  char format[] = "%E%E";
  char str1[100];
  char str2[100];
  float num1 = 123.02;
  float num2 = 1.33;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_5) {
  char format[] = "%E %E";
  char str1[100];
  char str2[100];
  float num1 = 0.873;
  float num2 = 1234.2;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_6) {
  char format[] = "%Estr\n%E";
  char str1[100];
  char str2[100];
  float num1 = 0;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_7) {
  char format[] = "%E\t%E";
  char str1[100];
  char str2[100];
  float num1 = -2;
  float num2 = 57.58;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_1) {
  char format[] = "%-E";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_2) {
  char format[] = "%+E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_3) {
  char format[] = "% E";
  char str1[100];
  char str2[100];
  float num = -13.1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_4) {
  char format[] = "%#E";
  char str1[100];
  char str2[100];
  float num = 12.0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_5) {
  char format[] = "%0E";
  char str1[100];
  char str2[100];
  float num = 1233.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_6) {
  char format[] = "%-+E";
  char str1[100];
  char str2[100];
  float num = 0.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_7) {
  char format[] = "%-+ E";
  char str1[100];
  char str2[100];
  float num = 33.33;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_8) {
  char format[] = "%-+ #E";
  char str1[100];
  char str2[100];
  float num = 103.1157;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_9) {
  char format[] = "%-+ #0E";
  char str1[100];
  char str2[100];
  float num = 23.127;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_10) {
  char format[] = "%+#-0 E";
  char str1[100];
  char str2[100];
  float num = -123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_11) {
  char format[] = "%10E";
  char str1[100];
  char str2[100];
  float num = 123123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_12) {
  char format[] = "%-10E";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_13) {
  char format[] = "%+10E";
  char str1[100];
  char str2[100];
  float num = -1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_14) {
  char format[] = "% 10E";
  char str1[100];
  char str2[100];
  float num = 0.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_15) {
  char format[] = "%#10E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_16) {
  char format[] = "%010E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_17) {
  char format[] = "%-+10E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_18) {
  char format[] = "%-+ 10E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_19) {
  char format[] = "%-+ #10E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_20) {
  char format[] = "%-+ #010E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_21) {
  char format[] = "%+#-0 10E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_22) {
  char format[] = "%+#-0 *E";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_23) {
  char format[] = "%.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_24) {
  char format[] = "%.0E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_25) {
  char format[] = "%.2E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_26) {
  char format[] = "%.3E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_27) {
  char format[] = "%-.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_28) {
  char format[] = "%+.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_29) {
  char format[] = "% .6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_30) {
  char format[] = "%#.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_31) {
  char format[] = "%0.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_32) {
  char format[] = "%-+.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_33) {
  char format[] = "%-+ .6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_34) {
  char format[] = "%-+ #.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_35) {
  char format[] = "%-+ #0.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_36) {
  char format[] = "%+#-0 .6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_37) {
  char format[] = "%+#-0 .*E";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_38) {
  char format[] = "%+#-0 10.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_39) {
  char format[] = "%+#-0 10.3E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_flags_40) {
  char format[] = "%+#-0 3.6E";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_long_1) {
  char format[] = "%lE";
  char str1[100];
  char str2[100];
  double num = 1e299;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_E_long_2) {
  char format[] = "%LE";
  char str1[100];
  char str2[100];
  long double num = 1e-309;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_1) {
  char format[] = "%f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_2) {
  char format[] = "str: %f";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_3) {
  char format[] = "%fstr1";
  char str1[100];
  char str2[100];
  float num = +123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_4) {
  char format[] = "%f%f";
  char str1[100];
  char str2[100];
  float num1 = 123.02;
  float num2 = 1.33;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_5) {
  char format[] = "%f %f";
  char str1[100];
  char str2[100];
  float num1 = 0.873;
  float num2 = 1234.2;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_6) {
  char format[] = "%fstr\n%f";
  char str1[100];
  char str2[100];
  float num1 = 0;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_7) {
  char format[] = "%f\t%f";
  char str1[100];
  char str2[100];
  float num1 = -2;
  float num2 = 57.58;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_1) {
  char format[] = "%-f";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_2) {
  char format[] = "%+f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_3) {
  char format[] = "% f";
  char str1[100];
  char str2[100];
  float num = -13.1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_4) {
  char format[] = "%#f";
  char str1[100];
  char str2[100];
  float num = 12.0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_5) {
  char format[] = "%0f";
  char str1[100];
  char str2[100];
  float num = 1233.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_6) {
  char format[] = "%-+f";
  char str1[100];
  char str2[100];
  float num = 0.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_7) {
  char format[] = "%-+ f";
  char str1[100];
  char str2[100];
  float num = 33.33;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_8) {
  char format[] = "%-+ #f";
  char str1[100];
  char str2[100];
  float num = 103.1157;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_9) {
  char format[] = "%-+ #0f";
  char str1[100];
  char str2[100];
  float num = 23.127;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_10) {
  char format[] = "%+#-0 f";
  char str1[100];
  char str2[100];
  float num = -123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_11) {
  char format[] = "%10f";
  char str1[100];
  char str2[100];
  float num = 123123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_12) {
  char format[] = "%-10f";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_13) {
  char format[] = "%+10f";
  char str1[100];
  char str2[100];
  float num = -1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_14) {
  char format[] = "% 10f";
  char str1[100];
  char str2[100];
  float num = 0.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_15) {
  char format[] = "%#10f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_16) {
  char format[] = "%010f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_17) {
  char format[] = "%-+10f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_18) {
  char format[] = "%-+ 10f";
  char str1[100];
  char str2[100];
  float num = 1e100;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_19) {
  char format[] = "%-+ #10f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_20) {
  char format[] = "%-+ #010f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_21) {
  char format[] = "%+#-0 10f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_22) {
  char format[] = "%+#-0 *f";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_23) {
  char format[] = "%.6f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_24) {
  char format[] = "%.0f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_25) {
  char format[] = "%.2f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_26) {
  char format[] = "%.3f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_27) {
  char format[] = "%-.6f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_28) {
  char format[] = "%+.6f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_29) {
  char format[] = "% .6f";
  char str1[100];
  char str2[100];
  float num = 1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_30) {
  char format[] = "%#.6f";
  char str1[100];
  char str2[100];
  float num = 103.100001;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_31) {
  char format[] = "%0.6f";
  char str1[100];
  char str2[100];
  float num = 0.999999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_32) {
  char format[] = "%-+.6f";
  char str1[100];
  char str2[100];
  float num = 100;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_33) {
  char format[] = "%-+ .6f";
  char str1[100];
  char str2[100];
  float num = 10033.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_34) {
  char format[] = "%-+ #.6f";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_35) {
  char format[] = "%-+ #0.6f";
  char str1[100];
  char str2[100];
  float num = -1.00003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_36) {
  char format[] = "%+#-0 .6f";
  char str1[100];
  char str2[100];
  float num = 0.13;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_37) {
  char format[] = "%+#-0 .*f";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_38) {
  char format[] = "%+#-0 10.6f";
  char str1[100];
  char str2[100];
  float num = 3.12301;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_39) {
  char format[] = "%+#-0 10.3f";
  char str1[100];
  char str2[100];
  float num = 23.12003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_flags_40) {
  char format[] = "%+#-0 3.6f";
  char str1[100];
  char str2[100];
  float num = 103.023;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_long_1) {
  char format[] = "%lf";
  char str1[100];
  char str2[100];
  double num = 13000000000000000;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_f_long_2) {
  char format[] = "%Lf";
  char str1[100];
  char str2[100];
  long double num = 1e-309;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_1) {
  char format[] = "%g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_2) {
  char format[] = "str: %g";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_3) {
  char format[] = "%gstr1";
  char str1[100];
  char str2[100];
  float num = +123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_4) {
  char format[] = "%g%g";
  char str1[100];
  char str2[100];
  float num1 = 123.02;
  float num2 = 1.33;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_5) {
  char format[] = "%g %g";
  char str1[100];
  char str2[100];
  float num1 = 0.873;
  float num2 = 1234.2;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_6) {
  char format[] = "%gstr\n%g";
  char str1[100];
  char str2[100];
  float num1 = 0;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_7) {
  char format[] = "%g\t%g";
  char str1[100];
  char str2[100];
  float num1 = -2;
  float num2 = 57.58;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_1) {
  char format[] = "%-g";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_2) {
  char format[] = "%+g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_3) {
  char format[] = "% g";
  char str1[100];
  char str2[100];
  float num = -13.1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_4) {
  char format[] = "%#g";
  char str1[100];
  char str2[100];
  float num = 12.0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_5) {
  char format[] = "%0g";
  char str1[100];
  char str2[100];
  float num = 1233.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_6) {
  char format[] = "%-+g";
  char str1[100];
  char str2[100];
  float num = 0.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_7) {
  char format[] = "%-+ g";
  char str1[100];
  char str2[100];
  float num = 33.33;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_8) {
  char format[] = "%-+ #g";
  char str1[100];
  char str2[100];
  float num = 103.1157;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_9) {
  char format[] = "%-+ #0g";
  char str1[100];
  char str2[100];
  float num = 23.127;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_10) {
  char format[] = "%+#-0 g";
  char str1[100];
  char str2[100];
  float num = -123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_11) {
  char format[] = "%10g";
  char str1[100];
  char str2[100];
  float num = 123123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_12) {
  char format[] = "%-10g";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_13) {
  char format[] = "%+10g";
  char str1[100];
  char str2[100];
  float num = -1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_14) {
  char format[] = "% 10g";
  char str1[100];
  char str2[100];
  float num = 0.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_15) {
  char format[] = "%#10g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_16) {
  char format[] = "%010g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_17) {
  char format[] = "%-+10g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_18) {
  char format[] = "%-+ 10g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_19) {
  char format[] = "%-+ #10g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_20) {
  char format[] = "%-+ #010g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_21) {
  char format[] = "%+#-0 10g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_22) {
  char format[] = "%+#-0 *g";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_23) {
  char format[] = "%.6g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_24) {
  char format[] = "%.0g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_25) {
  char format[] = "%.2g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_26) {
  char format[] = "%.3g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_27) {
  char format[] = "%-.6g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_28) {
  char format[] = "%+.6g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_29) {
  char format[] = "% .6g";
  char str1[100];
  char str2[100];
  float num = 1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_30) {
  char format[] = "%#.6g";
  char str1[100];
  char str2[100];
  float num = 103.100001;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_31) {
  char format[] = "%0.6g";
  char str1[100];
  char str2[100];
  float num = 0.999999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_32) {
  char format[] = "%-+.6g";
  char str1[100];
  char str2[100];
  float num = 100;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_33) {
  char format[] = "%-+ .6g";
  char str1[100];
  char str2[100];
  float num = 10033.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_34) {
  char format[] = "%-+ #.6g";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_35) {
  char format[] = "%-+ #0.6g";
  char str1[100];
  char str2[100];
  float num = -1.00003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_36) {
  char format[] = "%+#-0 .6g";
  char str1[100];
  char str2[100];
  float num = 0.13;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_37) {
  char format[] = "%+#-0 .*g";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_38) {
  char format[] = "%+#-0 10.6g";
  char str1[100];
  char str2[100];
  float num = 1e100;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_39) {
  char format[] = "%+#-0 10.3g";
  char str1[100];
  char str2[100];
  float num = 23.12003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_flags_40) {
  char format[] = "%+#-0 3.6g";
  char str1[100];
  char str2[100];
  float num = 103.023;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_long_1) {
  char format[] = "%lg";
  char str1[100];
  char str2[100];
  double num = 13000000000000000;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_g_long_2) {
  char format[] = "%Lg";
  char str1[100];
  char str2[100];
  long double num = 1e-309;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_1) {
  char format[] = "%G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_2) {
  char format[] = "str: %G";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_3) {
  char format[] = "%Gstr1";
  char str1[100];
  char str2[100];
  float num = +123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_4) {
  char format[] = "%G%G";
  char str1[100];
  char str2[100];
  float num1 = 123.02;
  float num2 = 1.33;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_5) {
  char format[] = "%G %G";
  char str1[100];
  char str2[100];
  float num1 = 0.873;
  float num2 = 1234.2;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_6) {
  char format[] = "%Gstr\n%G";
  char str1[100];
  char str2[100];
  float num1 = 0;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_7) {
  char format[] = "%G\t%G";
  char str1[100];
  char str2[100];
  float num1 = -2;
  float num2 = 57.58;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_1) {
  char format[] = "%-G";
  char str1[100];
  char str2[100];
  float num = -123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_2) {
  char format[] = "%+G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_3) {
  char format[] = "% G";
  char str1[100];
  char str2[100];
  float num = -13.1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_4) {
  char format[] = "%#G";
  char str1[100];
  char str2[100];
  float num = 12.0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_5) {
  char format[] = "%0G";
  char str1[100];
  char str2[100];
  float num = 1233.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_6) {
  char format[] = "%-+G";
  char str1[100];
  char str2[100];
  float num = 0.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_7) {
  char format[] = "%-+ G";
  char str1[100];
  char str2[100];
  float num = 33.33;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_8) {
  char format[] = "%-+ #G";
  char str1[100];
  char str2[100];
  float num = 103.1157;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_9) {
  char format[] = "%-+ #0G";
  char str1[100];
  char str2[100];
  float num = 23.127;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_10) {
  char format[] = "%+#-0 G";
  char str1[100];
  char str2[100];
  float num = -123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_11) {
  char format[] = "%10G";
  char str1[100];
  char str2[100];
  float num = 123123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_12) {
  char format[] = "%-10G";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_13) {
  char format[] = "%+10G";
  char str1[100];
  char str2[100];
  float num = -1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_14) {
  char format[] = "% 10G";
  char str1[100];
  char str2[100];
  float num = 0.003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_15) {
  char format[] = "%#10G";
  char str1[100];
  char str2[100];
  float num = 0.999999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_16) {
  char format[] = "%010G";
  char str1[100];
  char str2[100];
  float num = 9.99999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_17) {
  char format[] = "%-+10G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_18) {
  char format[] = "%-+ 10G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_19) {
  char format[] = "%-+ #10G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_20) {
  char format[] = "%-+ #010G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_21) {
  char format[] = "%+#-0 10G";
  char str1[100];
  char str2[100];
  float num = 0.10203;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_22) {
  char format[] = "%+#-0 *G";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_23) {
  char format[] = "%.6G";
  char str1[100];
  char str2[100];
  float num = 1243.3;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_24) {
  char format[] = "%.0G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_25) {
  char format[] = "%.2G";
  char str1[100];
  char str2[100];
  float num = -20.00123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_26) {
  char format[] = "%.3G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_27) {
  char format[] = "%-.6G";
  char str1[100];
  char str2[100];
  float num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_28) {
  char format[] = "%+.6G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_29) {
  char format[] = "% .6G";
  char str1[100];
  char str2[100];
  float num = 1;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_30) {
  char format[] = "%#.6G";
  char str1[100];
  char str2[100];
  float num = 103.100001;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_31) {
  char format[] = "%0.6G";
  char str1[100];
  char str2[100];
  float num = 0.999999;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_32) {
  char format[] = "%-+.6G";
  char str1[100];
  char str2[100];
  float num = 100;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_33) {
  char format[] = "%-+ .6G";
  char str1[100];
  char str2[100];
  float num = 10033.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_34) {
  char format[] = "%-+ #.6G";
  char str1[100];
  char str2[100];
  float num = 123.123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_35) {
  char format[] = "%-+ #0.6G";
  char str1[100];
  char str2[100];
  float num = -1.00003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_36) {
  char format[] = "%+#-0 .6G";
  char str1[100];
  char str2[100];
  float num = 0.13;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_37) {
  char format[] = "%+#-0 .*G";
  char str1[100];
  char str2[100];
  int num1 = 10;
  float num2 = 3;

  int res1 = s21_sprintf(str1, format, num1, num2);
  int res2 = sprintf(str2, format, num1, num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_38) {
  char format[] = "%+#-0 10.6G";
  char str1[100];
  char str2[100];
  float num = 3.12301;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_39) {
  char format[] = "%+#-0 10.3G";
  char str1[100];
  char str2[100];
  float num = 23.12003;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_flags_40) {
  char format[] = "%+#-0 3.6G";
  char str1[100];
  char str2[100];
  float num = 103.023;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_long_1) {
  char format[] = "%lG";
  char str1[100];
  char str2[100];
  double num = 13000000000000000;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_G_long_2) {
  char format[] = "%LG";
  char str1[100];
  char str2[100];
  long double num = 1e-309;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_1) {
  char format[] = "%o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_2) {
  char format[] = "str: %o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_3) {
  char format[] = "%ostr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_4) {
  char format[] = "%o%o";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_5) {
  char format[] = "%o %o";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_6) {
  char format[] = "%ostr\n%o";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_7) {
  char format[] = "%o\t%o";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_1) {
  char format[] = "%-o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_2) {
  char format[] = "%+o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_3) {
  char format[] = "% o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_4) {
  char format[] = "%#o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_5) {
  char format[] = "%0o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_6) {
  char format[] = "%-+o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_7) {
  char format[] = "%-+ o";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_8) {
  char format[] = "%-+ #o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_9) {
  char format[] = "%-+ #0o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_10) {
  char format[] = "%+#-0 o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_11) {
  char format[] = "%10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_12) {
  char format[] = "%-10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_13) {
  char format[] = "%+10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_14) {
  char format[] = "% 10o";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_15) {
  char format[] = "%#10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_16) {
  char format[] = "%010o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_17) {
  char format[] = "%-+10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_18) {
  char format[] = "%-+ 10o";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_19) {
  char format[] = "%-+ #10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_20) {
  char format[] = "%-+ #010o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_21) {
  char format[] = "%+#-0 10o";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_22) {
  char format[] = "%+#-0 *o";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_23) {
  char format[] = "%.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_24) {
  char format[] = "%.0o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_25) {
  char format[] = "%.2o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_26) {
  char format[] = "%.3o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_27) {
  char format[] = "%-.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_28) {
  char format[] = "%+.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_29) {
  char format[] = "% .10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_30) {
  char format[] = "%#.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_31) {
  char format[] = "%0.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_32) {
  char format[] = "%-+.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_33) {
  char format[] = "%-+ .10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_34) {
  char format[] = "%-+ #.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_35) {
  char format[] = "%-+ #0.10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_36) {
  char format[] = "%+#-0 .10o";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_37) {
  char format[] = "%+#-0 .*o";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_38) {
  char format[] = "%+#-0 10.10o";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_39) {
  char format[] = "%+#-0 10.3o";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_flags_40) {
  char format[] = "%+#-0 3.10o";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_long_1) {
  char format[] = "%ho";
  char str1[100];
  char str2[100];
  short int d = INT8_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_long_2) {
  char format[] = "%lo";
  char str1[100];
  char str2[100];
  long int d = INT32_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_o_long_3) {
  char format[] = "%llo";
  char str1[100];
  char str2[100];
  long long int d = INT64_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_1) {
  char format[] = "%s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_2) {
  char format[] = "str: %s";
  char str1[100];
  char str2[100];
  char *str = "Hello    ";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_3) {
  char format[] = "%sstr1";
  char str1[100];
  char str2[100];
  char *str = "     World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_4) {
  char format[] = "%s%s";
  char str1[100];
  char str2[100];
  char *str = "Hello ";
  char *Str = "World";

  int res1 = s21_sprintf(str1, format, str, Str);
  int res2 = sprintf(str2, format, str, Str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_5) {
  char format[] = "%s %s";
  char str1[100];
  char str2[100];
  char *str = "H";
  char *Str = "W";

  int res1 = s21_sprintf(str1, format, str, Str);
  int res2 = sprintf(str2, format, str, Str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_6) {
  char format[] = "%sstr\n%s";
  char str1[100];
  char str2[100];
  char *str = "123\n";
  char *Str = "\t\t222";

  int res1 = s21_sprintf(str1, format, str, Str);
  int res2 = sprintf(str2, format, str, Str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_7) {
  char format[] = "%s\t%s";
  char str1[100];
  char str2[100];
  char *str = "";
  char *Str = "";

  int res1 = s21_sprintf(str1, format, str, Str);
  int res2 = sprintf(str2, format, str, Str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_1) {
  char format[] = "%-s";
  char str1[100];
  char str2[100];
  char *str = "       Hello";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_2) {
  char format[] = "%+s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_3) {
  char format[] = "% s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_4) {
  char format[] = "%#s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_5) {
  char format[] = "%0s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_6) {
  char format[] = "%-+s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_7) {
  char format[] = "%-+ s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_8) {
  char format[] = "%-+ #s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_9) {
  char format[] = "%-+ #0s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_10) {
  char format[] = "%+#-0 s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_11) {
  char format[] = "%10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_12) {
  char format[] = "%-10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_13) {
  char format[] = "%+10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_14) {
  char format[] = "% 10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_15) {
  char format[] = "%#10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_16) {
  char format[] = "%010s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_17) {
  char format[] = "%-+10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_18) {
  char format[] = "%-+ 10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_19) {
  char format[] = "%-+ #10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_20) {
  char format[] = "%-+ #010s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_21) {
  char format[] = "%+#-0 10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_22) {
  char format[] = "%+#-0 *s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";
  int d = 10;

  int res1 = s21_sprintf(str1, format, d, str);
  int res2 = sprintf(str2, format, d, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_23) {
  char format[] = "%.10s";
  char str1[100];
  char str2[100];
  char *str = "";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_24) {
  char format[] = "%-.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_25) {
  char format[] = "%+.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_26) {
  char format[] = "% .10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_27) {
  char format[] = "%#.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_28) {
  char format[] = "%0.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_29) {
  char format[] = "%-+.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_30) {
  char format[] = "%-+ .10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_31) {
  char format[] = "%-+ #.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_32) {
  char format[] = "%-+ #0.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_33) {
  char format[] = "%+#-0 .10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_34) {
  char format[] = "%+#-0 .*s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";
  int d = 10;

  int res1 = s21_sprintf(str1, format, d, str);
  int res2 = sprintf(str2, format, d, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_35) {
  char format[] = "%+#-0 10.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_36) {
  char format[] = "%+#-0 10.3s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_37) {
  char format[] = "% s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_s_flags_38) {
  char format[] = "%+#-0 3.10s";
  char str1[100];
  char str2[100];
  char *str = "Hello World";

  int res1 = s21_sprintf(str1, format, str);
  int res2 = sprintf(str2, format, str);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_1) {
  char format[] = "%u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_2) {
  char format[] = "str: %u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_3) {
  char format[] = "%ustr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_4) {
  char format[] = "%u%u";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_5) {
  char format[] = "%u %u";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_6) {
  char format[] = "%ustr\n%u";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_7) {
  char format[] = "%u\t%u";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_1) {
  char format[] = "%-u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_2) {
  char format[] = "%+u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_3) {
  char format[] = "% u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_4) {
  char format[] = "%#u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_5) {
  char format[] = "%0u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_6) {
  char format[] = "%-+u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_7) {
  char format[] = "%-+ u";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_8) {
  char format[] = "%-+ #u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_9) {
  char format[] = "%-+ #0u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_10) {
  char format[] = "%+#-0 u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_11) {
  char format[] = "%10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_12) {
  char format[] = "%-10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_13) {
  char format[] = "%+10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_14) {
  char format[] = "% 10u";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_15) {
  char format[] = "%#10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_16) {
  char format[] = "%010u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_17) {
  char format[] = "%-+10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_18) {
  char format[] = "%-+ 10u";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_19) {
  char format[] = "%-+ #10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_20) {
  char format[] = "%-+ #010u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_21) {
  char format[] = "%+#-0 10u";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_22) {
  char format[] = "%+#-0 *u";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_23) {
  char format[] = "%.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_24) {
  char format[] = "%.0u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_25) {
  char format[] = "%.2u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_26) {
  char format[] = "%.3u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_27) {
  char format[] = "%-.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_28) {
  char format[] = "%+.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_29) {
  char format[] = "% .10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_30) {
  char format[] = "%#.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_31) {
  char format[] = "%0.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_32) {
  char format[] = "%-+.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_33) {
  char format[] = "%-+ .10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_34) {
  char format[] = "%-+ #.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_35) {
  char format[] = "%-+ #0.10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_36) {
  char format[] = "%+#-0 .10u";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_37) {
  char format[] = "%+#-0 .*u";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_38) {
  char format[] = "%+#-0 10.10u";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_39) {
  char format[] = "%+#-0 10.3u";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_flags_40) {
  char format[] = "%+#-0 3.10u";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_long_1) {
  char format[] = "%hu";
  char str1[100];
  char str2[100];
  short int d = INT8_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_long_2) {
  char format[] = "%lu";
  char str1[100];
  char str2[100];
  long int d = INT32_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_u_long_3) {
  char format[] = "%llu";
  char str1[100];
  char str2[100];
  long long int d = INT64_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_1) {
  char format[] = "%x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_2) {
  char format[] = "str: %x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_3) {
  char format[] = "%xstr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_4) {
  char format[] = "%x%x";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_5) {
  char format[] = "%x %x";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_6) {
  char format[] = "%xstr\n%x";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_7) {
  char format[] = "%x\t%x";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_1) {
  char format[] = "%-x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_2) {
  char format[] = "%+x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_3) {
  char format[] = "% x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_4) {
  char format[] = "%#x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_5) {
  char format[] = "%0x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_6) {
  char format[] = "%-+x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_7) {
  char format[] = "%-+ x";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_8) {
  char format[] = "%-+ #x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_9) {
  char format[] = "%-+ #0x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_10) {
  char format[] = "%+#-0 x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_11) {
  char format[] = "%10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_12) {
  char format[] = "%-10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_13) {
  char format[] = "%+10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_14) {
  char format[] = "% 10x";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_15) {
  char format[] = "%#10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_16) {
  char format[] = "%010x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_17) {
  char format[] = "%-+10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_18) {
  char format[] = "%-+ 10x";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_19) {
  char format[] = "%-+ #10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_20) {
  char format[] = "%-+ #010x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_21) {
  char format[] = "%+#-0 10x";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_22) {
  char format[] = "%+#-0 *x";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_23) {
  char format[] = "%.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_24) {
  char format[] = "%.0x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_25) {
  char format[] = "%.2x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_26) {
  char format[] = "%.3x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_27) {
  char format[] = "%-.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_28) {
  char format[] = "%+.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_29) {
  char format[] = "% .10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_30) {
  char format[] = "%#.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_31) {
  char format[] = "%0.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_32) {
  char format[] = "%-+.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_33) {
  char format[] = "%-+ .10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_34) {
  char format[] = "%-+ #.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_35) {
  char format[] = "%-+ #0.10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_36) {
  char format[] = "%+#-0 .10x";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_37) {
  char format[] = "%+#-0 .*x";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_38) {
  char format[] = "%+#-0 10.10x";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_39) {
  char format[] = "%+#-0 10.3x";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_flags_40) {
  char format[] = "%+#-0 3.10x";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_long_1) {
  char format[] = "%hx";
  char str1[100];
  char str2[100];
  short int d = INT8_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_long_2) {
  char format[] = "%lx";
  char str1[100];
  char str2[100];
  long int d = INT32_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_x_long_3) {
  char format[] = "%llx";
  char str1[100];
  char str2[100];
  long long int d = INT64_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_1) {
  char format[] = "%X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_2) {
  char format[] = "str: %X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_3) {
  char format[] = "%Xstr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_4) {
  char format[] = "%X%X";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_5) {
  char format[] = "%X %X";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_6) {
  char format[] = "%Xstr\n%X";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_7) {
  char format[] = "%X\t%X";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_1) {
  char format[] = "%-X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_2) {
  char format[] = "%+X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_3) {
  char format[] = "% X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_4) {
  char format[] = "%#X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_5) {
  char format[] = "%0X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_6) {
  char format[] = "%-+X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_7) {
  char format[] = "%-+ X";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_8) {
  char format[] = "%-+ #X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_9) {
  char format[] = "%-+ #0X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_10) {
  char format[] = "%+#-0 X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_11) {
  char format[] = "%10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_12) {
  char format[] = "%-10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_13) {
  char format[] = "%+10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_14) {
  char format[] = "% 10X";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_15) {
  char format[] = "%#10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_16) {
  char format[] = "%010X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_17) {
  char format[] = "%-+10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_18) {
  char format[] = "%-+ 10X";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_19) {
  char format[] = "%-+ #10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_20) {
  char format[] = "%-+ #010X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_21) {
  char format[] = "%+#-0 10X";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_22) {
  char format[] = "%+#-0 *X";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_23) {
  char format[] = "%.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_24) {
  char format[] = "%.0X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_25) {
  char format[] = "%.2X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_26) {
  char format[] = "%.3X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_27) {
  char format[] = "%-.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_28) {
  char format[] = "%+.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_29) {
  char format[] = "% .10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_30) {
  char format[] = "%#.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_31) {
  char format[] = "%0.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_32) {
  char format[] = "%-+.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_33) {
  char format[] = "%-+ .10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_34) {
  char format[] = "%-+ #.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_35) {
  char format[] = "%-+ #0.10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_36) {
  char format[] = "%+#-0 .10X";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_37) {
  char format[] = "%+#-0 .*X";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_38) {
  char format[] = "%+#-0 10.10X";
  char str1[100];
  char str2[100];
  int num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_39) {
  char format[] = "%+#-0 10.3X";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_flags_40) {
  char format[] = "%+#-0 3.10X";
  char str1[100];
  char str2[100];
  int num = 0;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_long_1) {
  char format[] = "%hX";
  char str1[100];
  char str2[100];
  short int d = INT8_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_long_2) {
  char format[] = "%lX";
  char str1[100];
  char str2[100];
  long int d = INT32_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_X_long_3) {
  char format[] = "%llX";
  char str1[100];
  char str2[100];
  long long int d = INT64_MAX;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_1) {
  char format[] = "%p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_2) {
  char format[] = "str: %p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_3) {
  char format[] = "%pstr1";
  char str1[100];
  char str2[100];
  int d = +228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_4) {
  char format[] = "%p%p";
  char str1[100];
  char str2[100];
  int d1 = -228;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_5) {
  char format[] = "%p %p";
  char str1[100];
  char str2[100];
  int d1 = 0x228;
  int d2 = 13;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_6) {
  char format[] = "%pstr\n%p";
  char str1[100];
  char str2[100];
  int d1 = 0xff;
  int d2 = 1;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_7) {
  char format[] = "%p\t%p";
  char str1[100];
  char str2[100];
  int d1 = 228;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_1) {
  char format[] = "%-p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_2) {
  char format[] = "%+p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_3) {
  char format[] = "% p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_4) {
  char format[] = "%#p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_5) {
  char format[] = "%0p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_6) {
  char format[] = "%-+p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_7) {
  char format[] = "%-+ p";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_8) {
  char format[] = "%-+ #p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_9) {
  char format[] = "%-+ #0p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_10) {
  char format[] = "%+#-0 p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_11) {
  char format[] = "%10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_12) {
  char format[] = "%-10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_13) {
  char format[] = "%+10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_14) {
  char format[] = "% 10p";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_15) {
  char format[] = "%#10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_16) {
  char format[] = "%010p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_17) {
  char format[] = "%-+10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_18) {
  char format[] = "%-+ 10p";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_19) {
  char format[] = "%-+ #10p";
  char str1[100];
  char str2[100];
  int d = 0;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_20) {
  char format[] = "%-+ #010p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_21) {
  char format[] = "%+#-0 10p";
  char str1[100];
  char str2[100];
  int d = -228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_22) {
  char format[] = "%+#-0 *p";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 0;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_23) {
  char format[] = "%.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_24) {
  char format[] = "%.0p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_25) {
  char format[] = "%.2p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_26) {
  char format[] = "%.3p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_27) {
  char format[] = "%-.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_28) {
  char format[] = "%+.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_29) {
  char format[] = "% .10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_30) {
  char format[] = "%#.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_31) {
  char format[] = "%0.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_32) {
  char format[] = "%-+.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_33) {
  char format[] = "%-+ .10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_34) {
  char format[] = "%-+ #.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_35) {
  char format[] = "%-+ #0.10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_36) {
  char format[] = "%+#-0 .10p";
  char str1[100];
  char str2[100];
  int d = 228;

  int res1 = s21_sprintf(str1, format, d);
  int res2 = sprintf(str2, format, d);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_37) {
  char format[] = "%+#-0 .*p";
  char str1[100];
  char str2[100];
  int d1 = 10;
  int d2 = 228;

  int res1 = s21_sprintf(str1, format, d1, d2);
  int res2 = sprintf(str2, format, d1, d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_38) {
  char format[] = "%+#-0 10.10p";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_39) {
  char format[] = "%+#-0 10.3p";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_p_flags_40) {
  char format[] = "%+#-0 3.10p";
  char str1[100];
  char str2[100];
  int num = 123;

  int res1 = s21_sprintf(str1, format, num);
  int res2 = sprintf(str2, format, num);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_spec_n_1) {
  char format[] = "%n";
  char str1[100];
  char str2[100];
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, &num1);
  int res2 = sprintf(str2, "%n", &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sprintf_spec_n_2) {
  char format[] = "str: %n";
  char str1[100];
  char str2[100];
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, &num1);
  int res2 = sprintf(str2, "str: %n", &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sprintf_spec_n_3) {
  char format[] = "%nstr!";
  char str1[100];
  char str2[100];
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, &num1);
  int res2 = sprintf(str2, "%nstr!", &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sprintf_spec_n_4) {
  char format[] = "%d%n";
  char str1[100];
  char str2[100];
  int integer = 228;
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, integer, &num1);
  int res2 = sprintf(str2, "%d%n", integer, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sprintf_spec_n_5) {
  char format[] = "%d%n%d";
  char str1[100];
  char str2[100];
  int integer = 228;
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, integer, &num1, integer);
  int res2 = sprintf(str2, "%d%n%d", integer, &num2, integer);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sprintf_spec_n_6) {
  char format[] = "%d\n%s\t%d%n";
  char str1[100];
  char str2[100];
  int integer = 228;
  char *str = "Hello World";
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, integer, str, integer, &num1);
  int res2 = sprintf(str2, "%d\n%s\t%d%n", integer, str, integer, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(sprintf_mixed_format_1) {
  char format[] = "%d\n%.2s\t%-+3.d%%ggf1111******";
  char str1[100];
  char str2[100];
  int integer = 228;
  char *str = "Hello World";
  int num1 = 0;
  int num2 = 0;

  int res1 = s21_sprintf(str1, format, integer, str, integer, &num1);
  int res2 = sprintf(str2, format, integer, str, integer, &num2);
  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

Suite *test_s21_sprintf() {
  Suite *suite = suite_create("s21_sprintf");
  TCase *tcase_sprintf = tcase_create("case_sprintf");

  tcase_add_test(tcase_sprintf, sprintf_spec_c_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_c_long_1);

  tcase_add_test(tcase_sprintf, sprintf_spec_d_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_long_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_d_long_3);

  tcase_add_test(tcase_sprintf, sprintf_spec_i_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_long_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_i_long_3);

  tcase_add_test(tcase_sprintf, sprintf_spec_e_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_e_long_2);

  tcase_add_test(tcase_sprintf, sprintf_spec_E_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_E_long_2);

  tcase_add_test(tcase_sprintf, sprintf_spec_f_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_f_long_2);

  tcase_add_test(tcase_sprintf, sprintf_spec_g_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_g_long_2);

  tcase_add_test(tcase_sprintf, sprintf_spec_G_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_G_long_2);

  tcase_add_test(tcase_sprintf, sprintf_spec_o_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_long_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_o_long_3);

  tcase_add_test(tcase_sprintf, sprintf_spec_s_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_s_flags_38);

  tcase_add_test(tcase_sprintf, sprintf_spec_u_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_long_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_u_long_3);

  tcase_add_test(tcase_sprintf, sprintf_spec_x_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_long_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_x_long_3);

  tcase_add_test(tcase_sprintf, sprintf_spec_X_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_flags_40);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_long_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_long_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_X_long_3);

  tcase_add_test(tcase_sprintf, sprintf_spec_p_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_6);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_7);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_8);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_9);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_10);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_11);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_12);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_13);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_14);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_15);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_16);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_17);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_18);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_19);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_20);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_21);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_22);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_23);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_24);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_25);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_26);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_27);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_28);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_29);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_30);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_31);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_32);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_33);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_34);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_35);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_36);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_37);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_38);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_39);
  tcase_add_test(tcase_sprintf, sprintf_spec_p_flags_40);

  tcase_add_test(tcase_sprintf, sprintf_spec_n_1);
  tcase_add_test(tcase_sprintf, sprintf_spec_n_2);
  tcase_add_test(tcase_sprintf, sprintf_spec_n_3);
  tcase_add_test(tcase_sprintf, sprintf_spec_n_4);
  tcase_add_test(tcase_sprintf, sprintf_spec_n_5);
  tcase_add_test(tcase_sprintf, sprintf_spec_n_6);

  tcase_add_test(tcase_sprintf, sprintf_mixed_format_1);

  suite_add_tcase(suite, tcase_sprintf);

  return suite;
}
