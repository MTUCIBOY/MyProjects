EXECUTABLE = s21_test
OPEN = open
FLAGS = -Wall -Werror -Wextra
LIBRARY_FLAGS=ar rc
BIBLIO = s21_matrix.a

SOURCES=$(wildcard func/*.c)
SOURCES_OBJECTS=$(patsubst func/%.c, obj/%.o, $(SOURCES))

ifeq ($(shell uname), Linux)
    DISTRIBUTION := $(shell cat /etc/*-release 2>/dev/null | grep -i '^ID=' | cut -d'=' -f2)
	ifeq ($(DISTRIBUTION), fedora)
		TESTFLAGS = -lcheck -lsubunit -lm
		OPEN = xdg-open
	else
		TESTFLAGS = -lcheck_pic -lsubunit -lm
	 endif
endif
ifeq ($(shell uname), Darwin)
	TESTFLAGS = -lcheck
endif

all: gcov_report

$(BIBLIO): $(SOURCES_OBJECTS)
	@$(LIBRARY_FLAGS) $(BIBLIO) $(SOURCES_OBJECTS) 
	@ranlib $(BIBLIO)

obj/%.o: func/%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@

test: $(BIBLIO)
	@gcc $(FLAGS) tests.c $(TESTFLAGS) -L. $(BIBLIO) -o $(EXECUTABLE)
	@./$(EXECUTABLE)

gcov_report: 
	@gcc $(FLAGS) tests.c $(SOURCES) $(TESTFLAGS) -o $(EXECUTABLE) --coverage
	@./$(EXECUTABLE)	
	@rm -rf s21_test-test*
	@lcov -t "tests" -o tests.info -c -d .
	@genhtml -o report tests.info
	$(OPEN) report/index.html

clean:
	@rm -rf $(EXECUTABLE)
	@rm -rf ./report
	@rm -rf func/*.o
	@rm -rf *.gcno *.gcda *.gcov *.info
	@rm -rf $(BIBLIO)
	@rm -rf RESULT_VALGRIND.txt
	@rm -rf *.out
	@rm -rf obj/

style:
	@clang-format -style=google -i func/* *.h *.c

mini_verter:
	cd ../materials/build && sh run.sh

check_style:
	clang-format -n --style=Google func/* *.h *.c

leaks: $(BIBLIO)
	@gcc $(FLAGS) tests.c $(TESTFLAGS) -L. $(BIBLIO) -o $(EXECUTABLE)
	valgrind --leak-check=full --log-file=RESULT_VALGRIND.txt ./$(EXECUTABLE); cat RESULT_VALGRIND.txt| grep "ERROR SUMMARY:"

main: $(BIBLIO)
	gcc main.c -L. $(BIBLIO) -o main.out -lm
	./main.out
