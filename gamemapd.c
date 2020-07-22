#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void setarray(char *map1,int x,int y,int xx,char value){
	map1[y*xx+x]=value;
}

char getarray(char *map1,int x,int y,int xx){
	char c=map1[y*xx+x];
	return c;
}



void startmap(char *map1,int xx,int yy){
	int x=0;
	int y=0;
	char i=0;
	i=32;
	for(x=0;x<xx*yy;x++){
		i++;
		map1[x]=i;
		if(i>125)i=32;
	}
}

void reportmap(char *map1,int xx,int yy){
	int x=0;
	int y=0;
	char xxxx[xx+2];
	printf("\n");
		for(y=0;y<yy;y++){
			strncpy(&xxxx[0],&map1[y*xx],xx);
			xxxx[xx+1]=0;
			printf("%s\n",xxxx);
		}
	printf("\n");
}




int main(int argc,char *argv[]){
	int x=12;
	int y=12;
	char map1[x*y+1];
	startmap(&map1[0],x,y);
	reportmap(&map1[0],x,y);
}