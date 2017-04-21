program_NAME := q01

.PHONY: $(program_NAME) clean

$(program_NAME):
	gcc $(CFLAGS) -o $(program_NAME) main.c

clean:
	rm -f $(program_NAME)
	rm -f output.txt

run:
	./$(program_NAME)
