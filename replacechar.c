#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace(char *s,char separator,char repl){
	char s1[2048];
	char *p1=NULL;
	char *p2=NULL;
	char *p3=NULL;
	p1=s;
	while(p1!=NULL){
		p2=strchr(p1,separator);
		if(p2!=NULL){
			p1=p2+1;
			p2[0]= repl;
		}else{
			p1=p2;
		}
		

	}
}



int main(int argc,char *argv[]){
	char s[]="c:\\windows\\dos\\command";
	char repl='/';
	char separator='\\';
	printf("%s\r\n",s);
	replace(s,separator,repl);
	printf("%s\r\n",s);
}