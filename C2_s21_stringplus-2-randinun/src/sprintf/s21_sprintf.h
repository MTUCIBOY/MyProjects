#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../func/s21_string.h"

size_t s21_strlen(const char* str);
int s21_sprintf(char* str, const char* format, ...);

void* integer_arg(void* number, const char LS, const bool plus, size_t prec,
                  const bool pf, const bool sharp, const char format);
void* float_e_arg(void* number, const char LS, const bool plus, size_t prec,
                  const bool sharp, const char format);
void* float_f_arg(void* number, const char LS, const bool plus, size_t prec,
                  const bool sharp, const char format);
void* float_g_arg(void* number, const char LS, const bool plus, size_t prec,
                  const bool pf, const bool sharp, const char format);
void* infinity(const bool plus, const bool sign, const char LS);

#endif