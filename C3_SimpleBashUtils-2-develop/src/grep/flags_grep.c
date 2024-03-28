#include "main.h"

void flags_grep(int* flags, char** argv, int argc) {
  // Объявление переменных
  char* pattern = malloc(sizeof(char));
  pattern[0] = '\0';
  char* filename = malloc(sizeof(char));
  filename[0] = '\0';

  FILE* f;
  char str[50];
  str[48] = '\0';

  char* buffer;
  char* head_buffer;
  char* head_filename;
  int result = 0, j = 0, many_files = 0, flag_c = 0, flag_n = 0;

  regex_t preg;
  regmatch_t pmatch[100];
  int comp_flag = REG_EXTENDED;

  // Флаг -e и -f
  if (flags[0] || flags[8]) {
    int i = 1;
    while (i < argc) {
      if (argv[i][0] != '-') {
        filename = realloc(filename, strlen(filename) + strlen(argv[i]) + 2);
        strcat(filename, argv[i]);
        strcat(filename, "|");
      } else {
        int k = 1;
        while (argv[i][k]) {
          if (argv[i][k] == 'e') {
            pattern =
                realloc(pattern, strlen(pattern) + strlen(argv[i + 1]) + 2);
            strcat(pattern, argv[i + 1]);
            strcat(pattern, "|");
            i++;
            break;
          }

          if (argv[i][k] == 'f') {
            char ch;
            int len_pat;

            // Проверка на наличие файла
            if (access(argv[i + 1], F_OK) == -1) {
              fprintf(stderr, "grep: %s: No such file or directory\n",
                      argv[i + 1]);
              exit(1);
            }
            // Проверка на право доступа к файлу
            else if (access(argv[i + 1], R_OK) == -1) {
              fprintf(stderr, "grep: %s: Access denied\n", argv[i + 1]);
              exit(1);
            }

            // Открытие файла
            f = fopen(argv[i + 1], "r");

            // Достаем паттерн
            while ((ch = fgetc(f)) != EOF) {
              len_pat = strlen(pattern);
              if (ch == '\n') ch = '|';
              pattern = realloc(pattern, len_pat + 1);
              pattern[len_pat] = ch;
            }

            len_pat = strlen(pattern);
            pattern = realloc(pattern, len_pat + 1);
            pattern[len_pat - 1] = '\0';

            i++;
            fclose(f);
            break;
          }
          k++;
        }
      }
      i++;
    }
  }

  // Убрать палку в конце паттерна
  if (flags[0] || flags[8]) pattern[strlen(pattern) - 1] = '\0';

  // Ищем паттерн и имя файла
  if (!flags[0] && !flags[8]) {
    pattern = find_pattern(pattern, argv, argc);
    filename = find_filename(filename, argv, argc);
  }

  // Флаг -i
  if (flags[1]) comp_flag |= REG_ICASE;

  // printf("\n%s\n%s\n", pattern, filename);

  // Начало работы алгоритма
  head_filename = filename;
  while (*head_filename) {
    // Достаем название файла
    char* one_filename = malloc(sizeof(char));

    while (*head_filename != '|') {
      one_filename[j] = *head_filename;
      one_filename = realloc(one_filename, j + 2);
      head_filename++;
      j++;
    }

    one_filename[j] = '\0';
    j = 0;
    head_filename++;

    // Проверка на несколько файлов
    if (*head_filename) many_files = 1;

    // Проверка на наличие файла
    if (access(one_filename, F_OK) == -1) {
      if (!flags[7])
        fprintf(stderr, "grep: %s: No such file or directory\n", one_filename);
      free(one_filename);
      continue;
    }
    // Проверка на право доступа к файлу
    else if (access(one_filename, R_OK) == -1) {
      if (!flags[7]) fprintf(stderr, "grep: %s: Access denied\n", one_filename);
      free(one_filename);
      continue;
    }

    // Открытие файла
    f = fopen(one_filename, "r");

    // Достаем строку
    while (fgets(str, 50, f) != NULL) {
      buffer = malloc(sizeof(char));
      buffer[0] = '\0';

      while (str[48] != '\0' && str[48] != '\n') {
        buffer = realloc(buffer, strlen(buffer) + 50);
        strcat(buffer, str);
        str[48] = '\0';
        fgets(str, 50, f);
      }

      buffer = realloc(buffer, strlen(buffer) + 50);
      strcat(buffer, str);

      if (!flags[9] || flags[3] || flags[4]) {
        // Нахождение строки
        regcomp(&preg, pattern, comp_flag);
        result = regexec(&preg, buffer, 0, NULL, 0);

        // Флаг -v
        if (!result && flags[2])
          result = 1;
        else if (flags[2])
          result = 0;

        // Флаг -с
        if (!result) flag_c++;

        // Флаг -n
        flag_n++;

        // Вывод строки
        if (!result && !flags[3] && !flags[4]) {
          if (many_files && !flags[6]) printf("%s:", one_filename);
          if (flags[5]) printf("%d:", flag_n);
          printf("%s", buffer);
          if (buffer[strlen(buffer) - 1] != '\n') printf("\n");
        }

        regfree(&preg);
      } else {
        head_buffer = buffer;

        // Флаг -n
        flag_n++;

        // Нахождение строки
        regcomp(&preg, pattern, comp_flag);

        int i;
        while ((result = regexec(&preg, head_buffer, 1, pmatch, 0)) == 0 &&
               *head_buffer) {
          i = 0;

          // Флаг -v
          if (flags[2]) result = 0;

          // Вывод строки
          if (result && !flags[3] && !flags[4]) {
            if (many_files && !flags[6]) printf("%s:", one_filename);
            if (flags[5]) printf("%d:", flag_n);
          }

          if (result) {
            while (i < pmatch[0].rm_eo - pmatch[0].rm_so) {
              printf("%c", head_buffer[pmatch[0].rm_so + i]);
              i++;
            }
            printf("\n");
          }

          head_buffer += pmatch[0].rm_eo;
        }

        // Флаг -с
        if (!result) flag_c++;

        regfree(&preg);
      }
      free(buffer);
    }

    // Флаг -с
    if (flags[3]) {
      if (many_files && !flags[6]) printf("%s:", one_filename);
      if (!flags[4])
        printf("%d", flag_c);
      else {
        if (flag_c)
          printf("1");
        else
          printf("0");
      }

      printf("\n");
    }

    // Флаг -l
    if (flags[4] && flag_c) printf("%s\n", one_filename);

    free(one_filename);
    fclose(f);
    flag_c = 0;
    flag_n = 0;
  }
  free(filename);
  free(pattern);
}
