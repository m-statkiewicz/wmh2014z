#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"state.h"
#include"strategy.h"
#include"timer.h"

int main (){

int n = 20;
int lambda = 20;
int iterations = 40;

OnePlusLambdaStrategy strategy;
Timer t;

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
