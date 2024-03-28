#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../func/s21_string.h"

int s21_sscanf(const char *str, const char *format, ...);
int writearg(const char *s, void *address, const char type, size_t *i,
             size_t num_of_symbol, const char LS);
size_t s21_strlen(const char *str);

#endif