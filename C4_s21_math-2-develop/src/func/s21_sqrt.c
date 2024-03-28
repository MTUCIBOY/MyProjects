#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (S21_ISNAN(x) || s21_fabs(x) == 0.0 || (S21_ISINF(x) && x == S21_POS_INF))
    return x;
  if (x < 0.0) return -S21_NAN;

  long double r = x;
  int iter_lim = 1000;
  for (int i = 0; i < iter_lim && s21_fabs(r * r - x) > S21_EPS; i++)
    r = (r + x / r) / 2.0;

  return r;
}
