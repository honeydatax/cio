#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct arglist{
	int size;
	char separator;
	char *args[2048];
};

class reportlist{
	public:
	void report(struct arglist *arglists){
		int i=0;
		for(i=0;i<arglists->size;i++){
			printf("%s\n",arglists->args[i]);
		}
	}
};


class argmslis{
	private:
	public:
	void startarglist(struct arglist *arglists,char *s2){
		char s1[2048];
		char *p1=NULL;
		char *p2=NULL;
		arglists->size=0;
		strncpy(s1,s2,2047);
		s1[2047]=0;
		p1=s1;
		arglists->args[arglists->size]=s1;
		arglists->size++;
		while(p1!=NULL){
			p2=strchr(p1,arglists->separator);
			if(p2!=NULL){
				arglists->args[arglists->size]=p2+1;
				p1=arglists->args[arglists->size];
				p2[0]=0;
				arglists->size++;
			}else{
				p1=p2;
			}
			
	
		}
	}
	
};

int main(int argc,char *argv[]){
	struct arglist arglists;
	argmslis *als=new argmslis();
	reportlist *rpt=new reportlist();
	char key[]="c:\\windows\\dos\\command";
	char separator='\\';
	arglists.separator=separator;
	als->startarglist(&arglists,key);
	rpt->report(&arglists);
}