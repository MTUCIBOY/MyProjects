#include "../s21_matrix.h"

matrix_t s21_rand_matrix(int seed, int rows, int columns, int full_rand) {
  srand(time(NULL) + seed);

  matrix_t result;
  if (full_rand) {
    result.rows = rand() % 10 + 1;
    result.columns = rand() % 10 + 1;
  } else {
    result.rows = rows;
    result.columns = columns;
  }
  s21_create_matrix(result.rows, result.columns, &result);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++)
      result.matrix[i][j] = (double)(rand()) / RAND_MAX * 100;
    // result.matrix[i][j] = rand() % 100;
  }

  return result;
}

// void s21_print_matrix(matrix_t A) {
//   printf("MATRIX %d x %d:\n", A.rows, A.columns);
//   for (int i = 0; i < A.rows; i++) {
//     for (int j = 0; j < A.columns; j++) printf("%lf ", A.matrix[i][j]);
//     printf("\n");
//   }
//   printf("\n");
// }

int s21_matrix_minor(int row, int column, matrix_t *A, matrix_t *result) {
  if (A->rows == 1 && A->columns == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1;
    result->rows = 1;
    result->columns = 1;
    return 0;
  }
  s21_create_matrix(A->rows - 1, A->columns - 1, result);

  int res_i = -1, res_j = -1;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    res_i++;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      res_j++;
      result->matrix[res_i][res_j] = A->matrix[i][j];
    }
    res_j = -1;
  }

  return 0;
}

int s21_is_bad_matrix(matrix_t *A) {
  if (A == NULL || A->rows < 1 || A->columns < 1 || A->matrix == NULL) return 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) return 1;
    }
  }

  return 0;
}
