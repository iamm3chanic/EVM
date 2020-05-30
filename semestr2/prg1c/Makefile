main: main.o input.o edit1.o Makefile
	gcc -o main main.o input.o edit1.o
main.o: main.c fun.h Makefile
	gcc -c main.c
input.o: input.c fun.h Makefile
	gcc -c input.c
edit1.o: edit1.c fun.h Makefile
	gcc -c edit1.c
clean:
	rm main  main.o input.o edit1.o