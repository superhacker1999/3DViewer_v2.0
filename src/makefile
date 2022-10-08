CC=gcc
FLAGS=-Wall -Wextra -lstdc++ -std=c++17 -fopenmp
SRC=test.cc model/subsystems/parser.cc model/facade/model.cc controller/controller.cc model/subsystems/shifter.cc model/subsystems/spinner.cc
clean:
	rm -rf tests*

build: clean
	$(CC) $(FLAGS) $(SRC) -o tests

test: build
	./tests

leak: build
	leaks -atExit -- tests