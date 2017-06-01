.PHONY: lib a clean 

lib: src/libseno.o
	ar cr lib/libseno.a src/libseno.o

libseno.o: src/libseno.c include/libseno.h
	gcc $(CFLAGS) -c src/libseno.c

a: src/main.o
	gcc $(CFLAGS) -o a src/main.o -L./lib/ -lseno -lm

main.o: src/main.c
	gcc ($CFLAGS) -c src/main.c


clean:
	rm -f src/*.o
