#include "../s21_math.h"

long double s21_atan(double x) {
  if (S21_ISINF(x)) return x < 0 ? -1 : 1;

  return s21_asin(x / s21_sqrt(1.0 + x * x));
}
