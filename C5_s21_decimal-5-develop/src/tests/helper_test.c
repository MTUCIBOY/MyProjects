#include <check.h>
#include <limits.h>
#include <sys/types.h>

#include "test.h"

START_TEST(s21_add_exp_decimal_test_1) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, 1);
  ck_assert_uint_eq(src.bits[3], 1 << 16);
}
END_TEST

START_TEST(s21_add_exp_decimal_test_2) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, 10);
  ck_assert_uint_eq(src.bits[3], 10 << 16);
}
END_TEST

START_TEST(s21_add_exp_decimal_test_3) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, 2);
  s21_change_sign_decimal(&src, 1);
  uint n = (2 << 16) + (1 << 31);
  ck_assert_uint_eq(src.bits[3], n);
}
END_TEST

START_TEST(s21_calc_exp_decimal_test_1) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_uint_eq(s21_calc_exp_decimal(src), 0);
}
END_TEST

START_TEST(s21_calc_exp_decimal_test_2) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_change_sign_decimal(&src, 1);
  ck_assert_uint_eq(s21_calc_exp_decimal(src), 0);
}
END_TEST

START_TEST(s21_calc_exp_decimal_test_3) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, 3);
  ck_assert_uint_eq(s21_calc_exp_decimal(src), 3);
}
END_TEST

START_TEST(s21_calc_exp_decimal_test_4) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, -1);
  ck_assert_uint_eq(s21_calc_exp_decimal(src), 0);
}
END_TEST

START_TEST(s21_calc_exp_decimal_test_5) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, 60);
  ck_assert_uint_eq(s21_calc_exp_decimal(src), 56);
}
END_TEST

START_TEST(s21_change_sign_decimal_test_1) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_change_sign_decimal(&src, 0);
  ck_assert_uint_eq(src.bits[3] >> 31, 0);
}
END_TEST

START_TEST(s21_change_sign_decimal_test_2) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_change_sign_decimal(&src, 1);
  ck_assert_uint_eq(src.bits[3] >> 31, 1);
}
END_TEST

START_TEST(s21_change_sign_decimal_test_3) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_change_sign_decimal(&src, 1);
  s21_change_sign_decimal(&src, 1);
  ck_assert_uint_eq(src.bits[3] >> 31, 1);
}
END_TEST

START_TEST(s21_change_sign_decimal_test_4) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_change_sign_decimal(&src, 0);
  s21_change_sign_decimal(&src, 0);
  ck_assert_uint_eq(src.bits[3] >> 31, 0);
}
END_TEST

START_TEST(s21_change_sign_decimal_test_5) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_change_sign_decimal(&src, 1);
  s21_change_sign_decimal(&src, 0);
  ck_assert_uint_eq(src.bits[3] >> 31, 0);
}
END_TEST

START_TEST(s21_clear_decimal_test_1) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_clear_decimal(&src);
  ck_assert_uint_eq(src.bits[0], 0);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}
END_TEST

START_TEST(s21_clear_decimal_test_2) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_clear_decimal(&src);
  ck_assert_uint_eq(src.bits[0], 0);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}
END_TEST

START_TEST(s21_clear_decimal_test_3) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_add_exp_decimal(&src, 23);
  s21_change_sign_decimal(&src, 1);
  s21_clear_decimal(&src);
  ck_assert_uint_eq(src.bits[0], 0);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}
END_TEST

START_TEST(s21_div_5_test) {
  s21_decimal src = {{10, 0, 0, 0}};
  s21_div_5(src, &src);
  ck_assert_uint_eq(src.bits[0], 2);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}
END_TEST

START_TEST(s21_div_5_full_test) {
  s21_decimal src = {{105, 0, 0, 0}};
  s21_add_exp_decimal(&src, 1);
  s21_change_sign_decimal(&src, 1);
  s21_div_5_full(src, &src);
  uint n = (1 << 16) + (1 << 31);
  ck_assert_uint_eq(src.bits[0], 21);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], n);
}
END_TEST

START_TEST(s21_exp_equaler_test_1) {
  s21_decimal val1 = {{105, 0, 0, 0}};
  s21_decimal val2 = {{5, 0, 0, 0}};
  s21_add_exp_decimal(&val1, 1);
  s21_add_exp_decimal(&val2, 0);
  s21_change_sign_decimal(&val1, 1);
  s21_change_sign_decimal(&val2, 1);
  s21_exp_equaler(&val1, &val2, 0);
  uint n = (1 << 16) + (1 << 31);
  ck_assert_uint_eq(val1.bits[0], 105);
  ck_assert_uint_eq(val1.bits[1], 0);
  ck_assert_uint_eq(val1.bits[2], 0);
  ck_assert_uint_eq(val1.bits[3], n);
  ck_assert_uint_eq(val2.bits[0], 50);
  ck_assert_uint_eq(val2.bits[1], 0);
  ck_assert_uint_eq(val2.bits[2], 0);
  ck_assert_uint_eq(val2.bits[3], n);
}
END_TEST

