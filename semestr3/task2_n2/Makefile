CC = g++
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fno-elide-constructors \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC


m: main.o Makefile
	$(CC) $(CFLAGS) -o m main.o 
main.o: main.cpp Makefile
	$(CC) $(CFLAGS) -c -g main.cpp
clean:
	rm m *.o vgcore*

