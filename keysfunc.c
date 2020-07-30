#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	char  *getfile(char *value){
		char *getss;
		getss=value;
		if(strchr(value,'\\')!=NULL){
			getss=strrchr(value,'\\')+1;;
		}
		return getss;
	}



	void getpat(char *value){
		if(strchr(value,'\\')==NULL){
			value[0]=0;
		}else{
			strrchr(value,'\\')[0]=0;
		}

	}


int main(int argc,char *argv){
//	char c[]="windows\\command\\z.txt";
//	char c[]="z.txt";
	char c[]="windows\\command\\data\\help\\z.txt";
	char cc[255];
	char *ccc;
	printf("%s\n",c);
	strcpy(cc,c);
	getpat(cc);
	printf("%s\n",cc);
	strcpy(cc,c);
	ccc=getfile(cc);
	printf("%s\n",ccc);
}