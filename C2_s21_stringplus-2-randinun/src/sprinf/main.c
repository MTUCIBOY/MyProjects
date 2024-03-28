#include "s21_sprintf.h"


int main(){
    int a = 0;
    int b = 30;
    long int j = 0xffffff;
    char c = 'H';
    float d1 = 1;
    float d2 = 1.1234567890e10;
    float g1 = 1.001e10;
    double g2 = -121;
    char* str = "1";
    char STR1[1000];
    char STR2[1000];
    char* format = "str: %d %+0#5i %-4lc %+010.0E %+e\n%+f %#.0lf\n%+02g %#G%n\n%+o %#+o\n%+010u %u\n%#x %X\n%p\n";

    printf("%d\n", sprintf(STR1, format, a, b, c, d1, d2, g1, g2, g1, g2, &a, a, b, a, b, j, j, j));
    printf("%s", STR1);
    a = 0;
    printf("%d\n", s21_sprintf(STR2, format, a, b, c, d1, d2, g1, g2, g1, g2, &a, a, b, a, b, j, j, j));
    printf("%s", STR2);

    return 0;
}

// База сканф. Парсер формата
int s21_sprintf(char *str, const char *format, ...) {
    //Объявление переменных
    va_list arguments; //Аргументы из которых будем писать данные
    void* address;
    size_t index_str = 0; 
    size_t index_string = 0;
    size_t width = 0;
    size_t precision = 0;
    char long_short_format = 0;
    bool not_spec = 0;
    bool plus = 0;
    bool minus = 0;
    bool nul_flag = 0;
    bool space = 0;
    bool precision_flag = 0;
    bool sharp = 0;

    int integer = 0;
    long int l_integer = 0;
    long long int ll_integer = 0;
    short int h_integer = 0;
    unsigned int u_integer = 0;
    unsigned long int u_l_integer = 0;
    unsigned long long int u_ll_integer = 0;
    unsigned short int u_h_integer = 0;
    float flt = 0;
    double l_flt = 0;
    long double ll_flt = 0;
    char ch = 0;
    char* string = 0;
    
    //Считывание переменных со списка функции
    va_start(arguments, *format);

    //Начало работы с форматом
    while(*format) {
        if(*format == '%') {
            format++;
            if(*format == '%') not_spec++;
            
            //Перебор флагов
            for(int i = 0; i < 5; i++){
                //Решетка
                if(*format == '#'){
                    sharp++;
                    format++;
                }

                //Знак
                if(*format == '+') {
                    plus = 1;
                    format++;
                }
                if(*format == '-') {
                    minus = 1;
                    format++;
                }

                //Флаг пробела
                while(*format == ' '){
                    space = 1;
                    format++;
                }

                //Флаг 0
                if(*format == '0') {
                    nul_flag = 1;
                    format++;
                }
            }
            
            //Ширина
            if(*format == '*'){
                width = va_arg(arguments, int);
                format++;
            } 
            else while(*format >= '0' && *format <= '9') {
                width = width * 10 + *format - '0';
                format++;
            }

            //Точность
            if(*format == '.') {
                precision_flag++;
                format++;
                if(*format == '*'){
                    precision = va_arg(arguments, int);
                    format++;
                } 
                else while(*format >= '0' && *format <= '9') {
                    precision = precision * 10 + *format - '0';
                    format++;
                }
            }

            //Считывание формата типа long short long long
            if(*format == 'l' || *format == 'L' || *format == 'h') {
                if(*format == 'l') {
                    format++;
                    if(*format == 'l') {
                        long_short_format = 'L';
                        format++;
                    }
                    else long_short_format = 'l';
                }
                else {
                    long_short_format = *format;
                    format++;
                }
            }
            else long_short_format = 0;

            // Запуск алгоритмов по спецификатору
            switch(*format) {
                case 'c':
                    if(long_short_format == 'l') {
                        string = malloc(sizeof(wchar_t) * 2);
                        *(wchar_t*)string = va_arg(arguments, wchar_t);
                        string++;
                        *(wchar_t*)string = '\0';
                        string--;
                    }
                    else {
                        string = malloc(sizeof(char) * 2);
                        *string = va_arg(arguments, int);
                        string++;
                        *string = '\0';
                        string--;
                    }
                    
                    break;
                case 'd':
                    if(long_short_format == 'h'){
                        h_integer = va_arg(arguments, int); 
                        string = integer_arg(&h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);   
                    }
                    else if(long_short_format == 'l') {
                        l_integer = va_arg(arguments, long int); 
                        string = integer_arg(&l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_integer = va_arg(arguments, long long int);
                        string = integer_arg(&ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        integer = va_arg(arguments, int);
                        string = integer_arg(&integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'i':
                    if(long_short_format == 'h'){
                        h_integer = va_arg(arguments, int); 
                        string = integer_arg(&h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);   
                    }
                    else if(long_short_format == 'l') {
                        l_integer = va_arg(arguments, long int); 
                        string = integer_arg(&l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_integer = va_arg(arguments, long long int);
                        string = integer_arg(&ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        integer = va_arg(arguments, int);
                        string = integer_arg(&integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    
                    break;                
                case 'e':
                    if(!precision_flag) precision = 6;
                    
                    if(long_short_format == 'l') {
                        l_flt = va_arg(arguments, double); 
                        string = float_e_arg(&l_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_flt = va_arg(arguments, long double);
                        string = float_e_arg(&ll_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        flt = va_arg(arguments, double);
                        string = float_e_arg(&flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'E':
                    if(!precision_flag) precision = 6;

                    if(long_short_format == 'l') {
                        l_flt = va_arg(arguments, double); 
                        string = float_e_arg(&l_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_flt = va_arg(arguments, long double);
                        string = float_e_arg(&ll_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        flt = va_arg(arguments, double);
                        string = float_e_arg(&flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'f':
                    if(!precision_flag) precision = 6;

                    if(long_short_format == 'l') {
                        l_flt = va_arg(arguments, double); 
                        string = float_f_arg(&l_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_flt = va_arg(arguments, long double);
                        string = float_f_arg(&ll_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        flt = va_arg(arguments, double);
                        string = float_f_arg(&flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'g':
                    if(!precision_flag) precision = 6;
                    
                    if(long_short_format == 'l') {
                        l_flt = va_arg(arguments, double); 
                        string = float_g_arg(&l_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_flt = va_arg(arguments, long double);
                        string = float_g_arg(&ll_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        flt = va_arg(arguments, double);
                        string = float_g_arg(&flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'G':
                    if(!precision_flag) precision = 6;
                    
                    if(long_short_format == 'l') {
                        l_flt = va_arg(arguments, double); 
                        string = float_g_arg(&l_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        ll_flt = va_arg(arguments, long double);
                        string = float_g_arg(&ll_flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        flt = va_arg(arguments, double);
                        string = float_g_arg(&flt, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'o':
                    if(long_short_format == 'h') {
                        u_h_integer = va_arg(arguments, unsigned int); 
                        string = integer_arg(&u_h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'l') {
                        u_l_integer = va_arg(arguments, unsigned long int); 
                        string = integer_arg(&u_l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        u_ll_integer = va_arg(arguments, unsigned long long int);
                        string = integer_arg(&u_ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        u_integer = va_arg(arguments, unsigned int);
                        string = integer_arg(&u_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 's':
                    char* str_tmp = va_arg(arguments, char*);
                    size_t tmp_len = (precision_flag) ? precision : s21_strlen(str_tmp);
                    
                    if(precision > s21_strlen(str_tmp)) {
                        tmp_len = s21_strlen(str_tmp);
                        precision = tmp_len;
                    }

                    string = malloc(sizeof(char) * (tmp_len + 1));
                
                    for(int i = 0; i < tmp_len || (precision_flag && precision != 0); i++){
                        string[i] = str_tmp[tmp_len - 1 - i];
                        precision--;
                    }
                    
                    string[tmp_len] = '\0';
                    break;
                case 'u':
                    if(long_short_format == 'h') {
                        u_h_integer = va_arg(arguments, unsigned int); 
                        string = integer_arg(&u_h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'l') {
                        u_l_integer = va_arg(arguments, unsigned long int); 
                        string = integer_arg(&u_l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        u_ll_integer = va_arg(arguments, unsigned long long int);
                        string = integer_arg(&u_ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        u_integer = va_arg(arguments, unsigned int);
                        string = integer_arg(&u_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'x':
                    if(long_short_format == 'h') {
                        u_h_integer = va_arg(arguments, unsigned int);
                        string = integer_arg(&u_h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'l') {
                        u_l_integer = va_arg(arguments, unsigned long int); 
                        string = integer_arg(&u_l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        u_ll_integer = va_arg(arguments, unsigned long long int);
                        string = integer_arg(&u_ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        u_integer = va_arg(arguments, unsigned int);
                        string = integer_arg(&u_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    
                    break;
                case 'X':
                    if(long_short_format == 'h') {
                        u_h_integer = va_arg(arguments, unsigned int); 
                        string = integer_arg(&u_h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'l') {
                        u_l_integer = va_arg(arguments, unsigned long int); 
                        string = integer_arg(&u_l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        u_ll_integer = va_arg(arguments, unsigned long long int);
                        string = integer_arg(&u_ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        u_integer = va_arg(arguments, unsigned int);
                        string = integer_arg(&u_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'p':
                    sharp = 1;

                    if(long_short_format == 'h') {
                        u_h_integer = va_arg(arguments, unsigned int); 
                        string = integer_arg(&u_h_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'l') {
                        u_l_integer = va_arg(arguments, unsigned long int); 
                        string = integer_arg(&u_l_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }
                    else if(long_short_format == 'L') {
                        u_ll_integer = va_arg(arguments, unsigned long long int);
                        string = integer_arg(&u_ll_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    } 
                    else {
                        u_integer = va_arg(arguments, unsigned int);
                        string = integer_arg(&u_integer, long_short_format, plus, precision, precision_flag, sharp, *format);
                    }

                    break;
                case 'n':
                    address = va_arg(arguments, void*);
                    *(int*)address = index_str;
                    string = malloc(1);
                    *string = '\0';
                    break;
                default:
                    not_spec++;
            }
            
            if(!not_spec){
                //Начало вывода
                index_string = s21_strlen(string);
                // printf("%ld\n", index_string);
                if(width < index_string) width = index_string;
                
                //Обработка флага пробела
                if(space && !plus && *format != 'c' && *format != 'u' && *format != 'o' && *format != 'x' && *format != 'X') {
                    index_string--;
                    if(string[index_string] != '-') str[index_str] = ' ';
                    index_str++;
                }
                
                //Проверка на бесконечность
                if((isinf(flt) || isinf(l_flt) || isinf(ll_flt)) && nul_flag)
                    nul_flag--;

                //Обработка знака
                if(nul_flag && !minus && *format != 'c' && *format != 's' && *format != 'n') {
                        index_string--;
                        if(string[index_string] == '-' || string[index_string] == '+'){
                            str[index_str] = string[index_string];
                            index_str++;
                            index_string--;
                            width--;
                        }
                }

                //Сам вывод
                bool b = 0;
                if((!string[index_string] && index_string) && !minus) index_string--;
                while(index_string || width){
                    // printf("%ld %ld\n", index_string, width);
                    if(index_string && (width == index_string || minus || !width)) index_string--;
                    if(width) width--;
                    
                    if((width == index_string || minus) && !b && string[index_string]) str[index_str] = string[index_string];
                    else {
                        if(nul_flag && !minus && *format != 'c' && *format != 's' && *format != 'n') str[index_str] = '0';
                        else str[index_str] = ' ';
                    }
                    index_str++;
                    if(!index_string && minus) b++;
                }
                
                format++;
                free(string);
            }
            else {
                //Вывод спецификатора напрямую, если он не смог вывести переменную
                while(*format != '%')
                    format--;
                
                str[index_str] = *format;
                index_str++;
                format++;
            }
        }
        else {
            //Вывод формата
            str[index_str] = *format;
            index_str++;
            format++;
        }
        
        //Обнуление флагов
        space = 0;
        long_short_format = 0;
        plus = 0;
        minus = 0;
        nul_flag = 0;
        width = 0;
        precision = 0;
        precision_flag = 0;
        not_spec = 0;
        sharp = 0;
    }


    //Освобождение памяти и return
    str[index_str] = '\0';
    va_end(arguments);  
    return s21_strlen(str);
}

void* integer_arg(void* number, const char LS, const bool plus, 
                  size_t prec, const bool pf, const bool sharp, const char format){
    char* head_int_to_char = malloc(sizeof(char));
    char* int_to_char = head_int_to_char;
    char temp_num = 0;
    int sign = 0;
    int mas_size = 1;
    bool zero = 0;

    //Если число ноль
    if(!*(int*)number) {
        zero++;
        if(prec || !pf) {
            mas_size++;
            *int_to_char = '0';
            head_int_to_char = realloc(head_int_to_char, mas_size + 1);
            int_to_char = head_int_to_char + mas_size - 1; 
        }
    }

    //Спецификаторы
    if(format == 'o'){
        if(LS == 'h') {
            while(*(unsigned short int*)number){
                mas_size++;
                temp_num = *(unsigned short int*)number%8 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned short int*)number /= 8;
            }
        }
        else if(LS == 'l') {
            while(*(unsigned long int*)number){
                mas_size++;
                temp_num = *(unsigned long int*)number%8 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned long int*)number /= 8;
            }
        }
        else if(LS == 'L'){
            while(*(unsigned long long int*)number){
                mas_size++;
                temp_num = *(unsigned long long int*)number%8 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned long long int*)number /= 8;
            }
        }
        else {
            //Вывод в массив
            while(*(unsigned int*)number){
                mas_size++;
                temp_num = *(unsigned int*)number%8 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned int*)number /= 8;
            }
        }
    }
    if(format == 'u'){
        if(LS == 'h') {
            while(*(unsigned short int*)number){
                mas_size++;
                temp_num = *(unsigned short int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned short int*)number /= 10;
            }
        }
        else if(LS == 'l') {
            while(*(unsigned long int*)number){
                mas_size++;
                temp_num = *(unsigned long int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned long int*)number /= 10;
            }
        }
        else if(LS == 'L'){
            while(*(unsigned long long int*)number){
                mas_size++;
                temp_num = *(unsigned long long int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned long long int*)number /= 10;
            }
        }
        else {
            //Вывод в массив
            while(*(unsigned int*)number){
                mas_size++;
                temp_num = *(unsigned int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned int*)number /= 10;
            }
        }
    }
    if(format == 'x' || format == 'X' || format == 'p'){
        if(LS == 'h') {
            while(*(unsigned short int*)number){
                mas_size++;
                if(*(unsigned short int*)number%16 < 10) temp_num = *(unsigned short int*)number%16 + '0';
                else if(format == 'x' || format == 'p') temp_num = *(unsigned short int*)number%16 + 'a' - 10;
                else if(format == 'X') temp_num = *(unsigned short int*)number%16 + 'A' - 10;
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned short int*)number /= 16;
            }
        }
        else if(LS == 'l') {
            while(*(unsigned long int*)number){
                mas_size++;
                if(*(unsigned long int*)number%16 < 10) temp_num = *(unsigned long int*)number%16 + '0';
                else if(format == 'x' || format == 'p') temp_num = *(unsigned long int*)number%16 + 'a' - 10;
                else if(format == 'X') temp_num = *(unsigned long int*)number%16 + 'A' - 10;
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned long int*)number /= 16;
            }
        }
        else if(LS == 'L'){
            while(*(unsigned long long int*)number){
                mas_size++;
                if(*(unsigned long long int*)number%16 < 10) temp_num = *(unsigned long long int*)number%16 + '0';
                else if(format == 'x' || format == 'p') temp_num = *(unsigned long long int*)number%16 + 'a' - 10;
                else if(format == 'X') temp_num = *(unsigned long long int*)number%16 + 'A' - 10;
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned long long int*)number /= 16;
            }
        }
        else {
            //Вывод в массив
            while(*(unsigned int*)number){
                mas_size++;
                if(*(unsigned int*)number%16 < 10) temp_num = *(unsigned int*)number%16 + '0';
                else if(format == 'x' || format == 'p') temp_num = *(unsigned int*)number%16 + 'a' - 10;
                else if(format == 'X') temp_num = *(unsigned int*)number%16 + 'A' - 10;
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(unsigned int*)number /= 16;
            }
        }  
    }    
    if(format == 'd' || format == 'i'){
        if(LS == 'h'){
            if(*(short int*)number < 0) {
                *(short int*)number *= -1;
                sign++;
            }
            
            while(*(short int*)number){
                mas_size++;
                temp_num = *(short int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(short int*)number /= 10;
            }
        }
        else if(LS == 'l') {
            if(*(long int*)number < 0) {
                *(long int*)number *= -1;
                sign++;
            }
            
            while(*(long int*)number){
                mas_size++;
                temp_num = *(long int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(long int*)number /= 10;
            }
        }
        else if(LS == 'L'){
            if(*(long long int*)number < 0) {
                *(long long int*)number *= -1;
                sign++;
            }
            
            while(*(long long int*)number){
                mas_size++;
                temp_num = *(long long int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(long long int*)number /= 10;
            }
        }
        else {
            //Знак
            if(*(int*)number < 0) {
                *(int*)number *= -1;
                sign++;
            }

            //Вывод в массив
            while(*(int*)number){
                mas_size++;
                temp_num = *(int*)number%10 + '0';
                *int_to_char = temp_num;
                head_int_to_char = realloc(head_int_to_char, mas_size + 1);
                int_to_char = head_int_to_char + mas_size - 1;
                *(int*)number /= 10;
            }
        }
    }
    
    //Точность
    if(prec > mas_size-1 && pf) {
        prec++;
        while(prec != mas_size) {
            mas_size++;
            *int_to_char = '0';
            head_int_to_char = realloc(head_int_to_char, mas_size + 1);
            int_to_char = head_int_to_char + mas_size - 1;
        }
    } 

    //Решетка
    if(sharp && !zero){
        if(format == 'o'){
            mas_size++;
            *int_to_char = '0';
            head_int_to_char = realloc(head_int_to_char, mas_size + 1);
            int_to_char = head_int_to_char + mas_size - 1;
        }
        
        if(format == 'x' || format == 'X' || format == 'p'){
            mas_size++;
            if(format == 'x' || format == 'p') *int_to_char = 'x';
            else *int_to_char = 'X';
            head_int_to_char = realloc(head_int_to_char, mas_size + 1);
            int_to_char = head_int_to_char + mas_size - 1;
            mas_size++;
            *int_to_char = '0';
            head_int_to_char = realloc(head_int_to_char, mas_size + 1);
            int_to_char = head_int_to_char + mas_size - 1;
        }       
    }

    //Вывод знака в массив
    if((sign || plus) && format != 'o' && format != 'u'){
        mas_size++;
        if(sign)*int_to_char = '-';
        else *int_to_char = '+';
        head_int_to_char = realloc(head_int_to_char, mas_size + 1);
        int_to_char = head_int_to_char + mas_size - 1;
    }

    //Конец строки и вывод
    *int_to_char = '\0';
    return head_int_to_char;
}

void* float_e_arg(void* number, const char LS, const bool plus, 
                size_t prec, const bool pf, const bool sharp, const char format){
    char* head_float_to_char = malloc(sizeof(char));
    char* float_to_char = head_float_to_char;
    int index_e = 0;
    char temp_index_e = 0;
    float f_mantis;
    double lf_mantis;
    long double llf_mantis;
    char* head_mantis_str = malloc(sizeof(char) * (prec + 1));
    char* mantis_str = head_mantis_str;
    size_t null_num = 0;
    size_t mas_size = 1;
    bool sign_e = 0;
    bool sign_num = 0;


    if(LS == 'l') {
        if(*(double*)number < 0) {
            *(double*)number *= -1;
            sign_num++;   
        }

        if(isinf(*(double*)number)) {
            free(head_float_to_char);
            free(head_mantis_str);
            head_float_to_char = infinity(plus, sign_num, format);
            return head_float_to_char;
        }

        if(floor(*(double*)number) == 0){
            sign_e = 1;
            while(floor(*(double*)number) == 0){
                *(double*)number *= 10;
                index_e++;
            }
        }
        else {
            while(floor(*(double*)number) != 0){
                *(double*)number /= 10;
                index_e++;
            }
            *(double*)number *= 10;
            index_e--;
        }
        
        lf_mantis = *(double*)number - floor(*(double*)number);
        int num = 0;
        for(int i = 0; i < prec; i++){
            lf_mantis *= 10;
            num = (int)lf_mantis;
            *mantis_str = num + '0';
            lf_mantis -= num;
            mantis_str++;
        }
        *mantis_str = '\0';
    }
    else if(LS == 'L') {
        if(*(long double*)number < 0) {
            *(long double*)number *= -1;
            sign_num++;   
        }

        if(isinf(*(long double*)number)) {
            free(head_float_to_char);
            free(head_mantis_str);
            head_float_to_char = infinity(plus, sign_num, format);
            return head_float_to_char;
        }

        if(floor(*(long double*)number) == 0){
            sign_e = 1;
            while(floor(*(long double*)number) == 0){
                *(long double*)number *= 10;
                index_e++;
            }
        }
        else {
            while(floor(*(long double*)number) != 0){
                *(long double*)number /= 10;
                index_e++;
            }
            *(long double*)number *= 10;
            index_e--;
        }
        
        llf_mantis = *(long double*)number - floor(*(long double*)number);
        int num = 0;
        for(int i = 0; i < prec; i++){
            llf_mantis *= 10;
            num = (int)llf_mantis;
            *mantis_str = num + '0';
            llf_mantis -= num;
            mantis_str++;
        }
        *mantis_str = '\0';
    }
    else {
        //Знак
        if(*(float*)number < 0) {
            *(float*)number *= -1;
            sign_num++;   
        }

        if(isinf(*(float*)number)) {
            free(head_float_to_char);
            free(head_mantis_str);
            head_float_to_char = infinity(plus, sign_num, format);
            return head_float_to_char;
        }

        //Приводим число к нужному виду
        if(floor(*(float*)number) == 0){
            sign_e = 1;
            while(floor(*(float*)number) == 0){
                *(float*)number *= 10;
                index_e++;
            }
        }
        else {
            while(floor(*(float*)number) != 0){
                *(float*)number /= 10;
                index_e++;
            }
            *(float*)number *= 10;
            index_e--;
        }
        
        //Считаем мантису
        f_mantis = *(float*)number - floor(*(float*)number);
        int num = 0;
        for(int i = 0; i < prec; i++){
            f_mantis *= 10;
            num = (int)f_mantis;
            *mantis_str = num + '0';
            f_mantis -= num;
            mantis_str++;
        }
        *mantis_str = '\0';
    }

    //Вывод степени
    for(int i = 0; i < 2 || index_e; i++){
        mas_size++;
        *float_to_char = index_e%10 + '0';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
        index_e /= 10;     
    }

    //Вывод знака
    if(sign_e){
        mas_size++;
        *float_to_char = '-';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }
    else{
        mas_size++;
        *float_to_char = '+';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }
    
    //Вывод е
    mas_size++;
    if(format == 'e' || format == 'g') *float_to_char = 'e';
    else *float_to_char = 'E';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;
    
    //Вывод мантисы
    if(format == 'g' && !sharp){
        mantis_str--;
        for(int i = s21_strlen(head_mantis_str); i > 1 && *mantis_str == '0'; i--){
            mantis_str--;
            prec--;
        }
        if(*mantis_str == '0') {
            free(head_mantis_str);
            mantis_str = NULL;
        }
        else mantis_str++;
    }

    while(prec && mantis_str != NULL){
        prec--;
        mantis_str--;
        mas_size++;
        *float_to_char = *mantis_str;
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }        
    if(mantis_str != NULL) free(head_mantis_str);

    //Вывод нулей
    while(null_num){
        mas_size++;
        *float_to_char = '0';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
        null_num--;
    }

    //Вывод точки
    float_to_char--;
    if(*float_to_char != 'e' && *float_to_char != 'E' && *float_to_char != 'g' && *float_to_char != 'G'){
        float_to_char++;
        mas_size++;
        *float_to_char = '.';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }
    else float_to_char++;

    //Вывод целого числа
    mas_size++;
    if(LS == 'l') *float_to_char = floor(*(double*)number) + '0';
    else if(LS == 'L') *float_to_char = floor(*(long double*)number) + '0';
    else *float_to_char = floor(*(float*)number) + '0';
    head_float_to_char = realloc(head_float_to_char, mas_size + 1);
    float_to_char = head_float_to_char + mas_size - 1;

    if(sign_num || plus){
        mas_size++;
        if(sign_num)*float_to_char = '-';
        else *float_to_char = '+';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }

    //Конец строки и вывод
    *float_to_char = '\0';
    return head_float_to_char;
}

void* float_f_arg(void* number, const char LS, const bool plus, 
                  size_t prec, const bool pf, const bool sharp, const char format){
    char* head_float_to_char = malloc(sizeof(char));
    char* float_to_char = head_float_to_char;
    int temp_num;
    float f_mantis;
    double lf_mantis;
    long double llf_mantis;
    char* head_mantis_str = malloc(sizeof(char) * (prec + 1));
    char* mantis_str = head_mantis_str;
    int64_t temp_mantis;
    size_t null_num = 0;
    size_t mas_size = 1;
    size_t prec_copy = prec;
    bool sign = 0;

    if(LS == 'l') {
        if(*(double*)number < 0) {
            *(double*)number *= -1;
            sign++;   
        }

        if(isinf(*(double*)number)) {
            free(head_float_to_char);
            free(head_mantis_str);
            head_float_to_char = infinity(plus, sign, 'e');
            return head_float_to_char;
        }
        
        f_mantis = *(double*)number - floor(*(float*)number);
        int num = 0;
        for(int i = 0; i < prec; i++){
            f_mantis *= 10;
            num = (int)f_mantis;
            *mantis_str = num + '0';
            f_mantis -= num;
            mantis_str++;
        }
        *mantis_str = '\0';
    }
    else if(LS == 'L'){
        if(*(long double*)number < 0) {
            *(long double*)number *= -1;
            sign++;   
        }

        if(isinf(*(long double*)number)) {
            free(head_float_to_char);
            free(head_mantis_str);
            head_float_to_char = infinity(plus, sign, 'e');
            return head_float_to_char;
        }
        
        f_mantis = *(long double*)number - floor(*(long double*)number);
        int num = 0;
        for(int i = 0; i < prec; i++){
            f_mantis *= 10;
            num = (int)f_mantis;
            *mantis_str = num + '0';
            f_mantis -= num;
            mantis_str++;
        }
        *mantis_str = '\0';
    }
    else {
        //Знак
        if(*(float*)number < 0) {
            *(float*)number *= -1;
            sign++;   
        }

        //Проверка на бесконечность
        if(isinf(*(float*)number)) {
            free(head_float_to_char);
            free(head_mantis_str);
            head_float_to_char = infinity(plus, sign, 'e');
            return head_float_to_char;
        }
        
        //Считаем мантису
        f_mantis = *(float*)number - floor(*(float*)number);
        int num = 0;
        for(int i = 0; i < prec; i++){
            f_mantis *= 10;
            num = (int)f_mantis;
            *mantis_str = num + '0';
            f_mantis -= num;
            mantis_str++;
        }
        *mantis_str = '\0';
    }
    
    //Вывод мантисы
    if(format == 'g' && !sharp){
        mantis_str--;
        for(int i = s21_strlen(head_mantis_str); i > 1 && *mantis_str == '0'; i--){
            mantis_str--;
            prec--;
        }
        if(*mantis_str == '0') {
            free(head_mantis_str);
            mantis_str = NULL;
        }
        else mantis_str++;
    }

    while(prec && mantis_str != NULL){
        prec--;
        mantis_str--;
        mas_size++;
        *float_to_char = *mantis_str;
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }        
    if(mantis_str != NULL) free(head_mantis_str);

    //Вывод нулей
    while(null_num){
        mas_size++;
        *float_to_char = '0';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
        null_num--;
    }

    //Вывод точки
    if(format == 'g' && prec_copy && mantis_str == NULL) prec_copy = 0;

    if(prec_copy || sharp){
        mas_size++;
        *float_to_char = '.';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }

    //Вывод целого числа
    if(LS == 'l'){
        do{
            *(double*)number /= 10;
            temp_num = (*(double*)number - floor(*(double*)number)) * 10;
            mas_size++;
            *float_to_char = temp_num + '0';
            head_float_to_char = realloc(head_float_to_char, mas_size + 1);
            float_to_char = head_float_to_char + mas_size - 1;
        }
        while(floor(*(double*)number));
    }
    else if(LS == 'L'){
        do{
            *(long double*)number /= 10;
            temp_num = (*(long double*)number - floor(*(long double*)number)) * 10;
            mas_size++;
            *float_to_char = temp_num + '0';
            head_float_to_char = realloc(head_float_to_char, mas_size + 1);
            float_to_char = head_float_to_char + mas_size - 1;
        }
        while(floor(*(long double*)number));
    }
    else{
        do{
            *(float*)number /= 10;
            temp_num = (*(float*)number - floor(*(float*)number)) * 10;
            mas_size++;
            *float_to_char = temp_num + '0';
            head_float_to_char = realloc(head_float_to_char, mas_size + 1);
            float_to_char = head_float_to_char + mas_size - 1;
        }
        while(floor(*(float*)number));
    }

    if(sign || plus){
        mas_size++;
        if(sign)*float_to_char = '-';
        else *float_to_char = '+';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }

    //Конец строки и вывод
    *float_to_char = '\0';
    return head_float_to_char;
}

void* float_g_arg(void* number, const char LS, const bool plus, 
                  size_t prec, const bool pf, const bool sharp, const char format){
    char* float_to_char;
    size_t mas_size = 1;
    size_t index_e = 0;
    bool sign = 0;


    switch (LS){
        case 'l':
            if(*(double*)number < 0){
                sign++;
                *(double*)number *= -1;
            }

            double l_copy_number = *(double*)number;
            while(1){
                if(floor(*(double*)number) != 0){
                    if(floor(l_copy_number) == 0) break;
                    l_copy_number /= 10;
                }
                else {
                    if(floor(l_copy_number) != 0) break;
                    l_copy_number *= 10;
                }
                index_e++;
            }

            if(sign) *(double*)number *= -1;
            break;
        case 'L':
            if(*(long double*)number < 0){
                sign++;
                *(long double*)number *= -1;
            }

            long double ll_copy_number = *(long double*)number;
            while(1){
                if(floor(*(long double*)number) != 0){
                    if(floor(ll_copy_number) == 0) break;
                    ll_copy_number /= 10;
                }
                else {
                    if(floor(ll_copy_number) != 0) break;
                    ll_copy_number *= 10;
                }
                index_e++;
            }

            if(sign) *(long double*)number *= -1;
            break;
        default:
            //Знак
            if(*(float*)number < 0){
                sign++;
                *(float*)number *= -1; //Если не сделать это, то цикл ниже не будет работать
            }

            //Оценка разряда числа
            float copy_number = *(float*)number;
            while(1){
                if(floor(*(float*)number) != 0){
                    if(floor(copy_number) == 0) break;
                    copy_number /= 10;
                }
                else {
                    if(floor(copy_number) != 0) break;
                    copy_number *= 10;
                }
                index_e++;
            }

            //Возращение знака
            if(sign) *(float*)number *= -1;
            break;
    } 

    //Выбор работы алгоритма
    if(prec < index_e){
        prec = 5;
        float_to_char = float_e_arg(number, LS, plus, prec, pf, sharp, format);
    }
    else{
        if(!pf) prec = 6 - index_e;
        else prec--;
        float_to_char = float_f_arg(number, LS, plus, prec, pf, sharp, 'g');
    }
    
    return float_to_char;
}

void* infinity(const bool plus, const bool sign, const char format){
    char* head_float_to_char = malloc(sizeof(char));
    char* float_to_char = head_float_to_char;
    size_t mas_size = 1;

    //Печатка inf
    for(int i = 0; i < 3; i++){
        mas_size++;
        switch (i){
            case 0:
                if(format == 'e') *float_to_char = 'f';
                if(format == 'E') *float_to_char = 'F';
                break;
            case 1:
                if(format == 'e') *float_to_char = 'n';
                if(format == 'E') *float_to_char = 'N';
                break;
            case 2:
                if(format == 'e') *float_to_char = 'i';
                if(format == 'E') *float_to_char = 'I';
                break;
        }
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }

    //Знак
    if(sign || plus){
        mas_size++;
        if(sign)*float_to_char = '-';
        else *float_to_char = '+';
        head_float_to_char = realloc(head_float_to_char, mas_size + 1);
        float_to_char = head_float_to_char + mas_size - 1;
    }

    *float_to_char = '\0';
    return head_float_to_char;
}