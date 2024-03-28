#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if (S21_ISNAN(x) || S21_ISNAN(y)) return S21_NAN;
  if (s21_is_zero(y) || S21_ISINF(x)) return -S21_NAN;
  if (s21_is_zero(x) || S21_ISINF(y)) return x;
  return x - (long long int)(x / y) * y;
}
