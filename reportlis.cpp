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
	void copylist(struct arglist *arglists,char *plist[]){
		arglists->size=0;
		arglists->args[arglists->size]=plist[arglists->size];			
		arglists->size++;
		while(plist[arglists->size][0]!='\0'){
			arglists->args[arglists->size]=plist[arglists->size];			
			arglists->size++;
		}
	}

};

int main(int argc,char *argv[]){
	struct arglist arglists;
	char *list1[]={"PC","ARM","ARM6","ARM7","X86","8086","80186","80286","80386","80486","80586","\0\0"};
	reportlist *rpt=new reportlist();
	char separator='\\';
	rpt->copylist(&arglists,list1);
	rpt->report(&arglists);
}