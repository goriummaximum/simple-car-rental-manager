all: main.o processCompany.o
	g++ main.o processCompany.o -o CarManager

main.o: main.cpp main.h processCompany.h
	g++ -c main.cpp main.h processCompany.h

processCompany.o: processCompany.cpp processCompany.h main.h
	g++ -c processCompany.cpp processCompany.h main.h

clean:
	rm -rf *o CarManager
