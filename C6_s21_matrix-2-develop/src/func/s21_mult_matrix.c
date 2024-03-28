#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_bad_matrix(A) || s21_is_bad_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, B->columns, result);
  for (int res_i = 0, res_j = 0; res_i < result->rows; res_i++) {
    /* Calc num */
    for (int j = 0; j < B->rows; j++)
      result->matrix[res_i][res_j] += A->matrix[res_i][j] * B->matrix[j][res_j];

    /* Next row or next column */
    if (res_j + 1 == result->columns)
      res_j = 0;
    else {
      res_j++;
      res_i--;
    }
  }

  return 0;
}
