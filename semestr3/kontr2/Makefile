m: CFunctions.o Main.o Makefile
	g++ -o m CFunctions.o Main.o
CFunctions.o: CFunctions.cpp CVektor.h Makefile
	wg++ -c -g CFunctions.cpp
Main.o: Main.cpp CVektor.h Makefile
	wg++ -c -g Main.cpp
clean:
	rm m CFunctions.o Main.o
