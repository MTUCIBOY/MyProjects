#include "main.h"

int main(int argc, char* argv[]) {
  int i = 1, is_empty = 1;
  int Bflags = 0b000000;

  // Флаги
  while (i < argc) {
    if (argv[i][0] == '-') {
      // GNU флаг
      if (argv[i][1] == '-') {
        if (strcmp(argv[i], "--number") == 0)
          if (!(Bflags & (1 << 0))) Bflags += 0b1;

        if (strcmp(argv[i], "--number-nonblank") == 0)
          if (!(Bflags & (1 << 1))) Bflags += 0b10;

        if (strcmp(argv[i], "--squeeze-blank") == 0)
          if (!(Bflags & (1 << 2))) Bflags += 0b100;
      } else {
        int k = 1;
        while (argv[i][k]) {
          switch (argv[i][k]) {
            case 'v':
              if (!(Bflags & (1 << 5))) Bflags += 0b100000;
              break;
            case 'b':
              if (!(Bflags & (1 << 1))) Bflags += 0b10;
              if (Bflags & (1 << 0)) Bflags -= 0b1;
              break;
            case 'n':
              if (!(Bflags & (1 << 0)) && !(Bflags & (1 << 1))) Bflags += 0b1;
              break;
            case 's':
              if (!(Bflags & (1 << 2))) Bflags += 0b100;
              break;
            case 't':
              if (!(Bflags & (1 << 3))) Bflags += 0b1000;
              if (!(Bflags & (1 << 5))) Bflags += 0b100000;
              break;
            case 'e':
              if (!(Bflags & (1 << 4))) Bflags += 0b10000;
              if (!(Bflags & (1 << 5))) Bflags += 0b100000;
              break;
            case 'E':
              if (!(Bflags & (1 << 4))) Bflags += 0b10000;
              break;
            case 'T':
              if (!(Bflags & (1 << 3))) Bflags += 0b1000;
              break;
          }
          k++;
        }
      }
    } else
      is_empty = 0;
    i++;
  }

  i = 1;

  while (i < argc) {
    if (is_empty)
      empty_cat();
    else {
      if (argv[i][0] != '-') {
        flags_cat(argv[i], Bflags);
      }
    }
    i++;
  }

  return 0;
}
