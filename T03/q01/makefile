program_NAME := q01

.PHONY: $(program_NAME) clean

$(program_NAME):
	gcc $(CFLAGS) -o $(program_NAME) main.c -pthread

clean:
	rm -f $(program_NAME)

run:
	./$(program_NAME)
