CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fno-elide-constructors \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

prg: fun.o Main.o Makefile
	$(CC) $(CFLAGS) -o m fun.o Main.o
fun.o: fun.cpp CVector.h Makefile
	$(CC) $(CFLAGS) -c -g -O2 fun.cpp
Main.o: Main.cpp CVector.h Makefile
	$(CC) $(CFLAGS) -c -g -O2 Main.cpp
clean:
	rm -f prg fun.o Main.o vgcore* out*.txt
