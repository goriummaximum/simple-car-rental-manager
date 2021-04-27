all: main.o processCompany.o tui.o
	g++ main.o processCompany.o tui.o -o CarManager

processCompany.o: processCompany.cpp processCompany.h main.h
	g++ -c processCompany.cpp processCompany.h main.h

tui.o: tui.h tui.cpp
	g++ -c tui.h tui.cpp

main.o: main.cpp main.h processCompany.h
	g++ -c main.cpp main.h processCompany.h

clean:
	rm -rf *o CarManager
