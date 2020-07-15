#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	size_t a=1;
	size_t b=512;
	size_t d=512;
	char c[512]; 
	d=fread(c,a,b,stdin);
	c[d]=0;
	printf("%d\n %s ",d,c);
	return 0;
}