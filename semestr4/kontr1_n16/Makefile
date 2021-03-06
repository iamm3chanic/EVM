CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fno-elide-constructors \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

t: fun.o Main.o Makefile
	$(CC) $(CFLAGS) -o t fun.o Main.o
fun.o: fun.cpp fun.h Makefile
	$(CC) $(CFLAGS) -c -g -O2 fun.cpp
Main.o: Main.cpp fun.h Makefile
	$(CC) $(CFLAGS) -c -g -O2 Main.cpp
clean:
	rm -f t fun.o Main.o out*.txt
