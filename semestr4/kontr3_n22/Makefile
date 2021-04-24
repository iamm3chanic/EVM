CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fno-elide-constructors -fopenmp \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

prog: main.o CVector.o Makefile
	$(CC) $(CFLAGS) -o prog main.o CVector.o
main.o: main.cpp CVector.h Makefile
	$(CC) $(CFLAGS) -c -g -std=c++11 main.cpp
CVector.o: CVector.cpp CVector.h Makefile
	$(CC) $(CFLAGS) -c -g -std=c++11 CVector.cpp
clean:
	rm prog *.o file*txt
