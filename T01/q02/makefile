program_NAME := $(notdir $(shell pwd))

.PHONY: $(program_NAME) clean

$(program_NAME):
	gcc $(CFLAGS) -o $(program_NAME) main.c

clean:
	rm -f $(program_NAME)

run:
	./$(program_NAME)
