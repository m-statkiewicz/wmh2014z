#include "strategy.h"

#define SIGMA_CORRECTION 1

State OnePlusLambdaStrategy::operator () (const int lambda, const State & initialState,const int iterations) const{

	const float corr=0.82;
	float sigma=lambda/2;
	int iter=0;
	State* best = new State(initialState);
	int bestScore = best->evaluate();	
	int betterMutationSum=0;	
	while (iter<iterations) {
		State** l = new State* [lambda];
		int dist = (int) (sigma+0.5);
		if (dist<1)
			dist=1;

//		int dist = rand()%lambda+1;
		for(int li =0; li<lambda; ++li){
			l[li]= new State(best);
			l[li]->mutate(dist);
		}
		int lib=0;
		int libScore=l[lib]->evaluate();
		for(int li =0; li<lambda; ++li){
			if (bestScore>l[li]->evaluate()){
				++betterMutationSum;
				int liScore=l[li]->evaluate();
				if (libScore>liScore){
					lib=li;				
					libScore=liScore;
				}
			}
		}
		if (bestScore>libScore){
			delete best;
			best = new State(l[lib]);
			bestScore=libScore;
		}			
		for(int li =0; li<lambda; ++li){
			delete l[li];
		}
		delete l;

		std::cout<<"iter = "<<iter<<std::endl;
		std::cout<<"   sigma = "<<sigma<<std::endl;
		std::cout<<"   dist  = "<<dist<<std::endl;
		std::cout<<"   sum   = "<<betterMutationSum<<std::endl;

		if (iter%SIGMA_CORRECTION==0){
			float q = (float)betterMutationSum/(SIGMA_CORRECTION*lambda);
			betterMutationSum=0;
			std::cout<<"   q     = "<<q<<std::endl;
			if (q>0.2)
				sigma/=corr;
			if (q<0.2)
				sigma*=corr;
		std::cout<<"new sigma = "<<sigma<<std::endl;
		}
		if (bestScore==0){
			return best;
		}	
		++iter;
	}
	return best;
}
