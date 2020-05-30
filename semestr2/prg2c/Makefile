prog: main.o search.o Makefile
	gcc -o prog main.o search.o
main.o: main.c fun.h Makefile
	gcc -c main.c
search.o: search.c fun.h Makefile
	gcc -c search.c
clean:
	rm prog main.o search.o