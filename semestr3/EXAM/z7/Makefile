CC = gcc
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
-Wold-style-definition -Wbad-function-cast -Wnested-externs \
-Wunused -Wuninitialized -fPIC


m: main.o Makefile
	$(CC) $(CFLAGS) -o m main.o 
main.o: main.c Makefile
	$(CC) $(CFLAGS) -c -g main.c
clean:
	rm m *.o vgcore*

