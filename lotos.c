#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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



void setarray(int *map1,int x,int y,int xx,int value){
	map1[y*xx+x]=value;
}

int getarray(int *map1,int x,int y,int xx){
	return map1[y*xx+x];
}



void startmap(int *map1,int xx,int yy){
	int x=0;
	int y=0;
	srandom(time(NULL));
	for(y=0;y<yy;y++){
		for(x=0;x<xx;x++){
			setarray(map1,x,y,xx,rnd(1,50));
		}
	}
}

void reportmap(int *map1,int xx,int yy){
	int x=0;
	int y=0;
	printf("\n");
	for(y=0;y<yy;y++){
		for(x=0;x<xx;x++){
			if(x!=0)printf(",");
			printf("%2d",getarray(map1,x,y,xx));
		}
		printf("\n");
	}
	printf("\n");
}




int main(int argc,char *argv[]){

	int map1[8*8];
	startmap(map1,8,8);
	reportmap(map1,8,8);
}