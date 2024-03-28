#include "../s21_math.h"

long double s21_fabs(double x) {
  if (S21_ISNAN(x) || S21_ISINF(x)) return x;
  if (s21_is_zero(x)) return x;
  return (x < -S21_EPS) ? (-1 * x) : x;
}
