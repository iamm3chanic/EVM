main: mainosn.o func.o input.o Makefile
	gcc -o main mainosn.o func.o input.o
maionosn.o: mainosn.c fun.h Makefile
	gcc -c mainosn.c
func.o: func.c fun.h Makefile
	gcc -c func.c
input.o:
	gcc -c input.c Makefile
clean:
	rm main mainosn.o func.o input.o
