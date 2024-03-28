#ifndef S21_MATRIX
#define S21_MATRIX

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum { INCORRECT_MATRIX = 1, CALCULATION_ERROR = 2 };

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

matrix_t s21_rand_matrix(int seed, int rows, int columns, int full_rand);
void s21_print_matrix(matrix_t A);
int s21_matrix_minor(int row, int column, matrix_t *A, matrix_t *result);
int s21_is_bad_matrix(matrix_t *A);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX
