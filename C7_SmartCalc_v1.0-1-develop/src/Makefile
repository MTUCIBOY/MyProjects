EXECUTABLE = s21_test
OPEN = open
FLAGS = -Wall -Werror -Wextra
LIBRARY_FLAGS=ar rc
BIBLIO = s21_calc.a
TESTPATH = Back_tests/*.c
TAR_FILE = s21_calc.tar

SOURCES=$(wildcard Back/*.c)
SOURCES_OBJECTS=$(patsubst Back/%.c, obj/%.o, $(SOURCES))

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

all: clean dist dvi gcov_report install install_credit install_deposit

$(BIBLIO): $(SOURCES_OBJECTS)
	@$(LIBRARY_FLAGS) $(BIBLIO) $(SOURCES_OBJECTS) 
	@ranlib $(BIBLIO)

obj/%.o: Back/%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@

test: $(BIBLIO)
	@gcc $(FLAGS) $(TESTPATH) $(TESTFLAGS) -L. $(BIBLIO) -o $(EXECUTABLE)
	@./$(EXECUTABLE)

gcov_report: 
	@gcc $(FLAGS) $(TESTPATH) $(SOURCES) $(TESTFLAGS) -o $(EXECUTABLE) --coverage
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
	@rm -rf build/
	@rm -rf build_credit/
	@rm -rf build_deposit/
	@rm -rf $(TAR_FILE)
	@rm -rf docs

style:
	@clang-format -style=google -i Back/* Back_tests/* Front/*.h Front/*.cpp Credit_Calc/*.h Credit_Calc/*.cpp Credit_Calc/*.c Deposit_Calc/*.h Deposit_Calc/*.cpp Deposit_Calc/*.c

mini_verter:
	cd ../materials/build && sh run.sh

check_style:
	@clang-format -style=google -n Back/* Back_tests/* Front/*.h Front/*.cpp Credit_Calc/*.h Credit_Calc/*.cpp Credit_Calc/*.c Deposit_Calc/*.h Deposit_Calc/*.cpp Deposit_Calc/*.c

leaks: $(BIBLIO)
	@gcc $(FLAGS) $(TESTPATH) $(TESTFLAGS) -L. $(BIBLIO) -o $(EXECUTABLE)
	valgrind --leak-check=full --log-file=RESULT_VALGRIND.txt ./$(EXECUTABLE); cat RESULT_VALGRIND.txt| grep "ERROR SUMMARY:"

main: $(BIBLIO)
	gcc main.c -L. $(BIBLIO) -o main.out -lm
	./main.out

debug: $(BIBLIO)
	gcc main.c -L. Back/*.c -g -o main.out -lm
	gdb ./main.out

install:
	mkdir -p build
	cd build && cmake ../Front && $(MAKE) all

install_credit:
	mkdir -p build_credit
	cd build_credit && cmake ../Credit_Calc && $(MAKE) all

install_deposit:
	mkdir -p build_deposit
	cd build_deposit && cmake ../Deposit_Calc && $(MAKE) all

uninstall:
	rm -rf build

dist: 
	tar cvf $(TAR_FILE) .
	tar tvf $(TAR_FILE)

dvi:
	doxygen Doxyfile
	open docs/html/index.html
