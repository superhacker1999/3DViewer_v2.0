CC=gcc
FLAGS=-Wall -Wextra -lstdc++ -std=c++17 -fopenmp
SRC=test.cc model/subsystems/parser.cc model/facade/model.cc controller/controller.cc model/subsystems/shifter.cc model/subsystems/spinner.cc
CLANG_SRC=controller/* model/facade/* model/helpers/* model/subsystems/* view/*.cpp view/*.h view/interface/*.cpp view/interface/*.h view/render/*.cpp view/render/*.h


clean:
	rm -rf tests*

build: clean
	$(CC) $(FLAGS) $(SRC) -o tests

test: build
	./tests

leak: build
	leaks -atExit -- tests

clang_check:
	clang-format -n $(CLANG_SRC)