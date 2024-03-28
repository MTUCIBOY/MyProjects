#ifndef FUNC_H
#define FUNC_H

#define S21_PI 3.1415926535897932384626433832795028841971
#define S21_EXP 2.71828182845904523536
#define S21_EPS 1e-18

#define S21_NAN (0.0 / 0.0)
#define S21_ISNAN(x) (x != x)

#define S21_POS_INF (1.0 / 0.0)
#define S21_NEG_INF (-1.0 / 0.0)
#define S21_ISINF(x) (!S21_ISNAN(x) && S21_ISNAN(x - x))

#include <stdbool.h>
#include <stdio.h>

long double s21_factorial(double x);
long double s21_multiexp(double x, int n);

int s21_is_zero(double x);
long double s21_powi(long double base, int exp);

int s21_abs(int x);
long double s21_cos(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_exp(double x);

long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
