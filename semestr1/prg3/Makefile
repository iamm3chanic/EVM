main: mainosn.o fun.o Makefile
	gcc -o main mainosn.o fun.o
maionosn.o: mainosn.c fun.h Makefile
	gcc -c mainosn.c
fun.o: fun.c fun.h Makefile
	gcc -c fun.c
clean:
	rm main mainosn.o fun.o