CC=gcc
FLAGS=-Wall -Wextra -lstdc++ -std=c++17 -g
SRC=test.cc model/subsystems/parser.cc model/facade/model.cc
clean:
	rm -rf tests

build: clean
	$(CC) $(FLAGS) $(SRC) -o tests

test: build
	./tests

leak: build
	leaks -atExit -- tests