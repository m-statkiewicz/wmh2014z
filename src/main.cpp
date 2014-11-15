#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"state.h"
#include"strategy.h"
#include"timer.h"

#define VERSION 0.1

int main (int argc, char **argv){


int n = 20;
int lambda = 20;
int iterations = 40;

OnePlusLambdaStrategy strategy;
Timer t;

for (int i=1; i<argc; ++i){
	if (std::string(argv[i])=="-n"){
		std::stringstream str(argv[++i]);
		str>>n;
	}
	if (std::string(argv[i])=="-l"){
		std::stringstream str(argv[++i]);
		str>>lambda;
	}
	if (std::string(argv[i])=="-i"){
		std::stringstream str(argv[++i]);
		str>>iterations;
	}
}


State* init = new State(n);
State* optstate = NULL;
init->generateRandomState();

srand(time(NULL));

std::cout<<"start eval. = "<<init->evaluate()<<std::endl;
t.start();
optstate= new State(strategy(lambda,*init,iterations));
t.stop();
std::cout<<*optstate<<std::endl;
std::cout<<"optimum eval. = "<<optstate->evaluate()<<std::endl;
std::cout<<"delta time = "<<t.deltaToString()<<std::endl<<std::endl;

delete init;
delete optstate;
return 0;
}

