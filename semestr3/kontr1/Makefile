m: CFunctions.o Main.o Makefile
	g++ -o m CFunctions.o Main.o
CFunctions.o: CFunctions.cpp CVektor.h Makefile
	g++ -c -g CFunctions.cpp
Main.o: Main.cpp CVektor.h Makefile
	g++ -c -g Main.cpp
clean:
	rm m CFunctions.o Main.o
