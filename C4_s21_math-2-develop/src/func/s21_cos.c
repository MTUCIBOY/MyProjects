#include "../s21_math.h"

const short int COS_LIMIT = 17;

long double s21_cos(double x) {
  if (S21_ISNAN(x) || S21_ISINF(x)) return S21_NAN;

  long double result = 0;

  if (x > 2 * S21_PI || x < (-2 * S21_PI)) x = s21_fmod(x, 2 * S21_PI);

  for (short int n = 0; n < COS_LIMIT; n++)
    result += s21_pow(-1, n) * (s21_pow(x, 2 * n) / s21_factorial(2 * n));

  return result;
}
