#include "../s21_math.h"

const short int ASIN_LIMIT = 35;

long double s21_asin(double x) {
  if (S21_ISINF(x) || x > 1 || x < -1) return -S21_NAN;
  if (S21_ISNAN(x)) return S21_NAN;

  long double result = 0;

  //Точность по бокам начинает хромать, поэтому используем другой аргумент
  if (x > 0.8 || x < -0.8) {
    result = s21_acos(s21_sqrt(1 - x * x));
    if (x < -0.8) result *= -1;
  } else
    for (short int n = 0; n < ASIN_LIMIT; n++)
      result += s21_factorial(2 * n) /
                (s21_pow(2, 2 * n) * (s21_pow(s21_factorial(n), 2))) *
                (s21_pow(x, 2 * n + 1) / (2 * n + 1));

  return result;
}
