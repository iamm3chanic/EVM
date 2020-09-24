m: CFunctions.o Main.o Makefile
	g++ -o m CFunctions.o Main.o
CFunctions.o: CFunctions.cpp CDynamic.h CList1.h Makefile
	wg++ -c -g CFunctions.cpp
Main.o: Main.cpp CDynamic.h CList1.h Makefile
	wg++ -c -g Main.cpp
clean:
	rm m CFunctions.o Main.o
