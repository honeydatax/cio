#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv){
	int size=1025;
	char aa[]="a.dat";
	FILE *f1;
	char a[size];
	int i=0;
	for(i=0;i<size-1;i++)a[i]='*';
	f1=fopen(aa,"w");
	fwrite(&a,size-1,1,f1);
	fclose(f1);
	
}