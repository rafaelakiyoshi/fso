program_NAME := q1

.PHONY: all clean

all: $(program_NAME) clean

$(program_NAME): src/io.o src/operations.o src/polygon.o src/main.o
	g++ -o $(program_NAME) src/io.o src/operations.o src/polygon.o src/main.o

io.o: src/io.c include/io.h
	g++ -c src/io.c

operations.o: src/operations.c include/operations.h
	g++ -c src/operations.c

polygon.o: src/polygon.c include/polygon.h
	h++ -c src/polygon.c

main.o: src/main.c include/operations.h include/io.h include/polygon.h
	g++ -c src/main.c

clean:
	rm -rf src/*.o

run:
	./$(program_NAME)
