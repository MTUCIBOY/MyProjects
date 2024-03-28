FLAGS=-Wall -Werror -Wextra -std=c11
COVERAGE=

all: clean s21_string.a

deafult: all

s21_string.o: func/*.c sscanf/*.c sprintf/*.c
	gcc $(FLAGS) -c $^

s21_string.a: s21_string.o
	ar cr s21_string.a *.o

clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda s21_test report

test: clean
	gcc $(FLAGS) $(COVERAGE) -o s21_test tests/*.c func/*.c sscanf/*.c sprintf/*.c -lcheck -lm
	./s21_test 

add_coverage:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage test
	./s21_test
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter func/ --filter sscanf/ --filter sprintf/

