all: clean nqueens install

install:
	mkdir ../target
	mv *.o ../target
	mv nqueens ../target

clean:
	rm -Rf ../target
	rm -rf *.o 

nqueens: main.o state.o strategy.o timer.o
	g++ main.o state.o strategy.o timer.o -o nqueens

main.o: 
	g++ -c -g main.cpp

state.o: state.cpp state.h 
	g++ -c -g state.cpp 

strategy.o: strategy.cpp strategy.h state.h 
	g++ -c -g strategy.cpp

timer.o: timer.cpp timer.h
	g++ -c -g timer.cpp
