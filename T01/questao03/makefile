program_NAME := q3

.PHONY: all clean

all: $(program_NAME) clean

$(program_NAME): src/io.o src/array.o src/main.o
	g++ -o $(program_NAME) src/io.o src/array.o src/main.o

io.o: src/io.c include/io.h
	g++ -c src/io.c

array.o: src/array.c include/array.h
	g++ -c src/array.c

main.o: src/main.c include/array.h include/io.h
	g++ -c src/main.c

clean:
	rm -rf src/*.o

run:
	./$(program_NAME)
