#include "../s21_math.h"

long double s21_log(double x) {
  if (S21_ISINF(x) || S21_ISNAN(x)) return (x == S21_NEG_INF) ? -S21_NAN : x;
  if (s21_is_zero(x)) return S21_NEG_INF;
  if (x < 0.0) return -S21_NAN;

  int ep = 0;
  long double res = 0;
  long double mid = 1e-6;
  long double mide = 0.0;
  int iter_lim = 1000;

  for (; x >= S21_EPS; x /= S21_EXP, ++ep) {
  }
  for (int i = 0; (s21_fabs(mid) > S21_EPS && i < iter_lim) || i < 2; i++) {
    mid = res;
    mide = s21_exp(mid);
    res = mid + (x - mide) / (x + mide) * 2.0;
  }
  return res + ep;
}
