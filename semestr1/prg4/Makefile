main: mainosn.o fun28.o input.o Makefile
	gcc -o main mainosn.o fun28.o input.o
maionosn.o: mainosn.c fun.h Makefile
	gcc -c mainosn.c
fun.o: fun28.c fun.h Makefile
	gcc -c fun28.c
input.o:
	gcc -c input.c Makefile
clean:
	rm main mainosn.o fun28.o input.o