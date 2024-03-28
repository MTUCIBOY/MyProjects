#include "s21_sscanf.h"

// int main(){
//     char format[] = "%hi %li %Li";
//   char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
//   short unsigned int d1, d2;
//   long unsigned int q1, q2;
//   long long unsigned int w1, w2;

//   int16_t res1 = s21_sscanf(str, format, &d1, &q1, &w1);
//   int16_t res2 = sscanf(str, format, &d2, &q2, &w2);

//   printf("%d %hd %ld %Ld\n", res1, d1, q1, w1);
//   printf("%d %hd %ld %Ld\n", res2, d2, q2, w2);

//   return 0;
// }

//База сканф. Парсер формата
int s21_sscanf(const char *str, const char *format, ...) {
  //Объявление переменных
  va_list arguments;  //Аргументы в которые будем писать данные
  size_t index_str = 0;      //Индекс строки
  size_t num_of_symbol = 0;  //Индекс перед спецификатором
  int result = 0;  //Количество удачных присвоенний
  int code = 1;  // 0 - присвоение прошло успешно, 1 - ошибка
  int star = 0;  //Флаг звездочки перед спецификатором
  char long_short_format = 0;  //Флаг формата (long, short, long long (для
                               // float: double и long double))

  //Затычки для считывания строки (нужны во время звездочки)
  int plug_int = 1;
  char *head_plug_char = malloc(s21_strlen(str));
  char *plug_char = head_plug_char;
  float plug_float = 1;

  //Считывание переменных со списка функции
  va_start(arguments, *format);

  //Начало работы с форматом
  while (*format) {
    if (*format == '%') {
      format++;

      //Считывание звездочки
      if (*format == '*') {
        star++;
        format++;
      } else
        while (*format >= '0' &&
               *format <= '9') {  //Считывание цифры (вместе звездочка и цифры
                                  //работать не могут)
          num_of_symbol = num_of_symbol * 10 + (*format - '0');
          format++;
        }

      //Считывание формата типа long short long long
      if (*format == 'l' || *format == 'L' || *format == 'h') {
        if (*format == 'l') {
          format++;
          if (*format == 'l') {
            long_short_format = 'L';
            format++;
          } else
            long_short_format = 'l';
        } else {
          long_short_format = *format;
          format++;
        }
      } else
        long_short_format = 0;

      //Запуск алгоритмов по спецификатору
      switch (*format) {
        case 'c':
          if (star)
            writearg(str, plug_char, 'c', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'c', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'd':
          if (star)
            writearg(str, &plug_int, 'd', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'd', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'i':
          if (star)
            writearg(str, &plug_int, 'i', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'i', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'e':
          if (star)
            writearg(str, &plug_float, 'e', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'e', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'E':
          if (star)
            writearg(str, &plug_float, 'e', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'e', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'f':
          if (star)
            writearg(str, &plug_float, 'e', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'e', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'g':
          if (star)
            writearg(str, &plug_float, 'e', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'e', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'G':
          if (star)
            writearg(str, &plug_float, 'e', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'e', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'o':
          if (star)
            writearg(str, &plug_int, 'o', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'o', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 's':
          if (star)
            writearg(str, plug_char, 's', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 's', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'u':
          if (star)
            writearg(str, &plug_int, 'u', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'u', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'x':
          if (star)
            writearg(str, &plug_int, 'x', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'x', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'X':
          if (star)
            writearg(str, &plug_int, 'x', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'x', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'p':
          if (star)
            writearg(str, &plug_int, 'p', &index_str, 0, 0);
          else
            code = writearg(str, va_arg(arguments, void *), 'p', &index_str,
                            num_of_symbol, long_short_format);
          break;
        case 'n':
          code = writearg(str, va_arg(arguments, void *), 'n', &index_str,
                          num_of_symbol, long_short_format);
          result--;
          break;
      }

      //Проверка формата на пропуск символов в строке
      format++;
      if (*format) {
        while (*format == ' ') format++;
        while (*format && *format == str[index_str]) {
          format++;
          index_str++;
          while (*format == ' ') format++;
        }
        if (*format == '%') code = 0;
      }

      //Счет успешных присваений
      if (!code || *format) {
        if (!star && *format != 'n') result++;
      } else
        break;

    } else
      format++;

    //Обнуление флагов
    num_of_symbol = 0;
    star = 0;
    long_short_format = 0;
    plug_char = head_plug_char;
  }

  //Освобождение памяти и return
  free(head_plug_char);
  va_end(arguments);

  return result;
}

//Блок с алгоритмов чтения строки и присвоение переменным
int writearg(const char *s, void *address, const char type, size_t *i,
             size_t out_index, const char LS) {
  int sign = 0;  //Флаг знака
  size_t len = s21_strlen(
      s);  //Если у нас нет цифры перед спецификатором, значит она максимальна

  switch (type) {
    case 'c':
      if (LS == 'l')
        *(wchar_t *)address = s[*i];
      else
        *(char *)address = s[*i];
      (*i)++;
      break;
    case 'd':
      if (out_index == 0) out_index = len;

      //Ищем нужную строку (разделителями переменных в строке есть пробелы и
      //спецсимволы)
      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;  // 92 == '\'
      }

      //Обработка знака перед числом и обнуление переменной, если она подходит
      //условием
      if (s[*i] &&
          ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '-' || s[*i] == '+') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          /*Это случий, когда в строке есть число со знаком(-+) и перед
          спецификатором стоит 1(один знак на чтение). sscanf считает этот
          знак не как матиматический, а теперь как обычное тире, поэтому код не
          должен работать после такого*/
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        if (LS == 'l')
          *(long int *)address = 0;
        else if (LS == 'L')
          *(long long int *)address = 0;
        else if (LS == 'h')
          *(short int *)address = 0;
        else
          *(int *)address = 0;
      } else
        return 1;

      //Основной алгоритм
      while (s[*i] && (s[*i] >= '0' && s[*i] <= '9') && out_index > 0) {
        if (LS == 'h')
          *(short int *)address = *(short int *)address * 10 + (s[*i] - '0');
        else if (LS == 'l')
          *(long int *)address = *(long int *)address * 10 + (s[*i] - '0');
        else if (LS == 'L')
          *(long long int *)address =
              *(long long int *)address * 10 + (s[*i] - '0');
        else
          *(int *)address = *(int *)address * 10 + (s[*i] - '0');
        (*i)++;
        out_index--;
      }

      //Присвоение отрицание, если в строке такое было
      if (sign) {
        if (LS == 'l')
          *(long int *)address *= -1;
        else if (LS == 'L')
          *(long long int *)address *= -1;
        else if (LS == 'h')
          *(short int *)address *= -1;
        else
          *(int *)address *= -1;
      }

      break;

    case 'i':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      if (s[*i] &&
          ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '-' || s[*i] == '+') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        if (LS == 'l')
          *(long int *)address = 0;
        else if (LS == 'L')
          *(long long int *)address = 0;
        else if (LS == 'h')
          *(short int *)address = 0;
        else
          *(int *)address = 0;
      } else
        return 1;

      while (s[*i] && (s[*i] >= '0' && s[*i] <= '9') && out_index > 0) {
        if (s[*i] == '0' && (s[*i + 1] == 'x' || s[*i + 1] == 'X')) {
          (*i)++;
          out_index--;
          if (out_index > 0) {
            (*i)++;
            out_index--;
          }
          int num = 0;

          while (s[*i] &&
                 ((s[*i] >= '0' && s[*i] <= '9') ||
                  (s[*i] >= 'A' && s[*i] <= 'F') ||
                  (s[*i] >= 'a' && s[*i] <= 'f')) &&
                 out_index > 0) {
            if (s[*i] >= '0' && s[*i] <= '9')
              num = s[*i] - '0';
            else if (s[*i] >= 'A' && s[*i] <= 'F')
              num = s[*i] - 'A' + 10;
            else if (s[*i] >= 'a' && s[*i] <= 'f')
              num = s[*i] - 'a' + 10;

            if (LS == 'h')
              *(short int *)address = *(short int *)address * 16 + num;
            else if (LS == 'l')
              *(long int *)address = *(long int *)address * 16 + num;
            else if (LS == 'L')
              *(long long int *)address = *(long long int *)address * 16 + num;
            else
              *(int *)address = *(int *)address * 16 + num;

            (*i)++;
            out_index--;
          }
        } else if (s[*i] == '0') {
          while (s[*i] && (s[*i] >= '0' && s[*i] <= '9') && out_index > 0) {
            if (LS == 'h')
              *(short int *)address = *(short int *)address * 8 + (s[*i] - '0');
            else if (LS == 'l')
              *(long int *)address = *(long int *)address * 8 + (s[*i] - '0');
            else if (LS == 'L')
              *(long long int *)address =
                  *(long long int *)address * 8 + (s[*i] - '0');
            else
              *(int *)address = *(int *)address * 8 + (s[*i] - '0');

            (*i)++;
            out_index--;
          }
        } else {
          while (s[*i] && (s[*i] >= '0' && s[*i] <= '9') && out_index > 0) {
            if (LS == 'h')
              *(short int *)address =
                  *(short int *)address * 10 + (s[*i] - '0');
            else if (LS == 'l')
              *(long int *)address = *(long int *)address * 10 + (s[*i] - '0');
            else if (LS == 'L')
              *(long long int *)address =
                  *(long long int *)address * 10 + (s[*i] - '0');
            else
              *(int *)address = *(int *)address * 10 + (s[*i] - '0');

            (*i)++;
            out_index--;
          }
        }
      }

      if (sign) {
        if (LS == 'l')
          *(long int *)address *= -1;
        else if (LS == 'L')
          *(long long int *)address *= -1;
        else if (LS == 'h')
          *(short int *)address *= -1;
        else
          *(int *)address *= -1;
      }

      break;

    case 'e':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      if (s[*i] &&
          ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '-' || s[*i] == '+' ||
           s[*i] == '.') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        if (LS == 'l')
          *(double *)address = 0;
        else if (LS == 'L')
          *(long double *)address = 0;
        else
          *(float *)address = 0;
      } else
        return 1;

      while (s[*i] && ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '.') &&
             out_index > 0) {
        if (s[*i] == '.') {
          (*i)++;
          out_index--;
          float mantis = 0;
          float index = 10;

          while (s[*i] && (s[*i] >= '0' && s[*i] <= '9') && out_index > 0) {
            mantis = mantis + (s[*i] - '0') / index;
            index *= 10;
            (*i)++;
            out_index--;
          }

          if (LS == 'l')
            *(double *)address = *(double *)address + mantis;
          else if (LS == 'L')
            *(long double *)address = *(long double *)address + mantis;
          else
            *(float *)address = *(float *)address + mantis;
        } else {
          if (LS == 'l')
            *(double *)address = *(double *)address * 10 + (s[*i] - '0');
          else if (LS == 'L')
            *(long double *)address =
                *(long double *)address * 10 + (s[*i] - '0');
          else
            *(float *)address = *(float *)address * 10 + (s[*i] - '0');

          (*i)++;
          out_index--;
        }
      }

      if (s[*i] == 'e' || s[*i] == 'E') {
        (*i)++;
        out_index--;
        long int index = 0;

        if (s[*i] == '-' && (s[*i + 1] >= '0' && s[*i + 1] <= '9') &&
            out_index > 0) {
          (*i)++;
          out_index--;

          while (s[*i] >= '0' && s[*i] <= '9' && out_index > 0) {
            index = index * 10 + (s[*i] - '0');
            (*i)++;
            out_index--;
          }

          if (LS == 'l')
            *(double *)address = *(double *)address / pow(10, index);
          else if (LS != 'L')
            *(float *)address = *(float *)address / pow(10, index);
          else {
            while (index) {
              *(long double *)address /= 10;
              index--;
            }
          }
        }

        else if (s[*i] == '+' && (s[*i + 1] >= '0' && s[*i + 1] <= '9') &&
                 out_index > 0) {
          (*i)++;
          out_index--;

          while (s[*i] >= '0' && s[*i] <= '9' && out_index > 0) {
            index = index * 10 + (s[*i] - '0');
            (*i)++;
            out_index--;
          }

          if (LS == 'l')
            *(double *)address = *(double *)address * pow(10, index);
          else if (LS != 'L')
            *(float *)address = *(float *)address * pow(10, index);
          else {
            while (index) {
              *(long double *)address *= 10;
              index--;
            }
          }
        }

        else if (s[*i] >= '0' && s[*i] <= '9' && out_index > 0) {
          while (s[*i] >= '0' && s[*i] <= '9' && out_index > 0) {
            index = index * 10 + (s[*i] - '0');
            (*i)++;
            out_index--;
          }

          if (LS == 'l')
            *(double *)address = *(double *)address * pow(10, index);
          else if (LS != 'L')
            *(float *)address = *(float *)address * pow(10, index);
          else {
            while (index) {
              *(long double *)address *= 10;
              index--;
            }
          }
        }
      }

      if (sign) {
        if (LS == 'l')
          *(double *)address *= -1;
        else if (LS == 'L')
          *(long double *)address *= -1;
        else
          *(float *)address *= -1;
      }

      break;

    case 'o':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      if (s[*i] &&
          ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '-' || s[*i] == '+') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        if (LS == 'l')
          *(long int *)address = 0;
        else if (LS == 'L')
          *(long long int *)address = 0;
        else if (LS == 'h')
          *(short int *)address = 0;
        else
          *(int *)address = 0;
      } else
        return 1;

      while (s[*i] && (s[*i] >= '0' && s[*i] <= '9') && out_index > 0) {
        if (LS == 'h')
          *(short int *)address = *(short int *)address * 8 + (s[*i] - '0');
        else if (LS == 'l')
          *(long int *)address = *(long int *)address * 8 + (s[*i] - '0');
        else if (LS == 'L')
          *(long long int *)address =
              *(long long int *)address * 8 + (s[*i] - '0');
        else
          *(int *)address = *(int *)address * 8 + (s[*i] - '0');

        (*i)++;
        out_index--;
      }

      if (sign) {
        if (LS == 'l')
          *(long int *)address *= -1;
        else if (LS == 'L')
          *(long long int *)address *= -1;
        else if (LS == 'h')
          *(short int *)address *= -1;
        else
          *(int *)address *= -1;
      }

      break;

    case 's':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      while (s[*i] != ' ' && s[*i] && out_index > 0) {
        *(char *)address = s[*i];
        address++;
        (*i)++;
        out_index--;
      }

      *(char *)address = '\0';
      break;

    case 'u':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      if (s[*i] &&
          ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '-' || s[*i] == '+') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        if (LS == 'l')
          *(long int *)address = 0;
        else if (LS == 'L')
          *(long long int *)address = 0;
        else if (LS == 'h')
          *(short int *)address = 0;
        else
          *(int *)address = 0;
      } else
        return 1;

      while (s[*i] && (s[*i] >= '0' && s[*i] <= '9')) {
        if (LS == 'h')
          *(short int *)address = *(short int *)address * 10 + (s[*i] - '0');
        else if (LS == 'l')
          *(long int *)address = *(long int *)address * 10 + (s[*i] - '0');
        else if (LS == 'L')
          *(long long int *)address =
              *(long long int *)address * 10 + (s[*i] - '0');
        else
          *(int *)address = *(int *)address * 10 + (s[*i] - '0');

        (*i)++;
        out_index--;
      }

      if (sign) {
        if (LS == 'l')
          *(long int *)address *= -1;
        else if (LS == 'L')
          *(long long int *)address *= -1;
        else if (LS == 'h')
          *(short int *)address *= -1;
        else
          *(int *)address *= -1;
      }

      break;

    case 'x':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      if (s[*i] &&
          (((s[*i] >= '0' && s[*i] <= '9') || (s[*i] >= 'A' && s[*i] <= 'F') ||
            (s[*i] >= 'a' && s[*i] <= 'f')) ||
           s[*i] == '-' || s[*i] == '+') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        if (LS == 'l')
          *(long int *)address = 0;
        else if (LS == 'L')
          *(long long int *)address = 0;
        else if (LS == 'h')
          *(short int *)address = 0;
        else
          *(int *)address = 0;
      } else
        return 1;

      if (s[*i] == '0' && (s[*i + 1] == 'x' || s[*i + 1] == 'X')) {
        (*i)++;
        out_index--;
        if (out_index > 0) {
          (*i)++;
          out_index--;
        }
      }

      int num = 0;
      while (s[*i] &&
             ((s[*i] >= '0' && s[*i] <= '9') ||
              (s[*i] >= 'A' && s[*i] <= 'F') ||
              (s[*i] >= 'a' && s[*i] <= 'f')) &&
             out_index > 0) {
        if (s[*i] >= '0' && s[*i] <= '9')
          num = s[*i] - '0';
        else if (s[*i] >= 'A' && s[*i] <= 'F')
          num = s[*i] - 'A' + 10;
        else if (s[*i] >= 'a' && s[*i] <= 'f')
          num = s[*i] - 'a' + 10;

        if (LS == 'h')
          *(short int *)address = *(short int *)address * 16 + num;
        else if (LS == 'l')
          *(long int *)address = *(long int *)address * 16 + num;
        else if (LS == 'L')
          *(long long int *)address = *(long long int *)address * 16 + num;
        else
          *(int *)address = *(int *)address * 16 + num;

        (*i)++;
        out_index--;
      }

      if (sign) {
        if (LS == 'l')
          *(long int *)address *= -1;
        else if (LS == 'L')
          *(long long int *)address *= -1;
        else if (LS == 'h')
          *(short int *)address *= -1;
        else
          *(int *)address *= -1;
      }

      break;

    case 'p':
      if (out_index == 0) out_index = len;

      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      if (s[*i] &&
          ((s[*i] >= '0' && s[*i] <= '9') || (s[*i] >= 'A' && s[*i] <= 'F') ||
           (s[*i] >= 'a' && s[*i] <= 'f') || s[*i] == '-' || s[*i] == '+') &&
          out_index > 0) {
        if (s[*i] == '-') {
          out_index--;
          if (out_index == 0)
            return 1;
          else {
            sign++;
            (*i)++;
          }
        } else if (s[*i] == '+') {
          out_index--;
          if (out_index == 0)
            return 1;
          else
            (*i)++;
        }

        *(long int *)address = 0;
      } else
        return 1;

      if (s[*i] == '0' && (s[*i + 1] == 'x' || s[*i + 1] == 'X')) {
        (*i)++;
        out_index--;
        if (out_index > 0) {
          (*i)++;
          out_index--;
        }
      }

      int Num = 0;

      while (s[*i] &&
             ((s[*i] >= '0' && s[*i] <= '9') ||
              (s[*i] >= 'A' && s[*i] <= 'F') ||
              (s[*i] >= 'a' && s[*i] <= 'f')) &&
             out_index > 0) {
        if (s[*i] >= '0' && s[*i] <= '9')
          Num = s[*i] - '0';
        else if (s[*i] >= 'A' && s[*i] <= 'F')
          Num = s[*i] - 'A' + 10;
        else if (s[*i] >= 'a' && s[*i] <= 'f')
          Num = s[*i] - 'a' + 10;
        *(long int *)address = *(long int *)address * 16 + Num;

        (*i)++;
        out_index--;
      }

      if (sign) *(long int *)address *= -1;

      break;

    case 'n':
      while (s[*i] == ' ') {
        (*i)++;
        if (s[*i] == 92) (*i)++;
      }

      *(int *)address = *i;
      break;
  }

  return 0;
}