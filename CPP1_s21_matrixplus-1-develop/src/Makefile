COMPILER = g++
EXTENSION = cpp
FLAGS = -Wall -Werror -Wextra
BIBLIO = s21_matrix_oop.a

SOURCES=$(wildcard *.$(EXTENSION))
SOURCES_OBJECTS=$(patsubst %.$(EXTENSION), obj/%.o, $(SOURCES))

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


$(BIBLIO): $(SOURCES_OBJECTS)
	ar rc $(BIBLIO) $(SOURCES_OBJECTS) 
	ranlib $(BIBLIO)

obj/%.o: %.$(EXTENSION)
	mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj
	rm -rf *.out
	rm -rf *.a
	rm -rf TEST

style:
	clang-format -i --style=Google *.cpp *.h

check_style:
	clang-format -n --style=Google *.cpp *.h

test: $(BIBLIO)
	$(COMPILER) tests/*.cpp -L. $(BIBLIO) -o TEST -lgtest -pthread
	./TEST

main: $(BIBLIO)
	$(COMPILER) main.$(EXTENSION) -L. $(BIBLIO) -o main.out -lm
	./main.out

leaks: $(BIBLIO)
	$(COMPILER) main.$(EXTENSION) -L. $(BIBLIO) -o main.out -lm
	valgrind --leak-check=full ./main.out