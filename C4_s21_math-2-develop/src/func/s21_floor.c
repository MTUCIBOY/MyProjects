#include "../s21_math.h"

long double s21_floor(double x) {
  if (S21_ISNAN(x) || S21_ISINF(x)) return x;

  long double i = (long long int)x;
  if (s21_fabs(x) > 0.0 && i != x) {
    if (x < 0.0) i -= 1;
    return (x < 0.0 && s21_is_zero(i)) ? (-1 * i) : i;
  }
  return x;
}
