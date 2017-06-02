.PHONY: static shared dynamic lib/libseno.a lib/libseno.so obj/main.o obj/libseno.o clean
.SILENT: man

man:
	echo "make static - compile a static version"
	echo ""
	echo "make shared - compile a shared version"
	echo ""
	echo "make dynamic - compile a dynamic loaded version"

static: lib/libseno.a obj/main.o
	gcc $(CFLAGS) -static -o bin/static obj/main.o -L./lib/ -lseno -lm

shared: LIBFLAG = -fPIC
shared: lib/libseno.so obj/main.o
	gcc $(CFLAGS) -o bin/shared obj/main.o -L./lib/ -lseno -Wl,-rpath,./lib/ -lm

dynamic: LIBFLAG = -fPIC
dynamic: lib/libseno.so obj/dynamic_main.o
	gcc -o bin/dynamic obj/dynamic_main.o -Wl,-rpath,./lib/ -ldl -lm

lib/libseno.a: obj/libseno.o
	ar cr $(CFLAGS) lib/libseno.a obj/libseno.o

lib/libseno.so: obj/libseno.o
	ld -shared -soname lib/libseno.so -o lib/libseno.so -lc obj/libseno.o

obj/libseno.o: src/libseno.c include/libseno.h
	gcc $(CFLAGS) $(LIBFLAG) -o obj/libseno.o -c src/libseno.c

obj/main.o: src/main.c
	gcc $(CFLAGS) -o obj/main.o -c src/main.c

obj/dynamic_main.o: src/dynamic_main.c
	gcc $(CFLAGS) -o obj/dynamic_main.o -c src/dynamic_main.c

clean:
	rm -f lib/* bin/* obj/*
