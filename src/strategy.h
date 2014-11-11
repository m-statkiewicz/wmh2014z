/*
 * strategy.h
 */

#ifndef STRATEGY
#define STRATEGY

#include<cstdlib>
#include<iostream>

#include"state.h"


class OnePlusLambdaStrategy
{
public:
	State operator () (const int lambda, const State & initialState,const int iterations) const;
};

#endif
