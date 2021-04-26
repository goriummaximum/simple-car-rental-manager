all: main.o processCompany.o gui.o
	g++ main.o processCompany.o gui.o -o CarManager

processCompany.o: processCompany.cpp processCompany.h main.h
	g++ -c processCompany.cpp processCompany.h main.h

gui.o: gui.h gui.cpp
	g++ -c gui.h gui.cpp

main.o: main.cpp main.h processCompany.h
	g++ -c main.cpp main.h processCompany.h

clean:
	rm -rf *o CarManager
