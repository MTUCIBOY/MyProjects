#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_is_bad_matrix(A)) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  double det_A;
  s21_determinant(A, &det_A);
  if (fabs(det_A) < 1e-7) return CALCULATION_ERROR;

  matrix_t alg_comp = {0}, T_alg_comp = {0};
  s21_calc_complements(A, &alg_comp);
  s21_transpose(&alg_comp, &T_alg_comp);
  s21_remove_matrix(&alg_comp);

  s21_mult_number(&T_alg_comp, (1.0 / det_A), result);
  s21_remove_matrix(&T_alg_comp);

  return 0;
}
