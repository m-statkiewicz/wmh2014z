#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"state.h"
#include"strategy.h"

int main (){
int n = 8;
OnePlusLambdaStrategy strategy;
State* init = new State(n);
init->generateRandomState();
std::cout<< strategy(10,*init,10);

delete init;
return 0;
}
