#include <check.h>

#include "../Back/main.h"

START_TEST(lexeme_plus) {
  bool code;

  double expression = 1 + 2;
  char *test = "1 + 2";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_minus) {
  bool code;

  double expression = 1 - 2;
  char *test = "1 - 2";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_multi) {
  bool code;

  double expression = 3 * 3;
  char *test = "3 * 3";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_div) {
  bool code;

  double expression = 10.0 / 3.0;
  char *test = "10.0 / 3.0";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_div_zero) {
  bool code;

  double expression = 10.0 / 0.0;
  char *test = "10.0 / 0.0";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_degree) {
  bool code;

  double expression = pow(3, 1.5);
  char *test = "3 ^ 1.5";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_cos) {
  bool code;

  double expression = cos(1);
  char *test = "cos ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_sin) {
  bool code;

  double expression = sin(1);
  char *test = "sin ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_tan) {
  bool code;

  double expression = tan(1);
  char *test = "tan ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_acos) {
  bool code;

  double expression = acos(1);
  char *test = "acos ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_asin) {
  bool code;

  double expression = asin(1);
  char *test = "asin ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_atan) {
  bool code;

  double expression = atan(1);
  char *test = "atan ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_sqrt) {
  bool code;

  double expression = sqrt(1);
  char *test = "sqrt ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_ln) {
  bool code;

  double expression = log(1);
  char *test = "ln ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_log) {
  bool code;

  double expression = log10(1);
  char *test = "log ( 1 )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(lexeme_func_mod) {
  bool code;

  double expression = fmod(10.5, 6);
  char *test = "10.5 mod 6";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_1) {
  bool code;

  double expression = 1 + 2 - 3;
  char *test = "1 + 2 - 3";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_2) {
  bool code;

  double expression = 10 * 2 - 3;
  char *test = "10 * 2 - 3";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_3) {
  bool code;

  double expression = 10 + 2 * 3;
  char *test = "10 + 2 * 3";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_4) {
  bool code;

  double expression = (10 + 2) * 3;
  char *test = "( 10 + 2 ) * 3";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_5) {
  bool code;

  double expression = ((10 + 2) * 3) + 4;
  char *test = "( ( 10 + 2 ) * 3 ) + 4";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_6) {
  bool code;

  double expression = ((-10 + 2) * 3) - pow(4, cos(3.14));
  char *test = "( ( - 10 + 2 ) * 3 ) - ( 4 ^ cos ( 3.14 ) )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(priority_7) {
  bool code;

  double expression = cos(sin(log(2.71)));
  char *test = "cos ( sin ( ln ( 2.71 ) ) )";

  ck_assert_double_eq(expression, calc(test, &code));
}
END_TEST

START_TEST(Errors) {
  bool code;

  char *test_1 = "+";
  char *test_2 = "12 +";
  char *test_3 = "( 12 + 4";
  char *test_4 = "12 + - 4";
  char *test_5 = "cos";
  char *test_6 = "cos ( )";
  // char *test_7 = "0..3";
  char *test_8 = " )";
  char *test_9 = ".";
  char *test_10 = "x";
  char *test_11 = "x + 3";

  calc(test_1, &code);
  ck_assert_int_eq(1, code);
  calc(test_2, &code);
  ck_assert_int_eq(1, code);
  calc(test_3, &code);
  ck_assert_int_eq(1, code);
  calc(test_4, &code);
  ck_assert_int_eq(1, code);
  calc(test_5, &code);
  ck_assert_int_eq(1, code);
  calc(test_6, &code);
  ck_assert_int_eq(1, code);
  calc(test_8, &code);
  ck_assert_int_eq(1, code);
  calc(test_9, &code);
  ck_assert_int_eq(1, code);
  calc(test_10, &code);
  ck_assert_int_eq(1, code);
  calc(test_11, &code);
  ck_assert_int_eq(1, code);
}
END_TEST

int main() {
  Suite *suite = suite_create("Unit");
  TCase *tcase = tcase_create("Tests");
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);

  tcase_add_test(tcase, lexeme_plus);
  tcase_add_test(tcase, lexeme_minus);
  tcase_add_test(tcase, lexeme_div);
  tcase_add_test(tcase, lexeme_div_zero);
  tcase_add_test(tcase, lexeme_multi);
  tcase_add_test(tcase, lexeme_degree);
  tcase_add_test(tcase, lexeme_func_cos);
  tcase_add_test(tcase, lexeme_func_sin);
  tcase_add_test(tcase, lexeme_func_tan);
  tcase_add_test(tcase, lexeme_func_acos);
  tcase_add_test(tcase, lexeme_func_asin);
  tcase_add_test(tcase, lexeme_func_atan);
  tcase_add_test(tcase, lexeme_func_ln);
  tcase_add_test(tcase, lexeme_func_log);
  tcase_add_test(tcase, lexeme_func_sqrt);
  tcase_add_test(tcase, lexeme_func_mod);
  tcase_add_test(tcase, priority_1);
  tcase_add_test(tcase, priority_2);
  tcase_add_test(tcase, priority_3);
  tcase_add_test(tcase, priority_4);
  tcase_add_test(tcase, priority_5);
  tcase_add_test(tcase, priority_6);
  tcase_add_test(tcase, priority_7);
  tcase_add_test(tcase, Errors);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? 0 : 1;
}
