#ifndef MAIN_H
#define MAIN_H

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void raw_grep(int argc, char** argv);
void flags_grep(int* flags, char** argv, int argc);
char* find_pattern(char* pattern, char** argv, int argc);
char* find_filename(char* filename, char** argv, int argc);

#endif