program_NAME := q1

.PHONY: clean

$(program_NAME): src/io.o src/operations.o src/polygon.o src/main.o
	gcc $(CFLAGS) -o $(program_NAME) src/io.o src/operations.o src/polygon.o src/main.o

io.o: src/io.c include/io.h
	gcc $(CFLAGS) -c src/io.c

operations.o: src/operations.c include/operations.h
	gcc $(CFLAGS) -c src/operations.c

polygon.o: src/polygon.c include/polygon.h
	gcc $(CFLAGS) -c src/polygon.c

main.o: src/main.c include/operations.h include/io.h include/polygon.h
	gcc $(CFLAGS) -c src/main.c

clean:
	rm -f src/*.o $(program_NAME)

run:
	./$(program_NAME)
