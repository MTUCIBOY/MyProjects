#include "main.h"

int main(int argc, char* argv[]) {
  int flags[10], i;
  memset(flags, 0, sizeof(int) * 10);

  int index_flags = 1;
  char f[10];
  memset(f, '0', sizeof(char) * 10);

  // Флаги
  while (index_flags < argc) {
    i = 0;

    if (argv[index_flags][0] == '-') {
      strcpy(f, argv[index_flags]);
      while (i < 10) {
        switch (f[i]) {
          case 'e':
            flags[0] = 1;
            break;
          case 'i':
            flags[1] = 1;
            break;
          case 'v':
            flags[2] = 1;
            break;
          case 'c':
            flags[3] = 1;
            break;
          case 'l':
            flags[4] = 1;
            break;
          case 'n':
            flags[5] = 1;
            break;
          case 'h':
            flags[6] = 1;
            break;
          case 's':
            flags[7] = 1;
            break;
          case 'f':
            flags[8] = 1;
            break;
          case 'o':
            flags[9] = 1;
            break;
        }
        i++;
      }
    }
    index_flags++;
  }

  flags_grep(flags, argv, argc);

  return 0;
}