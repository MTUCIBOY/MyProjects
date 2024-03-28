#include "main.h"

void flags_cat(char* file_name, int f) {
  FILE* file_cat;
  if ((file_cat = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "cat: %s: No such file or directory\n", file_name);
    exit(1);
  }

  int num_line = 1;
  char str = getc(file_cat);

  while (str != EOF) {
    if (f & (1 << 0)) {  //Флаг -n
      if (str != EOF) {
        printf("%6d\t", num_line);
        num_line++;
      }
    }

    if (f & (1 << 1)) {  //Флаг -b
      if (str != '\n' && str != EOF) {
        printf("%6d\t", num_line);
        num_line++;
      }
    }

    if (f & (1 << 2)) {  //Флаг -s
      if (str == '\n') {
        while ((str = getc(file_cat)) == '\n')
          ;
        if (str != EOF)
          printf("\n%c", str);
        else
          printf("\n");
        str = getc(file_cat);
      }
    }

    while (str != '\n' && str != EOF) {  //Вывод файла + флаг -v -t
      if (f & (1 << 3)) {                //Флаг -t
        while (str == '\t') {
          printf("^I");
          str = getc(file_cat);
        }
      }

      if (f & (1 << 5)) {  //Флаг -v
        if (str >= 32 && str <= 126) printf("%c", str);
        if (str == 9 || str == 10) printf("%c", str);
        if ((str < 32 || str > 126) && (str != 10 && str != 9 && str != EOF)) {
          if (str == 127)
            printf("^?");
          else
            printf("^%c", str + 64);
        }
        str = getc(file_cat);
      } else {
        printf("%c", str);
        str = getc(file_cat);
      }
    }

    if (str == EOF)
      break;  // Конец файла + флаг -e
    else {
      if (f & (1 << 4)) {  //Флаг -e
        if (str == '\n') printf("$");
      }
      printf("%c", str);
      str = getc(file_cat);
    }
  }
  fclose(file_cat);
}
