all: clean nqueens install

install:
	mkdir ../target
	mv *.o ../target
	mv nqueens ../target

clean:
	rm -Rf ../target
	rm -rf *.o 

nqueens: main.o state.o strategy.o
	g++ main.o state.o strategy.o -o nqueens

main.o: 
	g++ -c main.cpp

state.o: state.cpp state.h 
	g++ -c state.cpp 

strategy.o: strategy.cpp strategy.h state.h 
	g++ -c strategy.cpp