START_TEST(s21_exp_equaler_test_2) {
  s21_decimal val1 = {{0, 0, UINT_MAX, 0}};
  s21_decimal val2 = {{10, 0, 0, 0}};
  s21_add_exp_decimal(&val1, 1);
  s21_add_exp_decimal(&val2, 0);
  s21_change_sign_decimal(&val1, 1);
  s21_change_sign_decimal(&val2, 1);
  s21_exp_equaler(&val1, &val2, 1);
  uint n = (1 << 16) + (1 << 31);
  ck_assert_uint_eq(val1.bits[0], 0);
  ck_assert_uint_eq(val1.bits[1], 0);
  ck_assert_uint_eq(val1.bits[2], UINT_MAX);
  ck_assert_uint_eq(val1.bits[3], n);
  ck_assert_uint_eq(val2.bits[0], 100);
  ck_assert_uint_eq(val2.bits[1], 0);
  ck_assert_uint_eq(val2.bits[2], 0);
  ck_assert_uint_eq(val2.bits[3], n);
}
END_TEST

START_TEST(s21_exp_equaler_test_3) {
  s21_decimal val1 = {{0, UINT_MAX, 0, 0}};
  s21_decimal val2 = {{0, 0, UINT_MAX, 0}};
  s21_add_exp_decimal(&val1, 3);
  s21_add_exp_decimal(&val2, 2);
  s21_change_sign_decimal(&val1, 1);
  s21_change_sign_decimal(&val2, 1);
  s21_exp_equaler(&val1, &val2, 1);
  uint n = (2 << 16) + (1 << 31);
  ck_assert_uint_eq(val1.bits[0], 2147483648);
  ck_assert_uint_eq(val1.bits[1], 429496729);
  ck_assert_uint_eq(val1.bits[2], 0);
  ck_assert_uint_eq(val1.bits[3], n);
  ck_assert_uint_eq(val2.bits[0], 0);
  ck_assert_uint_eq(val2.bits[1], 0);
  ck_assert_uint_eq(val2.bits[2], 4294967295);
  ck_assert_uint_eq(val2.bits[3], n);
}
END_TEST

START_TEST(s21_is_zero_test) {
  s21_decimal src = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_zero(src), 1);
}

START_TEST(s21_FBRS_test) {
  s21_decimal src = {{0, 1, 0, 0}};
  int k, i;
  s21_first_bit_right_side(src, &k, &i);
  ck_assert_int_eq(k, 1);
  ck_assert_int_eq(i, 0);
}

START_TEST(s21_left_decimal_test) {
  s21_decimal src = {{0, 1, 0, 0}};
  s21_left_decimal(&src, 1);
  ck_assert_uint_eq(src.bits[0], 0);
  ck_assert_uint_eq(src.bits[1], 2);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}

START_TEST(s21_right_decimal_test) {
  s21_decimal src = {{0, 1, 0, 0}};
  s21_right_decimal(&src, 1);
  uint n = 1 << 31;
  ck_assert_uint_eq(src.bits[0], n);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}

START_TEST(s21_mul_10_test) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_mul_10(src, &src);
  ck_assert_uint_eq(src.bits[0], 10);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}

START_TEST(s21_unloader_test) {
  s21_decimal src = {{1600, 0, 0, 0}};
  s21_add_exp_decimal(&src, 1);
  s21_unloader(&src);
  ck_assert_uint_eq(src.bits[0], 160);
  ck_assert_uint_eq(src.bits[1], 0);
  ck_assert_uint_eq(src.bits[2], 0);
  ck_assert_uint_eq(src.bits[3], 0);
}

Suite *helper_suite(void) {
  Suite *s;
  TCase *tc_helper;

  s = suite_create("Helper");

  tc_helper = tcase_create("is equal");

  // ---------- Helper functions ----------

  suite_add_tcase(s, tc_helper);
  tcase_add_test(tc_helper, s21_add_exp_decimal_test_1);
  tcase_add_test(tc_helper, s21_add_exp_decimal_test_2);
  tcase_add_test(tc_helper, s21_add_exp_decimal_test_3);
  tcase_add_test(tc_helper, s21_add_exp_decimal_test_3);
  tcase_add_test(tc_helper, s21_calc_exp_decimal_test_1);
  tcase_add_test(tc_helper, s21_calc_exp_decimal_test_2);
  tcase_add_test(tc_helper, s21_calc_exp_decimal_test_3);
  tcase_add_test(tc_helper, s21_calc_exp_decimal_test_4);
  tcase_add_test(tc_helper, s21_calc_exp_decimal_test_5);
  tcase_add_test(tc_helper, s21_change_sign_decimal_test_1);
  tcase_add_test(tc_helper, s21_change_sign_decimal_test_2);
  tcase_add_test(tc_helper, s21_change_sign_decimal_test_3);
  tcase_add_test(tc_helper, s21_change_sign_decimal_test_4);
  tcase_add_test(tc_helper, s21_change_sign_decimal_test_5);
  tcase_add_test(tc_helper, s21_clear_decimal_test_1);
  tcase_add_test(tc_helper, s21_clear_decimal_test_2);
  tcase_add_test(tc_helper, s21_clear_decimal_test_3);
  tcase_add_test(tc_helper, s21_div_5_test);
  tcase_add_test(tc_helper, s21_div_5_full_test);
  tcase_add_test(tc_helper, s21_exp_equaler_test_1);
  tcase_add_test(tc_helper, s21_exp_equaler_test_2);
  tcase_add_test(tc_helper, s21_exp_equaler_test_3);
  tcase_add_test(tc_helper, s21_is_zero_test);
  tcase_add_test(tc_helper, s21_FBRS_test);
  tcase_add_test(tc_helper, s21_left_decimal_test);
  tcase_add_test(tc_helper, s21_right_decimal_test);
  tcase_add_test(tc_helper, s21_mul_10_test);
  tcase_add_test(tc_helper, s21_unloader_test);

  return s;
}
