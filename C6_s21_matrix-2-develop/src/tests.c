#include <check.h>

#include "s21_matrix.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"
#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define FAIL 1

START_TEST(create_matrix) {
  ck_assert_int_eq(s21_create_matrix(2, 2, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(2, 2, (void *)0), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(0, 2, (void *)0), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_create_matrix(2, 0, (void *)0), INCORRECT_MATRIX);
  matrix_t result = {0};
  int rows = 2, columns = 10;
  int exit_code = s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(0, exit_code);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      ck_assert_double_eq(result.matrix[i][j], 0);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, (void *)0), INCORRECT_MATRIX);
  int answer = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_01) {
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix) {
  matrix_t A = {0}, B = {0}, result = {0};
  int Arows = 5, Acolumns = 5;
  int Brows = 4, Bcolumns = 5;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, (void *)0), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_01) {
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] - B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_mult_number(&A, 5., (void *)0), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_number(&A, 5., NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_01) {
  matrix_t A = {0}, result = {0};
  int rows = 5, columns = 5;
  double number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j],
                              1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix) {
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_mult_matrix((void *)0, NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_01) {
  matrix_t A = {0}, B = {0}, result = {0};
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_02) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 1, &B);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  B.matrix[0][0] = 2.;
  B.matrix[1][0] = 1.;
  B.matrix[2][0] = 2.;
  int answer = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose) {
  ck_assert_int_eq(s21_transpose(NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_transpose((void *)0, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_01) {
  matrix_t A = {0}, result = {0};
  int rows = 3, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_02) {
  matrix_t A = {0}, result = {0}, result_tmp = {0};
  int rows = 3, columns = 2;
  int sum = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(columns, rows, &result_tmp);
  result_tmp.matrix[0][0] = 1;
  result_tmp.matrix[0][1] = 2;
  result_tmp.matrix[0][2] = 3;
  result_tmp.matrix[1][0] = 4;
  result_tmp.matrix[1][1] = 5;
  result_tmp.matrix[1][2] = 6;
  s21_transpose(&A, &result);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      if (fabs(result_tmp.matrix[i][j] - result.matrix[i][j]) > 1e-8) {
        sum++;
      }
    }
  }
  ck_assert_int_eq(sum, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_tmp);
}
END_TEST

START_TEST(calc_complements) {
  matrix_t A = {0}, result = {0};
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j / 3.3;
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_calc_complements(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_calc_complements((void *)0, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_01) {
  matrix_t A = {0}, result = {0}, result_true = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  result_true.matrix[0][0] = 0;
  result_true.matrix[0][1] = 10;
  result_true.matrix[0][2] = -20;
  result_true.matrix[1][0] = 4;
  result_true.matrix[1][1] = -14;
  result_true.matrix[1][2] = 8;
  result_true.matrix[2][0] = -8;
  result_true.matrix[2][1] = -2;
  result_true.matrix[2][2] = 4;
  s21_calc_complements(&A, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &result_true), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(determinant) {
  matrix_t A = {0};
  double result = 0.;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_determinant((void *)0, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_01) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  double result = 0;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_02) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  double result = 0;
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  A.matrix[0][2] = 3.;
  A.matrix[1][0] = 4.;
  A.matrix[1][1] = 5.;
  A.matrix[1][2] = 6.;
  A.matrix[2][0] = 7.;
  A.matrix[2][1] = 8.;
  A.matrix[2][2] = 9.;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0.);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix) {
  matrix_t A = {0}, result = {0}, result_true = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  result_true.matrix[0][0] = 1;
  result_true.matrix[0][1] = -1;
  result_true.matrix[0][2] = 1;
  result_true.matrix[1][0] = -38;
  result_true.matrix[1][1] = 41;
  result_true.matrix[1][2] = -34;
  result_true.matrix[2][0] = 27;
  result_true.matrix[2][1] = -29;
  result_true.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix((void *)0, (void *)0), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &result_true), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_01) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 6;
  A.matrix[0][2] = 9;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  matrix_t res;
  int return_value = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(return_value, OK);
  matrix_t C;
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -6;
  C.matrix[0][2] = 27;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 1;
  C.matrix[1][2] = -6;
  C.matrix[2][0] = 0;
  C.matrix[2][1] = 0.0;
  C.matrix[2][2] = 1;
  if (return_value == OK) return_value = s21_eq_matrix(&res, &C);
  ck_assert_int_eq(return_value, SUCCESS);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(com_1) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 12.36;
  true_res.matrix[1][0] = -9;
  true_res.matrix[2][0] = -6.76;
  true_res.matrix[0][1] = 4.12;
  true_res.matrix[1][1] = -3;
  true_res.matrix[2][1] = -16.12;
  true_res.matrix[0][2] = 7;
  true_res.matrix[1][2] = 5;
  true_res.matrix[2][2] = 13;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(com_2) {
  int rows = 5, columns = 5;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = -8;
  A.matrix[1][3] = 9;
  A.matrix[1][4] = 10;
  A.matrix[2][0] = -11;
  A.matrix[2][1] = 12;
  A.matrix[2][2] = 13;
  A.matrix[2][3] = 14;
  A.matrix[2][4] = 15;
  A.matrix[3][0] = 16;
  A.matrix[3][1] = 17;
  A.matrix[3][2] = 18;
  A.matrix[3][3] = 19;
  A.matrix[3][4] = -20;
  A.matrix[4][0] = 21;
  A.matrix[4][1] = -22;
  A.matrix[4][2] = 3;
  A.matrix[4][3] = 4;
  A.matrix[4][4] = 5;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 234560;
  true_res.matrix[1][0] = -9600;
  true_res.matrix[2][0] = -62400;
  true_res.matrix[3][0] = 3840;
  true_res.matrix[4][0] = -12800;
  true_res.matrix[0][1] = 222800;
  true_res.matrix[1][1] = -8000;
  true_res.matrix[2][1] = -52000;
  true_res.matrix[3][1] = 3200;
  true_res.matrix[4][1] = -38000;
  true_res.matrix[0][2] = 181760;
  true_res.matrix[1][2] = -47600;
  true_res.matrix[2][2] = -22400;
  true_res.matrix[3][2] = 2640;
  true_res.matrix[4][2] = -8800;
  true_res.matrix[0][3] = -374000;
  true_res.matrix[1][3] = 52000;
  true_res.matrix[2][3] = 92000;
  true_res.matrix[3][3] = 12000;
  true_res.matrix[4][3] = 42000;
  true_res.matrix[0][4] = 185312;
  true_res.matrix[1][4] = -7920;
  true_res.matrix[2][4] = -26880;
  true_res.matrix[3][4] = -13232;
  true_res.matrix[4][4] = -10560;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(com_3) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = -3;
  true_res.matrix[1][0] = 6;
  true_res.matrix[2][0] = -3;
  true_res.matrix[0][1] = 6;
  true_res.matrix[1][1] = -12;
  true_res.matrix[2][1] = 6;
  true_res.matrix[0][2] = -3;
  true_res.matrix[1][2] = 6;
  true_res.matrix[2][2] = -3;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(com_4) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 0;
  true_res.matrix[1][0] = 0;
  true_res.matrix[2][0] = 0;
  true_res.matrix[0][1] = 0;
  true_res.matrix[1][1] = 0;
  true_res.matrix[2][1] = 0;
  true_res.matrix[0][2] = 0;
  true_res.matrix[1][2] = 0;
  true_res.matrix[2][2] = 0;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(com_5) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 0;
  true_res.matrix[1][0] = 0;
  true_res.matrix[2][0] = 0;
  true_res.matrix[0][1] = 0;
  true_res.matrix[1][1] = 0;
  true_res.matrix[2][1] = 0;
  true_res.matrix[0][2] = 0;
  true_res.matrix[1][2] = 0;
  true_res.matrix[2][2] = 0;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
  END_TEST
}

START_TEST(com_6) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -10;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 4;
  matrix_t result = {0};
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 4;
  true_res.matrix[1][0] = 10;
  true_res.matrix[0][1] = -6;
  true_res.matrix[1][1] = 1;
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(com_7) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 89.324892;
  matrix_t result = {0};
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 1;
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(com_8) {
  int rows = 2, columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 6;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(com_9) {
  int rows = 1, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 6;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(com_10) {
  matrix_t A = {0};
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(com_11) {
  matrix_t result = {0};
  int res = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(com_12) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = 1.0 / 0.0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(com_13) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = -1.0 / 0.0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(com_14) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = 0.0 / 0.0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inv_1) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 12.36 / 41.6;
  true_res.matrix[0][1] = -9 / 41.6;
  true_res.matrix[0][2] = -6.76 / 41.6;
  true_res.matrix[1][0] = 4.12 / 41.6;
  true_res.matrix[1][1] = -3 / 41.6;
  true_res.matrix[1][2] = -16.12 / 41.6;
  true_res.matrix[2][0] = 7 / 41.6;
  true_res.matrix[2][1] = 5 / 41.6;
  true_res.matrix[2][2] = 13 / 41.6;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(inv_2) {
  int rows = 5, columns = 5;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = -8;
  A.matrix[1][3] = 9;
  A.matrix[1][4] = 10;
  A.matrix[2][0] = -11;
  A.matrix[2][1] = 12;
  A.matrix[2][2] = 13;
  A.matrix[2][3] = 14;
  A.matrix[2][4] = 15;
  A.matrix[3][0] = 16;
  A.matrix[3][1] = 17;
  A.matrix[3][2] = 18;
  A.matrix[3][3] = 19;
  A.matrix[3][4] = -20;
  A.matrix[4][0] = 21;
  A.matrix[4][1] = -22;
  A.matrix[4][2] = 3;
  A.matrix[4][3] = 4;
  A.matrix[4][4] = 5;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 234560.0 / 656000;
  true_res.matrix[0][1] = -9600.0 / 656000;
  true_res.matrix[0][2] = -62400.0 / 656000;
  true_res.matrix[0][3] = 3840.0 / 656000;
  true_res.matrix[0][4] = -12800.0 / 656000;
  true_res.matrix[1][0] = 222800.0 / 656000;
  true_res.matrix[1][1] = -8000.0 / 656000;
  true_res.matrix[1][2] = -52000.0 / 656000;
  true_res.matrix[1][3] = 3200.0 / 656000;
  true_res.matrix[1][4] = -38000.0 / 656000;
  true_res.matrix[2][0] = 181760.0 / 656000;
  true_res.matrix[2][1] = -47600.0 / 656000;
  true_res.matrix[2][2] = -22400.0 / 656000;
  true_res.matrix[2][3] = 2640.0 / 656000;
  true_res.matrix[2][4] = -8800.0 / 656000;
  true_res.matrix[3][0] = -374000.0 / 656000;
  true_res.matrix[3][1] = 52000.0 / 656000;
  true_res.matrix[3][2] = 92000.0 / 656000;
  true_res.matrix[3][3] = 12000.0 / 656000;
  true_res.matrix[3][4] = 42000.0 / 656000;
  true_res.matrix[4][0] = 185312.0 / 656000;
  true_res.matrix[4][1] = -7920.0 / 656000;
  true_res.matrix[4][2] = -26880.0 / 656000;
  true_res.matrix[4][3] = -13232.0 / 656000;
  true_res.matrix[4][4] = -10560.0 / 656000;
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(inv_3) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inv_4) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inv_5) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 3;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inv_6) {
  int rows = 2, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -10;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 4;
  matrix_t result = {0};
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 0.0625;
  true_res.matrix[0][1] = 0.15625;
  true_res.matrix[1][0] = -0.09375;
  true_res.matrix[1][1] = 0.015625;
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(inv_7) {
  int rows = 1, columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 89.324892;
  matrix_t result = {0};
  matrix_t true_res = {0};
  s21_create_matrix(rows, columns, &true_res);
  true_res.matrix[0][0] = 1 / 89.324892;
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, OK);
  int eq = s21_eq_matrix(&result, &true_res);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_res);
}
END_TEST

START_TEST(inv_8) {
  int rows = 2, columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 6;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inv_9) {
  int rows = 1, columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 6;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inv_10) {
  matrix_t A = {0};
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(inv_11) {
  matrix_t result = {0};
  int res = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(inv_12) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = 1.0 / 0.0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, FAIL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inv_13) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = -1.0 / 0.0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, FAIL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inv_14) {
  int rows = 3, columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = -4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 4.12;
  A.matrix[2][0] = 0.0 / 0.0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 0;
  matrix_t result = {0};
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, FAIL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix) {
  matrix_t m = s21_rand_matrix(0, 5, 5, 1);
  matrix_t mtx = s21_rand_matrix(0, 5, 5, 1);
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq) {
  matrix_t m = s21_rand_matrix(0, 3, 4, 1);
  matrix_t mtx = s21_rand_matrix(1, 4, 3, 1);

  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq1) {
  matrix_t m = {0};
  s21_create_matrix(-3, -7, &m);
  matrix_t mtx = {0};
  s21_create_matrix(3, 7, &mtx);
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(zero_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
}

START_TEST(zero_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = -4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = -4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.00000000234;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(casual_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_inverse_1) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &m);

  m.matrix[0][0] = 1431.12312331;
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
  ck_assert_int_eq(code, OK);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_zero_det) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &m);
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_another) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 4, &m);
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_normal) {
  matrix_t m = {0};
  matrix_t expected = {0};
  s21_create_matrix(3, 3, &m);
  s21_create_matrix(3, 3, &expected);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;

  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;

  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;

  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;

  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(inverse) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

int main(void) {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, create_matrix);
  tcase_add_test(tcase, eq_matrix);
  tcase_add_test(tcase, sum_matrix);
  tcase_add_test(tcase, sum_matrix_01);
  tcase_add_test(tcase, sub_matrix);
  tcase_add_test(tcase, sub_matrix_01);
  tcase_add_test(tcase, mult_number);
  tcase_add_test(tcase, mult_number_01);
  tcase_add_test(tcase, mult_matrix);
  tcase_add_test(tcase, mult_matrix_01);
  tcase_add_test(tcase, mult_matrix_02);
  tcase_add_test(tcase, transpose);
  tcase_add_test(tcase, transpose_01);
  tcase_add_test(tcase, transpose_02);
  tcase_add_test(tcase, calc_complements);
  tcase_add_test(tcase, calc_complements_01);
  tcase_add_test(tcase, determinant);
  tcase_add_test(tcase, determinant_01);
  tcase_add_test(tcase, determinant_02);
  tcase_add_test(tcase, inverse_matrix);
  tcase_add_test(tcase, inverse_matrix_01);
  tcase_add_test(tcase, com_6);
  tcase_add_test(tcase, com_1);
  tcase_add_test(tcase, com_2);
  tcase_add_test(tcase, com_3);
  tcase_add_test(tcase, com_4);
  tcase_add_test(tcase, com_5);
  tcase_add_test(tcase, com_7);
  tcase_add_test(tcase, com_8);
  tcase_add_test(tcase, com_9);
  tcase_add_test(tcase, com_10);
  tcase_add_test(tcase, com_11);
  tcase_add_test(tcase, com_12);
  tcase_add_test(tcase, com_14);
  tcase_add_test(tcase, com_13);
  tcase_add_test(tcase, inv_1);
  tcase_add_test(tcase, inv_2);
  tcase_add_test(tcase, inv_3);
  tcase_add_test(tcase, inv_4);
  tcase_add_test(tcase, inv_5);
  tcase_add_test(tcase, inv_6);
  tcase_add_test(tcase, inv_7);
  tcase_add_test(tcase, inv_8);
  tcase_add_test(tcase, inv_9);
  tcase_add_test(tcase, inv_10);
  tcase_add_test(tcase, inv_11);
  tcase_add_test(tcase, inv_12);
  tcase_add_test(tcase, inv_13);
  tcase_add_test(tcase, inv_14);
  tcase_add_test(tcase, not_eq);
  tcase_add_test(tcase, not_eq1);
  tcase_add_test(tcase, zero_matrix);
  tcase_add_test(tcase, zero_matrix_1);
  tcase_add_test(tcase, casual_matrix_1);
  tcase_add_test(tcase, casual_matrix_2);
  tcase_add_test(tcase, casual_matrix_3);
  tcase_add_test(tcase, casual_matrix_4);
  tcase_add_test(tcase, casual_matrix_5);
  tcase_add_test(tcase, casual_matrix_6);
  tcase_add_test(tcase, casual_matrix_7);
  tcase_add_test(tcase, casual_matrix_8);
  tcase_add_test(tcase, determinant_another);
  tcase_add_test(tcase, s21_inverse_1);
  tcase_add_test(tcase, test_one_by_one);
  tcase_add_test(tcase, test_zero_det);
  tcase_add_test(tcase, test_incorrect);
  tcase_add_test(tcase, test_not_sqare);
  tcase_add_test(tcase, test_normal);
  tcase_add_test(tcase, inverse);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
