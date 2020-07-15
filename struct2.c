#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct records{
	char data[16];
	char desc[30];
	double value; 
};


void report(struct records *rrs1[],int sizes){
	int i=0;
	
	for(i=0;i<sizes;i++)printf("%15s|%29s|%10.2f\n",rrs1[i]->data,rrs1[i]->desc,rrs1[i]->value);
	
}

void rrfill(struct records *rrs1[],int sizes){
	int i=0;
	
	for(i=0;i<sizes;i++){
		sprintf(rrs1[i]->data,"date %d",i);
		sprintf(rrs1[i]->desc,"designation %d",i);
		rrs1[i]->value=(double) i;
	}
	
}



int main(){
char ffile[80]="my.dat";
char afile[16]="r";
FILE *f1;
int sizes=50;
struct records rr1[sizes];
struct records *rrr1[sizes];
	int i=0;
	for(i=0;i<sizes;i++)rrr1[i]=&rr1[i];
	f1=fopen(ffile,afile);
	fread(&rr1,sizeof(rr1[0]),sizes,f1);
	fclose(f1);
	report(rrr1,sizes);
	return 0;
}

