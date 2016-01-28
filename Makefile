all: debug
debug: Matrix.o SymbolabFormatter.o main.o
	g++ -o debug Matrix.o SymbolabFormatter.o main.o
Matrix.o: Matrix.cpp
	g++ -o Matrix.o -c Matrix.cpp #-W -Wall -ansi -pedantic
SymbolabFormatter.o: SymbolabFormatter.cpp
	g++ -o SymbolabFormatter.o -c SymbolabFormatter.cpp #-W -Wall -ansi -pedantic
main.o: main.cpp
	g++ -o main.o -c main.cpp #-W -Wall -ansi -pedantic
clean:
	rm -rf *.o
mrproper: clean
	rm -rf debug
recompile: mrproper debug
