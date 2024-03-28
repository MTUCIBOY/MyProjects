#ifndef S21MATRIX_H
#define S21MATRIX_H

#include <math.h>

#include <exception>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  friend S21Matrix operator*(const double num, const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);
  double operator()(int i, int j) const;

  int Getrow();
  int Getcol();
  void Setrow(int row);
  void Setcol(int col);

  void RandMatrix();
  void Print();
  S21Matrix Minor(const int row, const int col);
};

void destroy(const int row, double** matrixptr);
double** initMatrix(const int rows, const int cols);
double** fillMatrix(const int rows, const int cols, double** matrixptr);
double** fillMatrix(const int rows, const int cols, double** matrixptr,
                    double** otherMatrix);

#endif  // S21MATRIX_H