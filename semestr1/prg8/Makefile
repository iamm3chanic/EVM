main: mainosn.o sort.o read.o check.o Makefile
	gcc -o main mainosn.o sort.o read.o check.o
maionosn.o: mainosn.c fun.h Makefile
	gcc -c mainosn.c
sort.o: sort.c fun.h Makefile
	gcc -c sort.c
read.o: read.c fun.h Makefile
	gcc -c read.c
check.o: check.c fun.h Makefile
	gcc -c check.c	
clean:
	rm main mainosn.o sort.o read.o check.o