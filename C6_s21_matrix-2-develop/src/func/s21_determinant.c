#include "../s21_matrix.h"

static double s21_calc_det(matrix_t *A) {
  if (A->rows == 1) /* matrix 1 x 1 */
    return A->matrix[0][0];
  else {
    double result = 0;
    matrix_t M;

    for (int j = 0; j < A->columns; j++) {
      s21_matrix_minor(0, j, A, &M);
      result += pow(-1, j) * A->matrix[0][j] * s21_calc_det(&M);
      s21_remove_matrix(&M);
    }

    return result;
  }
}

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_bad_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  *result = s21_calc_det(A);

  return 0;
}
