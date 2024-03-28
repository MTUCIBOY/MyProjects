#include "../s21_math.h"

int s21_is_zero(double x) {
  if (x > -S21_EPS && x < S21_EPS) return 1;
  return 0;
}

long double s21_powi(long double base, int exp) {
  const char sign = exp < -S21_EPS ? -1 : 1;
  long double result = 1.0;
  exp = s21_abs(exp);

  while (exp > 0) {
    if (exp & 1) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
  }

  return (sign == -1) ? (1.0 / result) : result;
}

long double s21_factorial(double x) {
  if (x == 0) {
    return 1;
  } else {
    return x * s21_factorial(x - 1);
  }
}
