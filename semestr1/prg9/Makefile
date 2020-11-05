CC = gcc
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
-Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs \
-Wunused -Wuninitialized -fPIC 


m: main.o sort.o heapify.o read.o check.o Makefile
	$(CC) $(CFLAGS) -o m main.o sort.o heapify.o read.o check.o
main.o: main.c fun.h Makefile
	$(CC) $(CFLAGS) -c -g main.c
sort.o: sort.c fun.h Makefile
	$(CC) $(CFLAGS) -c sort.c
heapify.o: heapify.c fun.h Makefile
	$(CC) $(CFLAGS) -c heapify.c
read.o: read.c fun.h Makefile
	$(CC) $(CFLAGS) -c read.c
check.o: check.c fun.h Makefile
	$(CC) $(CFLAGS) -c check.c
clean:
	rm m *.o vgcore*

