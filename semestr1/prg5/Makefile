main: mainosn.o fun21.o input.o Makefile
	gcc -o main mainosn.o fun21.o input.o
maionosn.o: mainosn.c fun.h Makefile
	gcc -c mainosn.c
fun.o: fun21.c fun.h Makefile
	gcc -c fun21.c
input.o:
	gcc -c input.c Makefile
clean:
	rm main mainosn.o fun21.o input.o