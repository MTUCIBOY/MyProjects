#include "main.h"

char* find_pattern(char* pattern, char** argv, int argc) {
  int i = 1;

  while (i < argc) {
    if (argv[i][0] != '-') {
      pattern = realloc(pattern, strlen(pattern) + strlen(argv[i]) + 1);
      strcat(pattern, argv[i]);

      i++;
      break;
    }
    i++;
  }

  return pattern;
}

char* find_filename(char* filename, char** argv, int argc) {
  int i = 1, pattern_flag = 0;

  while (i < argc) {
    if (argv[i][0] != '-') {
      if (pattern_flag == 0) {
        pattern_flag = 1;
        i++;
        continue;
      }

      filename = realloc(filename, strlen(filename) + strlen(argv[i]) + 2);
      strcat(filename, argv[i]);
      strcat(filename, "|");
    }
    i++;
  }

  return filename;
}