CC = g++
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

m: Main.o Makefile
	$(CC) $(CFLAGS) -o m Main.o
Main.o: Main.cpp CList2.h Makefile
	$(CC) $(CFLAGS) -c -g -std=c++11 Main.cpp
clean:
	rm m *.o vgcore*
