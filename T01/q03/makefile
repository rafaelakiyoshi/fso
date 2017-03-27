program_NAME := q03

.PHONY: $(program_NAME) clean

$(program_NAME): src/io.o src/array.o src/main.o
	gcc $(CFLAGS) -o $(program_NAME) src/io.o src/array.o src/main.o

io.o: src/io.c include/io.h
	gcc $(CFLAGS) -c src/io.c

array.o: src/array.c include/array.h
	gcc $(CFLAGS) -c src/array.c

main.o: src/main.c include/array.h include/io.h
	gcc $(CFLAGS) -c src/main.c

clean:
	rm -f src/*.o $(program_NAME)

run:
	./$(program_NAME)
