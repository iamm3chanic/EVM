prog: Main.o CListFunc.o malloc.o Makefile
	g++ -o prog Main.o CListFunc.o malloc.o
Main.o: Main.cpp CList.h walloc.h Makefile
	g++ -c -std=c++11 -fno-elide-constructors Main.cpp
CListFunc.o: CListFunc.cpp CList.h Makefile
	g++ -c -std=c++11 -fno-elide-constructors CListFunc.cpp
malloc.o: malloc.cpp CList.h walloc.h Makefile
	g++ -c -std=c++11 -fno-elide-constructors malloc.cpp
clean:
	rm prog Main.o CListFunc.o malloc.o
