#include "../s21_math.h"

long double s21_exp(double x) {
  if (S21_ISNAN(x)) return S21_NAN;
  if (S21_ISINF(x)) return x < 0 ? 0 : S21_POS_INF;
  if (x == 0) return 1;

  long double result = 0;
  bool sign = 0;

  if (x < 0) {
    sign = 1;
    x = -x;
  }

  for (int n = 0; n < 100; n++) result += s21_multiexp(x, n) / s21_factorial(n);

  return sign ? 1 / result : result;
}

long double s21_multiexp(double x, int n) {
  long double res = x;

  if (n == 0)
    return 1;
  else
    return res = res * s21_multiexp(x, n - 1);
}
