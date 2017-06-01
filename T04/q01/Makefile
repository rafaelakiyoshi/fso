.PHONY: static dynamic lib/libseno.a lib/libseno.so obj/main.o obj/libseno.o clean

static: lib/libseno.a obj/main.o
	gcc $(CFLAGS) -o static obj/main.o -L./lib/ -lseno

dynamic: LIBFLAG = -fPIC
dynamic: lib/libseno.so obj/main.o
	gcc $(CFLAGS) -o dynamic obj/main.o -L./lib/ -lseno -Wl,-rpath,./lib/

lib/libseno.a: obj/libseno.o
	ar cr $(CFLAGS) lib/libseno.a obj/libseno.o

lib/libseno.so: src/libseno.c include/libseno.h
	gcc -shared $(LIBFLAG) -o lib/libseno.so -c src/libseno.c

obj/libseno.o: src/libseno.c include/libseno.h
	gcc $(CFLAGS) -o obj/libseno.o -c src/libseno.c

obj/main.o: src/main.c
	gcc $(CFLAGS) -o obj/main.o -c src/main.c

clean:
	rm -f lib/* dynamic static obj/*.o
