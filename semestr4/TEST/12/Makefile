CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC -fno-elide-constructors


m: main.o Makefile
	$(CC) $(CFLAGS) -o m main.o
main.o: main.cpp Makefile
	$(CC) $(CFLAGS) -c -g -O2 main.cpp
clean:
	rm -f m *.o vgcore* 
