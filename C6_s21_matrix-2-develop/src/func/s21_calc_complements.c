#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_is_bad_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  matrix_t matrix_minor;
  double det = 0;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_matrix_minor(i, j, A, &matrix_minor);
      s21_determinant(&matrix_minor, &det);
      result->matrix[i][j] = pow(-1, i + j) * det;
      s21_remove_matrix(&matrix_minor);
    }
  }

  return 0;
}
