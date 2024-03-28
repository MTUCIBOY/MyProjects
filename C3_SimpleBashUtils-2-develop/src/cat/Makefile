FLAGS=-Wall -Werror -Wextra

all: clean s21_cat

s21_cat: main.o flags_cat.o empty_cat.o
	gcc $(FLAGS) empty_cat.o main.o flags_cat.o -o s21_cat

main.o: 
	gcc $(FLAGS) -c main.c

flags_cat.o: 
	gcc $(FLAGS) -c flags_cat.c

empty_cat.o: 
	gcc $(FLAGS) -c empty_cat.c

clean:
	rm -rf *.o main
	rm -rf s21_cat
