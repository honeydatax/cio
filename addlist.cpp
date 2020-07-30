#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct arglist{
	int size;
	char separator;
	char *args[10000];
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
	int findlist(struct arglist *arglists,char *plist){
		int i=-1;
		int ii=-1;		
		for(i=0;i<arglists->size;i++){
			if(strncmp(arglists->args[i],plist,strlen(arglists->args[i]))==0){
				ii=i;			
			}
		}
		return ii;
	}
	int addlist(struct arglist *arglists,char *plist){
		int ii=-1;		
			if(arglists->size<10000){
				arglists->args[arglists->size]=plist;			
				ii=arglists->size;
				arglists->size++;
			}			
		return ii;
	}
	void clear(struct arglist *arglists){
		arglists->size=0;
	}

};

int main(int argc,char *argv[]){
	int ii=0;
	struct arglist arglists;
	char *list1[]={"PC","ARM","ARM6","ARM7","X86","8086","80186","80286","80386","80486","80586","\0\0"};
	char *item1;
	item1=list1[0];
	reportlist *rpt=new reportlist();
	char separator='\\';
	rpt->clear(&arglists);
	while(item1[0]!='\0'){
		rpt->addlist(&arglists,item1);
		item1=list1[arglists.size];
	}
	rpt->report(&arglists);

}