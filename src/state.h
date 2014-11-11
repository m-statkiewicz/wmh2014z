/*
 * state.h
 */

#ifndef STATE
#define STATE

#include<cstdlib>
#include<iostream>

class State {
private:
	int n;	
	int* arrangement;
public:
	State(int size);
	State(const State* st);
	State(const State& st);
	~State();
	int getSize();
	int evaluate();
	void mutate(int distance);
	void generateRandomState();

	friend std::ostream& operator<< (std::ostream &os, const State & s);
};


#endif
