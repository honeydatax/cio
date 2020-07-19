#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct stringarray{
	int size;
	int max;
	char c[2048];	
	char *cc[200];	
};

void setstringarray(struct stringarray *c,int max){
	c->size=0;
	c->max=0;
}

char *getstringarray(struct stringarray *c,int index){
	return c->cc[index];
}

int appendstringarray(struct stringarray *c,char *cc){
	int i=0;
	int count=0;
	i=c->size;
	count=strlen(cc);
	strncpy(&c->c[c->max],cc,count);
	c->c[c->max+count]=0;
	c->cc[c->size]=&c->c[c->max];
	c->max=c->max+count+2;
	c->size++;
	return i;
}

void liststringarray(struct stringarray *c){
	int i=0;
	printf("\n");
	for(i=0;i<c->size;i++)printf("%s\n",getstringarray(c,i));
	printf("\n");
}



int main(int argc, char *argv[]){
	char ccc[80]="line";
	char cc[80];
	int i=0;
	struct stringarray c;
	setstringarray(&c,32);
	for(i=0;i<11;i++){
		sprintf(cc,"%s %d",ccc,i);
		appendstringarray(&c,cc);
	}
	liststringarray(&c);

}