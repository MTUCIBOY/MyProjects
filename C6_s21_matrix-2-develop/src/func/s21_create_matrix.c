#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1 || result == NULL) return INCORRECT_MATRIX;

  double **mas;
  mas = (double **)malloc(rows * sizeof(double *) +
                          rows * columns * sizeof(double));

  if (mas == NULL) return CALCULATION_ERROR;

  /* Init pointers in mas */
  mas[0] = (double *)(mas + rows);
  for (int i = 1; i < rows; i++) mas[i] = mas[0] + i * columns;

  /* Init mas */
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) mas[i][j] = 0.0;
  }

  /* Add in struct */
  result->matrix = mas;
  result->rows = rows;
  result->columns = columns;

  return 0;
}
