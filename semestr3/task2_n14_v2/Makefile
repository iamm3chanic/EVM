m: CFunctions.o Main.o Makefile
	wg++ -o m CFunctions.o Main.o
CFunctions.o: CFunctions.cpp INode.h Makefile
	wg++ -c -g CFunctions.cpp
Main.o: Main.cpp INode.h Makefile
	wg++ -c -g Main.cpp
clean:
	rm m CFunctions.o Main.o vgcore*
