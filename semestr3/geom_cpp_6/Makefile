m: CFunctions.o Main.o Makefile
	wg++ -o m CFunctions.o Main.o -lX11
CFunctions.o: CFunctions.cpp Classes.h Makefile
	wg++ -c -g CFunctions.cpp -lX11
Main.o: Main.cpp Classes.h Makefile
	wg++ -c -g Main.cpp -lX11
clean:
	rm m CFunctions.o Main.o vgcore*
