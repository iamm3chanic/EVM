main: main.o input1.o sort.o edit.o output2.o output1.o Makefile

	gcc -o main main.o input1.o sort.o edit.o output2.o output1.o

main.o: main.c fun.h Makefile

	gcc -c main.c

input1.o: input1.c fun.h Makefile

	gcc -c input1.c
	
sort.o: sort.c fun.h Makefile

	gcc -c sort.c

edit.o: edit.c fun.h Makefile

	gcc -c edit.c

output2.o: output2.c fun.h Makefile

	gcc -c output2.c
	
output1.o: output1.c fun.h Makefile

	gcc -c output1.c

clean:

	rm main  main.o input1.o sort.o edit.o output2.o output1.o