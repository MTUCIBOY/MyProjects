#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
  matrix_ = initMatrix(rows_, cols_);
  matrix_[0][0] = 0.0;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) throw std::exception();

  rows_ = rows;
  cols_ = cols;
  matrix_ = initMatrix(rows_, cols_);
  matrix_ = fillMatrix(rows_, cols_, matrix_);
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = initMatrix(rows_, cols_);
  matrix_ = fillMatrix(rows_, cols_, matrix_, other.matrix_);
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = new double *[1];
}

S21Matrix::~S21Matrix() { destroy(rows_, matrix_); }

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++)
      if (fabs(matrix_[i][k] - other.matrix_[i][k]) > 1e-7) return false;
  }

  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) throw std::exception();

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) matrix_[i][k] += other.matrix_[i][k];
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) throw std::exception();

  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) matrix_[i][k] -= other.matrix_[i][k];
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) matrix_[i][k] *= num;
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) throw std::exception();

  S21Matrix copy_matrix(*this);

  cols_ = other.cols_;
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_];
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }

  for (int res_i = 0, res_j = 0; res_i < rows_; res_i++) {
    /* Calc num */
    for (int j = 0; j < other.rows_; j++)
      matrix_[res_i][res_j] +=
          copy_matrix.matrix_[res_i][j] * other.matrix_[j][res_j];

    /* Next row or next column */
    if (res_j + 1 == cols_)
      res_j = 0;
    else {
      res_j++;
      res_i--;
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) result.matrix_[i][j] = matrix_[j][i];
  }

  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw std::exception();

  if (rows_ == 1)
    return matrix_[0][0];
  else {
    double result = 0;
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor_matrix(this->Minor(0, j));
      result += pow(-1, j) * matrix_[0][j] * minor_matrix.Determinant();
    }
    return result;
  }
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw std::exception();

  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor_matrix(this->Minor(i, j));
      result.matrix_[i][j] = pow(-1, i + j) * minor_matrix.Determinant();
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (fabs(det) < 1e-7) throw std::exception();
  if (rows_ == 1 && cols_ == 1) {
    S21Matrix result(1, 1);
    result(0, 0) = 1 / matrix_[0][0];
    return result;
  }

  S21Matrix calcComplMatrix(this->CalcComplements());
  S21Matrix T_calcComplMatrix(calcComplMatrix.Transpose());
  T_calcComplMatrix.MulNumber(1.0 / det);

  return T_calcComplMatrix;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  destroy(rows_, matrix_);
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = initMatrix(rows_, cols_);
  matrix_ = fillMatrix(rows_, cols_, matrix_, other.matrix_);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(const double num, const S21Matrix &other) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  return this->EqMatrix(other);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) throw std::exception();
  return matrix_[i][j];
}

double S21Matrix::operator()(int i, int j) const {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) throw std::exception();
  return matrix_[i][j];
}

int S21Matrix::Getrow() { return rows_; }

int S21Matrix::Getcol() { return cols_; }

void S21Matrix::Setrow(int row) {
  if (row < 1) throw std::exception();

  S21Matrix copy(*this);
  destroy(rows_, matrix_);
  matrix_ = initMatrix(row, cols_);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = i < rows_ ? copy.matrix_[i][j] : 0;
    }
  }
  rows_ = row;
}

void S21Matrix::Setcol(int col) {
  if (col < 1) throw std::exception();

  S21Matrix copy(*this);
  destroy(rows_, matrix_);
  matrix_ = initMatrix(rows_, col);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < col; j++) {
      matrix_[i][j] = j < cols_ ? copy.matrix_[i][j] : 0;
    }
  }
  cols_ = col;
}

void S21Matrix::RandMatrix() {
  srand(time(0) + rand());
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) {
      matrix_[i][k] = rand() % 10;
    }
  }
}

void S21Matrix::Print() {
  printf("Rows: %d\n", rows_);
  printf("Cols: %d\n", cols_);
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) {
      printf("%lf ", matrix_[i][k]);
    }
    printf("\n");
  }
}

S21Matrix S21Matrix::Minor(const int row, const int col) {
  if (row >= rows_ || row < 0 || col >= cols_ || col < 0)
    throw std::exception();

  if (rows_ == 1 && cols_ == 1) return *this;

  S21Matrix result(rows_ - 1, cols_ - 1);
  int res_i = -1, res_j = -1;
  for (int i = 0; i < rows_; i++) {
    if (i == row) continue;
    res_i++;
    for (int j = 0; j < cols_; j++) {
      if (j == col) continue;
      res_j++;
      result.matrix_[res_i][res_j] = matrix_[i][j];
    }
    res_j = -1;
  }

  return result;
}