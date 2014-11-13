#include "strategy.h"

State OnePlusLambdaStrategy::operator () (const int lambda, const State & initialState,const int iterations) const{


	int iter=0;
	State* best = new State(initialState);
	while (iter<iterations) {
		State** l = new State* [lambda];
		for(int li =0; li<lambda; ++li){
			l[li]= new State(best);
		}
		for(int li =0; li<lambda; ++li){
			int r1 = (rand() % best->getSize())+1;
			l[li]->mutate(1);
		}
		for(int li =0; li<lambda; ++li){
			if (best->evaluate()>=l[li]->evaluate()){
				delete best;
				best = new State(l[li]);
			}			
		}
		for(int li =0; li<lambda; ++li){
			delete l[li];
		}
		delete l;
		if (best->evaluate()==0){
			return best;
		}
		++iter;
	}
	return best;
}
