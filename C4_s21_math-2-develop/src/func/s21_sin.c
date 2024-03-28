#include "../s21_math.h"

long double s21_sin(double x) {
  if (S21_ISINF(x)) return -S21_NAN;
  if (S21_ISNAN(x)) return x;

  x = s21_fmod(x, S21_PI * 2);

  long double r = 0.0;
  long double m = 1e-6;
  int iter_lim = 1000;

  for (int i = 0; i < iter_lim && s21_fabs(m) > S21_EPS; i++) {
    m = s21_powi(-1.0, i) * s21_powi(x, 1 + 2 * i) / s21_factorial(1 + 2 * i);
    r += m;
  }
  return r;
}
