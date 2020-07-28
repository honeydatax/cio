#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calcs3(double w,double h,double z){
	return(w*h*z);
}

int main(int argc, char *argv){
	int size=162;
	int len=0;
	int i=0;
	char cc[size+1];
	char *c;
	c=cc;
	double w=0.00f;
	double h=0.00f;
	double z=0.00f;
	printf("w=");
	i=fscanf(stdin,"%Lf",&w);
	printf("\nh=");
	i=fscanf(stdin,"%Lf",&h);
	printf("\nz=");
	i=fscanf(stdin,"%Lf",&z);
	printf("%5.2Lf x %5.2Lf x %5.2Lf = %5.2Lf \n",w,h,z,calcs3(w,h,z));
}


