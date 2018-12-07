CC = clang++

all: main.o dynamic_bitset.o
	$(CC) main.o dynamic_bitset.o -o main_executable

main.o: main.cpp
	$(CC) -c main.cpp

dynamic_bitset.o: dynamic_bitset.cpp
	$(CC) -c dynamic_bitset.cpp

clean:
	rm *.o main_executable