#include "state.h"

State::State(int size){
	n=size;
	arrangement = new int[n];
	for (int i = 0; i<n; ++i)
		arrangement[i]=i;
};

State::State(const State * st){
	n=st->n;
	arrangement = new int[n];
	for (int i = 0; i<n; ++i)
		arrangement[i]=st->arrangement[i];	
};


State::State(const State & st){
	n=st.n;
	arrangement = new int[n];
	for (int i = 0; i<n; ++i)
		arrangement[i]=st.arrangement[i];	
};

State::~State(){
	delete arrangement;
}

int State::getSize(){
return n;
}

int State::evaluate(){
	int tmp=0;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (abs(arrangement[i]-arrangement[j])==abs(i-j))
				tmp++;
	return tmp;
};

void State::mutate(int distance){
	int tmp;
	for (int i=0; i<distance; ++i)
	{
		int r1=0,r2=0;
		while (r1==r2) {
			r1 = rand()%n; 	
			r2 = rand()%n;
		}
		tmp = arrangement[r1];
		arrangement[r1]=arrangement[r2];
		arrangement[r2]=tmp;
	}
};

void State::generateRandomState(){
	int r1,dist;
	dist= rand()%n;
	r1= rand()%n;
	for (int i=0; i<r1; ++i)
		mutate(dist);
};

std::ostream& operator<< (std::ostream &os, const State & s){
	os<<"size="<<s.n<<"\n";	
	for (int i=0; i<s.n; ++i)
	{
		for (int j=0; j<s.arrangement[i]; ++j)
			os<<" ";
	os<<"H\t"<<i<<"\\"<<s.arrangement[i]<<"\n";
	}
	return os;
};


