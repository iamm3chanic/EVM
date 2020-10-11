t: CFunctions.o Main.o Makefile
	g++ -o t Main.o CFunctions.o
Main.o: Main.cpp CString.h Makefile
	wg++ -c Main.cpp     
CFunctions.o: CFunctions.cpp CString.h Makefile
	wg++ -c CFunctions.cpp     

clean:
	rm t  Main.o CFunctions.o
