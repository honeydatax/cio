#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void reversestrings(char *s2,char *s1){
	int i=0;
	int ii=0;
	int iii=0;
	ii=strlen(s1);
	
	for(i=0;i<ii;i++){
		iii=ii-i-1;
		s2[iii]=s1[i];
	}
	
	s2[ii]=0;

} 

int main (int argc,char *argv[]){
	char c1[100];
	char c2[100];
	strcpy(c1,"hello world");
	printf("%s\n",c1);
	reversestrings(c2,c1);
	printf("%s\n",c2);
	//return 0;
}


