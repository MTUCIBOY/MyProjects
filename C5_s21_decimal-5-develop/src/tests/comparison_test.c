#include "test.h"

START_TEST(s21_is_equal_pos_pos) {
  s21_decimal var = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_equal_neg_neg) {
  s21_decimal var = {{50, 50, 50, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_equal_er_pos_neg) {
  s21_decimal var = {{50, 50, 50, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_equal_er) {
  s21_decimal var = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 30, 50, 0}};
  int ret = s21_is_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_not_equal_pos_pos_er) {
  s21_decimal var = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_not_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_not_equal_neg_neg_er) {
  s21_decimal var = {{50, 50, 50, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_not_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_not_equal_pos_neg) {
  s21_decimal var = {{50, 50, 50, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_not_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_not_equal_pos_pos) {
  s21_decimal var = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 30, 50, 0}};
  int ret = s21_is_not_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_equal) {
  s21_decimal var = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_less_pos_neg) {
  s21_decimal var = {{50, 20, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_less_neg_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_pos_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  s21_decimal var2 = {{50, 700, 660, 0}};
  var2.bits[3] = 1 << 16;
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_pos_pos_er) {
  s21_decimal var = {{50, 20, 50, 0}};
  s21_decimal var2 = {{50, 700, 0, 0}};
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_less_neg_neg) {
  s21_decimal var = {{50, 70, 50, 0}};
  var.bits[3] = 1 << 31;
  var.bits[3] |= 2 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  var2.bits[3] |= 5 << 16;
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_neg_neg_er) {
  s21_decimal var = {{50, 70, 5, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{30, 888, 666, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_less(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_eq) {
  s21_decimal var = {{500, 700, 50, 0}};
  var.bits[3] = 2 << 16;
  s21_decimal var2 = {{50, 70, 5, 0}};
  var2.bits[3] = 1 << 16;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_pos_neg) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 2 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 7 << 16;
  var2.bits[3] |= 1 << 31;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_neg_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 1 << 31;
  var.bits[3] |= 2 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 7 << 16;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_pos_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 5 << 16;
  s21_decimal var2 = {{50, 700, 660, 0}};
  var2.bits[3] = 1 << 16;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_pos_pos_er) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 5 << 16;
  s21_decimal var2 = {{50, 700, 660, 0}};
  var2.bits[3] = 10 << 16;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_less_or_equal_neg_neg) {
  s21_decimal var = {{50, 70, 50, 0}};
  var.bits[3] = 1 << 31;
  var.bits[3] |= 3 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  var2.bits[3] |= 5 << 16;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_neg_neg_er) {
  s21_decimal var = {{50, 70, 5, 0}};
  var.bits[3] = 3 << 16;
  var.bits[3] |= 1 << 31;
  s21_decimal var2 = {{30, 888, 666, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_less_or_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_eq) {
  s21_decimal var = {{50, 50, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_pos_neg) {
  s21_decimal var = {{50, 20, 50, 0}};
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_neg_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_pos_pos) {
  s21_decimal var = {{50, 20, 7000, 0}};
  s21_decimal var2 = {{50, 700, 660, 0}};
  var2.bits[3] = 1 << 16;
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_pos_pos_er) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 5 << 16;
  s21_decimal var2 = {{50, 700, 333, 0}};
  var2.bits[3] = 3 << 16;
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_neg_neg) {
  s21_decimal var = {{50, 70, 0, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_neg_neg_er) {
  s21_decimal var = {{50, 70, 5, 0}};
  var.bits[3] = 1 << 31;
  s21_decimal var2 = {{30, 888, 0, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_greater(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_eq) {
  s21_decimal var = {{500, 700, 50, 0}};
  var.bits[3] = 3 << 16;
  s21_decimal var2 = {{50, 70, 5, 0}};
  var2.bits[3] = 3 << 16;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_pos_neg) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 2 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 7 << 16;
  var2.bits[3] |= 1 << 31;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_neg_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 2 << 16;
  var.bits[3] |= 1 << 31;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 7 << 16;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_pos_pos) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 5 << 16;
  s21_decimal var2 = {{50, 700, 660, 0}};
  var2.bits[3] = 10 << 16;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_pos_pos_er) {
  s21_decimal var = {{50, 20, 50, 0}};
  var.bits[3] = 5 << 16;
  s21_decimal var2 = {{50, 7, 6, 0}};
  var2.bits[3] = 1 << 16;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_neg_neg) {
  s21_decimal var = {{50, 70, 5, 0}};
  var.bits[3] = 3 << 16;
  var.bits[3] |= 1 << 31;
  s21_decimal var2 = {{30, 888, 666, 0}};
  var2.bits[3] = 1 << 31;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_neg_neg_er) {
  s21_decimal var = {{50, 70, 50, 0}};
  var.bits[3] = 1 << 31;
  var.bits[3] |= 1 << 16;
  s21_decimal var2 = {{50, 50, 50, 0}};
  var2.bits[3] = 1 << 31;
  var2.bits[3] |= 5 << 16;
  int ret = s21_is_greater_or_equal(var, var2);
  ck_assert_int_eq(ret, 0);
}
END_TEST

Suite *comparison_suite(void) {
  Suite *s;
  TCase *tc_comparison;

  s = suite_create("Comparison");

  tc_comparison = tcase_create("is equal");

  // s21_is_equal
  tcase_add_test(tc_comparison, s21_is_equal_pos_pos);
  tcase_add_test(tc_comparison, s21_is_equal_neg_neg);
  tcase_add_test(tc_comparison, s21_is_equal_er_pos_neg);
  tcase_add_test(tc_comparison, s21_is_equal_er);
  // s21_is_not_equal
  tcase_add_test(tc_comparison, s21_is_not_equal_pos_pos_er);
  tcase_add_test(tc_comparison, s21_is_not_equal_neg_neg_er);
  tcase_add_test(tc_comparison, s21_is_not_equal_pos_neg);
  tcase_add_test(tc_comparison, s21_is_not_equal_pos_pos);
  // s21_is_less
  tcase_add_test(tc_comparison, s21_is_less_equal);
  tcase_add_test(tc_comparison, s21_is_less_pos_neg);
  tcase_add_test(tc_comparison, s21_is_less_neg_pos);
  tcase_add_test(tc_comparison, s21_is_less_pos_pos);
  tcase_add_test(tc_comparison, s21_is_less_pos_pos_er);
  tcase_add_test(tc_comparison, s21_is_less_neg_neg);
  tcase_add_test(tc_comparison, s21_is_less_neg_neg_er);
  // s21_is_less_or_equal
  tcase_add_test(tc_comparison, s21_is_less_or_equal_eq);
  tcase_add_test(tc_comparison, s21_is_less_or_equal_pos_neg);
  tcase_add_test(tc_comparison, s21_is_less_or_equal_neg_pos);
  tcase_add_test(tc_comparison, s21_is_less_or_equal_pos_pos);
  tcase_add_test(tc_comparison, s21_is_less_or_equal_pos_pos_er);
  tcase_add_test(tc_comparison, s21_is_less_or_equal_neg_neg);
  tcase_add_test(tc_comparison, s21_is_less_or_equal_neg_neg_er);
  // s21_is_greater
  tcase_add_test(tc_comparison, s21_is_greater_eq);
  tcase_add_test(tc_comparison, s21_is_greater_pos_neg);
  tcase_add_test(tc_comparison, s21_is_greater_neg_pos);
  tcase_add_test(tc_comparison, s21_is_greater_pos_pos);
  tcase_add_test(tc_comparison, s21_is_greater_pos_pos_er);
  tcase_add_test(tc_comparison, s21_is_greater_neg_neg);
  tcase_add_test(tc_comparison, s21_is_greater_neg_neg_er);
  // s21_is_greater_or_equal
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_eq);
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_pos_neg);
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_neg_pos);
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_pos_pos);
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_pos_pos_er);
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_neg_neg);
  tcase_add_test(tc_comparison, s21_is_greater_or_equal_neg_neg_er);

  suite_add_tcase(s, tc_comparison);

  return s;
}
