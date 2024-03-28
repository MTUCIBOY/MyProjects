#include "../s21_math.h"

long double s21_acos(double x) { return S21_PI / 2.0 - s21_asin(x); }
