FLAGS=-Wall -Werror -Wextra

all: clean s21_grep

s21_grep: main.o  flags_grep.o PAF.o
	gcc $(FLAGS) main.o flags_grep.o PAF.o -o s21_grep

main.o: main.c
	gcc  $(FLAGS) -c main.c

flags_grep.o: flags_grep.c
	gcc  $(FLAGS) -c flags_grep.c 

PAF.o: PAF.c
	gcc  $(FLAGS) -c PAF.c 

clean:
	rm -rf *.o main
	rm -rf s21_grep

