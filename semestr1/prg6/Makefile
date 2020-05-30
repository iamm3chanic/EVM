main: mainosn.o fun5.o input.o Makefile
	gcc -o main mainosn.o fun5.o input.o
maionosn.o: mainosn.c fun.h Makefile
	gcc -c mainosn.c
fun.o: fun5.c fun.h Makefile
	gcc -c fun5.c
input.o:
	gcc -c input.c Makefile
clean:
	rm main mainosn.o fun5.o input.o