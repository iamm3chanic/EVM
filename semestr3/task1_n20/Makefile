m: CFunctions.o Main.o Makefile
	g++ -o m CFunctions.o Main.o
CFunctions.o: CFunctions.cpp CString.h CList2.h Makefile
	wg++ -c -g -std=c++11 CFunctions.cpp
Main.o: Main.cpp CString.h CList2.h Makefile
	wg++ -c -g -std=c++11 Main.cpp
clean:
	rm m CFunctions.o Main.o vgcore*
