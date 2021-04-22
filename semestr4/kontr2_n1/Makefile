CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

prog: main1.o fun.o Makefile
	$(CC) $(CFLAGS) -o prog main1.o fun.o
fun.o: fun.cpp class.h Makefile
	$(CC) $(CFLAGS) -c -g -O2 fun.cpp
main1.o: main1.cpp class.h Makefile
	$(CC) $(CFLAGS) -c -g -O2 main1.cpp
clean:
	rm -f prog main1.o fun.o vgcore* out*.txt