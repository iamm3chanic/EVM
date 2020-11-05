CC = gcc
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
-Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs \
-Wunused -Wuninitialized -fPIC 


m: main.o fun.o Makefile
	$(CC) $(CFLAGS) -o m main.o fun.o
main.o: main.c fun.h Makefile
	$(CC) $(CFLAGS) -c -g main.c
fun.o: fun.c fun.h Makefile
	$(CC) $(CFLAGS) -c -g fun.c
clean:
	rm m main.o fun.o
