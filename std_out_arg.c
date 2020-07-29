#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
	int i;
	for(i=0;i<argc;i++){
		fprintf(stdout," %s ",argv[i]);
	}
		fprintf(stdout,"\n");
	for(i=0;i<argc;i++){
		fprintf(stdout,"%d =%s\n",i,argv[i]);
	}

	return 0;
}
