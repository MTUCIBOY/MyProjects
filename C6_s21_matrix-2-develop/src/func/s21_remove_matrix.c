#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  free(A->matrix);
  A->rows = 0;
  A->columns = 0;
}
