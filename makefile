CC = clang++

DEBUG = 0

ifeq ($(DEBUG), 1)
	DEBUG_PARAM = -g
endif

all: main.o dynamic_bitset.o
	$(CC) $(DEBUG_PARAM) -O3 main.o dynamic_bitset.o -o main_executable

main.o: main.cpp
	$(CC) $(DEBUG_PARAM) -O3 -c main.cpp

dynamic_bitset.o: dynamic_bitset.cpp dynamic_bitset.h
	$(CC) $(DEBUG_PARAM) -O3 -c dynamic_bitset.cpp

clean:
	rm *.o main_executable