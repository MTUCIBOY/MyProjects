#include "../s21_math.h"

long double s21_ceil(double x) {
  if (S21_ISINF(x)) return x < 0 ? S21_NEG_INF : S21_POS_INF;
  if (S21_ISNAN(x)) return S21_NAN;

  long double result = 0;

  if (x - s21_floor(x) != 0)
    result = s21_floor(x) + 1;
  else
    result = x;

  return result;
}
