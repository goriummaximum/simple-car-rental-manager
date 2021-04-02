all: main.o processCompany.o
	g++ main.o processCompany.o -o CarManager

processCompany.o: processCompany.cpp processCompany.h main.h
	g++ -c processCompany.cpp processCompany.h main.h

main.o: main.cpp main.h processCompany.h
	g++ -c main.cpp main.h processCompany.h

clean:
	rm -rf *o CarManager
