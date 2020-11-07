CC = g++
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations \
-Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs \
-Wunused -Wuninitialized -fPIC 


m: CFunctions.o main_test.o Makefile
	$(CC) $(CFLAGS) -o m CFunctions.o main_test.o
CFunctions.o: CFunctions.cpp CClass.h Makefile
	$(CC) $(CFLAGS) -c -g CFunctions.cpp
main_test.o: main_test.cpp CClass.h Makefile
	$(CC) $(CFLAGS) -c -g main_test.cpp
clean:
	rm m *.o
