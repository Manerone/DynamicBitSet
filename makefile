CC = clang++

DEBUG = 0

PARAMS = -std=c++11 -Wall -I /usr/local/Cellar/boost/1.68.0

ifeq ($(DEBUG), 1)
	PARAMS += -g
else
	PARAMS += -O3
endif

all: main.o dynamic_bitset.o
	$(CC) $(DEBUG_PARAM) $(PARAMS) main.o dynamic_bitset.o -o main_executable

main.o: main.cpp dynamic_bitset.h
	$(CC) $(DEBUG_PARAM) $(PARAMS) -c main.cpp

dynamic_bitset.o: dynamic_bitset.cpp dynamic_bitset.h
	$(CC) $(DEBUG_PARAM) $(PARAMS) -c dynamic_bitset.cpp

clean:
	rm *.o main_executable