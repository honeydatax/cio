#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct stringarray{
	int size;
	int max;
	char c[2048];	
};

void setstringarray(struct stringarray *c,int max){
	c->size=0;
	c->max=max;
}

char *getstringarray(struct stringarray *c,int index){
	return &c->c[index*c->max];
}

int appendstringarray(struct stringarray *c,char *cc){
	int i=0;
	i=c->size;
	strncpy(&c->c[i*c->max],cc,c->max-1);
	c->size++;
	c->c[c->size*c->max-1]=0;
	return i;
}

void liststringarray(struct stringarray *c){
	int i=0;
	printf("\n");
	for(i=0;i<c->size;i++)printf("%s\n",getstringarray(c,i));
	printf("\n");
}



int main(int argc, char *argv[]){
	char *cc[]={"PC","ARM","ARM6","ARM7","X86","8086","80186","80286","80386","80486","80586"};
	int i=0;
	struct stringarray c;
	setstringarray(&c,32);
	for(i=0;i<11;i++)appendstringarray(&c,cc[i]);
	liststringarray(&c);

}