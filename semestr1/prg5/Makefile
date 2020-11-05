CC = gcc
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
-Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs \
-Wunused -Wuninitialized -fPIC 


m: main.o fun21.o input.o Makefile
	$(CC) $(CFLAGS) -o m main.o fun21.o input.o
main.o: main.c fun.h Makefile
	$(CC) $(CFLAGS) -c -g main.c
fun28.o: fun21.c fun.h Makefile
	$(CC) $(CFLAGS) -c -g fun21.c
input.o: input.c fun.h Makefile
	$(CC) $(CFLAGS) -c -g input.c
clean:
	rm m *.o

