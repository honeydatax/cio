#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


int rnd(int count,int counts){
	int i=0;
	int r=0;
	int ii=0;
	int max=(16*1024-1);
	r=random() & max;
	counts=counts & max;
	count=count & max;
	i=counts-count;
	ii=max/i;
	i=r/ii;
	i=i+count;
	return i;
}

int getnumber(int ii){
	int i;
	cin>>i;
	cout<<"your number ";
	cout<<i;
	cout<<"  ";
	if(i>ii) cout<<">\n";
	if(i<ii) cout<<"<\n";
	if(i==ii){
		cout<<"=\n";
		exit(0);
	}
	return i;
}



int main(){
	int i=0;
	int ii=200;
	srandom(time(NULL));
	cout<<" gess number from 0 to 100?\n";
	i=rnd(0,100);
	while(ii!=i){
		ii=getnumber(i);
	}
;
}