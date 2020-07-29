#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char argv){
	double f;
	for(f=-0.5;f<0.60;f=f+0.1){
		fprintf(stdout,">>>>>>>>>>$%16.2Lf\n",f);
	}
	return 0;
}
