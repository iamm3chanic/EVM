main: main.o input1.o edit3.o Makefile

	gcc -o main main.o input1.o edit3.o

main.o: main.c fun.h Makefile

	gcc -c main.c

input1.o: input1.c fun.h Makefile

	gcc -c input1.c

edit3.o: edit3.c fun.h Makefile

	gcc -c edit3.c

clean:

	rm main  main.o input1.o edit3.o