#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  if (s21_is_zero(base) && !s21_is_zero(exp)) {
    if ((long long int)exp == exp && s21_fmod(exp, 2.0))
      return (exp > 0.0) ? base : (1.0 / base);
    else
      return (exp > 0.0) ? +0.0 : S21_POS_INF;
  }

  if (base == 1.0 || (base == -1.0 && S21_ISINF(exp))) return 1.0;

  if (!S21_ISINF(base) && !S21_ISNAN(base) && base < 0.0 && !S21_ISINF(exp) &&
      !S21_ISNAN(exp) && (long long int)exp != exp)
    return S21_NAN;

  if (S21_ISINF(exp)) {
    if (s21_fabs(base) > 1.0)
      return (exp == S21_NEG_INF) ? +0.0 : S21_POS_INF;
    else
      return (exp == S21_NEG_INF) ? S21_POS_INF : +0.0;
  }

  if (S21_ISINF(base) && base == S21_NEG_INF) {
    int mf = (long long int)exp == exp && s21_fmod(exp, 2.0);
    if (exp < 0.0)
      return (mf) ? -0.0 : +0.0;
    else
      return (mf) ? S21_NEG_INF : S21_POS_INF;
  }

  if (S21_ISINF(base) && base == S21_POS_INF)
    return (exp < 0.0) ? +0.0 : S21_POS_INF;

  const char sign = base < -S21_EPS ? 1 : 0;
  if (sign) base = s21_fabs(base);

  long double a = ((long long int)exp == exp) ? s21_powi(base, exp)
                                              : s21_exp(exp * s21_log(base));
  int s = (sign) ? -1 : 1;
  long double b = (s21_fmod(exp, 2.0) ? s : 1.0);
  return a * b;
}
