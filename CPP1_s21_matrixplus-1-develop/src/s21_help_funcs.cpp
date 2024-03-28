#include "s21_matrix_oop.h"

void destroy(const int row, double **matrixptr) {
  for (int i = 0; i < row; i++) delete[] matrixptr[i];
  delete[] matrixptr;
}

double **initMatrix(const int rows, const int cols) {
  double **matrix_ = new double *[rows];
  for (int i = 0; i < rows; i++) matrix_[i] = new double[cols];
  return matrix_;
}

double **fillMatrix(const int rows, const int cols, double **matrixptr) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) matrixptr[i][j] = 0.0;
  }
  return matrixptr;
}

double **fillMatrix(const int rows, const int cols, double **matrixptr,
                    double **otherMatrix) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) matrixptr[i][j] = otherMatrix[i][j];
  }
  return matrixptr;
}