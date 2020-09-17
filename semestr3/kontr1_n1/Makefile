prog: CFunctions.o main_test.o Makefile
	g++ -o prog CFunctions.o main_test.o
CFunctions.o: CFunctions.cpp CClass.h Makefile
	g++ -c CFunctions.cpp
main_test.o: main_test.cpp CClass.h Makefile
	g++ -c main_test.cpp
clean:
	rm prog CFunctions.o main_test.o
