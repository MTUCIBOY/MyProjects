EXECUTABLE = test
OPEN = open
FLAGS = -Wall -Werror -Wextra
LIBRARY_FLAGS=ar rc

SOURCES=$(wildcard func/s21_*.c)
SOURCES_OBJECTS=$(patsubst %.c, %.o, $(SOURCES));

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

s21_math.a: clean $(SOURCES_OBJECTS)
	@$(LIBRARY_FLAGS) s21_math.a $(SOURCES_OBJECTS) 
	@ranlib s21_math.a

test: clean
	@gcc $(FLAGS) $(SOURCES) tests/*.c $(TESTFLAGS) -o $(EXECUTABLE)
	@./$(EXECUTABLE)

gcov_report: clean add_coverage test
	@gcc $(FLAGS) tests/*.c $(SOURCES) $(TESTFLAGS) -o $(EXECUTABLE) --coverage
	@./$(EXECUTABLE)
	@rm -rf test-test* test-eq* test-is* equal_size* is_* test_*
	@lcov -t "tests" -o tests.info -c -d .
	@genhtml -o report tests.info
	$(OPEN) report/index.html

add_coverage:
	$(eval COVERAGE += --coverage)

clean:
	@rm -rf $(EXECUTABLE)
	@rm -rf s21_*.o
	@rm -rf ./report
	@rm -rf func/*.o
	@rm -rf *.gcno *.gcda *.gcov *.info
	@rm -rf s21_math.a
	@rm -rf s21_test
	@rm -rf RESULT_VALGRIND.txt
	@rm -rf test

style:
	@clang-format -style=google -i func/*.c *.h
	@clang-format -style=google -i tests/*.c tests/*.h

mini_verter:
	cd ../materials/build && sh run.sh

check_style:
	clang-format -n --style=Google func/* tests/* s21_math.h

leaks: test
	valgrind --leak-check=full --log-file=RESULT_VALGRIND.txt ./test; cat RESULT_VALGRIND.txt| grep "ERROR SUMMARY:"
