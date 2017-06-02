.PHONY: static dynamic lib/libseno.a lib/libseno.so obj/main.o obj/libseno.o clean

static: lib/libseno.a obj/main.o
	gcc $(CFLAGS) -o bin/static obj/main.o -L./lib/ -lseno -lm

dynamic: LIBFLAG = -fPIC
dynamic: lib/libseno.so obj/main.o
	gcc $(CFLAGS) -o bin/dynamic obj/main.o -L./lib/ -lseno -Wl,-rpath,./lib/ -lm

libdl: LIBFLAG = -fPIC
libdl: lib/libseno.so obj/libdl_main.o
	gcc -o bin/libdl obj/libdl_main.o -Wl,-rpath,./lib/ -ldl -lm

lib/libseno.a: obj/libseno.o
	ar cr $(CFLAGS) lib/libseno.a obj/libseno.o

lib/libseno.so: obj/libseno.o
	ld -shared -soname lib/libseno.so -o lib/libseno.so -lc obj/libseno.o

obj/libseno.o: src/libseno.c include/libseno.h
	gcc $(CFLAGS) $(LIBFLAG) -o obj/libseno.o -c src/libseno.c

obj/main.o: src/main.c
	gcc $(CFLAGS) -o obj/main.o -c src/main.c

obj/libdl_main.o: src/libdl_main.c
	gcc $(CFLAGS) -o obj/libdl_main.o -c src/libdl_main.c

clean:
	rm -f lib/* bin/* obj/*
