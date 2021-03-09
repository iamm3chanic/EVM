CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fno-elide-constructors\
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

prog: main1.o fun.o malloc.o Makefile
	$(CC) $(CFLAGS) -o prog main1.o fun.o malloc.o
main1.o: main1.cpp class.h Makefile
	$(CC) $(CFLAGS) -c -g main1.cpp
fun.o: fun.cpp class.h Makefile
	$(CC) $(CFLAGS) -c -g fun.cpp
clean:
	rm prog *.o out*
